#include "driverlib.h"
#include "device.h"
#include "board.h"
#include <stdio.h>

// ==================================================
// Fault Code & Thresholds
// ==================================================
#define FAULT_NORMAL          0
#define FAULT_UNDERVOLTAGE    1
#define FAULT_OVERLOAD        2
#define FAULT_DISCONNECT      3
#define FAULT_OVERVOLTAGE     4

#define VOLTAGE_MIN_X100        1050    // 10.50V
#define VOLTAGE_MAX_X100        1380    // 13.80V
#define CURRENT_THRESHOLD_X100  500     // 5.00A
#define CURRENT_MIN_X100        5       // 0.05A

// ==================================================
// Global Variables
// ==================================================
uint16_t adcResultCurrent; // 물리적 28번 (ADCINC0)
uint16_t adcResultVoltage; // 물리적 66번 (ADCINC1)

// ==================================================
// Function Prototypes
// ==================================================
void initADC(void);
void readSensors(uint16_t *v_x100, uint16_t *i_x100);
uint16_t classifyFault(uint16_t voltage_x100, uint16_t current_x100);
void sendReGridData(uint16_t voltage_x100, uint16_t current_x100, uint16_t fault);
void SCI_sendString(const char *str);
void SCI_sendUint(uint16_t value);
void SCI_sendFaultString(uint16_t fault);

// ==================================================
// Main
// ==================================================
void main(void)
{
    uint16_t voltage_x100 = 0;
    uint16_t current_x100 = 0;
    uint16_t fault = FAULT_NORMAL;

    Device_init();
    Device_initGPIO();
    Interrupt_initModule();
    Interrupt_initVectorTable();

    Board_init(); // SysConfig에서 설정한 SCI 초기화 등
    initADC();    // ADC 모듈 상세 설정

    EINT;
    ERTM;

    while(1)
    {
        // 1. 센서 값 읽기 및 물리량 변환
        readSensors(&voltage_x100, &current_x100);

        // 2. 상태 분류 (임계값 체크)
        fault = classifyFault(voltage_x100, current_x100);

        // 3. 라즈베리파이로 송신
        sendReGridData(voltage_x100, current_x100, fault);

        // 1초 대기
        DEVICE_DELAY_US(1000000);
    }
}

// ==================================================
// ADC Initialization (물리적 28:INC0, 66:INC1)
// ==================================================
void initADC(void)
{
    // ADCC 모듈 클럭 설정
    ADC_setPrescaler(ADCC_BASE, ADC_CLK_DIV_4_0);

    // ADC 컨버터 전원 켜기 (매우 중요!)
    ADC_enableConverter(ADCC_BASE);
    DEVICE_DELAY_US(1000); // 전원 안정화 대기

    // 변환 완료 시점 설정
    ADC_setInterruptPulseMode(ADCC_BASE, ADC_PULSE_END_OF_CONV);

    // SOC0 설정: 물리적 28번(ADCINC0), 전류 센서
    ADC_setupSOC(ADCC_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN0, 15);

    // SOC1 설정: 물리적 66번(ADCINC1), 전압 센서
    ADC_setupSOC(ADCC_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN1, 15);

    // SOC1 변환 완료 시 인터럽트 플래그(ADCINT1) 발생 설정
    ADC_setInterruptSource(ADCC_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
    ADC_enableInterrupt(ADCC_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCC_BASE, ADC_INT_NUMBER1);
}

// ==================================================
// Read Sensors & Physical Value Conversion
// ==================================================
void readSensors(uint16_t *v_x100, uint16_t *i_x100)
{
    ADC_forceSOC(ADCC_BASE, ADC_SOC_NUMBER0);
    ADC_forceSOC(ADCC_BASE, ADC_SOC_NUMBER1);

    while(ADC_getInterruptStatus(ADCC_BASE, ADC_INT_NUMBER1) == false);
    ADC_clearInterruptStatus(ADCC_BASE, ADC_INT_NUMBER1);

    adcResultCurrent = ADC_readResult(ADCCRESULT_BASE, ADC_SOC_NUMBER0);
    adcResultVoltage = ADC_readResult(ADCCRESULT_BASE, ADC_SOC_NUMBER1);

    // 1. ADC 입력 전압 계산 (0 ~ 3.3V)
    float adcVoltVoltage = ((float)adcResultVoltage * 3.3f) / 4095.0f;
    float adcVoltCurrent = ((float)adcResultCurrent * 3.3f) / 4095.0f;

    // 2. 전압 센서 보정 (11.2V 입력 시 16.5V가 나오던 문제 해결)
    // 실제 입력 11.2V일 때 ADC 측정 전압(adcVoltVoltage)을 기준으로 비율을 다시 잡습니다.
    // 만약 11.2V일 때 ADC에 3.3V가 꽉 차 있다면 보정계수는 11.2/3.3 = 3.394가 맞습니다.
    float f_volt = adcVoltVoltage * 3.394f; 

    // 3. 전류 센서 보정 (ACS712 30A 모델 기준)
    // [중요] 0A일 때 실제 ADC 전압이 몇 V인지 확인이 필요합니다. 
    // 만약 전압 분배 저항을 안 썼다면 2.5V, 썼다면 약 1.65V가 찍혀야 합니다.
    float CURRENT_ZERO_VOLTAGE = 1.65f; // 일단 1.65V로 두되, 값이 튀면 2.5f로 바꿔보세요.
    float CURRENT_SENSITIVITY = 0.066f; // 30A 모델: 66mV/A

    float f_curr = (adcVoltCurrent - CURRENT_ZERO_VOLTAGE) / CURRENT_SENSITIVITY;

    // 4. 노이즈 제거 (Dead-zone 처리)
    // 0.2A 미만의 미세 전류는 0으로 간주 (데이터 안정화)
    if(f_curr < 0.20f && f_curr > -0.20f) f_curr = 0.0f;
    if(f_curr < 0.0f) f_curr = 0.0f; 

    // 5. 최종 값 전달 (x100 포맷)
    *v_x100 = (uint16_t)(f_volt * 100.0f);
    *i_x100 = (uint16_t)(f_curr * 100.0f);
}

// ==================================================
// Fault Classification & Communication (기존 동일)
// ==================================================
uint16_t classifyFault(uint16_t voltage_x100, uint16_t current_x100)
{
    if(current_x100 > CURRENT_THRESHOLD_X100) return FAULT_OVERLOAD;
    if(current_x100 < CURRENT_MIN_X100)       return FAULT_DISCONNECT;
    if(voltage_x100 < VOLTAGE_MIN_X100)       return FAULT_UNDERVOLTAGE;
    if(voltage_x100 > VOLTAGE_MAX_X100)       return FAULT_OVERVOLTAGE;
    return FAULT_NORMAL;
}

void sendReGridData(uint16_t voltage_x100, uint16_t current_x100, uint16_t fault)
{
    SCI_sendString("V=");
    SCI_sendUint(voltage_x100);

    SCI_sendString(",I=");
    SCI_sendUint(current_x100);

    SCI_sendString(",RV=");
    SCI_sendUint(adcResultVoltage);

    SCI_sendString(",RI=");
    SCI_sendUint(adcResultCurrent);

    SCI_sendString(",FAULT=");
    SCI_sendUint(fault);

    SCI_sendString("\r\n");
}

void SCI_sendString(const char *str)
{
    uint16_t i = 0;
    while(str[i] != '\0')
    {
        SCI_writeCharBlockingFIFO(mySCI0_BASE, str[i]);
        i++;
    }
}

void SCI_sendUint(uint16_t value)
{
    char buffer[6];
    uint16_t i = 0, j;
    if(value == 0) { SCI_writeCharBlockingFIFO(mySCI0_BASE, '0'); return; }
    while(value > 0) { buffer[i++] = (value % 10) + '0'; value /= 10; }
    for(j = 0; j < i; j++) SCI_writeCharBlockingFIFO(mySCI0_BASE, buffer[i - j - 1]);
}

void SCI_sendFaultString(uint16_t fault)
{
    switch(fault)
    {
        case FAULT_NORMAL:
            SCI_sendString("NORMAL");
            break;

        case FAULT_UNDERVOLTAGE:
            SCI_sendString("UNDERVOLTAGE");
            break;

        case FAULT_OVERLOAD:
            SCI_sendString("OVERLOAD");
            break;

        case FAULT_DISCONNECT:
            SCI_sendString("DISCONNECT");
            break;

        case FAULT_OVERVOLTAGE:
            SCI_sendString("OVERVOLTAGE");
            break;

        default:
            SCI_sendString("UNKNOWN");
            break;
    }
}
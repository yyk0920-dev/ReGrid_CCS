/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// SCIA -> mySCI0 Pinmux
//
//
// SCIA_RX - GPIO Settings
//
#define GPIO_PIN_SCIA_RX 3
#define mySCI0_SCIRX_GPIO 3
#define mySCI0_SCIRX_PIN_CONFIG GPIO_3_SCIA_RX
//
// SCIA_TX - GPIO Settings
//
#define GPIO_PIN_SCIA_TX 2
#define mySCI0_SCITX_GPIO 2
#define mySCI0_SCITX_PIN_CONFIG GPIO_2_SCIA_TX

//
// SPIA -> mySPI0 Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 16
#define mySPI0_SPIPICO_GPIO 16
#define mySPI0_SPIPICO_PIN_CONFIG GPIO_16_SPIA_SIMO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 17
#define mySPI0_SPIPOCI_GPIO 17
#define mySPI0_SPIPOCI_PIN_CONFIG GPIO_17_SPIA_SOMI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 18
#define mySPI0_SPICLK_GPIO 18
#define mySPI0_SPICLK_PIN_CONFIG GPIO_18_SPIA_CLK
//
// SPIA_PTE - GPIO Settings
//
#define GPIO_PIN_SPIA_PTE 57
#define mySPI0_SPIPTE_GPIO 57
#define mySPI0_SPIPTE_PIN_CONFIG GPIO_57_SPIA_STE

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCI0_BASE SCIA_BASE
#define mySCI0_BAUDRATE 115200
#define mySCI0_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCI0_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCI0_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCI0_FIFO_TX_LVL SCI_FIFO_TX0
#define mySCI0_FIFO_RX_LVL SCI_FIFO_RX0
void mySCI0_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define mySPI0_BASE SPIA_BASE
#define mySPI0_BITRATE 1000000
#define mySPI0_DATAWIDTH 8
void mySPI0_init();

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	SCI_init();
void	SPI_init();
void	SYSCTL_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition

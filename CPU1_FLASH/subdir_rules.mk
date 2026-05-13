################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project" --include_path="C:/ti/C2000Ware_26_00_00_00" --include_path="C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-233623625: ../spi_ex1_loopback.syscfg
	@echo 'SysConfig - building file: "$<"'
	"C:/ti/ccs2051/ccs/utils/sysconfig_1.27.1/sysconfig_cli.bat" -s "C:/ti/C2000Ware_26_00_00_00/.metadata/sdk.json" --script "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/spi_ex1_loopback.syscfg" --context "system" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-233623625 ../spi_ex1_loopback.syscfg
syscfg/board.h: build-233623625
syscfg/board.cmd.genlibs: build-233623625
syscfg/board.opt: build-233623625
syscfg/board.json: build-233623625
syscfg/pinmux.csv: build-233623625
syscfg/device.c: build-233623625
syscfg/device.h: build-233623625
syscfg/device_cmd.cmd: build-233623625
syscfg/device_cmd.c: build-233623625
syscfg/device_cmd.h: build-233623625
syscfg/device_cmd.opt: build-233623625
syscfg/device_cmd.cmd.genlibs: build-233623625
syscfg/c2000ware_libraries.cmd.genlibs: build-233623625
syscfg/c2000ware_libraries.opt: build-233623625
syscfg/c2000ware_libraries.c: build-233623625
syscfg/c2000ware_libraries.h: build-233623625
syscfg/clocktree.h: build-233623625
syscfg: build-233623625

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project" --include_path="C:/ti/C2000Ware_26_00_00_00" --include_path="C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f28004x_codestartbranch.obj: C:/ti/C2000Ware_26_00_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project" --include_path="C:/ti/C2000Ware_26_00_00_00" --include_path="C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



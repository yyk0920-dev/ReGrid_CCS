################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/device_cmd.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := -l"syscfg/device_cmd.cmd" 

ORDERED_OBJS += \
"./ReGrid_main.obj" \
"./syscfg/board.obj" \
"./syscfg/device.obj" \
"./syscfg/device_cmd.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./f28004x_codestartbranch.obj" \
$(GEN_CMDS__FLAG) \
-lc2000ware_libraries.cmd.genlibs \
-lboard.cmd.genlibs \
-ldevice_cmd.cmd.genlibs \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ReGrid\ Project.out 

EXE_OUTPUTS__QUOTED += \
"ReGrid Project.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "ReGrid Project.out"

# Tool invocations
ReGrid\ Project.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'C2000 Linker - building target: "$@"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"ReGrid Project.map" --heap_size=0x200 --stack_size=0x3F8 --warn_sections -i"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/lib" -i"C:/ti/C2000Ware_26_00_00_00" -i"C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg" -i"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --reread_libs --define=_FLASH --define=generic_flash_lnk --diag_wrap=off --display_error_number --xml_link_info="ReGrid Project_linkInfo.xml" --entry_point=code_start --rom_model -o "ReGrid Project.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ReGrid_main.obj" "syscfg\board.obj" "syscfg\device.obj" "syscfg\device_cmd.obj" "syscfg\c2000ware_libraries.obj" "f28004x_codestartbranch.obj" 
	-$(RM) "ReGrid_main.d" "syscfg\board.d" "syscfg\device.d" "syscfg\device_cmd.d" "syscfg\c2000ware_libraries.d" 
	-$(RM) "f28004x_codestartbranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo ' '

post-build:
	-echo "========= Build of the CLB simulation has moved to the CLB Tool. Click the '?' icon by the _Generate CLB Simulation File_ enable for more details (located in the Global Parameters of the Tile Design SysConfig module) ============="
	-if 0 == 1  C:/ti/ccs2051/ccs/tools/node/node.exe "C:/ti/C2000Ware_26_00_00_00/utilities/clb_tool/clb_syscfg/dot_file_libraries/clbDotUtility.js"  "C:/ti/C2000Ware_26_00_00_00/utilities/clb_tool/clb_syscfg/" "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg" "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg/clb.dot"
	-if 0 == 1  mkdir "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/diagrams"
	-if 0 == 1  C:/ti/ccs2051/ccs/tools/node/node.exe "C:/ti/C2000Ware_26_00_00_00/driverlib/.meta/generate_diagrams.js" "C:/ti/C2000Ware_26_00_00_00" "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/diagrams" "C:/Users/20240620-LapTop/workspace_ccstheia/ReGrid Project/CPU1_FLASH/syscfg"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


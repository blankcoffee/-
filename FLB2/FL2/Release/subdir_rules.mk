################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="D:/ti/ccs1020/ccs/ccs_base/arm/include" --include_path="D:/ti/IQMATHLIB_01_10_00_05" --include_path="D:/ti/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="D:/ti/ccs1020/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/Desktop/FLB2/FL2" --include_path="D:/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


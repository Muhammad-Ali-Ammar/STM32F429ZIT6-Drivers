################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SCB/SCB.c 

OBJS += \
./MCAL/SCB/SCB.o 

C_DEPS += \
./MCAL/SCB/SCB.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SCB/%.o MCAL/SCB/%.su MCAL/SCB/%.cyclo: ../MCAL/SCB/%.c MCAL/SCB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/MCAL/GPIO" -I"/home/muhammad/Desktop/embedded/NTI TASK/STM32F429I/STM32F429/ECUL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-SCB

clean-MCAL-2f-SCB:
	-$(RM) ./MCAL/SCB/SCB.cyclo ./MCAL/SCB/SCB.d ./MCAL/SCB/SCB.o ./MCAL/SCB/SCB.su

.PHONY: clean-MCAL-2f-SCB


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SYSTICK/SYSTICK.c 

OBJS += \
./MCAL/SYSTICK/SYSTICK.o 

C_DEPS += \
./MCAL/SYSTICK/SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SYSTICK/%.o MCAL/SYSTICK/%.su MCAL/SYSTICK/%.cyclo: ../MCAL/SYSTICK/%.c MCAL/SYSTICK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/MCAL/GPIO" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/ECUL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-SYSTICK

clean-MCAL-2f-SYSTICK:
	-$(RM) ./MCAL/SYSTICK/SYSTICK.cyclo ./MCAL/SYSTICK/SYSTICK.d ./MCAL/SYSTICK/SYSTICK.o ./MCAL/SYSTICK/SYSTICK.su

.PHONY: clean-MCAL-2f-SYSTICK


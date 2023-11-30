################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC/RCC.c \
../MCAL/RCC/RCC_config.c 

OBJS += \
./MCAL/RCC/RCC.o \
./MCAL/RCC/RCC_config.o 

C_DEPS += \
./MCAL/RCC/RCC.d \
./MCAL/RCC/RCC_config.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC/%.o MCAL/RCC/%.su MCAL/RCC/%.cyclo: ../MCAL/RCC/%.c MCAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/MCAL/GPIO" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429 Drivers/ECUL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-RCC

clean-MCAL-2f-RCC:
	-$(RM) ./MCAL/RCC/RCC.cyclo ./MCAL/RCC/RCC.d ./MCAL/RCC/RCC.o ./MCAL/RCC/RCC.su ./MCAL/RCC/RCC_config.cyclo ./MCAL/RCC/RCC_config.d ./MCAL/RCC/RCC_config.o ./MCAL/RCC/RCC_config.su

.PHONY: clean-MCAL-2f-RCC


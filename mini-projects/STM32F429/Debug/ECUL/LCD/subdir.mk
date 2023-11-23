################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUL/LCD/LCD.c \
../ECUL/LCD/LCD_config.c 

OBJS += \
./ECUL/LCD/LCD.o \
./ECUL/LCD/LCD_config.o 

C_DEPS += \
./ECUL/LCD/LCD.d \
./ECUL/LCD/LCD_config.d 


# Each subdirectory must supply rules for building sources it contributes
ECUL/LCD/%.o ECUL/LCD/%.su ECUL/LCD/%.cyclo: ../ECUL/LCD/%.c ECUL/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/MCAL/GPIO" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/ECUL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECUL-2f-LCD

clean-ECUL-2f-LCD:
	-$(RM) ./ECUL/LCD/LCD.cyclo ./ECUL/LCD/LCD.d ./ECUL/LCD/LCD.o ./ECUL/LCD/LCD.su ./ECUL/LCD/LCD_config.cyclo ./ECUL/LCD/LCD_config.d ./ECUL/LCD/LCD_config.o ./ECUL/LCD/LCD_config.su

.PHONY: clean-ECUL-2f-LCD


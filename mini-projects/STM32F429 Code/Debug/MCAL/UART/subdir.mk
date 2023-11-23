################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/USART.c \
../MCAL/UART/USART_config.c 

OBJS += \
./MCAL/UART/USART.o \
./MCAL/UART/USART_config.o 

C_DEPS += \
./MCAL/UART/USART.d \
./MCAL/UART/USART_config.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o MCAL/UART/%.su MCAL/UART/%.cyclo: ../MCAL/UART/%.c MCAL/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/ECUL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/APP" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/SERVICES" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/MCAL" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/MCAL/GPIO" -I"/home/muhammad/Desktop/embedded/NTI TASK/Repo/STM32F429ZIT6-Drivers/STM32F429/ECUL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-UART

clean-MCAL-2f-UART:
	-$(RM) ./MCAL/UART/USART.cyclo ./MCAL/UART/USART.d ./MCAL/UART/USART.o ./MCAL/UART/USART.su ./MCAL/UART/USART_config.cyclo ./MCAL/UART/USART_config.d ./MCAL/UART/USART_config.o ./MCAL/UART/USART_config.su

.PHONY: clean-MCAL-2f-UART


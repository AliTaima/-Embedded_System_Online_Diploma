################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/stm32f103x8_EXTI_driver.c \
../MCAL/stm32f103x8_RCC_driver.c \
../MCAL/stm32f103x8_USART_driver.c \
../MCAL/stm32f103x8_gpio_driver.c 

OBJS += \
./MCAL/stm32f103x8_EXTI_driver.o \
./MCAL/stm32f103x8_RCC_driver.o \
./MCAL/stm32f103x8_USART_driver.o \
./MCAL/stm32f103x8_gpio_driver.o 

C_DEPS += \
./MCAL/stm32f103x8_EXTI_driver.d \
./MCAL/stm32f103x8_RCC_driver.d \
./MCAL/stm32f103x8_USART_driver.d \
./MCAL/stm32f103x8_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"B:/Embedded_Systems_Online_Diploma/Unit_8_MCU_Interfacing/Lesson3_UART_Driver_STM32/STM32F103C6_With_Polling/HAL/inc" -I"B:/Embedded_Systems_Online_Diploma/Unit_8_MCU_Interfacing/Lesson3_UART_Driver_STM32/STM32F103C6_With_Polling/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/stm32f103x8_EXTI_driver.cyclo ./MCAL/stm32f103x8_EXTI_driver.d ./MCAL/stm32f103x8_EXTI_driver.o ./MCAL/stm32f103x8_EXTI_driver.su ./MCAL/stm32f103x8_RCC_driver.cyclo ./MCAL/stm32f103x8_RCC_driver.d ./MCAL/stm32f103x8_RCC_driver.o ./MCAL/stm32f103x8_RCC_driver.su ./MCAL/stm32f103x8_USART_driver.cyclo ./MCAL/stm32f103x8_USART_driver.d ./MCAL/stm32f103x8_USART_driver.o ./MCAL/stm32f103x8_USART_driver.su ./MCAL/stm32f103x8_gpio_driver.cyclo ./MCAL/stm32f103x8_gpio_driver.d ./MCAL/stm32f103x8_gpio_driver.o ./MCAL/stm32f103x8_gpio_driver.su

.PHONY: clean-MCAL


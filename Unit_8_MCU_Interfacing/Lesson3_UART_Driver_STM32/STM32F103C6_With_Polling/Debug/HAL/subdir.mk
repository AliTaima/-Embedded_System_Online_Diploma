################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/_7segment.c \
../HAL/keypad.c \
../HAL/lcd.c 

OBJS += \
./HAL/_7segment.o \
./HAL/keypad.o \
./HAL/lcd.o 

C_DEPS += \
./HAL/_7segment.d \
./HAL/keypad.d \
./HAL/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"B:/Embedded_Systems_Online_Diploma/Unit_8_MCU_Interfacing/Lesson3_UART_Driver_STM32/STM32F103C6_With_Polling/HAL/inc" -I"B:/Embedded_Systems_Online_Diploma/Unit_8_MCU_Interfacing/Lesson3_UART_Driver_STM32/STM32F103C6_With_Polling/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/_7segment.cyclo ./HAL/_7segment.d ./HAL/_7segment.o ./HAL/_7segment.su ./HAL/keypad.cyclo ./HAL/keypad.d ./HAL/keypad.o ./HAL/keypad.su ./HAL/lcd.cyclo ./HAL/lcd.d ./HAL/lcd.o ./HAL/lcd.su

.PHONY: clean-HAL


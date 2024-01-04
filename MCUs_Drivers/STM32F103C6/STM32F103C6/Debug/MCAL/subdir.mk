################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32_F103C6_EXTI_Driver.c \
../MCAL/Stm32_F103C6_GPIO_Driver.c 

OBJS += \
./MCAL/Stm32_F103C6_EXTI_Driver.o \
./MCAL/Stm32_F103C6_GPIO_Driver.o 

C_DEPS += \
./MCAL/Stm32_F103C6_EXTI_Driver.d \
./MCAL/Stm32_F103C6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"B:/Embedded_Systems_Online_Diploma/MCUs_Drivers/STM32F103C6/STM32F103C6/HAL/inc" -I"B:/Embedded_Systems_Online_Diploma/MCUs_Drivers/STM32F103C6/STM32F103C6/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/Stm32_F103C6_EXTI_Driver.cyclo ./MCAL/Stm32_F103C6_EXTI_Driver.d ./MCAL/Stm32_F103C6_EXTI_Driver.o ./MCAL/Stm32_F103C6_EXTI_Driver.su ./MCAL/Stm32_F103C6_GPIO_Driver.cyclo ./MCAL/Stm32_F103C6_GPIO_Driver.d ./MCAL/Stm32_F103C6_GPIO_Driver.o ./MCAL/Stm32_F103C6_GPIO_Driver.su

.PHONY: clean-MCAL


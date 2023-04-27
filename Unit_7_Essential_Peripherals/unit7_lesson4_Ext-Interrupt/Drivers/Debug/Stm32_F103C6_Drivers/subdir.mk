################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.c 

OBJS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/%.o Stm32_F103C6_Drivers/%.su: ../Stm32_F103C6_Drivers/%.c Stm32_F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"B:/Embedded_Systems_Online_Diploma/Unit_7_Essential_Peripherals/unit7_lesson4_Ext-Interrupt/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Stm32_F103C6_Drivers

clean-Stm32_F103C6_Drivers:
	-$(RM) ./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.d ./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.o ./Stm32_F103C6_Drivers/Stm32_F103C6_EXTI_Driver.su

.PHONY: clean-Stm32_F103C6_Drivers


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.c 

OBJS += \
./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/GPIO/%.o Stm32_F103C6_Drivers/GPIO/%.su: ../Stm32_F103C6_Drivers/GPIO/%.c Stm32_F103C6_Drivers/GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"B:/Embedded_Systems_Online_Diploma/Unit_7_Essential_Peripherals/unit7_lesson3_drivers/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Stm32_F103C6_Drivers-2f-GPIO

clean-Stm32_F103C6_Drivers-2f-GPIO:
	-$(RM) ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.d ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.o ./Stm32_F103C6_Drivers/GPIO/Stm32_F103C6_GPIO_Driver.su

.PHONY: clean-Stm32_F103C6_Drivers-2f-GPIO


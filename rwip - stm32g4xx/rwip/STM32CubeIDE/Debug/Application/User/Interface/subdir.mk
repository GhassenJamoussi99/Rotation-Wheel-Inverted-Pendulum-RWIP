################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/modules/Src/Interface/display.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/modules/Src/Interface/led.c 

OBJS += \
./Application/User/Interface/display.o \
./Application/User/Interface/led.o 

C_DEPS += \
./Application/User/Interface/display.d \
./Application/User/Interface/led.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Interface/display.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/modules/Src/Interface/display.c Application/User/Interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../../../modules/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v6.1.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v6.1.2-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Interface/display.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Interface/led.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/modules/Src/Interface/led.c Application/User/Interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../../../modules/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v6.1.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v6.1.2-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Interface/led.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Interface

clean-Application-2f-User-2f-Interface:
	-$(RM) ./Application/User/Interface/display.d ./Application/User/Interface/display.o ./Application/User/Interface/display.su ./Application/User/Interface/led.d ./Application/User/Interface/led.o ./Application/User/Interface/led.su

.PHONY: clean-Application-2f-User-2f-Interface


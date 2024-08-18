################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/dac_ui.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/main.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_api.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_config.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_interface.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_math.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_parameters.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_tasks.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/motor_control_protocol.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/motorcontrol.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/regular_conversion_manager.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_hal_msp.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_it.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_mc_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/ui_task.c \
H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/user_interface.c 

OBJS += \
./Application/User/dac_ui.o \
./Application/User/main.o \
./Application/User/mc_api.o \
./Application/User/mc_config.o \
./Application/User/mc_interface.o \
./Application/User/mc_math.o \
./Application/User/mc_parameters.o \
./Application/User/mc_tasks.o \
./Application/User/motor_control_protocol.o \
./Application/User/motorcontrol.o \
./Application/User/regular_conversion_manager.o \
./Application/User/stm32g4xx_hal_msp.o \
./Application/User/stm32g4xx_it.o \
./Application/User/stm32g4xx_mc_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/ui_task.o \
./Application/User/user_interface.o 

C_DEPS += \
./Application/User/dac_ui.d \
./Application/User/main.d \
./Application/User/mc_api.d \
./Application/User/mc_config.d \
./Application/User/mc_interface.d \
./Application/User/mc_math.d \
./Application/User/mc_parameters.d \
./Application/User/mc_tasks.d \
./Application/User/motor_control_protocol.d \
./Application/User/motorcontrol.d \
./Application/User/regular_conversion_manager.d \
./Application/User/stm32g4xx_hal_msp.d \
./Application/User/stm32g4xx_it.d \
./Application/User/stm32g4xx_mc_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/ui_task.d \
./Application/User/user_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/dac_ui.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/dac_ui.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/dac_ui.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_api.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_api.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_api.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_config.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_config.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_config.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_interface.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_interface.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_math.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_math.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_math.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_parameters.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_parameters.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_parameters.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mc_tasks.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/mc_tasks.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/mc_tasks.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/motor_control_protocol.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/motor_control_protocol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/motor_control_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/motorcontrol.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/motorcontrol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/motorcontrol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/regular_conversion_manager.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/regular_conversion_manager.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/regular_conversion_manager.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_hal_msp.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_it.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32g4xx_mc_it.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/stm32g4xx_mc_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32g4xx_mc_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/ui_task.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/ui_task.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/ui_task.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/user_interface.o: H:/Masterstudium\ -\ HTW/ProjektEntwicklung/Repositories/software/motor_control_test/mitoot_encoder/OpenLoop/open_loop/Src/user_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../../Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/MCLib/G4xx/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/UILibrary/Inc -I../../MCSDK_v5.4.8-Full/MotorControl/MCSDK/SystemDriveParams -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/user_interface.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/dac_ui.d ./Application/User/dac_ui.o ./Application/User/dac_ui.su ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/mc_api.d ./Application/User/mc_api.o ./Application/User/mc_api.su ./Application/User/mc_config.d ./Application/User/mc_config.o ./Application/User/mc_config.su ./Application/User/mc_interface.d ./Application/User/mc_interface.o ./Application/User/mc_interface.su ./Application/User/mc_math.d ./Application/User/mc_math.o ./Application/User/mc_math.su ./Application/User/mc_parameters.d ./Application/User/mc_parameters.o ./Application/User/mc_parameters.su ./Application/User/mc_tasks.d ./Application/User/mc_tasks.o ./Application/User/mc_tasks.su ./Application/User/motor_control_protocol.d ./Application/User/motor_control_protocol.o ./Application/User/motor_control_protocol.su ./Application/User/motorcontrol.d ./Application/User/motorcontrol.o ./Application/User/motorcontrol.su ./Application/User/regular_conversion_manager.d ./Application/User/regular_conversion_manager.o ./Application/User/regular_conversion_manager.su ./Application/User/stm32g4xx_hal_msp.d ./Application/User/stm32g4xx_hal_msp.o ./Application/User/stm32g4xx_hal_msp.su ./Application/User/stm32g4xx_it.d ./Application/User/stm32g4xx_it.o ./Application/User/stm32g4xx_it.su ./Application/User/stm32g4xx_mc_it.d ./Application/User/stm32g4xx_mc_it.o ./Application/User/stm32g4xx_mc_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/ui_task.d ./Application/User/ui_task.o ./Application/User/ui_task.su ./Application/User/user_interface.d ./Application/User/user_interface.o ./Application/User/user_interface.su

.PHONY: clean-Application-2f-User


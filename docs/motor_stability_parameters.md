# Stabilization Process of Rotation Wheel Inverted Pendulum

## Introduction

The Rotation Wheel Inverted Pendulum system is a complex control system used to demonstrate and study the principles of dynamic equilibrium and feedback control. The objective is to maintain an inverted pendulum in a stable, upright position by manipulating the rotation of an attached wheel. This documentation serves as a guide for understanding and managing the stabilization process of the RWIP.

## System Description

### Components

- **Pendulum**: A rod-like structure that needs to be stabilized in an upright position.
- **Wheel**: A rotating wheel at the base of the pendulum which is used to control the pendulum's position.
- **Encoder**: A sensor used to measure the pendulum's angle and angular velocity.
- **Motor**: Powers the rotation of the wheel, with its speed controlled by a feedback loop.

## Stabilization Control Implementation

### Control Strategy Overview

The core of the stabilization process is a feedback control loop. This loop adjusts the speed of the motor based on the current state of the pendulum. By continuously updating the motor's speed, the pendulum is actively balanced in its upright position.

### Control Algorithm

The function `computeStabilization_test2()` encapsulates the control algorithm. It operates by performing the following steps:

1. **Angle Mapping**: It first maps the pendulum's current angle (`encoder.pendulum_angle`) relative to a predefined neutral angle (`neutral_angle`). This mapped angle is a measure of how far the pendulum is from its desired upright position.

2. **Control Signal Calculation**: A control signal (`controlSignalRPM`) is computed using a proportional-integral-derivative (PID) like approach. This signal is a weighted sum of three factors:
   - The deviation of the pendulum's angle from the neutral position.
   - The angular velocity of the pendulum (`encoder.pendulum_velocity`).
   - The current speed of the motor (`encoder.motor_speed`).
   The weights for these factors are provided by the `Kr` array, representing the system's tuning parameters.

3. **Signal Limiting**: To prevent excessive motor speed, the control signal is limited. If the absolute value of `controlSignalRPM` exceeds a certain percentage (`prozent`) of `MAX_APPLICATION_SPEED_RPM`, it's capped to this limit. This step ensures safety and protects the motor from operating beyond its capabilities.

4. **Motor Speed Adjustment**: The motor's speed is adjusted based on the control signal. The function `MC_ProgramSpeedRampMotor1` is used to set the motor's speed, considering the pendulum's angle relative to the swing-up angles (`POS_SWINGUP_ANGLE`, `NEG_SWINGUP_ANGLE`).

### PID Parameters for Motor Control

In addition to the control gains for the stabilization algorithm, the motor's control loop utilizes specific PID parameters:

- **`PID_SPEED_KP_DEFAULT`**: The proportional gain for the motor's speed control. It is calculated as `3000/(SPEED_UNIT/10)`. The proportional component adjusts the motor's response proportional to the current error, which is the difference between the desired and actual speeds.

- **`PID_SPEED_KI_DEFAULT`**: The integral gain, set as `50/(SPEED_UNIT/10)`. The integral component accumulates the error over time and responds based on the cumulative error. This helps in eliminating steady-state errors.

- **`PID_SPEED_KD_DEFAULT`**: The derivative gain, defined as `0/(SPEED_UNIT/10)`. In this case, it is set to zero, indicating that the derivative component (which responds to the rate of change of error) is not used in this control scheme.

These PID parameters are vital for fine-tuning the motor's response to the control signals. They are calculated based on the `SPEED_UNIT` which normalizes the gains to a standard unit.



### Key Variables and Parameters

- **`neutral_angle`**: The target angle at which the pendulum is perfectly vertical.
- **`Kr[3]`**: Control gains for the system. Each element corresponds to a different aspect of the pendulum's state:
  - `Kr[0]`: Gain for the pendulum angle deviation. The optimal value that we found after multiple testing is 135.8617.
  - `Kr[1]`: Gain for the pendulum's angular velocity. The optimal value that we found after multiple testing is 73.5572.
  - `Kr[2]`: Gain for the motor's speed. The optimal value that we found after multiple testing is 1.5.
- **`MAX_APPLICATION_SPEED_RPM`**: The maximum allowable speed for the motor.
- **`prozent`**: A scaling factor (expressed as a percentage) used to limit the maximum control signal applied to the motor.
- **`POS_SWINGUP_ANGLE`, `NEG_SWINGUP_ANGLE`**: These define the threshold angles for initiating the stabilization control. They mark the boundary within which the control algorithm actively tries to stabilize the pendulum.

## Conclusion

The stabilization of a Rotation Wheel Inverted Pendulum is a complex task that requires precise control and tuning of parameters. The implemented control algorithm effectively balances the pendulum by continuously adjusting the motor's speed based on the real-time angular position and velocity of the pendulum. Proper tuning of the control gains (`Kr`) and the careful setting of operational limits (like `MAX_APPLICATION_SPEED_RPM` and `prozent`) are critical for the successful operation of the system.
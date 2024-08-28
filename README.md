
<div align="center">
  <a href="http://www.youtube.com/watch?v=k0FuAN_W_Ps" target="_blank">
    <img src="https://github.com/GhassenJamoussi99/Rotation-Wheel-Inverted-Pendulum-RWIP/blob/main/docs/figures/rwip.gif" width="600" alt="Swing Up and Stabilization with External Forces">
  </a>
</div>

# Rotation-Wheel-Inverted-Pendulum-RWIP
This README provides step-by-step instructions on how to set up and run the RWIP software for your STM32 project.


## Project objectives

The RWIP project aims to design and build an inverted pendulum that automatically erects the pendulum to an upright position in a closed loop system. The project objectives are as followed:

The system
* shall be able to erect itself by the reaction wheels movement alone.
* shall keep itself in an upright position defying outside forces.
* shall achieve its movement by rotating a reaction wheel resulting in a torque for the entire pendulum.
* shall be driven by a BDLC motor controlled in a closed-loop system.
  
## Modules overview

### Control Module
#### Encoder 

The Control module includes encoder implementation, which interfaces with the low-level API functions from MC (Motor Control) for smoother development and motor control.

#### Error Handling

Error handling is integrated to manage issues that may arise during motor operation or software execution. This feature aids in debugging and troubleshooting.

#### Regulator

The Regulator module is responsible for swing-up control, helping maintain the desired control state for the motor.

### Interface Module
The Interface module encompasses:

Display: Used to present motor and software status.

LEDs: Indicate errors and motor/software status visually.


## Motor Control 

For a simple, first setup to get the motor rotating with an encoder in closed loop:

- In Motor Control Workbench create a project with the profiled motor and add "quadrature encoder" as a sensor to it
- Set the "Pulses per mechanical revolution" to whatever you set your encoder to. For the AMT103V I set 256 as higher values show a lot of noise though this can be done better later on (256 is still fine)
- Set the "Alignment electrical angle of Id" to 90 degrees. The amps should be the max amps of the motor
- The encoder counting has to match the rotation of the motor so clock wise motor should match clockwise encoder in the counting otherwise it might not work
- Generate the project

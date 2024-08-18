# Motor control

This project aims to control a motor in both directions using the P-NUCLEO-IHM03 motor-control Nucleo pack. The current code utilizes the MC API, but there is a delay when switching from one direction to another that needs to be eliminated.

## Code Sample to control the motor 
    MC_ProgramSpeedRampMotor1(700/6, 3000);
    MC_StartMotor1();
    HAL_DELAY(8000);
    MC_STopMotor1();
    HAL_DELAY(2000);

    MC_ProgramSpeedRampMotor1(-700/6, 3000);
    MC_StartMotor1();
    HAL_DELAY(8000);
    MC_STopMotor1();
    HAL_DELAY(2000);

In the provided code, there is a delay after stopping the motor before starting it again in the opposite direction. The goal is to switch between the two directions immediately without any delay.

Currently, removing the delay of 2000ms prevents the motor from switching its direction. However, it is desired to achieve a seamless transition between directions without any delay.

## Proposed Solution
To address this, the solution involves utilizing the position control of the MC_API with the following code principle:

    float x = 0;
    while (1)
    {
        MC_StartMotor1();
        x = x + 0.175;
        MC_ProgramPositionCommandMotor1(x, 0);
    }

In this code example, the variable 'x' represents the desired angle to direct the motor, while the second variable (set to 0 in this case) denotes the time set to reach the desired position. The motor keeps moving by incrementing 'x' by 0.175 at each cycle of the loop. By incorporating this code and building the program, the motor should change its direction smoothly.

Unfortunately, a new issue has been encountered where the motor does not run as expected when implementing the proposed solution. We are still investigating the cause of this issue and working towards finding a resolution.

## First solution
We are pleased to announce that a solution has been identified to run the motor seamlessly. This solution involves modifying the MC API code to better suit our specific requirements. You can find the working solution in the directory `software\motor_control_test\mitoot_encoder\PositionControl\`.

## Second solution
In our ongoing efforts to optimize motor control and resolve issues with the motor's behavior, we have implemented a second solution involving the fabrication of an enhanced motor axis. This improved axis design addresses encoder fixation issues and aims to enable precise torque and motor control. The modifications ensure that the API functions work seamlessly and without any problems. With the improved axis and encoder fixation, we can now implement torque control effectively using the API and without modifying it.


## Ongoing Issue: Compatibility Between Fabricated Axis and Pendulum

As we continue our efforts to refine the motor control system and integrate it with the pendulum component, a new issue has arisen. The current challenge stems from the compatibility between the previously fabricated motor axis and the pendulum.

### Issue Description

The issue at hand revolves around the size and design of the fabricated motor axis. While the axis is suitable for providing accurate encoder fixation and enabling precise torque control, it appears to be too large or incompatible with the pendulum component. As a result, the pendulum cannot be securely affixed to the motor axis, which hinders the successful integration of these two crucial parts.

### Proposed Solution

To address this compatibility issue, we are planning to design and print a new pendulum component that is specifically tailored to work seamlessly with the motor axis. This new pendulum will ensure a secure and precise connection with the motor, allowing for the effective operation of the entire system.

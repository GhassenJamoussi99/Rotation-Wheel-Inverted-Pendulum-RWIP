# Rotation Wheel Inverted Pendulum - PID Regulator

The `pid_regulator.h` (under '/references') file contains the implementation of a PID regulator component used in the control of a rotation wheel inverted pendulum. This readme file provides a detailed explanation of the components and how they can be used for stabilization and swing-up algorithms.

## Components

### PID_Handle

The `PID_Handle` structure represents the handle of a PID component and stores the parameters required for proportional, integral, and derivative regulation computation. It contains the following members:

- `hDefKpGain`: Default proportional gain (`Kp`) value.
- `hDefKiGain`: Default integral gain (`Ki`) value.
- `hKpGain`: Proportional gain value used by the PID component.
- `hKiGain`: Integral gain value used by the PID component.
- `wIntegralTerm`: Integral term value.
- `wUpperIntegralLimit`: Upper limit used to saturate the integral term.
- `wLowerIntegralLimit`: Lower limit used to saturate the integral term.
- `hUpperOutputLimit`: Upper limit used to saturate the PI output.
- `hLowerOutputLimit`: Lower limit used to saturate the PI output.
- `hKpDivisor`: Divisor for the proportional gain to obtain fractional values.
- `hKiDivisor`: Divisor for the integral gain to obtain fractional values.
- `hKpDivisorPOW2`: Proportional gain divisor expressed as a power of 2.
- `hKiDivisorPOW2`: Integral gain divisor expressed as a power of 2.
- `hDefKdGain`: Default derivative gain (`Kd`) value.
- `hKdGain`: Derivative gain value used by the PID component.
- `hKdDivisor`: Divisor for the derivative gain to obtain fractional values.
- `hKdDivisorPOW2`: Derivative gain divisor expressed as a power of 2.
- `wPrevProcessVarError`: Previous process variable error used by the derivative part of the PID component.

### Functions

The `pid_regulator.h` file provides several functions to initialize and manipulate the PID regulator:

- `void PID_HandleInit(PID_Handle_t *pHandle)`: Initializes the PID handle with default values.
- `void PID_SetKP(PID_Handle_t *pHandle, int16_t hKpGain)`: Updates the proportional gain (`Kp`) value.
- `void PID_SetKI(PID_Handle_t *pHandle, int16_t hKiGain)`: Updates the integral gain (`Ki`) value.
- `int16_t PID_GetKP(PID_Handle_t *pHandle)`: Returns the current proportional gain (`Kp`) value.
- `int16_t PID_GetKI(PID_Handle_t *pHandle)`: Returns the current integral gain (`Ki`) value.
- `int16_t PID_GetDefaultKP(PID_Handle_t *pHandle)`: Returns the default proportional gain (`Kp`) value.
- `int16_t PID_GetDefaultKI(PID_Handle_t *pHandle)`: Returns the default integral gain (`Ki`) value.
- `void PID_SetIntegralTerm(PID_Handle_t *pHandle, int32_t wIntegralTermValue)`: Sets a new value for the integral term.
- `uint16_t PID_GetKPDivisor(PID_Handle_t *pHandle)`: Returns the proportional gain divisor.
- `void PID_SetKPDivisorPOW2(PID_Handle_t *pHandle, uint16_t hKpDivisorPOW2)`: Updates the proportional gain divisor expressed as a power of 2.
- `uint16_t PID_GetKIDivisor(PID_Handle_t *pHandle)`: Returns the integral gain divisor.
- `void PID_SetKIDivisorPOW2(PID_Handle_t *pHandle, uint16_t hKiDivisorPOW2)`: Updates the integral gain divisor expressed as a power of 2.
- `void PID_SetLowerIntegralTermLimit(PID_Handle_t *pHandle, int32_t wLowerLimit)`: Sets a new value for the lower integral term limit.
- `void PID_SetUpperIntegralTermLimit(PID_Handle_t *pHandle, int32_t wUpperLimit)`: Sets a new value for the upper integral term limit.
- `void PID_SetLowerOutputLimit(PID_Handle_t *pHandle, int16_t hLowerLimit)`: Sets a new value for the lower output limit.
- `void PID_SetUpperOutputLimit(PID_Handle_t *pHandle, int16_t hUpperLimit)`: Sets a new value for the upper output limit.
- `void PID_SetPrevError(PID_Handle_t *pHandle, int32_t wPrevProcessVarError)`: Sets a new value for the previous process variable error used in the derivative term.
- `void PID_SetKD(PID_Handle_t *pHandle, int16_t hKdGain)`: Updates the derivative gain (`Kd`) value.
- `int16_t PID_GetKD(PID_Handle_t *pHandle)`: Returns the current derivative gain (`Kd`) value.
- `uint16_t PID_GetKDDivisor(PID_Handle_t *pHandle)`: Returns the derivative gain divisor.
- `void PID_SetKDDivisorPOW2(PID_Handle_t *pHandle, uint16_t hKdDivisorPOW2)`: Updates the derivative gain divisor expressed as a power of 2.
- `int16_t PI_Controller(PID_Handle_t *pHandle, int32_t wProcessVarError)`: Computes the output of a PI regulator (proportional + integral terms).
- `int16_t PID_Controller(PID_Handle_t *pHandle, int32_t wProcessVarError)`: Computes the output of a PID regulator (proportional + integral + derivative terms).

## Stabilization Algorithm

To stabilize the rotation wheel inverted pendulum, we can use the PID regulator with the following configuration:

1. Initialize the PID handle using `PID_HandleInit()` function.
2. Set the desired gains for the proportional (`Kp`) and integral (`Ki`) terms using `PID_SetKP()` and `PID_SetKI()` functions, respectively.
3. Set the integral term limits using `PID_SetLowerIntegralTermLimit()` and `PID_SetUpperIntegralTermLimit()` functions.
4. Set the output limits using `PID_SetLowerOutputLimit()` and `PID_SetUpperOutputLimit()` functions.
5. Optionally, set the derivative gain (`Kd`) using `PID_SetKD()` function.
6. Perform the stabilization algorithm in a control loop:
   - Measure the current angle of the pendulum.
   - Compute the error between the desired angle range (180 to 210 degrees) and the measured angle.
   - Pass the error to the PID regulator using `PID_Controller()` function to calculate the control output.
   - Apply the control output to the motor or actuator responsible for stabilizing the pendulum.
   - Repeat the control loop at regular intervals.

The gains and limits needs to be adjusted as necessary to achieve stable and accurate stabilization of the pendulum. The proportional gain determines the strength of the corrective action based on the error, while the integral gain eliminates steady-state errors. The derivative gain can be used to introduce damping and improve stability.

## Swing-Up Algorithm

The swing-up algorithm is used to bring the pendulum from the idle state (0 degrees) to the desired angle range of 180 to 210 degrees or -180 to -150 degrees. The algorithm does not require a regulation mechanism but relies on applying torque in the opposite direction of the pendulum's velocity.

### Algorithm Overview

The swing-up algorithm follows a simple approach to swing the pendulum to the desired angle range. It consists of the following steps:

1. Measure the current angle and velocity of the pendulum.
2. Check if the pendulum is already in the desired angle range. If so, no action is needed, and the algorithm can terminate.
3. Determine the target torque based on the sign of the pendulum's velocity.
4. Apply the target torque in the opposite direction of the pendulum's velocity to swing the pendulum.
5. Repeat steps 1-4 until the pendulum reaches the desired angle range.

### Implementation Example

An example implementation of the swing-up algorithm in C:

```c
// Constants
#define DESIRED_ANGLE_RANGE_MIN 180
#define DESIRED_ANGLE_RANGE_MAX 210
#define IDLE_STATE_ANGLE 0

// Global Variables
double motorTorqueLimit = 1000.0f; // Example motor torque limit
double factor = 0.4f;

// Swing-Up Algorithm Function
void computeSwingUp(double currentAngle, double currentVelocity)
{
    // Determine the target torque based on the sign of the pendulum's velocity
    double targetTorque = -_sign(currentVelocity) * motorTorqueLimit * factor;

    // Apply the target torque to the motor or actuator to swing the pendulum
    // ...

    // Repeat the control loop until the pendulum reaches the desired angle range
    while (abs(currentAngle) < DESIRED_ANGLE_RANGE_MIN || abs(currentAngle) > DESIRED_ANGLE_RANGE_MAX)
    {
        // Recalculate the target torque based on the updated velocity
        targetTorque = -_sign(currentVelocity) * motorTorqueLimit * factor;

        // Apply the updated target torque to the motor
        // ...
    }
}
```
## References
`references/pid_regulator.c`

`references/pid_regulator.h`


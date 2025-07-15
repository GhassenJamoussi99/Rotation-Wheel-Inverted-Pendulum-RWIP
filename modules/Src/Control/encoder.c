#include <stdio.h>
#include <math.h>

#include "Control/encoder.h"
#include "trajectory_ctrl.h"
#include "mc_config.h"

extern Encoder encoder;

/**
 * @brief Get the mechanical speed from the encoder handle.
 * @param pHandle Pointer to the encoder handle.
 * @return Mechanical speed in RPM.
 */
float getMecSpeed(ENCODER_Handle_t *pHandle)
{
    return ((float)pHandle->_Super.hAvrMecSpeedUnit * 60.0f) / 10.0f;
}

/**
 * @brief Get the pendulum angle from the encoder handle.
 * @param pHandle Pointer to the encoder handle.
 * @return Pendulum angle in degrees, normalized to [0, 360).
 */
float getPendulumAngle(ENCODER_Handle_t *pHandle)
{
    float currentPositionRad = (float)(pHandle->_Super.wMecAngle) / RADTOS16;
    float angle = currentPositionRad * 180.0f / (float)M_PI;
    float fangle = fmodf(angle, 360.0f);
    if (fangle < 0.0f) fangle += 360.0f;
    return fangle;
}

/**
 * @brief Get the legacy pendulum angle from the encoder handle.
 * @param pHandle Pointer to the encoder handle.
 * @return Legacy pendulum angle in degrees.
 */
float getLegacyPendulumAngle(ENCODER_Handle_t *pHandle)
{
    float currentPositionRad = (float)(pHandle->_Super.wMecAngle) / RADTOS16;
    return currentPositionRad * 180.0f / (float)M_PI;
}

/**
 * @brief Calculate the pendulum velocity.
 * @return Pendulum velocity (rad/s).
 */
float calculatePendulumVelocity(void) {
    static float last_angle = 0.0f;
    static float pen_velocity = 0.0f;
    const int delay_ms = 20; // ms
    if (HAL_GetTick() % delay_ms == 0) {
        float angle_rad = (encoder.pendulum_angle * (float)M_PI) / 180.0f;
        pen_velocity = (angle_rad - last_angle) / (delay_ms * 1e-3f);
        printf("angle_rad = %f\r\n", encoder.pendulum_angle);
        last_angle = angle_rad;
    }
    return pen_velocity;
}

/**
 * @brief Calculate the pendulum acceleration.
 * @return Pendulum acceleration (rad/s^2).
 */
float calculatePendulumAcceleration(void) {
    static float last_accel = 0.0f;
    static float pen_accel = 0.0f;
    const int delay_ms = 20; // ms
    if (HAL_GetTick() % delay_ms == 0) {
        pen_accel = (encoder.pendulum_velocity - last_accel) / (delay_ms * 1e-3f);
        printf("accel = %f\r\n", pen_accel);
        last_accel = encoder.pendulum_velocity;
    }
    return pen_accel;
}



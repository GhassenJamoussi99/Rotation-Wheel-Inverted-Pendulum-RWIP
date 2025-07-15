#pragma once

#include "mc_interface.h"
#include "encoder_speed_pos_fdbk.h"

/**
 * @brief Structure representing the encoder and its associated operations.
 */
typedef struct {
    volatile float pendulum_angle;              /**< Current pendulum angle in degrees. */
    volatile float pendulum_acceleration;       /**< Current pendulum acceleration. */
    volatile float motor_speed;                 /**< Current motor speed. */
    volatile float pendulum_velocity;           /**< Current pendulum velocity. */
    volatile float legacy_pendulum_angle;       /**< Legacy pendulum angle (for backward compatibility). */

    /**
     * @brief Calculates the pendulum velocity.
     * @return Pendulum velocity.
     */
    float (*calculatePendulumVelocity)(void);

    /**
     * @brief Calculates the pendulum acceleration.
     * @return Pendulum acceleration.
     */
    float (*calculatePendulumAcceleration)(void);

    /**
     * @brief Gets the mechanical speed from the encoder handle.
     * @param pHandle Pointer to the encoder handle.
     * @return Mechanical speed.
     */
    float (*getMecSpeed)(ENCODER_Handle_t *pHandle);

    /**
     * @brief Gets the pendulum angle from the encoder handle.
     * @param pHandle Pointer to the encoder handle.
     * @return Pendulum angle.
     */
    volatile float (*getPendulumAngle)(ENCODER_Handle_t *pHandle);

    /**
     * @brief Gets the legacy pendulum angle from the encoder handle.
     * @param pHandle Pointer to the encoder handle.
     * @return Legacy pendulum angle.
     */
    volatile float (*getLegacyPendulumAngle)(ENCODER_Handle_t *pHandle);

} Encoder;

// Global encoder ticks (if needed elsewhere)
extern int32_t m_ticks;




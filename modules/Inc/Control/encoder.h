#pragma once

#include "mc_interface.h"
#include "encoder_speed_pos_fdbk.h"

extern int32_t m_ticks;
//extern volatile float last_angle;
//extern float g_pendulum_velocity;

typedef struct {
	volatile float pendulum_angle;
	volatile float pendulum_acceleration;
	volatile float motor_speed;
	volatile float pendulum_velocity;
	volatile float legacy_pendulum_angle;
	float (*calculatePendulumVelocity)();
	float (*calculatePendulumAcceleration)();
	float (*getMecSpeed)(ENCODER_Handle_t *pHandle);
	volatile float (*getPendulumAngle)(ENCODER_Handle_t *pHandle);
	volatile float (*getLegacyPendulumAngle)(ENCODER_Handle_t *pHandle);

} Encoder;




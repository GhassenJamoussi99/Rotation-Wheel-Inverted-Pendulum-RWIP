#ifndef APPLICATION_USER_CONTROL_ENCODER_H_
#define APPLICATION_USER_CONTROL_ENCODER_H_

#include "mc_interface.h"

typedef struct {
	float pendulum_speed;
	float pendulum_angle;
	float motor_speed;
	float (*getMecSpeed)(MCI_Handle_t *pHandle);
	float (*getAngle)(MCI_Handle_t *pHandle);
} Encoder;

#endif /* APPLICATION_USER_CONTROL_ENCODER_H_ */



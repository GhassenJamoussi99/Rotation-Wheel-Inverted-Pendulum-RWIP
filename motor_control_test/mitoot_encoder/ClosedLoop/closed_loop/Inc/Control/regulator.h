#ifndef APPLICATION_USER_CONTROL_REGULATOR_H_
#define APPLICATION_USER_CONTROL_REGULATOR_H_

#include "pid_regulator.h"

#define DESIRED_ANGLE_RANGE_MIN 180
#define DESIRED_ANGLE_RANGE_MAX 210
#define IDLE_STATE_ANGLE 0

extern PID_Handle_t pid_regulator;
extern float motorTorqueLimit;

typedef struct {
	void (*computeStabilization)(float currentAngle);
	void (*computeSwingUp)(float currentAngle);
} Regulator;

#endif /* APPLICATION_USER_CONTROL_REGULATOR_H_ */



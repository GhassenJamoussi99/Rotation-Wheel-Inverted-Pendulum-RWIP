#ifndef APPLICATION_USER_CONTROL_REGULATOR_H_
#define APPLICATION_USER_CONTROL_REGULATOR_H_

#include "pid_regulator.h"
#include "Control/encoder.h"

#define POS_SWINGUP_ANGLE 120
#define NEG_SWINGUP_ANGLE 240
//#define NEUTRAL_ANGLE 180.5

extern PID_Handle_t pid_regulator;
extern volatile Encoder encoder;

extern bool stop_algo1;
extern bool stop_algo2;
extern bool stop_both_algos;

extern float neutral_angle;
extern volatile float controlSignalRPM;
extern int level;
extern float Kr[3];
extern int swing_level;

typedef struct {
	void (*computeStabilization)();
	void (*computeSwingUp)();
} Regulator;

#endif /* APPLICATION_USER_CONTROL_REGULATOR_H_ */



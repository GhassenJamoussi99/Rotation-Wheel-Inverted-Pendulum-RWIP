#include <stdio.h>
#include <math.h>

#include "Control/encoder.h"
#include "trajectory_ctrl.h"
#include "mc_config.h"

extern Encoder encoder;

float getMecSpeed(ENCODER_Handle_t *pHandle)
{
    return ((float)pHandle->_Super.hAvrMecSpeedUnit * 60) / 10;
}

/* Note:    
        Encoder needs to be first aligned to run this function.
        Also before running the function make sure to init the mechanical angle to
        ENCODER_M2._Super.wMecAngle = 0;
        ENC_Init and ENC_Clear of the second init encoder needs to be also considered

        Since the API needs to be generated, it is important to note all of the important 
        functions/features that needs to be added for the second encoder in order to work correctly:

        These followings points needs to be added to the Motor Control API:
        
        This needs to be added to mc_config.c:
        ENCODER_Handle_t ENCODER_M2 =
        {
        ._Super = {
            .bElToMecRatio                     =	POLE_PAIR_NUM,
            .hMaxReliableMecSpeedUnit          =	(uint16_t)(1.15*MAX_APPLICATION_SPEED_UNIT),
            .hMinReliableMecSpeedUnit          =	(uint16_t)(MIN_APPLICATION_SPEED_UNIT),
            .bMaximumSpeedErrorsNumber         =	M1_SS_MEAS_ERRORS_BEFORE_FAULTS,
            .hMaxReliableMecAccelUnitP         =	65535,
            .hMeasurementFrequency             =	TF_REGULATION_RATE_SCALED,
            .DPPConvFactor                     =  DPP_CONV_FACTOR,
        },
        .PulseNumber           =	M2_ENCODER_PPR*4,
        .SpeedSamplingFreqHz   =	MEDIUM_FREQUENCY_TASK_RATE,
        .SpeedBufferSize       =	ENC_AVERAGING_FIFO_DEPTH,
        .TIMx                  =	TIM3,
        .ICx_Filter            =  M1_ENC_IC_FILTER,
        };

        inside mc_tasks.c specifically under __weak uint8_t TSK_HighFrequencyTask(void):
        (void)ENC_CalcAngle(&ENCODER_M2); 

        
        Under pmsm_motor_parameters.h:
        #define M2_ENCODER_PPR             2048  // Number of pulses per revolution 

        Under parameters_conversion.h:
        #define M2_PULSE_NBR ( (4 * (M2_ENCODER_PPR)) - 1 )

*/
float getPendulumAngle(ENCODER_Handle_t *pHandle)
{
    float currentPositionRad = (float)(pHandle->_Super.wMecAngle) / RADTOS16;

    float angle = currentPositionRad * 180 / M_PI;

    float fangle = fmod(angle, 360.0); 
    if (fangle < 0 ) fangle+=360;
    return fangle;
}

float getLegacyPendulumAngle(ENCODER_Handle_t *pHandle)
{
    float currentPositionRad = (float)(pHandle->_Super.wMecAngle) / RADTOS16;
    return currentPositionRad * 180 / M_PI;
}

float calculatePendulumVelocity(){
	static float last_angle = 0.0f;
	static float pen_velocity = 0.0f;

	//Runs every 20ms
	int delay_ms = 20; //ms
	if (HAL_GetTick() % delay_ms == 0) {
		volatile float angle_rad =  (encoder.pendulum_angle * M_PI) / 180;
		pen_velocity =  (angle_rad - last_angle)/(delay_ms*1e-3);
        printf("angle_rad = %f\r\n",encoder.pendulum_angle);
        last_angle = angle_rad;
    }

	return pen_velocity;
}

float calculatePendulumAcceleration(){
	static float last_accel = 0.0f;
    static float pen_accel = 0.0f;

	int delay_ms = 20; //ms
	if (HAL_GetTick() % delay_ms == 0) {
		pen_accel =  (encoder.pendulum_velocity - last_accel)/(delay_ms*1e-3);
        printf("accel = %f\r\n",pen_accel);
        last_accel = encoder.pendulum_velocity;
    }

	return pen_accel;
}

// Deprecated
// float getAngle(MCI_Handle_t *pHandle)
// {
//     pHandle->pFOCVars->bDriveInput = INTERNAL;
//     float currentPositionRad = (float)(SPD_GetMecAngle(STC_GetSpeedSensor(pHandle->pSTC))) / RADTOS16;
//     pHandle->LastModalitySetByUser = STC_TORQUE_MODE;
//     return currentPositionRad * 180 / M_PI;
// }



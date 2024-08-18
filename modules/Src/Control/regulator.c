#include "Control/regulator.h"
#include "mc_config.h"
#include "drive_parameters.h"

#include <math.h>
#include <stdio.h>

#define _sign(a) ( ( (a) < 0 )  ?  -1   : ( (a) > 0 ) )

void computeStabilization_test0(){
	 // Implementation of stabilization control
	printf("Computing stabilize algorithm...\r\n");
	if (encoder.pendulum_angle >= POS_SWINGUP_ANGLE  && encoder.pendulum_angle <  neutral_angle)
	{
		MC_ProgramSpeedRampMotor1(-1500/6,0);
	} else if ( encoder.pendulum_angle <= NEG_SWINGUP_ANGLE && encoder.pendulum_angle > neutral_angle)
	{
		MC_ProgramSpeedRampMotor1(1500/6,0);
	}
}

void computeStabilization_test1(){
	 // Implementation of stabilization control
	printf("Computing stabilize algorithm...\r\n");

	float mapped_angle = encoder.pendulum_angle - 180;

	float K1 = 350;
	controlSignalRPM = K1*mapped_angle;
    MC_ProgramSpeedRampMotor1((int)controlSignalRPM/6, 0);
}

void computeStabilization_test2(){
	 // Implementation of stabilization control
	float mapped_angle = encoder.pendulum_angle - neutral_angle;

	controlSignalRPM = Kr[0]*mapped_angle + Kr[1]*encoder.pendulum_velocity+Kr[2]*encoder.motor_speed;

	// limit the control signal set to the motor
	float prozent = 0.3;
	if(fabs(controlSignalRPM) > MAX_APPLICATION_SPEED_RPM*prozent) controlSignalRPM = _sign(controlSignalRPM)*MAX_APPLICATION_SPEED_RPM*prozent;

	//Make sure that encoder is in the stabilize angle (due to timing issue)
	if (encoder.pendulum_angle >= POS_SWINGUP_ANGLE  && encoder.pendulum_angle <=  neutral_angle)
	{
	    MC_ProgramSpeedRampMotor1((int)controlSignalRPM/6, 0);
	} else if ( encoder.pendulum_angle <= NEG_SWINGUP_ANGLE && encoder.pendulum_angle >= neutral_angle)
	{
	    MC_ProgramSpeedRampMotor1((int)(controlSignalRPM)/6, 0);
	}
}

void computeStabilization() {
	computeStabilization_test2();
}

void startSwingUp()
{
   printf("Start Swing up - Level 0\r\n");

  if (encoder.pendulum_angle <= 360 && encoder.pendulum_angle > NEG_SWINGUP_ANGLE)
  {
    MC_ProgramSpeedRampMotor1(-1000 / 6, 0);
    HAL_Delay(165);
  }
  else if (encoder.pendulum_angle < 360 && encoder.pendulum_angle < POS_SWINGUP_ANGLE)
  {
    MC_ProgramSpeedRampMotor1(1000 / 6, 0);
    HAL_Delay(165);
  }
}

void startSwingUp3()
{
  if (encoder.pendulum_angle <= 360 && encoder.pendulum_angle > NEG_SWINGUP_ANGLE)
  {
	//printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    //printf("Right angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(-1000 / 6, 0);
    HAL_Delay(35);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(35);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(34);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(34);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
	///printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
  }
  else if (encoder.pendulum_angle < 360 && encoder.pendulum_angle < POS_SWINGUP_ANGLE)
  {
    //printf("Left angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(1000 / 6, 0);
    HAL_Delay(35);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(35);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(34);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    HAL_Delay(34);
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
  }
}

void finishSwingUp1()
{
  printf("Swing up - Level 1 \r\n");
  if (encoder.pendulum_angle <= 360 && encoder.pendulum_angle > NEG_SWINGUP_ANGLE)
  {
    //printf("Right angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(-2000 / 6, 0);
    HAL_Delay(200);
  }
  else if (encoder.pendulum_angle < 360 && encoder.pendulum_angle < POS_SWINGUP_ANGLE)
  {
    //printf("Left angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(2000 / 6, 0);
    HAL_Delay(200);
  }
}
// 2200 -> 390

// 2800 ->
void finishSwingUp2()
{
printf("Swing up - Level 2 \r\n");
	  if (encoder.pendulum_angle <= 360 && encoder.pendulum_angle > NEG_SWINGUP_ANGLE)
  {
    //printf("Right angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(-1700 / 6, 0);
    HAL_Delay(200);
  }
else if (encoder.pendulum_angle < 360 && encoder.pendulum_angle < POS_SWINGUP_ANGLE)
  {
    //printf("Left angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(1700 / 6, 0);
    //MC_ProgramSpeedRampMotor1(0/ 6, 0);
    HAL_Delay(200);
  }
}

void finishSwingUp3()
{
printf("Swing up - Level 2 \r\n");
	  if (encoder.pendulum_angle <= 360 && encoder.pendulum_angle > NEG_SWINGUP_ANGLE)
  {
    //printf("Right angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(-3200 / 6, 0);
    HAL_Delay(400);
  }
else if (encoder.pendulum_angle < 360 && encoder.pendulum_angle < POS_SWINGUP_ANGLE)
  {
    //printf("Left angle = %.2f\r\n", encoder.pendulum_angle);
    MC_ProgramSpeedRampMotor1(3200 / 6, 0);
    //MC_ProgramSpeedRampMotor1(0/ 6, 0);
    HAL_Delay(400);
  }
}

void computeSwingUp_test1() {
    printf("Computing swing up algorithm...\r\n");
	float mapped_angle = encoder.getLegacyPendulumAngle(&ENCODER_M2);
	//float factor = 0.4;
	int k = 35;

	if (stop_algo1 == false && stop_algo2 == false)
	{
	    controlSignalRPM = 0;
		startSwingUp();
	}
	else if (stop_algo1 == true && stop_algo2 == false)
	{
	    controlSignalRPM = 1;
		finishSwingUp1();
	}
	else if (stop_algo2 == true && stop_both_algos == false)
	{
	    controlSignalRPM = 2;
	    finishSwingUp1();
	}
	else if (stop_both_algos == true)
	{
	    controlSignalRPM = 3;
	    finishSwingUp2();
	}

}


void computeSwingUp_test2() {
    printf("Computing swing up algorithm...\r\n");
	float mapped_angle = encoder.getLegacyPendulumAngle(&ENCODER_M2);
	//float factor = 0.4;
	int k = 35;

	if (stop_algo1 == false && stop_algo2 == false)
	{
	    swing_level = 0;
		startSwingUp();
	}
	else if (stop_algo1 == true && stop_algo2 == false)
	{
	    swing_level = 1;
		finishSwingUp1();
	}
	else if (stop_algo2 == true)
	{
		swing_level = 2;
		finishSwingUp2();
	}


}

void computeSwingUp_test22() {
    printf("Computing swing up algorithm...\r\n");
	float mapped_angle = encoder.getLegacyPendulumAngle(&ENCODER_M2);
	//float factor = 0.4;
	int k = 35;

	if (stop_algo1 == false && stop_algo2 == false)
	{
	    swing_level = 0;
		startSwingUp();
	}
	else if (stop_algo1 == true && stop_algo2 == false)
	{
	    swing_level = 1;
		finishSwingUp1();
	}
	else if (stop_algo2 == true)
	{
		swing_level = 2;
		controlSignalRPM = -_sign(encoder.pendulum_velocity)*MAX_APPLICATION_SPEED_RPM*0.5;
		MC_ProgramSpeedRampMotor1((int)controlSignalRPM/6, 0);
	}
}

void computeSwingUp_test3() {
    printf("Computing swing up algorithm...\r\n");
	controlSignalRPM = -_sign(encoder.pendulum_velocity)*MAX_APPLICATION_SPEED_RPM*0.15;
	MC_ProgramSpeedRampMotor1((int)controlSignalRPM/6, 0);
}

void computeSwingUp() {
	printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
	startSwingUp();
}


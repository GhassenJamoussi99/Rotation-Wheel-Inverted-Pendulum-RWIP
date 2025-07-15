#include "Control/regulator.h"
#include "mc_config.h"
#include "drive_parameters.h"

#include <math.h>
#include <stdio.h>

#define SIGN(a) (((a) < 0) ? -1 : ((a) > 0))

/**
 * @brief Compute stabilization using test algorithm 0.
 */
static void computeStabilization_test0(void) {
    printf("Computing stabilize algorithm...\r\n");
    if (encoder.pendulum_angle >= POS_SWINGUP_ANGLE && encoder.pendulum_angle < neutral_angle) {
        MC_ProgramSpeedRampMotor1(-1500 / 6, 0);
    } else if (encoder.pendulum_angle <= NEG_SWINGUP_ANGLE && encoder.pendulum_angle > neutral_angle) {
        MC_ProgramSpeedRampMotor1(1500 / 6, 0);
    }
}

/**
 * @brief Compute stabilization using test algorithm 1.
 */
static void computeStabilization_test1(void) {
    printf("Computing stabilize algorithm...\r\n");
    float mapped_angle = encoder.pendulum_angle - 180.0f;
    const float K1 = 350.0f;
    controlSignalRPM = K1 * mapped_angle;
    MC_ProgramSpeedRampMotor1((int)(controlSignalRPM / 6), 0);
}

/**
 * @brief Compute stabilization using test algorithm 2 (default).
 */
static void computeStabilization_test2(void) {
    float mapped_angle = encoder.pendulum_angle - neutral_angle;
    controlSignalRPM = Kr[0] * mapped_angle + Kr[1] * encoder.pendulum_velocity + Kr[2] * encoder.motor_speed;
    const float percent = 0.3f;
    if (fabsf(controlSignalRPM) > MAX_APPLICATION_SPEED_RPM * percent) {
        controlSignalRPM = SIGN(controlSignalRPM) * MAX_APPLICATION_SPEED_RPM * percent;
    }
    if (encoder.pendulum_angle >= POS_SWINGUP_ANGLE && encoder.pendulum_angle <= neutral_angle) {
        MC_ProgramSpeedRampMotor1((int)(controlSignalRPM / 6), 0);
    } else if (encoder.pendulum_angle <= NEG_SWINGUP_ANGLE && encoder.pendulum_angle >= neutral_angle) {
        MC_ProgramSpeedRampMotor1((int)(controlSignalRPM / 6), 0);
    }
}

/**
 * @brief Compute stabilization (default: test2).
 */
void computeStabilization(void) {
    computeStabilization_test2();
}

/**
 * @brief Start the swing-up procedure (level 0).
 */
static void startSwingUp(void) {
    printf("Start Swing up - Level 0\r\n");
    if (encoder.pendulum_angle <= 360.0f && encoder.pendulum_angle > NEG_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(-1000 / 6, 0);
        HAL_Delay(165);
    } else if (encoder.pendulum_angle < 360.0f && encoder.pendulum_angle < POS_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(1000 / 6, 0);
        HAL_Delay(165);
    }
}

/**
 * @brief Finish the swing-up procedure (level 1).
 */
static void finishSwingUp1(void) {
    printf("Swing up - Level 1 \r\n");
    if (encoder.pendulum_angle <= 360.0f && encoder.pendulum_angle > NEG_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(-2000 / 6, 0);
        HAL_Delay(200);
    } else if (encoder.pendulum_angle < 360.0f && encoder.pendulum_angle < POS_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(2000 / 6, 0);
        HAL_Delay(200);
    }
}

/**
 * @brief Finish the swing-up procedure (level 2).
 */
static void finishSwingUp2(void) {
    printf("Swing up - Level 2 \r\n");
    if (encoder.pendulum_angle <= 360.0f && encoder.pendulum_angle > NEG_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(-1700 / 6, 0);
        HAL_Delay(200);
    } else if (encoder.pendulum_angle < 360.0f && encoder.pendulum_angle < POS_SWINGUP_ANGLE) {
        MC_ProgramSpeedRampMotor1(1700 / 6, 0);
        HAL_Delay(200);
    }
}

/**
 * @brief Compute swing-up using test algorithm 1.
 */
static void computeSwingUp_test1(void) {
    printf("Computing swing up algorithm...\r\n");
    if (!stop_algo1 && !stop_algo2) {
        controlSignalRPM = 0;
        startSwingUp();
    } else if (stop_algo1 && !stop_algo2) {
        controlSignalRPM = 1;
        finishSwingUp1();
    } else if (stop_algo2 && !stop_both_algos) {
        controlSignalRPM = 2;
        finishSwingUp1();
    } else if (stop_both_algos) {
        controlSignalRPM = 3;
        finishSwingUp2();
    }
}

/**
 * @brief Compute swing-up (default: startSwingUp).
 */
void computeSwingUp(void) {
    printf("Pendulum angle = %.2f\r\n", encoder.pendulum_angle);
    startSwingUp();
}

// TODO: Add additional swing-up strategies and parameter tuning as needed.


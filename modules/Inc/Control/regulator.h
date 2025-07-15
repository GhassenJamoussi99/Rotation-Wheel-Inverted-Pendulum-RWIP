#pragma once

#include "pid_regulator.h"
#include "Control/encoder.h"

/**
 * @brief Positive swing-up angle threshold (degrees).
 */
#define POS_SWINGUP_ANGLE 120
/**
 * @brief Negative swing-up angle threshold (degrees).
 */
#define NEG_SWINGUP_ANGLE 240

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

/**
 * @brief Structure for regulator operations.
 */
typedef struct {
    /**
     * @brief Compute stabilization control.
     */
    void (*computeStabilization)(void);
    /**
     * @brief Compute swing-up control.
     */
    void (*computeSwingUp)(void);
} Regulator;



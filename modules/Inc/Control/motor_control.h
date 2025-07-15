#pragma once

#include <stdint.h>
#include "mc_interface.h"
#include "Interface/led.h"
#include "Interface/display.h"

extern Led led;
extern Display display;

/**
 * @brief Structure for motor control operations and state.
 */
typedef struct {
    char *fault_code; /**< Current fault code string. */

    /**
     * @brief Get the motor status as a string.
     * @param pHandle Pointer to the motor control interface handle.
     * @return Status string.
     */
    char *(*getMotorStatus)(MCI_Handle_t *pHandle);
} MotorControl;



#pragma once

#include <stdint.h>
#include "mc_interface.h"
#include "Interface/led.h"
#include "Interface/display.h"

extern Led led;
extern Display display;

/**
 * @brief Structure for error handling operations and state.
 */
typedef struct {
    char *fault_code; /**< Current fault code string. */

    /**
     * @brief Get the motor status as a string.
     * @param pHandle Pointer to the motor control interface handle.
     * @return Status string.
     */
    char *(*getMotorStatus)(MCI_Handle_t *pHandle);

    /**
     * @brief Get the current state of the motor.
     * @param pHandle Pointer to the motor control interface handle.
     * @return State as integer.
     */
    int (*getCurrentMotorState)(MCI_Handle_t *pHandle);

    /**
     * @brief Convert a fault code to a string.
     * @param fCode Fault code.
     * @return Fault code as string.
     */
    char *(*faultCodeToString)(uint16_t fCode);

    /**
     * @brief Send an error message to the user interface.
     * @param error Error message string.
     */
    void (*sendToInterface)(const char *error);

} ErrorHandling;



#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Control/error_handling.h"

/**
 * @brief Convert a motor control fault code to a human-readable string.
 * @param fCode Fault code.
 * @return Dynamically allocated string describing the fault. Caller must free.
 */
char *faultCodeToString(uint16_t fCode)
{
    char errorString[50];
    switch (fCode)
    {
        case MC_NO_ERROR:
            snprintf(errorString, sizeof(errorString), "No Error");
            break;
        case MC_DURATION:
            snprintf(errorString, sizeof(errorString), "Error: FOC Rate Too High");
            break;
        case MC_OVER_VOLT:
            snprintf(errorString, sizeof(errorString), "Error: Software Over Voltage");
            break;
        case MC_UNDER_VOLT:
            snprintf(errorString, sizeof(errorString), "Error: Software Under Voltage");
            break;
        case MC_OVER_TEMP:
            snprintf(errorString, sizeof(errorString), "Error: Software Over Temperature");
            break;
        case MC_START_UP:
            snprintf(errorString, sizeof(errorString), "Error: Startup Failed");
            break;
        case MC_SPEED_FDBK:
            snprintf(errorString, sizeof(errorString), "Error: Speed Feedback Error");
            break;
        case MC_BREAK_IN:
            snprintf(errorString, sizeof(errorString), "Error: Emergency Input (Over Current)");
            break;
        case MC_SW_ERROR:
            snprintf(errorString, sizeof(errorString), "Error: Software Error");
            break;
        default:
            snprintf(errorString, sizeof(errorString), "Unknown Error");
            break;
    }
    return strdup(errorString);
}

/**
 * @brief Get the current motor status as a string.
 * @param pHandle Pointer to the motor control interface handle.
 * @return Status string (dynamically allocated, must be freed by caller).
 */
char *getMotorStatus(MCI_Handle_t *pHandle)
{
    return faultCodeToString(MCI_GetCurrentFaults(pHandle));
}

/**
 * @brief Get the current state of the motor control state machine.
 * @param pHandle Pointer to the motor control interface handle.
 * @return State as integer.
 */
int getCurrentMotorState(MCI_Handle_t *pHandle)
{
    return MCI_GetSTMState(pHandle);
}

/**
 * @brief Send an error message to the user interface (display and LEDs).
 * @param error Error message string.
 */
void sendToInterface(const char *error)
{
    if (display.show) {
        display.show((char *)error);
    }
    if (strcmp(error, "No Error") == 0) {
        if (led.indicateNormalOperation) led.indicateNormalOperation();
    } else if (strcmp(error, "Startup") == 0) {
        if (led.indicateWarning) led.indicateWarning();
    } else {
        if (led.indicateError) led.indicateError();
    }
}

// TODO: Add more robust error handling, warning state during startup, encoder alignment handling, and additional diagnostics as needed.

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Control/error_handling.h"

/*
void sendToInterface(char *msg)
{
    //send status to display
    display.show(msg);

    //send status to led 
    if (strcmp(msg, "No Error") == 0) {
        led.indicateNormalOperation();
    } else if (strcmp(msg, "Startup") == 0) {
        led.indicateWarning();
    } else {
        led.indicateError();
    }
    
}
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

//Status of motor
char *getMotorStatus(MCI_Handle_t *pHandle)
{
    return faultCodeToString(MCI_GetCurrentFaults(pHandle));
}

//State machine
int getCurrentMotorState(MCI_Handle_t *pHandle)
{
    return MCI_GetSTMState(pHandle);
}

// int getOccuredFaults(MCI_Handle_t *pHandle){
//     return MCI_GetOccurredFaults(pHandle);
// }


/*
 * TODOs:
 * Set a warning state during the startup and send it to the display and leds.
 * Add encoder alignment handling
 * Add Retrieving the control mode of the motor
 * Add Retrieving speed sensor reliability
 * Add error acknowledgement
 * MC_GetOccurredFaultsMotor1 : Retrieving the latest motor control faults
 * MC_GetCurrentFaultsMotor1  : Retrieving all motor control faults
 * MCI_GetSTMStateMotor1 : Retrieving the state of the motor control state machine
 */

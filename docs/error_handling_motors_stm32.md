# Error Handling with STM32

This README report provides an overview of how error handling works with STM32 microcontrollers in the context of a motor control subsystem. It explains the fault codes associated with the Motor Control subsystem, how to retrieve fault codes using the `MCI_GetCurrentFaults` function, and presents a proposed error handling implementation using a `ErrorHandling` structure and associated functions.

## Fault Codes

The fault codes represent the errors that can occur within the Motor Control subsystem. The following fault codes are defined:

```c
#define MC_NO_ERROR       ((uint16_t)0x0000) /**< @brief No error.*/
#define MC_NO_FAULTS      ((uint16_t)0x0000) /**< @brief No error.*/
#define MC_DURATION       ((uint16_t)0x0001) /**< @brief Error: FOC rate too high.*/
#define MC_OVER_VOLT      ((uint16_t)0x0002) /**< @brief Error: Software over voltage.*/
#define MC_UNDER_VOLT     ((uint16_t)0x0004) /**< @brief Error: Software under voltage.*/
#define MC_OVER_TEMP      ((uint16_t)0x0008) /**< @brief Error: Software over temperature.*/
#define MC_START_UP       ((uint16_t)0x0010) /**< @brief Error: Startup failed.*/
#define MC_SPEED_FDBK     ((uint16_t)0x0020) /**< @brief Error: Speed feedback.*/
#define MC_BREAK_IN       ((uint16_t)0x0040) /**< @brief Error: Emergency input (Over current).*/
#define MC_SW_ERROR       ((uint16_t)0x0080) /**< @brief Software Error.*/
```

These fault codes are used to identify and categorize specific errors that occur during motor control operations.

## Retrieving Fault Codes

To retrieve the current fault codes within the Motor Control subsystem, the function `MCI_GetCurrentFaults` is provided. The function has the following signature:

```c
__weak uint16_t MCI_GetCurrentFaults(MCI_Handle_t *pHandle)
```

The function takes a pointer to an `MCI_Handle_t` structure and returns the current fault codes as a `uint16_t` value.

## Error Handling Implementation

To handle and display errors, a proposed `ErrorHandling` structure is defined. It consists of the following members:

```c
typedef struct {
    char *fault_code;
    char *(*getMotorStatus)(MCI_Handle_t *pHandle);
    char *(*faultCodeToString)(uint16_t fCode);
} ErrorHandling;
```

1. `getMotorStatus` is a function pointer that retrieves the current motor status or fault codes using the `MCI_GetCurrentFaults` function. It takes an `MCI_Handle_t` pointer as a parameter and returns a `char*` representing the motor status or fault codes.

2. `faultCodeToString` is a function pointer that converts a fault code (represented as a `uint16_t`) into a human-readable error string. It takes a fault code as a parameter and returns a `char*` representing the error message.

Here's an example implementation of the `getMotorStatus` and `faultCodeToString` functions:

```c
char *getMotorStatus(MCI_Handle_t *pHandle){
    return faultCodeToString(MCI_GetCurrentFaults(pHandle));
}

char *faultCodeToString(uint16_t fCode) {
    char errorString[50];
    
    switch (fCode) {
        case MC_NO_ERROR:
            snprintf(errorString, sizeof(errorString), "No Error");
            break;


        case MC_DURATION:
            snprintf(errorString, sizeof(errorString), "Error: FOC Rate Too High");
            break;
        // Handle other fault codes
        default:
            snprintf(errorString, sizeof(errorString), "Unknown Error");
            break;
    }

    return strdup(errorString);
}
```

In the main, an instance of the `ErrorHandling` structure can now be created and used to handle and display errors. For example:

```c
ErrorHandling errorHandling;

// Retrieve the motor status or fault codes
char *motorStatus = errorHandling.getMotorStatus(&motorControlHandle);

// Display the motor status or error string on the display
display.showError(errorString);
```

The full implementation is found under `rwip/Src/Control/error_handling.c` and `rwip/Inc/Control/error_handling.h`.

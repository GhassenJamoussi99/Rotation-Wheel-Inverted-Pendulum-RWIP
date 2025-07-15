#include "Interface/led.h"
#include <stdio.h>

/**
 * @brief Indicate an error condition by turning on the red LED and turning off the yellow and green LEDs.
 */
void indicateError(void) {
    printf("Error LED turned on.\n");
    // TODO: Implement hardware-specific GPIO logic
}

/**
 * @brief Indicate a warning condition by turning on the yellow LED and turning off the red and green LEDs.
 */
void indicateWarning(void) {
    printf("Warning LED turned on.\n");
    // TODO: Implement hardware-specific GPIO logic
}

/**
 * @brief Indicate normal operation by turning on the green LED and turning off the red and yellow LEDs.
 */
void indicateNormalOperation(void) {
    printf("Normal operation LED turned on.\n");
    // TODO: Implement hardware-specific GPIO logic
}

/**
 * @brief Turn off all LEDs.
 */
void turnOffAllLeds(void) {
    printf("All LEDs turned off.\n");
    // TODO: Implement hardware-specific GPIO logic
}

/**
 * @brief Turn on the specified LED color.
 * @param color The LED color to turn on (RED, YELLOW, or GREEN).
 */
void turnOnLed(LedColor color) {
    switch (color) {
        case RED:
            indicateError();
            break;
        case YELLOW:
            indicateWarning();
            break;
        case GREEN:
            indicateNormalOperation();
            break;
    }
}
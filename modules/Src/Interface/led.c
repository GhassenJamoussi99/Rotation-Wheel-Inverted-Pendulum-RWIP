#include "Interface/led.h"

/**
 * @brief Indicate an error condition by turning on the red LED and turning off the 
 * yellow and green LEDs.
 * 
 * Note: GPIO pins for the LEDs need to be defined separately.
 */
void indicateError() {
    printf("Error LED turned on.\n");
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);    // Turn on the red LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);  // Turn off the yellow LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);  // Turn off the green LED
}

/**
 * @brief Indicate a warning condition by turning on the yellow LED and turning off the
 * red and green LEDs.
 * 
 * Note: GPIO pins for the LEDs need to be defined separately.
 */
void indicateWarning() {
    printf("Warning LED turned on.\n");
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);  // Turn off the red LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);    // Turn on the yellow LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);  // Turn off the green LED
}

/**
 * @brief Indicate normal operation by turning on the green LED and turning off the red and
 * yellow LEDs.
 * 
 * Note: GPIO pins for the LEDs need to be defined separately.
 */
void indicateNormalOperation() {
    printf("Normal operation LED turned on.\n");
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);  // Turn off the red LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);  // Turn off the yellow LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);    // Turn on the green LED
}

/**
 * @brief Turn off all LEDs by turning off the red, yellow, and green LEDs.
 * 
 * Note: GPIO pins for the LEDs need to be defined separately.
 */
void turnOffAllLeds() {
    printf("All LEDs turned off.\n");
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);  // Turn off the red LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);  // Turn off the yellow LED
    // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);    // Turn on the green LED
}

/**
 * @brief Turn on the specified LED color.
 *
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
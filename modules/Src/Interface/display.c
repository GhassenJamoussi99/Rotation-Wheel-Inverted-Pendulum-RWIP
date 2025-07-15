#include <stdio.h>
#include "Interface/display.h"

/**
 * @brief Show an error or status message on the display (stub implementation).
 * @param error Error or status message string.
 */
void display_show(char *error) {
    printf("Display: %s\n", error);
    // TODO: Implement actual display logic for hardware
}


#pragma once

/**
 * @brief Structure for display interface operations.
 */
typedef struct {
    /**
     * @brief Show an error or status message on the display.
     * @param error Error or status message string.
     */
    void (*show)(char *error);
} Display;



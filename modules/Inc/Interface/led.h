#pragma once

/**
 * @brief Enumeration for LED colors.
 */
typedef enum {
    RED,    /**< Red LED. */
    YELLOW, /**< Yellow LED. */
    GREEN   /**< Green LED. */
} LedColor;

/**
 * @brief Structure for LED interface operations.
 */
typedef struct {
    /**
     * @brief Indicate an error condition (turn on red LED).
     */
    void (*indicateError)(void);
    /**
     * @brief Indicate a warning condition (turn on yellow LED).
     */
    void (*indicateWarning)(void);
    /**
     * @brief Indicate normal operation (turn on green LED).
     */
    void (*indicateNormalOperation)(void);
    /**
     * @brief Turn off all LEDs.
     */
    void (*turnOffAllLeds)(void);
    /**
     * @brief Turn on the specified LED color.
     * @param color The LED color to turn on (RED, YELLOW, or GREEN).
     */
    void (*turnOnLed)(LedColor color);
} Led;

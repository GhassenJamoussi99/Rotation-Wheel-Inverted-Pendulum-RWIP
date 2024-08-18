#ifndef APPLICATION_USER_INTERFACE_LED_H_
#define APPLICATION_USER_INTERFACE_LED_H_

typedef enum {
    RED,
    YELLOW,
    GREEN
} LedColor;

typedef struct {
    void (*indicateError)();
    void (*indicateWarning)();
    void (*indicateNormalOperation)();
    void (*turnOffAllLeds)();
    void (*turnOnLed)(LedColor color);
} Led;

#endif /* APPLICATION_USER_INTERFACE_LED_H_ */

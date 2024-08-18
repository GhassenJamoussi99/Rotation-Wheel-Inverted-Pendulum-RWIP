#ifndef APPLICATION_USER_INTERFACE_DISPLAY_H_
#define APPLICATION_USER_INTERFACE_DISPLAY_H_


typedef struct {
    void *(*show)(char *error);
} Display;

#endif /* APPLICATION_USER_INTERFACE_DISPLAY_H_ */



#ifndef APPLICATION_USER_CONTROL_ERROR_HANDLING_H_
#define APPLICATION_USER_CONTROL_ERROR_HANDLING_H_

#include <stdint.h>
#include "mc_interface.h"
#include "Interface/led.h"
#include "Interface/display.h"

extern Led led;
extern Display display;

typedef struct {
	char *fault_code;
	char *(*getMotorStatus)(MCI_Handle_t *pHandle);

} ErrorHandling;


#endif /* APPLICATION_USER_CONTROL_ERROR_HANDLING_H_ */



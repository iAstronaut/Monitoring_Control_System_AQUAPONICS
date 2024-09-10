#ifndef INC_TASKMOBUS_H_
#define INC_TASKMOBUS_H_

#include "globals.h"

#ifdef __cplusplus
extern "C"
{
#endif

    void sendModbusCommand(const uint8_t command[], size_t length);
    
#ifdef __cplusplus
}
#endif

void sendValue(int index, String state);

#endif /* INC_TASKMOBUS_H_ */

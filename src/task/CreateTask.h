#ifndef INC_CREATETASK_H_
#define INC_CREATETASK_H_

#include <globals.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void TaskLed(void *pvParameters);
    void TaskServer(void *pvParameters);
    void TaskSchedule(void *pvParameters);
    void TaskLoadSchedule(void *pvParameters);

#ifdef __cplusplus
}
#endif

extern AsyncWebServer server;
extern AsyncWebSocket ws;

void CreateTask();
void deleteScheduleById(int id);
void saveSchedulesToFile();

#endif /* INC_CREATETASK_H_ */

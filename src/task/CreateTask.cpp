#include "CreateTask.h"

void CreateTask()
{
    xTaskCreate(TaskLed, "TaskLed", 2048, NULL, 2, NULL);
    xTaskCreate(TaskSchedule, "TaskSchedule", 4096, NULL, 1, NULL);
    xTaskCreate(TaskServer, "TaskServer", 8192, NULL, 1, NULL);
}
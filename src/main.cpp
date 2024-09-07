
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ;
  }
  Wire.begin(11, 12);
  Wire.setClock(250000);
  Serial2.begin(BAUD_RATE_2, SERIAL_8N1, TXD_RELAY, RXD_RELAY);
  Serial.println("Starting...");

  // FreeRTOS tasks
  xTaskCreate(TaskLoadSchedule, "TaskLoadSchedule", 4096, NULL, 1, NULL);
  xTaskCreate(TaskMQTT, "TaskMQTT", 4096, NULL, 1, NULL);
  xTaskCreate(TaskSchedule, "TaskSchedule", 4096, NULL, 1, NULL);
  xTaskCreate(TaskServer, "TaskServer", 8192, NULL, 1, NULL);
  xTaskCreate(TaskTemperatureHumidity, "TaskTemperatureHumidity", 4096, NULL, 1, NULL);
  xTaskCreate(TaskWifi, "TaskWifi", 4096, NULL, 1, NULL);
}

void loop()
{
}

#include "globals.h"

void setup()
{
  Serial.begin(115200);
  Serial2.begin(BAUD_RATE_2, SERIAL_8N1, TXD_RELAY, RXD_RELAY);
  Serial.println("Starting...");

  wifi_init();
  mqtt_init();
  xTaskCreate(TaskGps, "TaskGps", 4096, NULL, 1, NULL);
  xTaskCreate(TaskLoadSchedule, "TaskLoadSchedule", 4096, NULL, 1, NULL);
  xTaskCreate(TaskTemperatureHumidity, "TaskTemperatureHumidity", 4096, NULL, 1, NULL);
  CreateTask();
}

void loop()
{
  while (ss.available() > 0)
    gps.encode(ss.read());
}

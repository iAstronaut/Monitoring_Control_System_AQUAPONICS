#include "TaskWifi.h"

volatile bool wifiConnected = false;

void TaskWifi(void *pvParameters)
{
    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(delay_wifi / portTICK_PERIOD_MS);
        Serial.println("Connecting to WiFi..");
    }
    wifiConnected = true;
    vTaskDelete(NULL);
}
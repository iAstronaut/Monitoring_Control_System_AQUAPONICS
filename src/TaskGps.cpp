#include "TaskGps.h"

TinyGPSPlus gps;
SoftwareSerial ss(TXD_GPS, RXD_GPS);

float X = 0;
float Y = 0;

void TaskGps(void *pvParameters)
{

    ss.begin(9600);
    while (true)
    {
        if (!wifiConnected || !client.connected())
        {
            vTaskDelay(delay_connect / portTICK_PERIOD_MS);
            continue;
        }
        while (ss.available() > 0)
        {
            gps.encode(ss.read());
            if (gps.location.isUpdated())
            {
                X = gps.location.lat();
                Y = gps.location.lng();
            }
        }
        String data = "{\"latitude\":" + String(X, 7) + ",\"longitude\":" + String(Y, 7) + "}";
        publishData("location", (String(X, 7) + "-" + String(Y, 7)));
        if (ws.count() > 0)
        {
            ws.textAll(data);
        }
        vTaskDelay(delay_gps / portTICK_PERIOD_MS);
    }
}
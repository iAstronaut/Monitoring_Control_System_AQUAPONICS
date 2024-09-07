#include "TaskTemperatureHumidity.h"

DHT20 dht20;

void TaskTemperatureHumidity(void *pvParameters)
{
    Wire.begin(11, 12);
    Wire.setClock(250000);

    if (dht20.begin() != 0)
    {
        Serial.println("Failed to initialize DHT20 sensor");
        vTaskDelete(NULL); // Dừng task nếu cảm biến không khởi động được
    }
    while (1)
    {
        if (!wifiConnected || !client.connected())
        {
            vTaskDelay(delay_connect / portTICK_PERIOD_MS);
            continue;
        }

        int status = dht20.read();
        if (status != 0)
        {
            Serial.print("Error: ");
            Serial.println(status);
        }
        else
        {
            float temperature = dht20.getTemperature();
            float humidity = dht20.getHumidity();
            String temperatureStr = String(temperature, 2);
            String humidityStr = String(humidity, 2);
            publishData("temperature", temperatureStr);
            publishData("humidity", humidityStr);
            if (ws.count() > 0)
            {
                String data = "{\"temperature\":" + temperatureStr + ",\"humidity\":" + humidityStr + "}";
                ws.textAll(data);
            }
        }
        vTaskDelay(delay_temp / portTICK_PERIOD_MS);
    }
}

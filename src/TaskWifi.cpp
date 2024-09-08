#include "TaskWifi.h"

Adafruit_NeoPixel led_rgb(NUM_PIXELS, LED, NEO_GRB + NEO_KHZ800);

void TaskWifi(void *pvParameters)
{
    led_rgb.begin();
    led_rgb.show();
    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(delay_wifi / portTICK_PERIOD_MS);
        Serial.println("Connecting to WiFi");
    }
    led_rgb.setPixelColor(0, led_rgb.Color(0, 255, 0));
    led_rgb.show();
    vTaskDelete(NULL);
}
#include "TaskServer.h"

AsyncWebServer server(httpPort);
AsyncWebSocket ws("/ws");

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    if (type == WS_EVT_CONNECT)
    {
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    }
    else if (type == WS_EVT_DISCONNECT)
    {
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
    }
    else if (type == WS_EVT_DATA)
    {
        AwsFrameInfo *info = (AwsFrameInfo *)arg;

        if (info->opcode == WS_TEXT)
        {
            String message;
            message += String((char *)data).substring(0, len);
            parseJson(message);
        }
    }
}

void TaskServer(void *pvParameters)
{

    if (!LittleFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        vTaskDelete(NULL); // Delete the task if SPIFFS initialization fails
    }
    Serial.println("SPIFFS mounted successfully");
    while (!wifiConnected)
    {
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    ws.onEvent(onEvent);
    server.addHandler(&ws);
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/index.html", "text/html"); });
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/script.js", "application/javascript"); });
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/styles.css", "text/css"); });
    server.begin();
    Serial.println(WiFi.localIP());
    vTaskDelete(NULL); // Delete the task when done
}
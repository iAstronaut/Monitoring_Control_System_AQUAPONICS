#include "TaskMobus.h"

void sendModbusCommand(const uint8_t command[], size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        Serial2.write(command[i]);
    }
}

void sendValue(int index, String state)
{
    if (index >= 1 && index <= 32)
    {
        int relay_id = index - 1;
        if (state == "ON")
        {
            sendModbusCommand(relay_ON[relay_id], sizeof(relay_ON[relay_id]));
        }
        else
        {
            sendModbusCommand(relay_OFF[relay_id], sizeof(relay_OFF[relay_id]));
        }
    }
    String response = "{\"index\":" + String(index) + ",\"state\":\"" + state + "\"}";
    String sendData = String(index) + '-' + state;
    Serial.println(sendData);
    if (client.connected())
    {
        publishData("relay", sendData);
    }
    else
    {
        Serial.println("Not connected to MQTT");
    }
    if (ws.count() > 0)
    {
        ws.textAll(response);
    }
}
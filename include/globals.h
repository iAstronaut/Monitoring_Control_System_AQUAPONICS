#ifndef GLOBALS_H
#define GLOBALS_H

// include libraries
#include <Wire.h>
#include <WiFi.h>
#include <DHT20.h>
#include "LittleFS.h"
#include <AsyncTCP.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <ESPAsyncWebServer.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Adafruit_NeoPixel.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// include common files
#include "../src/common/defines.h"
#include "../src/common/RelayStatus.h"

// include init
#include "../src/task/TaskMQTT.h"
#include "../src/task/TaskWifi.h"

// include device
#include "../src/device/TaskGps.h"
#include "../src/device/TaskMobus.h"
#include "../src/device/TaskTemperatureHumidity.h"

// include Task files
#include "../src/task/CreateTask.h"

#include "./utils/utility_functions.h"

typedef struct
{
    int id;
    bool state;
    String days[MAX_DAYS];
    String time;
    struct
    {
        int relayId;
        String action;
    } actions[MAX_ACTIONS];
    int actionCount;
} Schedule;

extern Schedule schedules[MAX_SCHEDULES];
extern int scheduleCount;

#endif
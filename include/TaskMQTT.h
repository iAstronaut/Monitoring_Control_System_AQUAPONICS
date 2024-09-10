#ifndef INC_TASKMQTT_H_
#define INC_TASKMQTT_H_

#include "globals.h"

extern PubSubClient client;

void mqtt_init();
void reconnect();
void publishData(String feed, String data);

#endif /* INC_TASKMQTT_H_ */

#ifndef MQTTInt_H
#define MQTTInt_H
#include <mosquitto.h>
#include <iostream>
#include "string.h"

using namespace std;

class myMosq : public mosquitto
{
private:
 const char     *     host;
 const char    *     id;
 const char    *     topic;
 int                port;
 int                keepalive;

 void on_connect(int rc);
 void on_disconnect(int rc);
 void on_publish(int mid);
public:
 myMosq(const char *id, const char * _topic, const char *host, int port);
 ~myMosq();
 bool send_message(const char * _message);
};


#endif

#include "MQTTIntegration.h"


myMosq::myMosq(const char * _id,const char * _topic, const char * _host, int _port) : mosquittopp(_id)
 {
 mosquitto::lib_init();        // Mandatory initialization for mosquitto library
 this->keepalive = 60;    // Basic configuration setup for myMosq class
 this->id = _id;
 this->port = _port;
 this->host = _host;
 this->topic = _topic;
 connect_async(host,     // non blocking connection to broker request
 port,
 keepalive);
 loop_start();            // Start thread managing connection / publish / subscribe
 };

myMosq::~myMosq() {
 loop_stop();            // Kill the thread
 mosqpp::lib_cleanup();    // Mosquitto library cleanup
 }


bool myMosq::send_message(const  char * _message)
 {
 // Send message - depending on QoS, mosquitto lib managed re-submission this the thread
 //
 // * NULL : Message Id (int *) this allow to latter get status of each message
 // * topic : topic to be used
 // * lenght of the message
 // * message
 // * qos (0,1,2)
 // * retain (boolean) - indicates if message is retained on broker or not
 // Should return MOSQ_ERR_SUCCESS
 int ret = publish(NULL,this->topic,strlen(_message),_message,1,false);
 return ( ret == MOSQ_ERR_SUCCESS );
 }
void myMosq::on_disconnect(int rc) {
 cout << ">> myMosq - disconnection(" << rc << ")" << endl;
 }
void myMosq::on_connect(int rc)
 {
 if ( rc == 0 ) {
 cout << ">> myMosq - connected with server" << endl;
 } else {
 cout << ">> myMosq - Impossible to connect with server(" << rc << ")" << endl;
 }
 }

void myMosq::on_publish(int mid)
 {
 cout << ">> myMosq - Message (" << mid << ") succeed to be published " << endl;
 }




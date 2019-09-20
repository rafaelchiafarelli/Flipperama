
#include "sequence.h"
sequence S;
color pixels_of_interest[20];

void setup() {
S.setFrameDisplayed(0);
Serial.begin(57600);
}
char msg[100];
unsigned int count =0;
int l=0;
void loop() {
S.handler();

count++;
sprintf(msg, "count %d l %d Efx %d, pix %d, pos %d speed %d, control %d, ",count,l,S.G1.Efx,S.G1.pixel[1].red,S.G1.position[1],S.G1.speed,S.G1.control);
Serial.println(msg);
if(count > 0xfffe)
{
	l++;
	count=0;
	sprintf(msg, "count %d l %d",count,l);
	Serial.println(msg);
	S.setFrameDisplayed(l);
	if(l>60)
	{
		l=0;
	}
}
delay(1);
}

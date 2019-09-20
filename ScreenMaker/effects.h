#ifndef EFFECTS_H
#define EFFECTS_H

#include <QObject>
#include <QWidget>
#include "config.h"
#include "bin.h"
#include "ledindicator.h"


typedef enum {
    TRAIN_BACK,
    TRAIN_FWRD,
    FLASH,
    SMOTH_BLINK,
    STROBE,
    STROBE_TRAIN,
    RAMDOM,

    NONE

}fx;


class pixel
{
public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class screen
{
public:
    pixel color[NUMPIXELS+1];

};


class effects
{
private:
    LedIndicator *pixels; //pixels being displayed in the hardware;
    uint8_t control[GROUPS+1];
    uint8_t time[GROUPS+1];
    fx type[GROUPS+1];
    uint8_t speed[GROUPS+1]; //0 is stopped and the bigger the slower
public:
    void setFrameDisplayed(int i);
    void update(screen *c_frame, screen* l_frame);
    void setSpeed(uint8_t s,uint8_t g){speed[g] = s;}
    uint8_t getSpeed(uint8_t g){return speed[g];}
    effects(int i){setFrameDisplayed(i);}
    effects(){setFrameDisplayed(0);}
    ~effects(){}
};

#endif // EFFECTS_H

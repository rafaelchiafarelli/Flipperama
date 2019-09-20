#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QObject>
#include <QWidget>
#include "config.h"
#include "bin.h"
#include "ledindicator.h"
#include "effects.h"

class sequence : public QWidget
{
    Q_OBJECT

signals:

public slots:
private:
    effects Efx; //must be equivalent to number_of_seeds * number of groups
    int seq_number; // number of the sequence being displayed
    screen cur_frame; //must be defined in memory, because, the effects will use this as variables.
    screen last_frame;

public:

    void setFrameDisplayed(int i);
    LedIndicator *LED;
    void setSpeed(uint8_t i, uint8_t g){Efx.setSpeed(i,g);}
    void incSpeed(uint8_t g){Efx.setSpeed(((Efx.getSpeed(g)==UINT8_MAX) ? UINT8_MAX : Efx.getSpeed(g)+1),g);}
    void decSpeed(uint8_t g){Efx.setSpeed(((Efx.getSpeed(g)==0) ? 0 : Efx.getSpeed(g)-1),g);}

    void handler(); //must be called every 16milliseconds;
    explicit sequence(QWidget *parent = nullptr);

    ~sequence();
};

#endif // SEQUENCE_H

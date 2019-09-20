#include "sequence.h"

sequence::sequence(QWidget *parent) :
            QWidget(parent)
{
    setFrameDisplayed(0);
    LED = new LedIndicator[NUMPIXELS+1];
    QColor white(255,255,255,255);
    QColor black(0,0,0,0);
    for(int i =0; i<NUMPIXELS; i++)
    {
        LED[i].setState(true);
        LED[i].setOnColor(white);
        LED[i].setOffColor(black);
        LED[i].setParent(parent);
        LED[i].setLedSize(27);
       // LED[i].setGroup(this->pix[i].g);
       //find a way to give the connection this needs LED[i].move(this->pix[i].x,this->pix[i].y);
    }
}

sequence::~sequence()
{
    delete LED;
}

void sequence::setFrameDisplayed(int j)
{
    seq_number = j;
    for(int i =0;i<NUMPIXELS;i++)
    {
      //  cur_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
       // cur_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
      //  cur_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));

      //  last_frame.color[i].red = (uint8_t)pgm_read_byte(&(frames[j][i][0]));
      //  last_frame.color[i].green = (uint8_t)pgm_read_byte(&(frames[j][i][1]));
      //  last_frame.color[i].blue = (uint8_t)pgm_read_byte(&(frames[j][i][2]));
    }
    Efx.setFrameDisplayed(j);
}

void sequence::handler()
{
    Efx.update(&cur_frame,&last_frame);
    for(int i =0 ; i< NUMPIXELS;i++)
    {
        QColor C(cur_frame.color[i].red,
                 cur_frame.color[i].green,
                 cur_frame.color[i].blue,255);
      LED[i].setColor_noShow(C);
    }
}

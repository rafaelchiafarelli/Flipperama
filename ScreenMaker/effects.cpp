#include "effects.h"



void effects::setFrameDisplayed(int i)
{
    for (int j =0; j<GROUPS;j++){
        time[j] = 0;
        control[j] = 0;
        //make it read from config file.
        //speed[j] = (uint8_t)pgm_read_byte(&(effects_and_groups[i][j][0]));
        //type[j] = (uint8_t)pgm_read_byte(&(effects_and_groups[i][j][1]));
    }
}
void effects::update(screen *c_frame, screen* l_frame)
{
    pixel tmp;
    for(int i =0 ;i<GROUPS;i++)
    {
        if(speed[i] == 0) break;
        time[i]++;
        if (time[i] >= (UINT8_T_MAX - speed[i]))
        {
        time[i]=0;
        switch(type[i])
            {
            case TRAIN_BACK:
                memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
                tmp = c_frame->color[0];
                memmove(c_frame,c_frame+1,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                c_frame->color[NUMPIXELS] = tmp;
                break;

            case TRAIN_FWRD:
                memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
                tmp = c_frame->color[NUMPIXELS];
                memmove(c_frame+1,l_frame,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                c_frame->color[0] = tmp;
                break;

            case FLASH:
                memset(c_frame,0,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                break;

            case STROBE:
                control[i] = (control[i] == 0)? 1:0;
                memset(c_frame,UINT8_MAX*control[i],(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                break;

            case STROBE_TRAIN:
                if (control[i] == 0)
                {
                    memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
                    tmp = c_frame->color[NUMPIXELS];
                    memmove(c_frame+1,l_frame,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                    c_frame->color[0] = tmp;
                    control[i] = 1;
                }
                else
                {
                    memset(c_frame,0,(size_t)((NUMPIXELS-1)*sizeof(pixel)));
                    control[i] = 0;
                }
                break;

            case SMOTH_BLINK:
                for(int k = 0; k<NUMPIXELS;k++)
                    {
                        if(control[i] == 0 )
                        {
                            memcpy(l_frame,c_frame,(size_t)NUMPIXELS*sizeof(pixel));
                        }else if (control[i] == 1)
                        {
                          (c_frame[i].color[k].red < l_frame[i].color[NUMPIXELS].red)? c_frame[i].color[k].red++ : c_frame[i].color[k].red;
                          (c_frame[i].color[k].green < l_frame[i].color[NUMPIXELS].green)? c_frame[i].color[k].green++ : c_frame[i].color[k].green;
                          (c_frame[i].color[k].blue < l_frame[i].color[NUMPIXELS].blue)? c_frame[i].color[k].blue++ : c_frame[i].color[k].blue;
                          if((c_frame[i].color[k].red == l_frame[i].color[NUMPIXELS].red) &&
                                  (c_frame[i].color[k].green == l_frame[i].color[NUMPIXELS].green) &&
                                      (c_frame[i].color[k].blue == l_frame[i].color[NUMPIXELS].blue) )
                          control[i] = 2;
                        }
                        else if (control[i] == 2)
                        {
                            (c_frame[i].color[k].red > 0)? c_frame[i].color[k].red-- : c_frame[i].color[k].red;
                            (c_frame[i].color[k].green > 0)? c_frame[i].color[k].green-- : c_frame[i].color[k].green;
                            (c_frame[i].color[k].blue > 0)? c_frame[i].color[k].blue-- : c_frame[i].color[k].blue;
                              if((c_frame[i].color[k].red == 0) &&
                                      (c_frame[i].color[k].green == 0) &&
                                          (c_frame[i].color[k].blue == 0) )
                              control[i] = 1;
                        }
                    }
                break;
            case RAMDOM:
                for(int k =0 ;k<NUMPIXELS;k++)
                {
                    c_frame[i].color[k].red = rand()%255;
                    c_frame[i].color[k].green = rand()%255;
                    c_frame[i].color[k].blue = rand()%255;
                }
                break;
            case NONE:
            default:
                break;
            }
        }
    }
}

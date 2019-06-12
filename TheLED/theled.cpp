#include "theled.h"

TheLED::TheLED()
{
    InitPin();
}

TheLED::~TheLED()
{

}

int TheLED::InitPin()
{
     //setup_io();
     if(map_peripheral(&gpio)==-1)
     {
         printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
         return -1;
     }

    for(int i = 0; i < SEG_NUM; ++i)
    {
        INP_GPIO(seg_pins[i]);
        OUT_GPIO(seg_pins[i]);
        if(i < 4)
        {
            INP_GPIO(pos_pins[i]);
            OUT_GPIO(pos_pins[i]);
        }
    }
    return 0;
}

void TheLED::SetDigit(int pos, int n)
{
    for(int p = 0; p < POS_NUM ; ++p)
    {
        if(p == pos)
            GPIO_CLR = 1 << pos_pins[p]; // LOW
        else
            GPIO_SET = 1 << pos_pins[p]; // HIGH
    }

    for(int s = 0; s < SEG_NUM ; ++s)
    {
        if(pins_signal[n][s] == true)
            GPIO_CLR = 1 << seg_pins[s]; // HIGH
        else
            GPIO_SET = 1 << seg_pins[s]; // LOW
    }
}

#ifndef THELED_H
#define THELED_H

#if defined(THELED_LIBRARY)
#  define THELEDSHARED_EXPORT __attribute__((visibility("default")))
#else
#  define THELEDSHARED_EXPORT __attribute__((visibility("default")))
#endif

#include "bcmtest.h"

#define PIN_0 12
#define PIN_1 16
#define PIN_2 20
#define PIN_3 21
#define PIN_A 17
#define PIN_B 27
#define PIN_C 22
#define PIN_D 5
#define PIN_E 6
#define PIN_F 13
#define PIN_G 19
#define PIN_H 26

#define POS_NUM 4
#define SEG_NUM 8

const unsigned char pos_pins[POS_NUM] = {PIN_0, PIN_1, PIN_2, PIN_3};
const unsigned char seg_pins[SEG_NUM] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_H};

const bool pins_signal[12][SEG_NUM] = {
    {false, false, false, false, false, false, true, true}, // 0
    {true, false, false, true, true, true, true, true}, // 1
    {false, false, true, false, false, true, false, true}, // 2
    {false, false, false, false, true, true, false, true}, // 3
    {true, false, false, true, true, false, false, true}, // 4
    {false, true, false, false, true, false, false, true}, // 5
    {false, true, false, false, false, false, false, true}, // 6
    {false, false, false, true, true, true, true, true}, // 7
    {false, false, false, false, false, false, false, true}, // 8
    {false, false, false, false, true, false, false, true}, // 9
    {false, false, false, true, false, false, false, false}, // A.
    {true, true, false, false, false, false, false, false}  // b.
};

class THELEDSHARED_EXPORT TheLED
{
private:
    int  InitPin();


public:
    TheLED();
    ~TheLED();
    void SetDigit(int pos, int n);
};

#endif // THELED_H

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

const byte pos_pins[POS_NUM] = {PIN_0, PIN_1, PIN_2, PIN_3};
const byte seg_pins[SEG_NUM] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_H};

#define t true
#define f false

const bool pins_signal[12][SEG_NUM] = {
    {f, f, f, f, f, f, t, t}, // 0
    {t, f, f, t, t, t, t, t}, // 1
    {f, f, t, f, f, t, f, t}, // 2
    {f, f, f, f, t, t, f, t}, // 3
    {t, f, f, t, t, f, f, t}, // 4
    {f, t, f, f, t, f, f, t}, // 5
    {f, t, f, f, f, f, f, t}, // 6
    {f, f, f, t, t, t, t, t}, // 7
    {f, f, f, f, f, f, f, t}, // 8
    {f, f, f, f, t, f, f, t}, // 9
    {f, f, t, t, t, f, f, f}, // up O.
    {t, t, f, f, f, t, f, f}  // down O. 
};

int  InitPin();
void SetDigit(int pos, int n);
void SetPinNumber(int num1, int num2, int delaytime);

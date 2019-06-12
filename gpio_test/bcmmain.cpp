#include "bcmtest.h"


int main()
{      
    //setup_io();
    if(map_peripheral(&gpio)==-1)
    {
        printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        return -1;
    }

    INP_GPIO(4);
    OUT_GPIO(4);

    printf("Hello");

    while(1)
    {
        printf("In");
        GPIO_SET = 1 << 4;
        sleep(1);

        printf("OUT");
        GPIO_CLR = 1 <<4;
        sleep(1);
    }
    return 0;
}

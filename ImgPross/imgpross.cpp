#include "imgpross.h"
#include <stdlib.h>


ImgPross::ImgPross()
{
}
ImgPross::~ImgPross()
{
}

int ImgPross::Binary(unsigned char *raw,int wid,int hei, int kbit)
{
    unsigned char thress = 1;
    //unsigned char *newraw = new unsigned char;
    //newraw = (unsigned char *)malloc(wid*hei);

    for(int j = 0;j<hei;j++)
    {
        for(int i = 0;i<wid;i++)
        {
            int group = 256 / (thress << kbit);
            int tmp = *(raw + i + j*wid) / group;
            if(group *(tmp +1) == 256)
                *(raw + i + j*wid) = 255;
            else
                *(raw + i + j*wid) = (unsigned char)(group*tmp);
        }
    }
    return 0;
}

int ImgPross::Binary_thres(unsigned char *raw,int wid,int hei, int threshold)
{

    for(int j = 0;j<hei;j++)
    {
        for(int i = 0;i<wid;i++)
        {
            if(*(raw + i + j*wid) > threshold)
                *(raw + i + j*wid) = 255;
            else
                *(raw + i + j*wid) = 0;
        }
    }
    return 0;
}



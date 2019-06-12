#ifndef BITMAPSTRUCT_H
#define BITMAPSTRUCT_H

#pragma once 
#pragma pack(push)
#pragma pack(2) 

typedef struct tagbmpfileheader{
    unsigned short  bfType;
    unsigned int bfSize;
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned int bfOffset;
} bmpfileheader;

typedef struct tagbmpinfoheader{
    unsigned int biSize;
    int  biWidth;
    int  biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int biCompression;
    unsigned int biImageSize;
    int  biXPelsPerMeter;
    int  biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
}bmpinfoheader;



typedef struct tagbmpstruct{
    tagbmpfileheader bmpFhead;
    tagbmpinfoheader bmpIhead;
    unsigned char *bmpRGB;
}BMP;
#pragma pack(pop)



#endif // BITMAPSTRUCT_H


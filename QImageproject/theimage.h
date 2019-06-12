#ifndef THEIMAGE_H
#define THEIMAGE_H

#include "bitmapstruct.h"


class TheImage
{
private:
    int   m_width_;
    int   m_height_;
    unsigned char *m_rawdate_;
    BMP   m_img_;

public:
    TheImage();
    ~TheImage();

public:
    int  LoadBMPfile(const char *file);
    int  SaveImage(const char *file);
    int  GetImgWidth();
    int  GetImgHeight();
    unsigned char *GetRaw();
    unsigned char *GetColorTable();
    unsigned char *GetReverse();
    int ChangedRaw(unsigned char *targetraw);
};

#endif // THEIMAGE_H

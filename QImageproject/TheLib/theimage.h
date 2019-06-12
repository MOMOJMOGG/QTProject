#ifndef THEIMAGE_H
#define THEIMAGE_H

#if defined(THEIMAGE_LIBRARY)
#define THEIMAGESHARED_EXPORT __attribute__((visibility("default")))
#else
#define THEIMAGESHARED_EXPORT __attribute__((visibility("default")))
#endif

#include "bmpstruct.h"

class THEIMAGESHARED_EXPORT TheImage
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
    int  SetImgWidth(int tarwid);
    int  SetImgHeight(int tarhei);
    unsigned char *GetRaw();
    unsigned char *GetColorTable();
    unsigned char *GetReverse();
    int ChangedRaw(unsigned char *targetraw);
    int SetColorTable();
    int SetRawSize(int tarsized);
    int SetBMPInfo(int tarwidth, int tarheight);
    int CopyRaw(unsigned char *sourceraw,int tarsized,int wid, int hei);
};

#endif // THEIMAGE_H

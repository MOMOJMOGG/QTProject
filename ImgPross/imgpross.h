#ifndef IMGPROSS_H
#define IMGPROSS_H

#if defined(IMGPROSS_LIBRARY)
#define IMGPROSSSHARED_EXPORT __attribute__((visibility("default")))
#else
#define IMGPROSSSHARED_EXPORT __attribute__((visibility("default")))
#endif

class IMGPROSSSHARED_EXPORT ImgPross
{

public:
    ImgPross();
    ~ImgPross();

public:
    int Binary(unsigned char *raw,int wid,int hei, int kbit);
    int Binary_thres(unsigned char *raw,int wid,int hei, int threshold);
    //unsigned char *Filter(unsigned char *raw,int wid,int hei, int mode);

};

#endif // IMGPROSS_H

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
    //ItemInfo *ScanItem(int threshold,int filtersize);

    RLEtable *BuildRLE(unsigned char *raw,int wid, int hei,int threshold);
    RLEtable *FindNodeHead(RLEtable *curr, int mode, int pos, RLEtable *tar);
    void ChangeNodetar(RLEtable *curr, int item, int val, int val2);
    void DeleteBlobNode(RLEtable *blobtar, int mode);
    ItemInfo *GetInfoFromBlob(RLEtable *blob, int filtersize);
    void CleanNode(RLEtable *tar);
    void CleanItem(ItemInfo *theITM);
    void PrintBlob(RLEtable *blobhead);
    void PrintITM(ItemInfo *ITM);
    void ClearBlob(RLEtable *thehead);
};

#endif // THEIMAGE_H

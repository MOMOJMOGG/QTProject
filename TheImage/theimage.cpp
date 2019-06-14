#include "theimage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TheImage::TheImage()
{
    m_rawdate_ = NULL;
    m_img_.bmpRGB = NULL;
}

TheImage::~TheImage()
{
    free(m_img_.bmpRGB);
    free(m_rawdate_);
    m_rawdate_ = NULL;
    m_img_.bmpRGB = NULL;
}

int TheImage::LoadBMPfile(const char *file)
{
    FILE *f_op;
    f_op=NULL;

    unsigned short  buf_unshort;
    unsigned int buf_unint;
    int  buf_int;

    /**open file**/
    f_op = fopen(file, "rb");
    if(f_op == NULL)
        return -1;

    fseek(f_op, 0, SEEK_SET);

    /**read file header**/
    fread(&buf_unshort, sizeof(unsigned short), 1, f_op);
    m_img_.bmpFhead.bfType = buf_unshort;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpFhead.bfSize = buf_unint;
    fread(&buf_unshort, sizeof(unsigned short), 1, f_op);
    m_img_.bmpFhead.bfReserved1 = buf_unshort;
    fread(&buf_unshort, sizeof(unsigned short), 1, f_op);
    m_img_.bmpFhead.bfReserved2 = buf_unshort;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpFhead.bfOffset = buf_unint;

    /**read info header**/
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpIhead.biSize = buf_unint;
    fread(&buf_int, sizeof(int), 1, f_op);
    m_img_.bmpIhead.biWidth = buf_int;
    fread(&buf_int, sizeof(int), 1, f_op);
    m_img_.bmpIhead.biHeight = buf_int;
    fread(&buf_unshort, sizeof(unsigned short), 1, f_op);
    m_img_.bmpIhead.biPlanes = buf_unshort;
    fread(&buf_unshort, sizeof(unsigned short), 1, f_op);
    m_img_.bmpIhead.biBitCount = buf_unshort;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpIhead.biCompression = buf_unint;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpIhead.biImageSize = buf_unint;
    fread(&buf_int, sizeof(int), 1, f_op);
    m_img_.bmpIhead.biXPelsPerMeter = buf_int;
    fread(&buf_int, sizeof(int), 1, f_op);
    m_img_.bmpIhead.biYPelsPerMeter = buf_int;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpIhead.biClrUsed = buf_unint;
    fread(&buf_unint, sizeof(unsigned int), 1, f_op);
    m_img_.bmpIhead.biClrImportant = buf_unint;

    /**read color table**/
    int tmp_clr_size;
    tmp_clr_size = (m_img_.bmpFhead.bfOffset - sizeof(m_img_.bmpFhead)-sizeof(m_img_.bmpIhead));
    m_img_.bmpRGB = (unsigned char *)malloc(tmp_clr_size);
    if(m_img_.bmpRGB == NULL)
        return -1;
    else
    {
        memset(m_img_.bmpRGB, 0xFF, tmp_clr_size);
        fread(m_img_.bmpRGB, tmp_clr_size, 1, f_op);
    }

    /**read raw data**/
    if(m_img_.bmpIhead.biBitCount > 8)
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight * 3;
    else
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight;
    m_rawdate_ = (unsigned char *)malloc(tmp_clr_size);
    if(m_rawdate_ == NULL)
        return -1;
    else
    {
        memset(m_rawdate_, 0xFF, tmp_clr_size);
        fread(m_rawdate_, tmp_clr_size, 1, f_op);
    }

    /* update value */
    m_width_ = m_img_.bmpIhead.biWidth;
    m_height_ = m_img_.bmpIhead.biHeight;
    fclose(f_op);
    return 0;
}

int TheImage::SaveImage(const char *file)
{
    FILE *f_out;
    f_out = NULL;

    if(!fopen(file, "rb"))
        f_out = fopen(file, "wb");
    else
        f_out = fopen(file, "rb+");

    if(f_out == NULL)
    {
        return -1;
    }

    fwrite(&m_img_.bmpFhead, sizeof(m_img_.bmpFhead), 1, f_out);
    fwrite(&m_img_.bmpIhead, sizeof(m_img_.bmpIhead), 1, f_out);

    int tmp_clr_size;
    tmp_clr_size = (m_img_.bmpFhead.bfOffset - sizeof(m_img_.bmpFhead)-sizeof(m_img_.bmpIhead));
    fwrite(m_img_.bmpRGB, tmp_clr_size, 1, f_out);

    if(m_img_.bmpIhead.biBitCount > 8)
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight * 3;
    else
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight;

     fwrite(m_rawdate_, tmp_clr_size, 1, f_out);
     fclose(f_out);
     return 0;
}

int TheImage::GetImgWidth()
{
    return m_width_;
}
int TheImage::GetImgHeight()
{
    return m_height_;
}

unsigned char *TheImage::GetRaw()
{
    return m_rawdate_;
}

unsigned char *TheImage::GetColorTable()
{
    return m_img_.bmpRGB;
}

unsigned char *TheImage::GetReverse()
{
    int tmp_clr_size;
    unsigned char *newraw = NULL;

    /**read raw data**/
    if(m_img_.bmpIhead.biBitCount > 8)
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight * 3;
    else
        tmp_clr_size = m_img_.bmpIhead.biWidth * m_img_.bmpIhead.biHeight;
    newraw = (unsigned char *)malloc(tmp_clr_size);
    memset(newraw, 0xFF, tmp_clr_size);

    /**reverse raw data**/

    for(int j = 0; j < m_height_;j++ )
    {
        for(int i =0; i< m_width_;i++)
        {
            //*(newraw + (m_width_-1-i)+(m_height_-1-j)*m_width_) = *(m_rawdate_ + i + j*m_width_);
            *(newraw + i +(m_height_-1-j)*m_width_) = *(m_rawdate_ + i + j*m_width_);
        }
    }
    return newraw;
}

int TheImage::ChangedRaw(unsigned char *targetraw)
{
    m_rawdate_ = targetraw;
    return 0;
}

int TheImage::SetBMPInfo(int tarwidth, int tarheight)
{
    m_img_.bmpFhead.bfType = 0x4D42;
    m_img_.bmpFhead.bfReserved1 = 0;
    m_img_.bmpFhead.bfReserved2 = 0;
    m_img_.bmpFhead.bfOffset = 1024+14+40;

    m_img_.bmpIhead.biSize = 40;
    m_img_.bmpIhead.biPlanes = 1;
    m_img_.bmpIhead.biBitCount = 8;
    m_img_.bmpIhead.biCompression = 0;
    m_img_.bmpIhead.biImageSize = 0;
    m_img_.bmpIhead.biXPelsPerMeter = 0;
    m_img_.bmpIhead.biYPelsPerMeter = 0;
    m_img_.bmpIhead.biClrUsed = 0;
    m_img_.bmpIhead.biClrImportant = 0;

    m_img_.bmpIhead.biWidth = tarwidth;
    m_img_.bmpIhead.biHeight = tarheight;
    m_img_.bmpFhead.bfSize = m_img_.bmpFhead.bfOffset + tarwidth*tarheight;


    return 0;
}

int  TheImage::SetImgWidth(int tarwid)
{
    m_width_ = tarwid;
    return 0;
}

int  TheImage::SetImgHeight(int tarhei)
{
    m_height_ = tarhei;
    return 0;
}

int TheImage::SetColorTable()
{
    /**set color table**/
    const int tmp_clr_size = (m_img_.bmpFhead.bfOffset - sizeof(m_img_.bmpFhead) - sizeof(m_img_.bmpIhead));

    if(m_img_.bmpRGB != NULL)
    {
        free(m_img_.bmpRGB);
        m_img_.bmpRGB = NULL;
    }
    m_img_.bmpRGB = (unsigned char *)malloc(tmp_clr_size);
    memset(m_img_.bmpRGB, 0xFF, tmp_clr_size);
    for(int i = 0;i<256;i++)
    {
        *(m_img_.bmpRGB + i*4) = i;
        *(m_img_.bmpRGB + i*4+1) = i;
        *(m_img_.bmpRGB + i*4+2) = i;
        *(m_img_.bmpRGB + i*4+3) = i;
    }

    return 0;
}

int TheImage::SetRawSize(int tarsized)
{

    if(m_rawdate_ != NULL)
    {
        free(m_rawdate_);
        m_rawdate_ = NULL;
    }
    m_rawdate_ = (unsigned char *)malloc(tarsized);
    memset(m_rawdate_, 0xFF, tarsized);

    return 0;
}

int TheImage::CopyRaw(unsigned char *sourceraw,int tarsized,int wid, int hei)
{
    m_width_ = wid;
    m_height_ = hei;
    for(int i = 0;i<tarsized;i++)
        *(m_rawdate_ + i) = *(sourceraw + i);
    return 0;
}

RLEtable *TheImage::BuildRLE(unsigned char *raw,int tarsized,int wid, int hei,int threshold)
{
    RLEtable *parentcol, *currcol, *tmpnode1, *tmpnode2, *Blob, *tmpblob;
    parentcol = new RLEtable{0, 0, 0, 0, NULL, NULL, NULL, NULL, 0};
    currcol = new RLEtable{0, 0, 0, 0, NULL, NULL, NULL, NULL, 0};
    Blob = new RLEtable{0, 0, 0, 0, NULL, NULL, NULL, NULL, 0};

    bool headflag = false;
    int blobindex = 1;

    for(int j = 0;j < hei;++j)
    {
        tmpnode2 = currcol;
        for(int i = 0;i<wid;++i)
        {
            // image process create a col datalink
            if(*(raw + i + j*wid) > threshold)
            {
                *(raw + i + j*wid) = 255;
                headflag = false;
            }
            else
            {
                *(raw + i + j*wid) = 0;
                if(!headflag)
                {
                    RLEtable *newnode  = new RLEtable{0, i, i, j, NULL, NULL, NULL, NULL, 0};
                    tmpnode2->beside = newnode;
                    tmpnode2 = tmpnode2->beside;
                    headflag = true;
                }
                else
                {
                    tmpnode2->Xend = i;
                }
            }
        } // end width
        headflag = false;

        tmpnode1 = parentcol->beside;
        tmpnode2 = currcol->beside;
        while(tmpnode2 != NULL)
        {
            while(tmpnode1 != NULL)
            {
                if(tmpnode1->Xend >= tmpnode2->Xstart && tmpnode1->Xstart <= tmpnode2->Xend)
                {
                    tmpnode1->count += 1;
                    tmpnode2->count += 1;

                    if(tmpnode2->count == 1) // I, m, Left W
                    {
                        if(tmpnode1->nextnode == NULL) // I
                        {
                            tmpnode1->nextnode = tmpnode2;
                            tmpnode2->parenode = tmpnode1;
                            tmpnode2->Index = tmpnode1->Index;
                            ChangeNodetar(Blob, 3, tmpnode2->Index, 1);
                        }
                        else
                        {
                            if(tmpnode1->count == 1) //Left W
                            {
                                tmpblob = FindNodeHead(tmpnode1, 3, NULL);
                                tmpblob->nextnode = tmpnode2;
                                tmpnode2->parenode = tmpblob;
                                tmpnode2->Index = tmpblob->Index;
                                ChangeNodetar(Blob, 3, tmpnode2->Index, 1);
                            }
                            else // m
                            {
                                tmpblob = FindNodeHead(tmpnode1, 3, tmpnode1->count-1);
                                if(tmpblob->nextnode != NULL)
                                {
                                    tmpblob->nextnode->parenode = tmpnode2;
                                    tmpnode2->nextnode = tmpblob->nextnode;
                                }
                                tmpblob->nextnode = tmpnode2;
                                tmpnode2->parenode = tmpblob;
                                tmpnode2->Index = tmpblob->Index;
                                ChangeNodetar(Blob, 3, tmpnode2->Index, 1);
                            }
                        }
                    }
                    else // U, No
                    {
                        if(tmpnode1->nextnode == NULL) // U
                        {
                            tmpblob = FindNodeHead(tmpnode1, 1, NULL);
                            tmpnode2->parenode->nextnode = tmpblob->nextnode;
                            tmpblob->nextnode->parenode = tmpnode2->parenode;
                            ChangeNodetar(tmpblob->nextnode, 2, tmpnode2->parenode->Index, NULL);
                            ChangeNodetar(Blob, 3, tmpnode2->Index, tmpblob->Ypos);
                            tmpblob->nextnode = NULL;
                            DeleteBlobNode(tmpblob, 0);
                            tmpnode1->nextnode = tmpnode2;
                            tmpnode2->parenode = tmpnode1;
                        }
                    }
                } // end connect
                tmpnode1 = tmpnode1->beside;
            }// end parecol
            tmpnode2 = tmpnode2->beside;
            tmpnode1 = parentcol->beside;
        }//end currcol
        tmpnode2 = currcol->beside;
        while(tmpnode2 != NULL) // find root
        {
            if(tmpnode2->count == 0)
            {
                RLEtable *newnode = new RLEtable{blobindex, 0, 0, 1, NULL, NULL, NULL, NULL, 0};
                tmpblob = FindNodeHead(Blob, 2, NULL);
                tmpblob->beside = newnode;
                newnode->preside = tmpblob;
                newnode->nextnode = tmpnode2;
                tmpnode2->parenode = newnode;
                tmpnode2->Index = newnode->Index;
                blobindex += 1;
            }
            tmpnode2 = tmpnode2->beside;
        }// end find root

        ChangeNodetar(currcol, 1, 0, 0);
        parentcol->beside = currcol->beside;
        currcol->beside = NULL;
    }// end height

    if(parentcol != NULL)
        CleanNode(parentcol);
    if(currcol != NULL)
        CleanNode(currcol);

    return Blob;
}

RLEtable *TheImage::FindNodeHead(RLEtable *curr, int mode, int pos)
{
    switch (mode) {
    case 1:
        curr = curr->parenode;
        while(curr->parenode != NULL)
            curr = curr->parenode;
        break;
    case 2:
        while(curr->beside != NULL)
            curr = curr->beside;
        break;
    case 3:
        if(pos == NULL)
        {
            curr = curr->nextnode;
            while(curr->nextnode != NULL)
                curr = curr->nextnode;
        }
        else
        {
            for(int f = 0; f < pos; ++f)
                curr = curr->nextnode;
        }
        break;
    default:
        break;
    }
    return curr;
}

void TheImage::ChangeNodetar(RLEtable *curr, int item, int val, int val2)
{
    switch (item) {
    case 1:
        while(curr->beside != NULL){
            curr = curr->beside;
            curr->count = val;
        }
        break;
    case 2:
        while(curr != NULL)
        {
            curr->Index = val;
            curr = curr->nextnode;
        }
        break;
    case 3:
        while(curr != NULL)
        {
            if(curr->Index == val)
            {
                curr->Ypos += val2;
                return;
            }
            curr = curr->beside;
        }
        break;
    default:
        break;
    }
}

void TheImage::DeleteBlobNode(RLEtable *blobtar, int mode)
{
    if(mode == 0)
    {
        RLEtable *prenode = blobtar->preside;
        prenode->beside = blobtar->beside;
        if(blobtar->beside != NULL)
            blobtar->beside->preside = prenode;
        CleanNode(blobtar);
    }
    else
    {
        RLEtable *prenode = blobtar->parenode;
        prenode->nextnode = blobtar->nextnode;
        if(blobtar->nextnode != NULL)
            blobtar->nextnode->parenode = prenode;
        CleanNode(blobtar);
    }
}

ItemInfo *TheImage::GetInfoFromBlob(RLEtable *blob, int filtersize)
{
    RLEtable *tmp1, *tmp2;
    int xmin=0, xmax=0, ymin=0, ymax=0;
    ItemInfo *itmnode, *tmpitmnode;
    itmnode = new ItemInfo{{{0,0},{0,0},{0,0},{0,0}}, 0, 0.0, NULL};
    tmpitmnode = itmnode;

    bool initflag = true;

    tmp1 = blob->beside;
    while(tmp1 != NULL)
    {
        if(tmp1->Ypos < filtersize)
        {
            while(tmp1->nextnode != NULL)
            {
                tmp2 = tmp1->nextnode;
                DeleteBlobNode(tmp2, 1);
            }
            DeleteBlobNode(tmp1, 0);
            tmp1 = blob->beside;
        }
        else
        {
            tmp2 = tmp1->nextnode;
            while(tmp2 != NULL)
            {
                if(initflag)
                {
                    ItemInfo *newitm = new ItemInfo{{{tmp2->Xstart,tmp2->Ypos},{tmp2->Xend,tmp2->Ypos},{(tmp2->Xstart + tmp2->Xend)/2,tmp2->Ypos},{(tmp2->Xstart + tmp2->Xend)/2,tmp2->Ypos}}, 0, 0.0, NULL};
                    tmpitmnode->next = newitm;
                    itmnode->targetNum += 1;
                    tmpitmnode = tmpitmnode->next;
                    initflag = false;

                    xmin = tmp2->Xstart;
                    xmax = tmp2->Xend;
                    ymin = tmp2->Ypos;
                    ymax = tmp2->Ypos;
                }

                if(xmin > tmp2->Xstart)
                {
                    xmin = tmp2->Xstart;
                    tmpitmnode->points[0].x = tmp2->Xstart;
                    tmpitmnode->points[0].y = tmp2->Ypos;
                }

                if(xmax < tmp2->Xend)
                {
                    xmax = tmp2->Xend;
                    tmpitmnode->points[1].x = tmp2->Xend;
                    tmpitmnode->points[1].y = tmp2->Ypos;
                }

                if(ymin > tmp2->Ypos)
                {
                    ymin = tmp2->Ypos;
                    tmpitmnode->points[2].x = (tmp2->Xstart + tmp2->Xend)/2;
                    tmpitmnode->points[2].y = tmp2->Ypos;
                }

                if(ymax < tmp2->Ypos)
                {
                    ymax = tmp2->Ypos;
                    tmpitmnode->points[3].x = (tmp2->Xstart + tmp2->Xend)/2;
                    tmpitmnode->points[3].y = tmp2->Ypos;
                }

                DeleteBlobNode(tmp2, 1);
                tmp2 = tmp1->nextnode;
            }

            DeleteBlobNode(tmp1, 0);
            tmp1 = blob->beside;
        } // end search for 1 blob node

        initflag = true;
    }// end search for all

    if(blob != NULL)
        CleanNode(blob);

    return itmnode;
}

void TheImage::CleanNode(RLEtable *tar)
{
    tar->beside = NULL;
    tar->preside = NULL;
    tar->nextnode = NULL;
    tar->parenode = NULL;
    delete tar;
}

void TheImage::CleanItem(ItemInfo *theITM)
{
    ItemInfo *pre = theITM->next;
    while(pre != NULL)
    {
        theITM->next = pre->next;
        pre->next = NULL;
        delete pre;
        pre = theITM->next;
    }
    if(theITM != NULL)
        delete theITM;
}

/*
void TheImage::InitITM(ItemInfo *ITM)
{
    for(int p = 0; p < 4; ++p)
    {
        ITM->points[p].x = 0;
        ITM->points[p].y = 0;
    }
    ITM->next = NULL;
    ITM->targetNum = 0;
    ITM->theta = 0.0;
}

ItemInfo *TheImage::ScanItem(int threshold,int filtersize)
{
    RLEtable *theblob;
    theblob= BuildRLE(threshold);
    ItemInfo *theITM;
    theITM = GetInfoFromBlob(theblob, filtersize);
    return theITM;
}
*/
void TheImage::PrintITM(ItemInfo *ITM)
{
    printf("<<ITM Head Size : %d >>\n", ITM->targetNum);
    ITM = ITM->next;
    while(ITM != NULL)
    {
        printf("[xmin:( %d, %d), ymin:( %d, %d), xmax:( %d, %d), ymax:( %d, %d)]\n",
               ITM->points[0].x, ITM->points[0].y,
               ITM->points[2].x, ITM->points[2].y,
               ITM->points[1].x, ITM->points[1].y,
               ITM->points[3].x, ITM->points[3].y);
        ITM = ITM->next;
    }
}

void TheImage::PrintBlob(RLEtable *blobhead)
{
    RLEtable *tmpblob, *tmpnode;
    tmpblob = blobhead->beside;
    while(tmpblob != NULL)
    {
        printf("<< Blobnode %d, nodeSize: %d >>\n", tmpblob->Index, tmpblob->Ypos);
        tmpnode = tmpblob->nextnode;
        while(tmpnode != NULL)
        {
            printf("Blobnum: %d, Xs: %d, Xe: %d, Y: %d, Cnt: %d\n", tmpnode->Index, tmpnode->Xstart, tmpnode->Xend, tmpnode->Ypos, tmpnode->count);
            tmpnode = tmpnode->nextnode;
        }
        tmpblob = tmpblob->beside;
    }
}

void TheImage::ClearBlob(RLEtable *blobhead)
{
    RLEtable *tmpblob, *tmpnode;
    tmpblob = blobhead->beside;
    while(tmpblob != NULL)
    {
        while(tmpblob->nextnode != NULL)
        {
            tmpnode = tmpblob->nextnode;
            DeleteBlobNode(tmpnode, 1);
        }
        DeleteBlobNode(tmpblob,0);
        tmpblob = blobhead->beside;
    }
    if(blobhead != NULL)
        CleanNode(blobhead);
}

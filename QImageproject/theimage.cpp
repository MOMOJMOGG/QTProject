#include "theimage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TheImage::TheImage()
{
    m_rawdate_ = new unsigned char;
    m_img_.bmpRGB = new unsigned char;
}

TheImage::~TheImage()
{
    delete m_img_.bmpRGB;
    delete m_rawdate_;
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
    unsigned char *newraw = new unsigned char;
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

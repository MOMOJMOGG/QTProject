#include "theimage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    TheImage *g_img = new TheImage();
    time_t str_t, end_t;
    g_img->LoadBMPfile("lenaaa.bmp");
    RLEtable *theblob;
    str_t = time(NULL);
    theblob = g_img->BuildRLE(127);
    ItemInfo *theItm = g_img->GetInfoFromBlob(theblob, 50);
    g_img->PrintITM(theItm);
    g_img->CleanItem(theItm);
    end_t = time(NULL);
    double diff_t = end_t - str_t;
    printf("Time = %f\n",diff_t);
    system("pause");
    return 0;
}

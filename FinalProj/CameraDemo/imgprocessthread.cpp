#include "imgprocessthread.h"

#include <QThread>
#include <QMutexLocker>
#include <QMutex>
#include "theimage.h"
#include <QDebug>
#include <QSemaphore>

extern TheImage *g_img_;
extern QMutex mutex_cam_param;
extern bool g_threshold_flag;
//extern int k_bits;
extern int g_threshold;
extern QSemaphore sema_cam;
extern QSemaphore sema_pro;

imgprocessthread::imgprocessthread(QObject *parent) : QObject(parent)
{
    isStop = false;
    for(int i = 0; i < 256; i++)
       grayColourTable.append(qRgb(i, i, i));
}
void imgprocessthread::closeThread()
{
    isStop = true;
}

void imgprocessthread::slot_startThread()
{
    while (1)
    {
       if(isStop)
            return;

       if(g_threshold_flag)
       {

           sema_pro.acquire();
           //m_imgpross.Binary_thres(g_img_->GetRaw(),g_img_->GetImgWidth(),g_img_->GetImgHeight(),g_threshold);
           g_img_->GetInfoFromBlob( g_img_->BuildRLE(150),100);

           sema_cam.release();

           QImage imgg(g_img_->GetRaw(),g_img_->GetImgWidth(),g_img_->GetImgHeight(), QImage::Format_Indexed8);
           imgg.setColorTable(grayColourTable);

           emit(processed(imgg));

       }
       else
       {}




       QThread::usleep(1000);
    }
}

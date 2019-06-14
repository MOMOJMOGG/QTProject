#include "imgprocessthread.h"

#include <QThread>
#include <QMutexLocker>
#include <QMutex>
#include "theimage.h"
#include <QDebug>
#include <QSemaphore>

extern TheImage *g_img_;
extern bool g_threshold_flag;
extern int g_threshold;
extern QMutex g_mutex;
extern QWaitCondition g_waitprocess;
extern QWaitCondition g_waitcopy;
extern bool prfinish_flag;

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
           //emit cmd_suspend_cap();
           //g_mutex.lock();
           //m_imgpross.Binary_thres(g_img_->GetRaw(), g_img_->GetImgWidth(),g_img_->GetImgHeight(), g_threshold);
           //QImage imgg(g_img_->GetRaw(),g_img_->GetImgWidth(),g_img_->GetImgHeight(), QImage::Format_Indexed8);
           //g_waitprocess.wakeOne();

           //g_mutex.unlock();
           //emit processed(imgg);
           //imgg.setColorTable(grayColourTable);
           //emit cmd_resume_cap();



           //RLEtable *rle = g_img_->BuildRLE(150);
           //ItemInfo *theitm = g_img_->GetInfoFromBlob(rle, 100);
           //g_img_->CleanItem(theitm);
       }

       QThread::usleep(1000);
    }
}

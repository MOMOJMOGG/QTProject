#include "mainwindow.h"

#include "capturethread.h"

#include <QThread>
#include <QMutexLocker>
#include "CameraApi.h"
#include <QDebug>
#include <QSemaphore>

extern cam_param g_cam;
extern TheImage *g_img_;
extern QMutex mutex_cam_param;
extern bool g_threshold_flag;
extern QSemaphore sema_cam;
extern QSemaphore sema_pro;

CaptureThread::CaptureThread(QObject *parent) : QObject(parent)
{
    isStop = false;

    for(int i = 0; i < 256; i++)
       grayColourTable.append(qRgb(i, i, i));

}

void CaptureThread::closeThread()
{
    isStop = true;
}

void CaptureThread::slot_startThread()
{
    while (1)
    {
       if(isStop)
            return;

       if (CameraGetImageBuffer(g_cam.hCamera,&g_cam.tFrameHead,&g_cam.pRawBuffer,2000) == CAMERA_STATUS_SUCCESS)
       {
           CameraImageProcess(g_cam.hCamera,g_cam.pRawBuffer,g_cam.pRgbBuffer,&g_cam.tFrameHead);
           if(g_cam.tFrameHead.uiMediaType==CAMERA_MEDIA_TYPE_MONO8)
           {
               memcpy(g_cam.rawBuffer,g_cam.pRgbBuffer,  g_cam.wid*g_cam.hei);


               QImage imggg(g_cam.rawBuffer,g_cam.wid,g_cam.hei, QImage::Format_Indexed8);
               emit captured(imggg);
               if(!g_threshold_flag)
               {

                  memcpy(g_img_->GetRaw(), g_cam.rawBuffer,  g_cam.wid*g_cam.hei);

                  QImage imgg(g_img_->GetRaw(),g_img_->GetImgWidth(),g_img_->GetImgHeight(), QImage::Format_Indexed8);

                  imgg.setColorTable(grayColourTable);

                  emit captured2(imgg);
               }
               else
               {
                   sema_cam.acquire();
                   memcpy(g_img_->GetRaw(), g_cam.rawBuffer,  g_cam.wid*g_cam.hei);
                   sema_pro.release();
               }

           }
           CameraReleaseImageBuffer(g_cam.hCamera,g_cam.pRawBuffer);
       }

       QThread::usleep(1000);
    }
}

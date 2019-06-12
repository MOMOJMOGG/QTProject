#include "ledthread.h"
#include <QThread>

extern bool g_led_flag;
extern int lednum1;
extern int lednum2;

LedThread::LedThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void LedThread::closeThread()
{
    isStop = true;
}

void LedThread::slot_startThread()
{
    while (1)
    {
       if(isStop)
            return;

       if(g_led_flag)
       {
           m_theled.SetDigit(3, 10);
           QThread::msleep(10);
           m_theled.SetDigit(2, lednum1);
           QThread::msleep(10);
           m_theled.SetDigit(1, 11);
           QThread::msleep(10);
           m_theled.SetDigit(0, lednum2);
           QThread::msleep(10);
       }

       QThread::usleep(1000);
    }
}

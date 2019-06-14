#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QImage>
#include "theimage.h"
#include "imgpross.h"
#include "thelock.h"

class CaptureThread : public QObject
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);

    void closeThread();
    ImgPross m_imgpross;

    void suspend();
    void resume();

signals:
    void captured(QImage img);
    void captured2(QImage img);

public slots:
    void slot_startThread();
    //void slot_binaryThread();

private:
    QVector<QRgb> grayColourTable;

    QMutex mutex;
    QWaitCondition bufferisnotprocess;
    void WaitOne(unsigned long time);

private:
    volatile bool isStop;
    volatile bool isPause;
};

#endif // CAPTURETHREAD_H

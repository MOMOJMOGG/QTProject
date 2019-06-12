#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QImage>
#include "theimage.h"

class CaptureThread : public QObject
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);

    void closeThread();

signals:
    void captured(QImage img);
    void captured2(QImage img);

public slots:
    void slot_startThread();

private:
    QVector<QRgb> grayColourTable;
    QMutex mutex;
    QWaitCondition monitor;

private:
    volatile bool isStop;
};

#endif // CAPTURETHREAD_H

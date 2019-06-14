#ifndef IMGPROCESSTHREAD_H
#define IMGPROCESSTHREAD_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QImage>
#include "theimage.h"
#include "imgpross.h"

class imgprocessthread : public QObject
{
    Q_OBJECT
public:
    explicit imgprocessthread(QObject *parent = 0);

    void closeThread();
    ImgPross m_imgpross;

signals:
    void processed(QImage);
    void cmd_suspend_cap();
    void cmd_resume_cap();
public slots:
    void slot_startThread();
private:
    volatile bool isStop;
    QVector<QRgb> grayColourTable;
    QWaitCondition monitor;


};

#endif // IMGPROCESSTHREAD_H

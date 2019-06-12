#ifndef LEDTHREAD_H
#define LEDTHREAD_H

#include <QObject>
#include "theled.h"

class LedThread : public QObject
{
    Q_OBJECT
public:
    explicit LedThread(QObject *parent = 0);

    void closeThread();
    TheLED m_theled;
public slots:
    void slot_startThread();
private:
    volatile bool isStop;
};

#endif // LEDTHREAD_H

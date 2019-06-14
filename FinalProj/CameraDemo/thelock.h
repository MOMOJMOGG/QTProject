#ifndef THELOCK_H
#define THELOCK_H

#include <QDebug>
#include <QMutex>
#include <QWaitCondition>

class TheLock
{
public:
    TheLock();
    QMutex mutex;
    QWaitCondition waitCond;
};

#endif // THELOCK_H

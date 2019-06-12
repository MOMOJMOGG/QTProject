#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T23:15:13
#
#-------------------------------------------------

QT       -= core gui

TARGET = TheLED
TEMPLATE = lib

DEFINES += THELED_LIBRARY

SOURCES += theled.cpp \
    bcmtest.cpp

HEADERS += theled.h \
    bcmtest.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T04:07:51
#
#-------------------------------------------------

QT       -= core gui

TARGET = ImgPross
TEMPLATE = lib

DEFINES += IMGPROSS_LIBRARY

SOURCES += imgpross.cpp

HEADERS += imgpross.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

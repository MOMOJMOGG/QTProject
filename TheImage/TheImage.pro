#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T03:02:57
#
#-------------------------------------------------

QT       -= core gui

TARGET = TheImage
TEMPLATE = lib

DEFINES += THEIMAGE_LIBRARY

SOURCES += theimage.cpp

HEADERS += \
    bmpstruct.h \
    theimage.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

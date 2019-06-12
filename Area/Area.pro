#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T13:29:11
#
#-------------------------------------------------

QT       -= core gui

TARGET = Area
TEMPLATE = lib

DEFINES += AREA_LIBRARY

SOURCES += area.cpp \
    b.cpp

HEADERS += \
    area.h \
    b.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

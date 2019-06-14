#-------------------------------------------------
#
# Project created by QtCreator 2019-04-21T02:12:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Camera/capturethread.cpp \
    imgprocessthread.cpp \
    ledthread.cpp \
    thelock.cpp

HEADERS += \
        mainwindow.h \
    Camera/CameraApi.h \
    Camera/CameraDefine.h \
    Camera/CameraStatus.h \
    Camera/capturethread.h \
    TheLib/bcmtest.h \
    TheLib/bmpstruct.h \
    TheLib/imgpross.h \
    TheLib/theimage.h \
    TheLib/theled.h \
    imgprocessthread.h \
    ledthread.h \
    thelock.h

FORMS += \
        mainwindow.ui

LIBS += -L$$PWD/Camera/ -lMVSDK
INCLUDEPATH += $$PWD/Camera
DEPENDPATH += $$PWD/Camera

unix:!macx: LIBS += -L$$PWD/TheLib/ -lImgPross

INCLUDEPATH += $$PWD/TheLib
DEPENDPATH += $$PWD/TheLib

unix:!macx: LIBS += -L$$PWD/TheLib/ -lTheImage

INCLUDEPATH += $$PWD/TheLib
DEPENDPATH += $$PWD/TheLib

unix:!macx: LIBS += -L$$PWD/TheLib/ -lTheLED

INCLUDEPATH += $$PWD/TheLib
DEPENDPATH += $$PWD/TheLib

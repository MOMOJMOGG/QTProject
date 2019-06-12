#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T14:03:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QImageproject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    TheLib/theimage.h



FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/TheLib/ -lTheImage

INCLUDEPATH += $$PWD/TheLib
DEPENDPATH += $$PWD/TheLib

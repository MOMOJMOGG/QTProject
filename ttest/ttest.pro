#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T17:19:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ttest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    bmpstruct.h \
    theimage.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/./ -lTheImage

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

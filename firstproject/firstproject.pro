#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T12:57:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firstproject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ../practice/first_class.h \
    ../Area/area.h

FORMS    += mainwindow.ui

#unix:!macx: LIBS += -L$$PWD/../practice/ -lfirstclass

#INCLUDEPATH += $$PWD/../practice
#DEPENDPATH += $$PWD/../practice

unix:!macx: LIBS += -L$$PWD/../Area/ -lArea

INCLUDEPATH += $$PWD/../Area
DEPENDPATH += $$PWD/../Area

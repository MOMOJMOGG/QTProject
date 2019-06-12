/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_loadimg;
    QPushButton *btn_loadimg_dialog;
    QPushButton *btn_threshold;
    QGraphicsView *graphicsView;
    QPushButton *btn_getbitmap;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_loadimg = new QPushButton(centralWidget);
        btn_loadimg->setObjectName(QStringLiteral("btn_loadimg"));
        btn_loadimg->setGeometry(QRect(20, 20, 99, 27));
        btn_loadimg_dialog = new QPushButton(centralWidget);
        btn_loadimg_dialog->setObjectName(QStringLiteral("btn_loadimg_dialog"));
        btn_loadimg_dialog->setGeometry(QRect(20, 70, 99, 27));
        btn_threshold = new QPushButton(centralWidget);
        btn_threshold->setObjectName(QStringLiteral("btn_threshold"));
        btn_threshold->setGeometry(QRect(20, 120, 99, 27));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(130, 20, 256, 192));
        btn_getbitmap = new QPushButton(centralWidget);
        btn_getbitmap->setObjectName(QStringLiteral("btn_getbitmap"));
        btn_getbitmap->setGeometry(QRect(20, 170, 99, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 220, 361, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_loadimg->setText(QApplication::translate("MainWindow", "Load bmp", 0));
        btn_loadimg_dialog->setText(QApplication::translate("MainWindow", "Load bmp 2", 0));
        btn_threshold->setText(QApplication::translate("MainWindow", "Threshold", 0));
        btn_getbitmap->setText(QApplication::translate("MainWindow", "Get IMG", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_init_cam;
    QPushButton *pushButton_start;
    QPushButton *pushButton_pause;
    QGraphicsView *graphicsView;
    QLabel *label;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_binary;
    QPushButton *pushButton_led;
    QLineEdit *lineEdit_threshold;
    QLineEdit *lineEdit_wd;
    QLineEdit *lineEdit_fov_w;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_fov_h;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_filtersize;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_circle;
    QLabel *label_square;
    QPushButton *pushButton_antiflash;
    QPushButton *pushButton_mirror_h;
    QPushButton *pushButton_mirror_v;
    QPushButton *pushButton_chmod;
    QPushButton *pushButton_softtrigg;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1649, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_init_cam = new QPushButton(centralWidget);
        pushButton_init_cam->setObjectName(QStringLiteral("pushButton_init_cam"));
        pushButton_init_cam->setGeometry(QRect(10, 10, 121, 25));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(10, 40, 121, 25));
        pushButton_pause = new QPushButton(centralWidget);
        pushButton_pause->setObjectName(QStringLiteral("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(10, 70, 121, 25));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(170, 10, 561, 451));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 151, 17));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(880, 10, 561, 451));
        pushButton_binary = new QPushButton(centralWidget);
        pushButton_binary->setObjectName(QStringLiteral("pushButton_binary"));
        pushButton_binary->setGeometry(QRect(10, 120, 41, 25));
        pushButton_led = new QPushButton(centralWidget);
        pushButton_led->setObjectName(QStringLiteral("pushButton_led"));
        pushButton_led->setGeometry(QRect(60, 120, 41, 25));
        lineEdit_threshold = new QLineEdit(centralWidget);
        lineEdit_threshold->setObjectName(QStringLiteral("lineEdit_threshold"));
        lineEdit_threshold->setGeometry(QRect(100, 180, 61, 27));
        lineEdit_wd = new QLineEdit(centralWidget);
        lineEdit_wd->setObjectName(QStringLiteral("lineEdit_wd"));
        lineEdit_wd->setGeometry(QRect(100, 210, 61, 27));
        lineEdit_fov_w = new QLineEdit(centralWidget);
        lineEdit_fov_w->setObjectName(QStringLiteral("lineEdit_fov_w"));
        lineEdit_fov_w->setGeometry(QRect(100, 240, 61, 27));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 220, 71, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 250, 91, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 280, 91, 17));
        lineEdit_fov_h = new QLineEdit(centralWidget);
        lineEdit_fov_h->setObjectName(QStringLiteral("lineEdit_fov_h"));
        lineEdit_fov_h->setGeometry(QRect(100, 270, 61, 27));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 190, 81, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 310, 71, 17));
        lineEdit_filtersize = new QLineEdit(centralWidget);
        lineEdit_filtersize->setObjectName(QStringLiteral("lineEdit_filtersize"));
        lineEdit_filtersize->setGeometry(QRect(100, 300, 61, 27));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 340, 71, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 370, 71, 17));
        label_circle = new QLabel(centralWidget);
        label_circle->setObjectName(QStringLiteral("label_circle"));
        label_circle->setGeometry(QRect(90, 340, 51, 17));
        label_circle->setAlignment(Qt::AlignCenter);
        label_square = new QLabel(centralWidget);
        label_square->setObjectName(QStringLiteral("label_square"));
        label_square->setGeometry(QRect(90, 370, 51, 17));
        label_square->setAlignment(Qt::AlignCenter);
        pushButton_antiflash = new QPushButton(centralWidget);
        pushButton_antiflash->setObjectName(QStringLiteral("pushButton_antiflash"));
        pushButton_antiflash->setGeometry(QRect(110, 120, 41, 25));
        pushButton_mirror_h = new QPushButton(centralWidget);
        pushButton_mirror_h->setObjectName(QStringLiteral("pushButton_mirror_h"));
        pushButton_mirror_h->setGeometry(QRect(30, 150, 41, 25));
        pushButton_mirror_v = new QPushButton(centralWidget);
        pushButton_mirror_v->setObjectName(QStringLiteral("pushButton_mirror_v"));
        pushButton_mirror_v->setGeometry(QRect(90, 150, 41, 25));
        pushButton_chmod = new QPushButton(centralWidget);
        pushButton_chmod->setObjectName(QStringLiteral("pushButton_chmod"));
        pushButton_chmod->setGeometry(QRect(10, 400, 61, 27));
        pushButton_softtrigg = new QPushButton(centralWidget);
        pushButton_softtrigg->setObjectName(QStringLiteral("pushButton_softtrigg"));
        pushButton_softtrigg->setGeometry(QRect(80, 400, 61, 27));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_init_cam->setText(QApplication::translate("MainWindow", "Initial Camera", 0));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start Capture", 0));
        pushButton_pause->setText(QApplication::translate("MainWindow", "Pause Capture", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_binary->setText(QApplication::translate("MainWindow", "B", 0));
        pushButton_led->setText(QApplication::translate("MainWindow", "L", 0));
        label_2->setText(QApplication::translate("MainWindow", "WD(mm) :", 0));
        label_3->setText(QApplication::translate("MainWindow", "FOV W(mm):", 0));
        label_4->setText(QApplication::translate("MainWindow", "FOV H(mm):", 0));
        label_5->setText(QApplication::translate("MainWindow", "Threshold :", 0));
        label_6->setText(QApplication::translate("MainWindow", "filtersize :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Cir Num :", 0));
        label_8->setText(QApplication::translate("MainWindow", "Sqr Num :", 0));
        label_circle->setText(QApplication::translate("MainWindow", "0", 0));
        label_square->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_antiflash->setText(QApplication::translate("MainWindow", "F", 0));
        pushButton_mirror_h->setText(QApplication::translate("MainWindow", "<>", 0));
        pushButton_mirror_v->setText(QApplication::translate("MainWindow", "^v", 0));
        pushButton_chmod->setText(QApplication::translate("MainWindow", "chmod", 0));
        pushButton_softtrigg->setText(QApplication::translate("MainWindow", "trigg", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

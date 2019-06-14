#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "theimage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    TheImage *g_img = new TheImage();
    //double str_t, end_t;
    QTime timedebug;
    g_img->LoadBMPfile("lenaaa.bmp");
    RLEtable *theblob;
    ItemInfo *theit,*themm;
    timedebug.start();
    theblob = g_img->BuildRLE(200);
    qDebug() << "Build " << timedebug.elapsed() << "ms";
    g_img->ClearBlob(theblob);
/*
    theit = g_img->GetInfoFromBlob(theblob, 1);
    ui->listWidget->addItem("<<ITM Head Size :"+QString::number(theit->targetNum)  +">>\n");
    qDebug() << "Build+Get " <<timedebug.elapsed() << "ms";
    themm = theit;
    themm = themm->next;
    while(themm != NULL)
    {
       ui->listWidget->addItem("<<[xmin:( "+QString::number(themm->points[0].x)+","+QString::number(themm->points[0].y)  +")]");
       ui->listWidget->addItem("<<[ymin:( "+QString::number(themm->points[1].x)+","+QString::number(themm->points[1].y)  +")]");
       ui->listWidget->addItem("<<[xmax:( "+QString::number(themm->points[2].x)+","+QString::number(themm->points[2].y)  +")]");
       ui->listWidget->addItem("<<[ymax:( "+QString::number(themm->points[3].x)+","+QString::number(themm->points[3].y)  +")]");
       ui->listWidget->addItem("");
        themm = themm->next;
    }


    g_img->CleanItem(theit);
*/


    //g_img->CleanItem(theit);
    //ui->listWidget->addItem("Blob Num:" + QString::number(theblob->beside->Index) +
    //                      "Size: " + QString::number(theblob->beside->Ypos));

    qDebug() << "Build+Get+clean "<<timedebug.elapsed() << "ms";
    //ui->listWidget->addItem("Build Time: " + QString::number((end_t - str_t)) + "ms");
}

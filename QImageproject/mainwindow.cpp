#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    g_img_obj = new TheImage();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete g_img;
}

void MainWindow::on_btn_loadimg_clicked()
{
    QString filename = "lena.bmp";
    g_img = new QImage(filename,"BMP");

    ui->graphicsView->setFixedHeight(g_img->height());
    ui->graphicsView->setFixedWidth(g_img->width());

    QPixmap pixmap = QPixmap::fromImage(*g_img);

    scene->clear();
    scene->setSceneRect(0,0,g_img->width(),g_img->height());
    scene->addPixmap(pixmap);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();


}

void MainWindow::on_btn_loadimg_dialog_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open image name",".",
                                                    "Image file (*.bmp);;All Files(*.*)");



    if(fileName != "")
    {
        QByteArray filebyte = fileName.toLocal8Bit();
        char *filename = filebyte.data();

        g_img = new QImage(filename);

        ui->graphicsView->setFixedHeight(g_img->height());
        ui->graphicsView->setFixedWidth(g_img->width());

        QPixmap pixmap = QPixmap::fromImage(*g_img);

        scene->clear();
        scene->setSceneRect(0,0,g_img->width(),g_img->height());
        scene->addPixmap(pixmap);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
    }

}

void MainWindow::on_btn_threshold_clicked()
{
    int wid = g_img->width();
    int hei = g_img->height();

    QImage grayImg;

    QVector<QRgb> table;
    for(int i=0;i<256;i++)
        table.push_back(qRgb(i,i,i));

    grayImg = g_img->convertToFormat(QImage::Format_Grayscale8, table);

    uchar *data;
    for(int i=0;i<hei;i++)
    {
        data = grayImg.scanLine(i);
        for(int j=0;j<wid;j++)
        {
            int value = data[j];
            if(value > 128)
                data[j] = 255;
            else
                data[j] = 0;
        }
    }

    QPixmap pixmap = QPixmap::fromImage(grayImg);

    scene->clear();
    scene->setSceneRect(0,0,grayImg.width(),grayImg.height());
    scene->addPixmap(pixmap);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::on_btn_getbitmap_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,"open image name",".",
                                                    "Image file (*.bmp);;All Files(*.*)");

    QByteArray ba = fileName.toLocal8Bit();
    const char *f_name = ba.data();
    g_img_obj->LoadBMPfile(f_name);
    ui->label->setText("Img Width: " + QString::number(g_img_obj->GetImgWidth()) + " Img Height : " + QString::number(g_img_obj->GetImgHeight()));

    QString fileName1 = QFileDialog::getSaveFileName(this,"save image name",".",
                                                    "Image file (*.bmp);;All Files(*.*)");

    ba = fileName1.toLocal8Bit();
    f_name = ba.data();
    g_img_obj->SaveImage(f_name);

    unsigned char *toqimg = g_img_obj->GetReverse();


    QImage img(toqimg, g_img_obj->GetImgWidth(), g_img_obj->GetImgHeight(), QImage::Format_Indexed8);
    QVector<QRgb> table;
    GetColorTable(&table,g_img_obj);
    img.setColorTable(table);

    ui->graphicsView->setFixedHeight(g_img_obj->GetImgHeight());
    ui->graphicsView->setFixedWidth(g_img_obj->GetImgWidth());
    QPixmap pixmap = QPixmap::fromImage(img);

    scene->clear();
    scene->setSceneRect(0,0,img.width(),img.height());
    scene->addPixmap(pixmap);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();



}

void MainWindow::GetColorTable(QVector<QRgb> *thetable, TheImage *imgclass)
{
    unsigned char *therawtable = imgclass->GetColorTable();
    int r,g,b,rv;
    int batchsize = 256*4;
    for(int i =0;i<batchsize;)
    {
        b = *(therawtable + i);
        g = *(therawtable + i + 1);
        r = *(therawtable + i + 2);
        rv = *(therawtable + i + 3);
        i=i+4;
        thetable->push_back(qRgb(r,g,b));
        qDebug() << r << g<<b<<rv;
    }
}



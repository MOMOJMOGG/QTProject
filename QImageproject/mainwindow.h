#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "theimage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    QImage *g_img;
    TheImage *g_img_obj;

    void GetColorTable(QVector<QRgb> *thetable, TheImage *imgclass);

private slots:
    void on_btn_loadimg_clicked();

    void on_btn_loadimg_dialog_clicked();

    void on_btn_threshold_clicked();

    void on_btn_getbitmap_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

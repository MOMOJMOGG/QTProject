#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include <QMutex>
#include <QGraphicsScene>

#include "CameraDefine.h"
#include "capturethread.h"

#include "theimage.h"
#include "imgprocessthread.h"
#include "ledthread.h"

typedef struct _cam_param
{
    int                     hCamera = -1;
    unsigned char           *pRawBuffer=NULL;
    unsigned char           *pRgbBuffer=NULL;

    tSdkFrameHead           tFrameHead;
    tSdkCameraCapbility     tCapability;

    int                     wid;
    int                     hei;
    long                    bufferSize;
    unsigned char           *rawBuffer=NULL;
}cam_param;


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
    QGraphicsScene *scene2;

    QMutex mutex_cam_param;

    int Init_Cam();
    void Uninit_Cam();

    QThread         *controlThread;
    CaptureThread   *myCaptureThread;

    //QThread          *controlProssThread;
    //imgprocessthread *imgProssThread;

    QThread          *controlLEDThread;
    LedThread        *ledThread;

    QPen             *thepen;
    QGraphicsTextItem *tx;
    QFont             *font;
signals:
    void circle_cmd(int tar);
    void square_cmd(int tar);
private slots:
    void on_pushButton_init_cam_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_pause_clicked();

    void slot_handleCaputred(QImage img);
    void slot_handleCaputred2(QImage img, ItemInfo *rct);

    void on_lineEdit_threshold_textChanged(const QString &arg1);

    void on_lineEdit_wd_textChanged(const QString &arg1);

    void on_lineEdit_fov_w_textChanged(const QString &arg1);

    void on_lineEdit_fov_h_textChanged(const QString &arg1);

    void on_lineEdit_filtersize_textChanged(const QString &arg1);

    void on_pushButton_led_clicked();

    void on_pushButton_antiflash_clicked();

    void on_pushButton_mirror_h_clicked();

    void on_pushButton_mirror_v_clicked();

    void on_pushButton_binary_clicked();

    void on_pushButton_chmod_clicked();

    void on_pushButton_softtrigg_clicked();

    void update_circle(int tar);
    void update_square(int tar);
//    void cap_to_suspend();
//    void cap_to_resume();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

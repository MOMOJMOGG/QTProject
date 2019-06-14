#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#include "CameraDefine.h"
#include "CameraStatus.h"
#include "CameraApi.h"
#include "capturethread.h"

#include <QDebug>

cam_param g_cam;
TheImage *g_img_ = new TheImage();
bool mirror_h = true;
bool mirror_v = true;
BOOL anti = true;

bool g_threshold_flag=false;
int g_threshold = 127;
QMutex g_mutex;
QWaitCondition g_waitprocess;
QWaitCondition g_waitcopy;
bool prfinish_flag = false;

int lednum1=0;
int lednum2=0;
bool g_led_flag=false;

double g_fov_w = 144; // 144 mm
double g_fov_h = 108; // 108 mm
double g_wd = 360; // 360 mm
double g_focal = 12; // 12 mm
double g_x_ratio = g_fov_w/g_wd*g_focal/752; // mm
double g_y_ratio = g_fov_h/g_wd*g_focal/480; // mm
int g_filtersize=50;
int cam_mode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene2 = new QGraphicsScene();
    ui->graphicsView_2->setScene(scene2);

    controlThread = new QThread;  //contorll thread
    myCaptureThread = new CaptureThread; //work thread

    myCaptureThread->moveToThread(controlThread);    // move object based thread to controll thread
    connect(controlThread,SIGNAL(finished()),controlThread,SLOT(deleteLater()));   //finish and delete
    connect(controlThread,SIGNAL(started()),myCaptureThread,SLOT(slot_startThread()));
    connect(myCaptureThread,SIGNAL(captured(QImage)), this, SLOT(slot_handleCaputred(QImage)));
    connect(myCaptureThread,SIGNAL(captured2(QImage)),this, SLOT(slot_handleCaputred2(QImage)));

    controlProssThread = new QThread;  //controll thread
    imgProssThread = new imgprocessthread; //work thread

    imgProssThread->moveToThread(controlProssThread);
    connect(controlProssThread,SIGNAL(finished()),controlProssThread,SLOT(deleteLater()));
    connect(controlProssThread,SIGNAL(started()),imgProssThread,SLOT(slot_startThread()));
    connect(imgProssThread, SIGNAL(processed(QImage)), this, SLOT(slot_handleCaputred2(QImage)));
    connect(imgProssThread, SIGNAL(cmd_resume_cap()),this, SLOT(cap_to_resume()));
    connect(imgProssThread, SIGNAL(cmd_suspend_cap()),this, SLOT(cap_to_suspend()));

    controlLEDThread = new QThread; // controll thread
    ledThread = new LedThread; // work thread

    ledThread->moveToThread(controlLEDThread);
    connect(controlLEDThread, SIGNAL(finished()), controlLEDThread,SLOT(deleteLater()));
    connect(controlLEDThread,SIGNAL(started()),ledThread, SLOT(slot_startThread()));


    ui->lineEdit_threshold->setText(QString::number(g_threshold));
    ui->lineEdit_wd->setText(QString::number(g_wd));
    ui->lineEdit_fov_w->setText(QString::number(g_fov_w));
    ui->lineEdit_fov_h->setText(QString::number(g_fov_h));
    ui->lineEdit_filtersize->setText(QString::number(g_filtersize));

    ui->label_circle->setText(QString::number(lednum1));
    ui->label_square->setText(QString::number(lednum2));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete scene2;

    if(controlThread->isRunning())
    {
        myCaptureThread->closeThread();  //close thread slot
        controlThread->quit();        //break from event loop
        controlThread->wait();        //release resource slot
    }

    if(controlProssThread->isRunning())
    {
        imgProssThread->closeThread();
        controlProssThread->quit();
        controlProssThread->wait();
    }

    if(controlLEDThread->isRunning())
    {
        ledThread->closeThread();
        controlLEDThread->quit();
        controlLEDThread->wait();
    }

    Uninit_Cam();

    delete controlThread;
    delete myCaptureThread;
    delete controlProssThread;
    delete imgProssThread;
    delete controlLEDThread;
    delete ledThread;
}

void MainWindow::on_pushButton_init_cam_clicked()
{
    if(g_cam.hCamera != -1)
        return;

    int err = Init_Cam();

    if(err == 0)
    {
        controlThread->start();  //open thread slot
        ui->graphicsView->setFixedSize(g_cam.wid + 4, g_cam.hei + 4);
        ui->graphicsView_2->setFixedSize(g_cam.wid + 4, g_cam.hei + 4);
        controlProssThread->start();
        controlLEDThread->start();
    }

    if(err == 0)
        ui->label->setText("Init Cam OK");
    else
        ui->label->setText("Init Cam NG");
}

int MainWindow::Init_Cam()
{
    int                     iCameraCounts = 1;
    int                     iStatus=-1;
    tSdkCameraDevInfo       tCameraEnumList[1];

    //sdk初始化  0 English 1中文
    CameraSdkInit(1);

    //列舉設備並建立清單
    CameraEnumerateDevice(tCameraEnumList,&iCameraCounts);

    //沒有找到設備
    if(iCameraCounts==0){
        return -1;
    }

    //相機初始化,初始化後才能使用相機操作函式
    iStatus = CameraInit(&tCameraEnumList[0],-1,-1,&g_cam.hCamera);

    //如果初始化失敗
    if(iStatus!=CAMERA_STATUS_SUCCESS){
        return -1;
    }

    //獲得相機特性參數結構
    CameraGetCapability(g_cam.hCamera,&g_cam.tCapability);

    g_cam.pRgbBuffer = (unsigned char*)malloc(g_cam.tCapability.sResolutionRange.iHeightMax*g_cam.tCapability.sResolutionRange.iWidthMax*3);
    g_cam.rawBuffer = (unsigned char*)malloc(g_cam.tCapability.sResolutionRange.iHeightMax*g_cam.tCapability.sResolutionRange.iWidthMax*3);

    //設置圖像輸出格式
    if(g_cam.tCapability.sIspCapacity.bMonoSensor)
        CameraSetIspOutFormat(g_cam.hCamera,CAMERA_MEDIA_TYPE_MONO8);

    g_cam.wid = g_cam.tCapability.sResolutionRange.iWidthMax;
    g_cam.hei = g_cam.tCapability.sResolutionRange.iHeightMax;
    g_cam.bufferSize = sizeof(unsigned char) * g_cam.wid * g_cam.hei;

    g_img_->SetImgWidth(g_cam.wid);
    g_img_->SetImgHeight(g_cam.hei);
    g_img_->SetBMPInfo(g_img_->GetImgWidth(),g_img_->GetImgHeight());
    g_img_->SetRawSize(g_cam.wid * g_cam.hei);
    CameraGetTriggerMode(g_cam.hCamera, &cam_mode);
    //qDebug() << g_cam.wid;
    //qDebug() << g_cam.hei;

    return 0;
}

void MainWindow::Uninit_Cam()
{
    if(g_cam.rawBuffer!=NULL){
        free(g_cam.rawBuffer);
        g_cam.rawBuffer=NULL;
    }

    if(g_cam.pRgbBuffer!=NULL){
        free(g_cam.pRgbBuffer);
        g_cam.pRgbBuffer=NULL;
    }

    if(g_cam.hCamera>0){
        //相機反初始化,釋放資源
        CameraUnInit(g_cam.hCamera);
        g_cam.hCamera=-1;
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    if(g_cam.hCamera == -1)
        return;

    /*讓相機進入工作模式，開始接收相機所擷取到的資料數據。
    如果當下是觸發模式則需要接收到觸發訊號後才會更新資料*/
    CameraPlay(g_cam.hCamera);

    ui->label->setText("CameraPlay");
    ui->pushButton_pause->setStyleSheet("color : black;"
                                            "background-color : white;");
}

void MainWindow::on_pushButton_pause_clicked()
{
    if(g_cam.hCamera == -1)
        return;

    CameraPause(g_cam.hCamera);

    ui->label->setText("CameraPause");
    ui->pushButton_pause->setStyleSheet("color : white;"
                                            "background-color : red;");
}

void MainWindow::slot_handleCaputred(QImage img)
{
    QPixmap pixmap = QPixmap::fromImage(img);

    scene->clear();
    scene->setSceneRect(0,0,img.width(),img.height());
    scene->addPixmap(pixmap);
}

void MainWindow::slot_handleCaputred2(QImage img)
{
    QPixmap pixmap = QPixmap::fromImage(img); 

    scene2->clear();
    scene2->setSceneRect(0,0,img.width(),img.height());
    scene2->addPixmap(pixmap);
}


void MainWindow::on_lineEdit_threshold_textChanged(const QString &arg1)
{
    g_threshold = arg1.toInt();
}

void MainWindow::on_lineEdit_wd_textChanged(const QString &arg1)
{
    g_wd = arg1.toDouble();
}

void MainWindow::on_lineEdit_fov_w_textChanged(const QString &arg1)
{
    g_fov_w = arg1.toDouble();
}

void MainWindow::on_lineEdit_fov_h_textChanged(const QString &arg1)
{
    g_fov_h = arg1.toDouble();
}

void MainWindow::on_lineEdit_filtersize_textChanged(const QString &arg1)
{
    g_filtersize = arg1.toInt();
}

void MainWindow::on_pushButton_led_clicked()
{
    g_led_flag = !g_led_flag;
    if(g_led_flag)
        ui->pushButton_led->setStyleSheet("color : black;"
                                                "background-color : green;");
    else
        ui->pushButton_led->setStyleSheet("color : black;"
                                                "background-color : white;");
}

void MainWindow::on_pushButton_antiflash_clicked()
{
    CameraSetAntiFlick(g_cam.hCamera, anti);
    if(anti)
        ui->pushButton_antiflash->setStyleSheet("color : black;"
                                                "background-color : green;");
    else
        ui->pushButton_antiflash->setStyleSheet("color : black;"
                                                "background-color : white;");
    anti = !anti;
}

void MainWindow::on_pushButton_mirror_h_clicked()
{
    CameraSetMirror(g_cam.hCamera, 0, mirror_h);
    if(mirror_h)
        ui->pushButton_mirror_h->setStyleSheet("color : black;"
                                                "background-color : green;");
    else
        ui->pushButton_mirror_h->setStyleSheet("color : black;"
                                                "background-color : white;");
    mirror_h = !mirror_h;
}

void MainWindow::on_pushButton_mirror_v_clicked()
{
    CameraSetMirror(g_cam.hCamera, 1, mirror_v);
    if(mirror_v)
        ui->pushButton_mirror_v->setStyleSheet("color : black;"
                                                "background-color : green;");
    else
        ui->pushButton_mirror_v->setStyleSheet("color : black;"
                                                "background-color : white;");
    mirror_v = !mirror_v;
}

void MainWindow::on_pushButton_binary_clicked()
{
    g_threshold_flag = !g_threshold_flag;
    if(g_threshold_flag)
        ui->pushButton_binary->setStyleSheet("color : black;"
                                                "background-color : green;");
    else
        ui->pushButton_binary->setStyleSheet("color : black;"
                                                "background-color : white;");
}

void MainWindow::on_pushButton_chmod_clicked()
{
    if(cam_mode == 0)
    {
        cam_mode = 1;
        CameraSetTriggerMode(g_cam.hCamera, cam_mode);
    }
    else
    {
        cam_mode = 0;
        CameraSetTriggerMode(g_cam.hCamera, cam_mode);
    }
}
void MainWindow::on_pushButton_softtrigg_clicked()
{
    if(cam_mode == 1)
    {
        CameraSoftTrigger(g_cam.hCamera);
    }
}

void MainWindow::cap_to_resume()
{
    myCaptureThread->resume();
}

void MainWindow::cap_to_suspend()
{
    myCaptureThread->suspend();
}

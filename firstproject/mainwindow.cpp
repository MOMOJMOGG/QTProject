#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "first_class.h"
#include "area.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(send_signalDemo()),this,SLOT(receive_signalDemo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Hello QT");
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString input_string = ui->lineEdit->text();
    ui->label->setText(input_string);
}

void MainWindow::on_pushButton_2_clicked()
{
    emit send_signalDemo();
}

void MainWindow::receive_signalDemo()
{
    ui->label->setText("Hello QT from signal!");
}

void MainWindow::on_pushButton_3_clicked()
{
    //Area_Calculator *calculator = new Area_Calculator();
    Area *calculator = new Area();
    calculator->SetTriangleParam(4,4);
    double triangle = calculator->GetTriangleArea();

    ui->label->setText("Triangle Area : " + QString::number(triangle));

    delete calculator;
}

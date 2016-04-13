#include "mainwindow.h"
#include "ui_mainwindow.h"

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

//Handle when the captureButton is clicked
void MainWindow::on_captureButton_clicked()
{
    if(ui->statusLabel->text() == "Status: IDLE"){
        ui->statusLabel->setText("Status: CAPTURING");
        ui->captureButton->setText("Stop");
        //INITIATE CAPTURE HERE
    } else {
        ui->statusLabel->setText("Status: IDLE");
        ui->captureButton->setText("Capture");
        //STOP CAPTURE HERE
    }
}

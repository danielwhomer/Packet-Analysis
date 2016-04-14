#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();
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
        startCapture();
    } else {
        ui->statusLabel->setText("Status: IDLE");
        ui->captureButton->setText("Capture");
        //STOP CAPTURE HERE
        stopCapture();
    }
}

void MainWindow::exit()
{
  qApp->exit();
}

void MainWindow::startCapture()
{

}
void MainWindow::stopCapture(){}
void MainWindow::saveCapture(){}


void MainWindow::createActions()
{
    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setStatusTip(tr("Exit Appliction"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::exit);

    startAct = new QAction(tr("&Start"), this);
    startAct->setStatusTip(tr("Begin capturing packets on the local network"));
    connect(startAct, &QAction::triggered, this, &MainWindow::startCapture);

    stopAct = new QAction(tr("&Stop"), this);
    stopAct->setStatusTip(tr("Stop capturing packets on the local network"));
    connect(stopAct, &QAction::triggered, this, &MainWindow::stopCapture);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setStatusTip(tr("Save the captured packets to this machine."));
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveCapture);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);

    captureMenu = menuBar()->addMenu(tr("&Capture"));
    captureMenu->addAction(startAct);
    captureMenu->addAction(stopAct);
    captureMenu->addAction(saveAct);

}

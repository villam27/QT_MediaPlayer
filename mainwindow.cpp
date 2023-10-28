#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _video = new QVideoWidget(this);
    _video->setGeometry(20, 20, WIN_WIDTH - 40, WIN_HEIGHT - 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _video = new QVideoWidget(this);
    _video->setGeometry(20, 30, WIN_WIDTH - 40, WIN_HEIGHT - 100);

    _menuBar = new CustomMenuBar(this);
    setMenuBar(_menuBar);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _video;
    delete _menuBar;
}


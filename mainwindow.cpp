#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget(this);
    _layout = new QVBoxLayout(centralWidget);
    _video = new QVideoWidget(this);
    _menuBar = new CustomMenuBar(this);

    setCentralWidget(centralWidget);
    _video->setGeometry(20, 30, WIN_WIDTH - 40, WIN_HEIGHT - 100);
    _mediaPlayerButton = new MediaPlayerButton(this);

    _layout->setMenuBar(_menuBar);
    _layout->addWidget(_video);
    _layout->addWidget(_mediaPlayerButton, 0, Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _video;
    delete _menuBar;
    delete _mediaPlayerButton;
    delete _layout;
}


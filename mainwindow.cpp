#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget(this);
    _layout = new QVBoxLayout(centralWidget);
    _video = new QVideoWidget(this);
    _menuBar = new CustomMenuBar(this);
    _videoSlider = new QSlider(Qt::Horizontal, this);
    _mediaPlayerButton = new MediaPlayerButton(this);
    _player = new QMediaPlayer(this);

    setCentralWidget(centralWidget);
    _video->setGeometry(20, 30, WIN_WIDTH - 40, WIN_HEIGHT - 100);
    _player->setVideoOutput(_video);
    //_videoSlider->setRange(0, _player->duration() / 1000);
    _videoSlider->setFixedWidth(WIN_WIDTH - 40);
    _menuBar->setMediaPlayer(_player);
    _mediaPlayerButton->setMediaPlayer(_player);

    connect(_player, &QMediaPlayer::mediaStatusChanged
                   , this, &MainWindow::onMediaStatusChanged);
    connect(_player, &QMediaPlayer::playbackStateChanged
                   , this, &MainWindow::onPlaybackStateChanged);

    _layout->setMenuBar(_menuBar);
    _layout->addWidget(_video);
    _layout->addWidget(_videoSlider, 0, Qt::AlignHCenter);
    _layout->addWidget(_mediaPlayerButton, 0, Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _video;
    delete _menuBar;
    delete _mediaPlayerButton;
    delete _layout;
    delete _player;
    delete _videoSlider;
}

// Slots

void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::LoadedMedia)
        _player->play();
}

void MainWindow::onPlaybackStateChanged(QMediaPlayer::PlaybackState state)
{
    std::cout << "Changed playback state "
              << QString::number(state).toStdString()
              << std::endl;
}

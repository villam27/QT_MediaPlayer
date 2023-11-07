#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget(this);
    _layout = new QVBoxLayout(centralWidget);
    _layout->setContentsMargins(0, 0, 0, 0);
    _video = new QVideoWidget(this);
    _audio = new QAudioOutput;
    _menuBar = new CustomMenuBar(this);
    _videoSlider = new QSlider(Qt::Horizontal, this);
    _mediaPlayerButton = new MediaPlayerButton(this);
    _player = new QMediaPlayer;

    setCentralWidget(centralWidget);
    _video->setGeometry(0, 0, WIN_WIDTH, WIN_HEIGHT - 100);
    _player->setVideoOutput(_video);
    _player->setAudioOutput(_audio);
    _videoSlider->setFixedWidth(WIN_WIDTH - 40);
    _videoSlider->setTracking(true);
    _videoSlider->setTickInterval(1);
    _videoSlider->setTickPosition(QSlider::TicksBelow);
    _videoSlider->setDisabled(true);
    _menuBar->setMediaPlayer(_player);
    _mediaPlayerButton->setMediaPlayer(_player);
    _mediaPlayerButton->setAudioOutput(_audio);
    _audio->setVolume(1);

    connect(_player, &QMediaPlayer::mediaStatusChanged
                   , this, &MainWindow::onMediaStatusChanged);
    connect(_player, &QMediaPlayer::playbackStateChanged
                   , this, &MainWindow::onPlaybackStateChanged);
    connect(_player, &QMediaPlayer::positionChanged
                   , this, &MainWindow::onPositionChanged);
    connect(_videoSlider, &QSlider::sliderMoved
                        , this, &MainWindow::onValueChanged);

    _layout->setMenuBar(_menuBar);
    _layout->addWidget(_video);
    _layout->addWidget(_videoSlider, 0, Qt::AlignHCenter);
    _layout->addWidget(_mediaPlayerButton, 0, Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _video;
    delete _audio;
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
    {
        _videoSlider->setDisabled(false);
        _player->setPosition(0);
        _player->play();
        _videoSlider->setRange(0, _player->duration() / 1000);
    }
}

void MainWindow::onPlaybackStateChanged(QMediaPlayer::PlaybackState state)
{
    std::cout << "Changed playback state "
              << QString::number(state).toStdString()
              << std::endl;
}

void MainWindow::onPositionChanged(qint64 position)
{
    _videoSlider->setValue(position / 1000);
}

void MainWindow::onValueChanged(int value)
{
    _player->setPosition(value * 1000);
}

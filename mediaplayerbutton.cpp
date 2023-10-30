#include "mediaplayerbutton.h"
#include <iostream>

MediaPlayerButton::MediaPlayerButton(QWidget *parent) : QWidget(parent)
{
    _layout = new QHBoxLayout(this);
    _layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(_layout);

    _audio = nullptr;
    _player = nullptr;
    _prevButton = new QPushButton("Prev", this);
    _backButton = new QPushButton("<< 10", this);
    _stopButton = new QPushButton("Stop", this);
    _pauseButton = new QPushButton("Pause", this);
    _forwardButton = new QPushButton("10 >>", this);
    _nextButton = new QPushButton("Next", this);

    _audioSlider = new QSlider(Qt::Horizontal, this);
    _audioSlider->setRange(0, 100);
    _audioSlider->setValue(100);

    connect(_audioSlider, &QSlider::sliderMoved
            , this, &MediaPlayerButton::OnAudioSliderValueChanged);
    connectButton();

    _layout->addWidget(_prevButton);
    _layout->addWidget(_backButton);
    _layout->addWidget(_stopButton);
    _layout->addWidget(_pauseButton);
    _layout->addWidget(_forwardButton);
    _layout->addWidget(_nextButton);
    _layout->addWidget(_audioSlider);
}

MediaPlayerButton::~MediaPlayerButton()
{}

void MediaPlayerButton::connectButton()
{
    connect(_prevButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnPrevButtonClicked);
    connect(_backButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnBackButtonClicked);
    connect(_stopButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnStopButtonClicked);
    connect(_pauseButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnPauseButtonClicked);
    connect(_forwardButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnForwardButtonClicked);
    connect(_nextButton, &QPushButton::clicked
            , this, &MediaPlayerButton::OnNextButtonClicked);
}

void MediaPlayerButton::setMediaPlayer(QMediaPlayer *player)
{
    _player = player;
}

void MediaPlayerButton::setAudioOutput(QAudioOutput *audio)
{
    _audio = audio;
}

// Slots

void MediaPlayerButton::OnPrevButtonClicked()
{
    //_player->pause();
    _player->setPosition(0);
}

void MediaPlayerButton::OnBackButtonClicked()
{
    _player->setPosition(_player->position() - 10000);
}

void MediaPlayerButton::OnStopButtonClicked()
{
    _player->pause();
    _player->setPosition(0);
}

void MediaPlayerButton::OnPauseButtonClicked()
{
    if (_player->isPlaying())
        _player->pause();
    else
        _player->play();
}

void MediaPlayerButton::OnForwardButtonClicked()
{
    _player->setPosition(_player->position() + 10000);
}

void MediaPlayerButton::OnNextButtonClicked()
{
    //_player->pause();
    _player->setPosition(_player->duration());
}

void MediaPlayerButton::OnAudioSliderValueChanged(int value)
{
    std::cout << value << std::endl;
    if (_audio)
        _audio->setVolume((float)value / 100.0f);
}

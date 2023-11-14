#include "mediaplayerbutton.h"
#include <iostream>

MediaPlayerButton::MediaPlayerButton(QWidget *parent) : QWidget(parent)
{
    QPixmap pixmap("://assets/play.svg");
    _playIcon.addPixmap(pixmap);
    pixmap.load("://assets/pause.svg");
    _pauseIcon.addPixmap(pixmap);

    _layout = new QHBoxLayout(this);
    _layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(_layout);

    _audio = nullptr;
    _player = nullptr;
    _prevButton = createButton("://assets/prev.svg", 35, 35);
    _backButton = createButton("://assets/b_rewind.svg", 40, 40);
    _stopButton = createButton("://assets/stop.svg");
    _pauseButton = createButton("://assets/pause.svg");
    _forwardButton = createButton("://assets/f_rewind.svg", 40, 40);
    _nextButton = createButton("://assets/next.svg", 35, 35);
    _soundButton = createButton("://assets/sound.svg", 35, 35);

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
    _layout->addSpacing(50);
    _layout->addWidget(_soundButton);
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

QPushButton *MediaPlayerButton::createButton(const QString &path, int w, int h)
{
    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    QPushButton *button = new QPushButton("", this);
    button->setIcon(ButtonIcon);
    button->setIconSize(QSize(w, h));
    return button;
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
    {
        _pauseButton->setIcon(_playIcon);
        _player->pause();
    }
    else
    {
        _pauseButton->setIcon(_pauseIcon);
        _player->play();
    }
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
    if (_audio)
        _audio->setVolume((float)value / 100.0f);
}

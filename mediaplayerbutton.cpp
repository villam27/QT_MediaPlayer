#include "mediaplayerbutton.h"
#include <iostream>

MediaPlayerButton::MediaPlayerButton(QWidget *parent) : QWidget(parent)
{
    _layout = new QHBoxLayout(this);
    _layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(_layout);

    _prevButton = createQuickWidget("Prev");
    _backButton = createQuickWidget("<< 10");
    _stopButton = createQuickWidget("Stop");
    _pauseButton = createQuickWidget("Pause");
    _forwardButton = createQuickWidget("10 >>");
    _nextButton = createQuickWidget("Next");

    connectButton();

    _layout->addWidget(_prevButton);
    _layout->addWidget(_backButton);
    _layout->addWidget(_stopButton);
    _layout->addWidget(_pauseButton);
    _layout->addWidget(_forwardButton);
    _layout->addWidget(_nextButton);
}

MediaPlayerButton::~MediaPlayerButton()
{}

void MediaPlayerButton::setMediaPlayer(QMediaPlayer *player)
{
    _player = player;
}

void MediaPlayerButton::connectButton()
{
    connect(_prevButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnPauseButtonClicked()));
    connect(_backButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnBackButtonClicked()));
    connect(_stopButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnStopButtonClicked()));
    connect(_pauseButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnPauseButtonClicked()));
    connect(_forwardButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnForwardButtonClicked()));
    connect(_nextButton->rootObject(), SIGNAL(onButtonClicked())
            , this, SLOT(OnNextButtonClicked()));
}

QQuickWidget *MediaPlayerButton::createQuickWidget(QVariant customText)
{
    QQuickWidget *quickWidget = new QQuickWidget(this);
    quickWidget->setSource(QUrl("qrc:/custombutton.qml"));
    quickWidget->rootObject()->setProperty("customText", customText);
    return quickWidget;
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

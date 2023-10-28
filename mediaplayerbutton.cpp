#include "mediaplayerbutton.h"

MediaPlayerButton::MediaPlayerButton(QWidget *parent) : QWidget(parent)
{
    _layout = new QHBoxLayout(this);
    _layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(_layout);

    _prevButton = new QPushButton("Prev", this);
    _backButton = new QPushButton("<< 10", this);
    _stopButton = new QPushButton("Stop", this);
    _pauseButton = new QPushButton("Pause", this);
    _forwardButton = new QPushButton("10 >>", this);
    _nextButton = new QPushButton("Next", this);

    _layout->addWidget(_prevButton);
    _layout->addWidget(_backButton);
    _layout->addWidget(_stopButton);
    _layout->addWidget(_pauseButton);
    _layout->addWidget(_forwardButton);
    _layout->addWidget(_nextButton);
}

MediaPlayerButton::~MediaPlayerButton()
{}

#include "custommenubar.h"
#include <iostream>

CustomMenuBar::CustomMenuBar(QWidget *parent) : QMenuBar(parent)
{
    (void)parent;
    addMenus();
    setupFileMenu();
    setupMediaMenu();
    _player = NULL;
}

CustomMenuBar::~CustomMenuBar()
{
    delete _fileMenu;
    delete _mediaMenu;
    delete _speedMenu;
    delete _audioMenu;
    delete _videoMenu;
    delete _openAction;
    delete _openMultipleAction;
    delete _openFolderAction;
    delete _normalSpeedAction;
    delete _fastSpeedAction;
    delete _slowSpeedAction;
    delete _pauseAction;
    delete _stopAction;
    delete _prevAction;
    delete _nextAction;
    delete _prevFrameAction;
    delete _nextFrameAction;
}

void CustomMenuBar::setMediaPlayer(QMediaPlayer *player)
{
    _player = player;
}

void CustomMenuBar::addMenus()
{
    _fileMenu = addMenu("File");
    _mediaMenu = addMenu("Media");
    _audioMenu = addMenu("Audio");
    _videoMenu = addMenu("Video");
}

void CustomMenuBar::setupFileMenu()
{
    _openAction = new QAction("Open", this);
    _openAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    connect(_openAction, &QAction::triggered, this, &CustomMenuBar::load);
    _fileMenu->addAction(_openAction);
    _openMultipleAction = new QAction("Open Multiple", this);
    _openMultipleAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));
    connect(_openMultipleAction, &QAction::triggered, this, &CustomMenuBar::loadMultiple);
    _fileMenu->addAction(_openMultipleAction);
    _openFolderAction = new QAction("Open Folder", this);
    _openFolderAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F));
    connect(_openFolderAction, &QAction::triggered, this, &CustomMenuBar::loadFolder);
    _fileMenu->addAction(_openFolderAction);
}

void CustomMenuBar::setupMediaMenu()
{
    _speedMenu = _mediaMenu->addMenu("Speed");
    _normalSpeedAction = new QAction("Normal", this);
    _fastSpeedAction = new QAction("Fast", this);
    _slowSpeedAction = new QAction("Slow", this);
    _normalSpeedAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_2));
    _fastSpeedAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_3));
    _slowSpeedAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_1));
    connect(_normalSpeedAction, &QAction::triggered, this, &CustomMenuBar::setNormalSpeed);
    connect(_fastSpeedAction, &QAction::triggered, this, &CustomMenuBar::setFastSpeed);
    connect(_slowSpeedAction, &QAction::triggered, this, &CustomMenuBar::setSlowSpeed);
    _speedMenu->addAction(_slowSpeedAction);
    _speedMenu->addAction(_normalSpeedAction);
    _speedMenu->addAction(_fastSpeedAction);
    _mediaMenu->addSeparator();
    _pauseAction = new QAction("Pause/Resume", this);
    _stopAction = new QAction("Stop", this);
    _prevAction = new QAction("Previous", this);
    _nextAction = new QAction("Next", this);
    _prevFrameAction = new QAction("Prev Frame", this);
    _nextFrameAction = new QAction("Next Frame", this);
    _pauseAction->setShortcut(QKeySequence(Qt::Key_Space));
    _stopAction->setShortcut(QKeySequence(Qt::Key_S));
    _prevAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
    _nextAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    _prevFrameAction->setShortcut(QKeySequence(Qt::Key_Left));
    _nextFrameAction->setShortcut(QKeySequence(Qt::Key_Right));
    connect(_pauseAction, &QAction::triggered, this, &CustomMenuBar::onPause);
    connect(_stopAction, &QAction::triggered, this, &CustomMenuBar::onStop);
    connect(_prevAction, &QAction::triggered, this, &CustomMenuBar::onPrev);
    connect(_nextAction, &QAction::triggered, this, &CustomMenuBar::onNext);
    connect(_prevFrameAction, &QAction::triggered, this, &CustomMenuBar::onPrevFrame);
    connect(_nextFrameAction, &QAction::triggered, this, &CustomMenuBar::onNextFrame);
    _mediaMenu->addAction(_pauseAction);
    _mediaMenu->addAction(_stopAction);
    _mediaMenu->addAction(_prevAction);
    _mediaMenu->addAction(_nextAction);
    _mediaMenu->addAction(_prevFrameAction);
    _mediaMenu->addAction(_nextFrameAction);
}

// Slots
void CustomMenuBar::load()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "*.mkv *.mp4");
    std::cout << filename.toStdString() << std::endl;
    if(_player)
        _player->setSource(QUrl::fromLocalFile(filename));
}

void CustomMenuBar::loadMultiple()
{
    //  Todo: Store the list
    QStringList files = QFileDialog::getOpenFileNames(this, "Open a file", QDir::homePath(), "*.mkv *.mp4");
    if(_player && files.length() != 0)
        _player->setSource(QUrl::fromLocalFile(files.at(0)));
}

void CustomMenuBar::loadFolder()
{
    //  Todo: Store the list
    QString dir = QFileDialog::getExistingDirectory(this, "Open a file", QDir::homePath());
    QDir directory(dir);
    QStringList files = directory.entryList(QStringList() << "*.mkv" << "*.mp4" ,QDir::Files);
    if(_player && files.length() != 0)
        _player->setSource(QUrl::fromLocalFile(dir + "/" + files.at(0)));
}

void CustomMenuBar::setNormalSpeed()
{
    if(_player)
        _player->setPlaybackRate(1);
}

void CustomMenuBar::setFastSpeed()
{
    if(_player)
        _player->setPlaybackRate(1.5);
}

void CustomMenuBar::setSlowSpeed()
{
    if(_player)
        _player->setPlaybackRate(0.5);
}

void CustomMenuBar::onPause()
{
    if(_player)
        _player->isPlaying() ? _player->pause() : _player->play();
}

void CustomMenuBar::onStop()
{
    if(_player)
    {
        _player->pause();
        _player->setPosition(0);
    }
}

void CustomMenuBar::onPrev()
{
    if(_player)
        _player->setPosition(0);
}

void CustomMenuBar::onNext()
{
    if(_player)
        _player->setPosition(_player->duration());
}

void CustomMenuBar::onPrevFrame()
{
    if(_player)
        _player->setPosition(_player->position() - 1000);
}

void CustomMenuBar::onNextFrame()
{
    if(_player)
        _player->setPosition(_player->position() + 1000);
}

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

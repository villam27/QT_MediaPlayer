#include "custommenubar.h"
#include <iostream>

CustomMenuBar::CustomMenuBar(QWidget *parent) : QMenuBar(parent)
{
    (void)parent;
    addMenus();
    _loadAction = new QAction("Load", this);
    connect(_loadAction, &QAction::triggered, this, &CustomMenuBar::load);
    _fileMenu->addAction(_loadAction);
    _player = NULL;
}

CustomMenuBar::~CustomMenuBar()
{
    delete _fileMenu;
    delete _mediaMenu;
    delete _audioMenu;
    delete _videoMenu;
    delete _loadAction;
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

// Slots
void CustomMenuBar::load()
{
    _player->pause();
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "*.mkv *.mp4");
    std::cout << filename.toStdString() << std::endl;
    if(_player)
        _player->setSource(QUrl::fromLocalFile(filename));
}

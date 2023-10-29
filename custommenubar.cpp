#include "custommenubar.h"
#include <iostream>

CustomMenuBar::CustomMenuBar(QWidget *parent) : QMenuBar(parent)
{
    (void)parent;
    setStyleSheet("background-color: white; color: black;");
    QMenu *menu = addMenu("File");
    QAction *action = new QAction("Load", this);
    connect(action, &QAction::triggered, this, &CustomMenuBar::load);
    menu->addAction(action);
    _player = NULL;
}

CustomMenuBar::~CustomMenuBar()
{}

void CustomMenuBar::setMediaPlayer(QMediaPlayer *player)
{
    _player = player;
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

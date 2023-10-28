#include "custommenubar.h"
#include <iostream>

CustomMenuBar::CustomMenuBar(QWidget *parent) : QMenuBar(parent)
{
    (void)parent;
    QMenu *menu = addMenu("File");
    QAction *action = new QAction("Load", this);
    connect(action, &QAction::triggered, this, &CustomMenuBar::load);
    menu->addAction(action);
}

CustomMenuBar::~CustomMenuBar()
{}

// Slots
void CustomMenuBar::load()
{
    // TODO: Implement
    std::cout << "Load file" << std::endl;
}

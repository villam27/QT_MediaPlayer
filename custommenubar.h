#ifndef CUSTOMMENUBAR_H
#define CUSTOMMENUBAR_H

#include <QWidget>
#include <QMenuBar>

class CustomMenuBar : public QMenuBar
{
public:
    CustomMenuBar(QWidget *parent = nullptr);
    ~CustomMenuBar();
};

#endif // CUSTOMMENUBAR_H

#ifndef CUSTOMMENUBAR_H
#define CUSTOMMENUBAR_H

#include <QWidget>
#include <QMenuBar>

class CustomMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    CustomMenuBar(QWidget *parent = nullptr);
    ~CustomMenuBar();

private slots:
    void load();
};

#endif // CUSTOMMENUBAR_H

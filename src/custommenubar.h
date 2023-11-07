#ifndef CUSTOMMENUBAR_H
#define CUSTOMMENUBAR_H

#include <QWidget>
#include <QMenuBar>
#include <QFileDialog>
#include <QMediaPlayer>

class CustomMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    CustomMenuBar(QWidget *parent = nullptr);
    ~CustomMenuBar();

    void setMediaPlayer(QMediaPlayer *player);

private:
    void addMenus();
    void setupFileMenu();

private:
    QMediaPlayer *_player;

    QMenu *_fileMenu;
    QAction *_openAction;
    QAction *_openMultipleAction;
    QAction *_openFolderAction;

    QMenu *_mediaMenu;

    QMenu *_audioMenu;

    QMenu *_videoMenu;

private slots:
    void load();
    void loadMultiple();
    void loadFolder();
};

#endif // CUSTOMMENUBAR_H

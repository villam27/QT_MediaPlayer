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
    void setupMediaMenu();

private:
    QMediaPlayer *_player;

    QMenu *_fileMenu;
    QAction *_openAction;
    QAction *_openMultipleAction;
    QAction *_openFolderAction;

    QMenu *_mediaMenu;
    QMenu *_speedMenu;
    QAction *_normalSpeedAction;
    QAction *_fastSpeedAction;
    QAction *_slowSpeedAction;

    QMenu *_audioMenu;

    QMenu *_videoMenu;

private slots:
    void load();
    void loadMultiple();
    void loadFolder();

    void setNormalSpeed();
    void setFastSpeed();
    void setSlowSpeed();
};

#endif // CUSTOMMENUBAR_H

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
    void setupAudioMenu();

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
    QAction *_pauseAction;
    QAction *_stopAction;
    QAction *_prevAction;
    QAction *_nextAction;
    QAction *_prevFrameAction;
    QAction *_nextFrameAction;

    QMenu *_audioMenu;
    QAction *_increaseVolumeAction;
    QAction *_decreaseVolumeAction;
    QAction *_muteAction;

    QMenu *_videoMenu;
    QAction *_fullscreenAction;

private slots:
    void load();
    void loadMultiple();
    void loadFolder();

    void setNormalSpeed();
    void setFastSpeed();
    void setSlowSpeed();
    void onPause();
    void onStop();
    void onPrev();
    void onNext();
    void onPrevFrame();
    void onNextFrame();

    void onIncreaseVolume();
    void onDecreaseVolume();
    void onMute();

    void onFullScreen();

};

#endif // CUSTOMMENUBAR_H

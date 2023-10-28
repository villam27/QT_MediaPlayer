#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QSlider>
#include "custommenubar.h"
#include "mediaplayerbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout *_layout;

    Ui::MainWindow *ui;
    CustomMenuBar *_menuBar;
    QVideoWidget *_video;
    QMediaPlayer *_player;
    QSlider *_videoSlider;
    MediaPlayerButton *_mediaPlayerButton;

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onPlaybackStateChanged(QMediaPlayer::PlaybackState state);

    void onPositionChanged(qint64 position);
    void onValueChanged(int value);
};
#endif // MAINWINDOW_H

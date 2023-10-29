#ifndef MEDIAPLAYERBUTTON_H
#define MEDIAPLAYERBUTTON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QtQuickWidgets>

class MediaPlayerButton : public QWidget
{
    Q_OBJECT

public:
    MediaPlayerButton(QWidget *parent = nullptr);
    ~MediaPlayerButton();

    void setMediaPlayer(QMediaPlayer *player);

private:
    void connectButton();

private:
    QHBoxLayout *_layout;
    QPushButton *_prevButton;
    QPushButton *_backButton;
    QPushButton *_stopButton;
    QPushButton *_pauseButton;
    QPushButton *_forwardButton;
    QPushButton *_nextButton;

    QMediaPlayer *_player;

    QQuickWidget *_testButton;

private slots:
    void OnPrevButtonClicked();
    void OnBackButtonClicked();
    void OnStopButtonClicked();
    void OnPauseButtonClicked();
    void OnForwardButtonClicked();
    void OnNextButtonClicked();
};

#endif // MEDIAPLAYERBUTTON_H

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
    QQuickWidget *createQuickWidget(QVariant customText);

private:
    QHBoxLayout *_layout;
    QQuickWidget *_prevButton;
    QQuickWidget *_backButton;
    QQuickWidget *_stopButton;
    QQuickWidget *_pauseButton;
    QQuickWidget *_forwardButton;
    QQuickWidget *_nextButton;

    QMediaPlayer *_player;

private slots:
    void OnPrevButtonClicked();
    void OnBackButtonClicked();
    void OnStopButtonClicked();
    void OnPauseButtonClicked();
    void OnForwardButtonClicked();
    void OnNextButtonClicked();
};

#endif // MEDIAPLAYERBUTTON_H

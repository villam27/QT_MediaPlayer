#ifndef MEDIAPLAYERBUTTON_H
#define MEDIAPLAYERBUTTON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QMediaPlayer>
#include <QAudioOutput>

class MediaPlayerButton : public QWidget
{
    Q_OBJECT

public:
    MediaPlayerButton(QWidget *parent = nullptr);
    ~MediaPlayerButton();

    void setMediaPlayer(QMediaPlayer *player);
    void setAudioOutput(QAudioOutput *audio);

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

    QSlider *_audioSlider;
    QAudioOutput *_audio;


    QMediaPlayer *_player;

private slots:
    void OnPrevButtonClicked();
    void OnBackButtonClicked();
    void OnStopButtonClicked();
    void OnPauseButtonClicked();
    void OnForwardButtonClicked();
    void OnNextButtonClicked();

    void OnAudioSliderValueChanged(int value);
};

#endif // MEDIAPLAYERBUTTON_H

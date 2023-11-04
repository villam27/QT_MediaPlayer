#ifndef MEDIAPLAYERBUTTON_H
#define MEDIAPLAYERBUTTON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QMediaPlayer>
#include <QAudioOutput>

#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 50

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
    QPushButton *createButton(const QString &path, int w = DEFAULT_WIDTH, int h = DEFAULT_HEIGHT);

private:
    QHBoxLayout *_layout;
    QPushButton *_prevButton;
    QPushButton *_backButton;
    QPushButton *_stopButton;
    QPushButton *_pauseButton;
    QPushButton *_forwardButton;
    QPushButton *_nextButton;
    QPushButton *_soundButton;

    QSlider *_audioSlider;
    QAudioOutput *_audio;

    QIcon _playIcon;
    QIcon _pauseIcon;

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

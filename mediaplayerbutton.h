#ifndef MEDIAPLAYERBUTTON_H
#define MEDIAPLAYERBUTTON_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class MediaPlayerButton : public QWidget
{
    Q_OBJECT

public:
    MediaPlayerButton(QWidget *parent = nullptr);
    ~MediaPlayerButton();

private:
    QHBoxLayout *_layout;
    QPushButton *_prevButton;
    QPushButton *_backButton;
    QPushButton *_stopButton;
    QPushButton *_pauseButton;
    QPushButton *_forwardButton;
    QPushButton *_nextButton;
};

#endif // MEDIAPLAYERBUTTON_H

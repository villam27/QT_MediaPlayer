#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <QMainWindow>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QStackedLayout>
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
    QVideoWidget *_video;
    CustomMenuBar *_menuBar;
    MediaPlayerButton *_mediaPlayerButton;
};
#endif // MAINWINDOW_H

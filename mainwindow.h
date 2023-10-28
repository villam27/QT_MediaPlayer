#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <QMainWindow>
#include <QVideoWidget>

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
    Ui::MainWindow *ui;
    QVideoWidget *_video;
};
#endif // MAINWINDOW_H

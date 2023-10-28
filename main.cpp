#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    w.show();
    return a.exec();
}

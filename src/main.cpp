#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load stylesheet
    QFile styleFile("://Style.qss");
    if (!styleFile.exists())
        QDebug(QtWarningMsg) << "Stylesheet not loaded";
    else
        QDebug(QtWarningMsg) << "Stylesheet loaded";
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QMediaPlayer mediaPlayer;

    engine.rootContext()->setContextProperty("mediaPlayer", &mediaPlayer);

    engine.load(QUrl(QStringLiteral("qrc:/Components/mainwindow.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

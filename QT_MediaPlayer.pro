QT       += core gui widgets multimediawidgets quick quickwidgets core5compat multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custommenubar.cpp \
    main.cpp \
    mainwindow.cpp \
    mediaplayerbutton.cpp

HEADERS += \
    custommenubar.h \
    mainwindow.h \
    mediaplayerbutton.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	CustomButton.qml \
	assets/b_rewind.svg \
	assets/f_rewind.svg \
	assets/full.svg \
	assets/loop.svg \
	assets/m_sound.svg \
	assets/next.svg \
	assets/no_sound.svg \
	assets/pause.svg \
	assets/play.svg \
	assets/prev.svg \
	assets/replay.svg \
	assets/s_loop.svg \
	assets/save.svg \
	assets/sound.svg \
	assets/stop.svg \
	assets/z_sound.svg
	CustomVideo.qml

RESOURCES += \
	ressources.qrc

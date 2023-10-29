import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia

Rectangle {
    id: videoScreen

    anchors {
        top: parent.top
        bottom: bottomBar.top
        right: parent.right
    }
    color: "black"
    width: parent.width * 0.75

    MediaPlayer {
        id: player
        source: "C:/Users/Ducky/Videos/cyberbonk.mkv"
        audioOutput: AudioOutput {}
        videoOutput: videoOutput
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onPressed: player.playing ? player.pause() : player.play();
    }
}

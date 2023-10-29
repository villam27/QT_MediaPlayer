import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    id: bottomBar

    anchors {
        left:  parent.left
        right: parent.right
        bottom: parent.bottom
    }
    color: "#9DC5BB"
    height: 70

    RowLayout {
        id: bottomBarLayout
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
            margins: 15
        }
        spacing: 5
        IconButton {
            id: playButton
            iconSource: "qrc:/assets/play.svg"
        }
        IconButton {
            id: replayButton
            iconSource: "qrc:/assets/replay.svg"
        }
        IconButton {
            id: stopButton
            iconSource: "qrc:/assets/stop.svg"
        }
    }
    RowLayout {
        id: bottomBarLayout2
        anchors {
            left: bottomBarLayout.right
            verticalCenter: parent.verticalCenter
            margins: 15
            leftMargin: 50
        }
        spacing: 5
        IconButton {
            id: prevButton
            iconSource: "qrc:/assets/prev.svg"
        }
        IconButton {
            id: rewindBackButton
            iconSource: "qrc:/assets/b_rewind.svg"
        }
        IconButton {
            id: rewindForwardButton
            iconSource: "qrc:/assets/f_rewind.svg"
        }
        IconButton {
            id: nextButton
            iconSource: "qrc:/assets/next.svg"
        }
    }
    RowLayout {
        id: bottomBarLayout3
        anchors {
            left: bottomBarLayout2.right
            verticalCenter: parent.verticalCenter
            margins: 15
            leftMargin: 50
        }
        spacing: 15
        IconButton {
            id: loopButton
            iconSource: "qrc:/assets/loop.svg"
        }
        IconButton {
            id: soundButton
            iconSource: "qrc:/assets/sound.svg"
        }
    }
    RowLayout {
        id: bottomBarLayout4
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
            margins: 15
        }
        spacing: 35
        IconButton {
            id: settingsButton
            iconSource: "qrc:/assets/save.svg"
        }
        IconButton {
            id: fullButton
            iconSource: "qrc:/assets/full.svg"
        }
    }
}

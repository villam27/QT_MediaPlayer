import QtQuick 2.15

Image {
    property string iconSource: ""

    id: iconButton

    source: iconSource
    sourceSize: Qt.size(50, 50)
    opacity: 1

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onPressed: {
            iconButton.scale = 0.9
        }
        onReleased: {
            iconButton.scale = 1
        }
        onEntered: {
            iconButton.opacity = 0.7
        }
        onExited: {
            iconButton.opacity = 1
        }
    }
}

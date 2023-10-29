import QtQuick 2.15

Image {
    property string iconSource: ""

    source: iconSource
    sourceSize: Qt.size(50, 50)
    MouseArea {
        anchors.fill: parent
        onPressed: {
            console.log("click")
        }
    }
}

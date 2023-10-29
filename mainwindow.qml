import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 200
    height: 100
    title: "Red Button Example"

    Rectangle {
        width: parent.width
        height: parent.height

        Button {
            text: "Click Me"
            anchors.centerIn: parent
            background: Rectangle {
                color: "red"
                radius: 5
                border.color: "black"
            }
        }
    }
}

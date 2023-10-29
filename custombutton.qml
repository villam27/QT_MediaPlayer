import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: redButton

    width: 100
    height: 40
    text: "Red Button"
    background: Rectangle {
        color: "red"
        radius: 5
        border.color: "black"
    }
    onClicked: {
        console.log("Red button clicked")
    }
}

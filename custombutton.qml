import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: redButton

    width: 80
    height: 30
    text: customText
    background: Rectangle {
        color: "red"
        radius: 5
        border.color: "black"
    }

    signal onButtonClicked()

    onClicked: {
        redButton.onButtonClicked();
    }

    property string customText: "Red Button"
}

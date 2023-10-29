import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: redButton
    property color backgroundDefaultColor: "#41cd52"
    property color backgroundPressedColor: Qt.darker(backgroundDefaultColor, 1.2)
    property color contentItemTextColor: "white"

    width: 70
    height: 30

    contentItem: redButtonText
    Text {
        id: redButtonText
        text: customText
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
        font.bold: true
    }

    background: Rectangle {
        color: "#41cd52"
        radius: 5
        border.color: "black"
    }

    signal onButtonClicked()
    onClicked: {
        redButton.onButtonClicked();
    }
    property string customText: "Red Button"
}

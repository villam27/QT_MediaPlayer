import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    anchors {
        left: parent.left
        right: videoScreen.left
        bottom: bottomBar.top
        top: parent.top
    }
    color: "#DEE5E5"

    CustomButton {
        customText: "Add Source"
        anchors {
            bottom: parent.bottom
            margins: 10
        }
    }
}

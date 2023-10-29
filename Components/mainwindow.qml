import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia
import QtQuick.Layouts

Window {
    visible: true
    width: 1000
    height: 600
    title: "Qt Video Player"

    CustomVideo {
        id: videoScreen
    }

    LeftScreen {
        id: leftScreen
    }

    BottomBar {
        id: bottomBar
    }
}

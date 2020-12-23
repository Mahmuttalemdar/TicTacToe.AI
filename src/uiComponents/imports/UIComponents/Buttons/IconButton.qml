import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Button {
    id: root

    property string buttonIcon: "qrc:/imports/Theme/images/StartScreen/icon_back.svg"
    property string buttonIconColor: "#FFFFFF"
    property string buttonBackgroundColor: "#000000"
    property real buttonSize: 40
    property real buttonOpacity: 1

    width: buttonSize
    height: buttonSize
    icon.source: buttonIcon
    icon.color: "#FFFFFF"

    // BUTTON BACKGROUND
    background: Rectangle {
        width: root.buttonSize
        height: root.buttonSize
        color: root.buttonBackgroundColor
        opacity: root.buttonOpacity
        radius: root.buttonSize / 2
    }

}

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.12


Button {
    id: root

    property string imageSource: "qrc:/imports/Theme/images/StartScreen/id_card.svg"
    property string buttonText: "Button"
    property string buttonTextColor: "#D8D8D8"
    property string buttonBackgroundColor: "#242424"
    property real buttonWidth: 343
    property real buttonHeight: 80
    property real buttonOpacity: 1
    property real buttonRadius: 10

    width: buttonWidth
    height: buttonHeight

    // BUTTON BACKGROUND
    background: Rectangle {
        id: background
        width: root.width
        height: root.height
        color: root.buttonBackgroundColor
        opacity: root.buttonOpacity
        radius: root.buttonRadius
    }

    DropShadow {
        anchors.fill: background
        horizontalOffset: 0
        verticalOffset: 8
        radius: root.buttonRadius
        samples: 16
        color: "#00000033"
        source: background
    }

    // ICON
    Image {
        id: buttonIcon
        width: 48
        height: 48
        source: imageSource

        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.verticalCenter: parent.verticalCenter
    }

    // BUTTON TEXT
    Text {
        text: root.buttonText
        color: root.buttonTextColor
        font.family: "Montserrat"
        font.pixelSize: 15
        font.weight: Font.DemiBold
        font.letterSpacing: 0.3
        wrapMode: Text.WrapAnywhere

        anchors.left: buttonIcon.right
        anchors.leftMargin: 16
        anchors.verticalCenter: parent.verticalCenter
    }

    // ARROW ICON
    Image {
        id: arrowIcon
        width: 24
        height: 24
        source: "qrc:/imports/Theme/images/StartScreen/arrow.svg"

        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.verticalCenter: parent.verticalCenter
    }

}







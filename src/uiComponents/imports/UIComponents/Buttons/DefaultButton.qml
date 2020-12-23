import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Button {
    id: root

    property string buttonText: "Button"
    property string buttonTextColor: "#FFFFFF"
    property string buttonBackgroundColor: "#000000"
    property string buttonIcon: ""
    property real buttonWidth: 164
    property real buttonHeight: 54
    property real buttonOpacity: 0.5
    property real buttonRadius: 10
    property bool isButtonActive: buttonIcon === "" ? false : true

    width: buttonWidth
    height: buttonHeight

    // BOTTOM TEXT AREA
    Row {
        id: bottomTextArea
        spacing: isButtonActive ? 8 : 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        // ICON
        Image {
            width: isButtonActive ? 24 : 0
            height: isButtonActive ? 24 : 0
            source: buttonIcon
        }

        // BUTTON TEXT
        Text {
            height: 24
            text: root.buttonText
            color: root.buttonTextColor
            font.family: "Montserrat"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 16
            font.weight: Font.DemiBold
            font.letterSpacing: 0.38
            wrapMode: Text.WrapAnywhere
        }
    }

    // BUTTON BACKGROUND
    background: Rectangle {
        width: root.width
        height: root.height
        color: root.buttonBackgroundColor
        opacity: root.buttonOpacity
        radius: root.buttonRadius
    }

}







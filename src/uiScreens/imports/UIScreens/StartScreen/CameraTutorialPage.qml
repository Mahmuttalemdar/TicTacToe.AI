import QtQuick 2.15
import QtQuick.Controls 2.15

import UIComponents.Buttons 1.0

Rectangle{
    id: root
    color: "#121212"

    // BACKGROUND IMAGE
    AnimatedImage {
        id: handLogo
        width: 220
        height: 220
        source: "qrc:/imports/Theme/images/StartScreen/id-card-scan-dark.gif"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height / 4

        playing: true
        paused: false
        speed: 2
        onStatusChanged: playing = (status == AnimatedImage.Ready)
    }

    // HEADER TEXT
    Text {
        id: headerText
        text: "Align the card."
        color: "#DCDCDC"
        font.family: "Open Sans"
        font.bold: true
        font.pixelSize: 20

        anchors.top: handLogo.bottom
        anchors.topMargin: 42
        anchors.horizontalCenter: parent.horizontalCenter
    }

    // DESCRIPTION
    Text {
        id: descriptionText
        text: "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
        color: "#6D6E71"
        opacity: 0.5
        font.pixelSize: 15
        font.family: "Montserrat"
        font.weight: Font.Medium
        wrapMode: Text.WrapAnywhere
        horizontalAlignment: Text.AlignHCenter

        anchors.top: headerText.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 24
        anchors.right: parent.right
        anchors.rightMargin: 24
    }

    // BACK BUTTON
    IconButton {
        id: backButton
        buttonIcon: "qrc:/imports/Theme/images/StartScreen/icon_back.svg"
        buttonIconColor: "#FFFFFF"
        buttonBackgroundColor: "#292929"
        buttonSize: 40
        buttonOpacity: 1

        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.top: parent.top
        anchors.topMargin: 36

        onClicked: entrance.statechart.submitEvent("triggerPreviousPage")
    }

    // START BUTTON
    DefaultButton {
        id: startButton
        buttonWidth: 343
        buttonHeight: 54
        buttonText: "Let's Start."
        buttonTextColor: "#FFFFFF"
        buttonBackgroundColor: "#0F72FF"
        buttonOpacity: 1
        buttonRadius: 10

        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16

        onClicked: entrance.statechart.submitEvent("openMRZDetectionPage")
    }
}

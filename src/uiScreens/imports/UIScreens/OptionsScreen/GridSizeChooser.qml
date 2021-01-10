import QtQuick 2.15
import QtGraphicalEffects 1.15

import Core.Data 1.0

Item {
    id: root
    width: parent.width
    height: parent.height

    property int optionSpacing: 50

    // EASY OPTION AREA
    Item {
        id: easyOptionArea
        width: parent.height
        height: parent.height
        anchors.right: mediumOptionArea.left
        anchors.rightMargin: root.optionSpacing

        property bool isActivated: true

        // TITLE TEXT
        Text {
            id: easyOptionText
            width: parent.width
            text: "3 x 3"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 42
            font.letterSpacing: 0.7
            color: easyOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.fill: parent
        }

        // BOTTOM LINE
        Rectangle {
            width: easyOptionText.width / 2
            height: 2
            visible: easyOptionArea.isActivated
            color: easyOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.horizontalCenter: easyOptionText.horizontalCenter
            anchors.top: easyOptionText.bottom
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                easyOptionArea.isActivated = true
                entrance.gameSettings.gridSize = 3
            }
        }
    }

    // MEDIUM OPTION AREA
    Item {
        id: mediumOptionArea
        width: parent.height
        height: parent.height
        anchors.centerIn: parent

        property bool isActivated: false

        // TITLE TEXT
        Text {
            id: mediumOptionText
            width: parent.width
            text: "5 x 5"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 42
            font.letterSpacing: 0.7
            color: mediumOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.fill: parent
        }

        // BOTTOM LINE
        Rectangle {
            width: mediumOptionText.width / 2
            height: 2
            visible: mediumOptionArea.isActivated
            color: mediumOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.horizontalCenter: mediumOptionText.horizontalCenter
            anchors.top: mediumOptionText.bottom
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                mediumOptionArea.isActivated = true
                entrance.gameSettings.gridSize = 5
            }
        }
    }

    // HARD OPTION AREA
    Item {
        id: hardOptionArea
        width: parent.height
        height: parent.height
        anchors.left: mediumOptionArea.right
        anchors.leftMargin: root.optionSpacing

        property bool isActivated: false

        // TITLE TEXT
        Text {
            id: hardOptionText
            width: parent.width
            text: "7 x 7"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 42
            font.letterSpacing: 0.7
            color: hardOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.fill: parent
        }

        // BOTTOM LINE
        Rectangle {
            width: hardOptionText.width / 2
            height: 2
            visible: hardOptionArea.isActivated
            color: hardOptionArea.isActivated ?  "#FF8924" : "#FFFFFF"
            anchors.horizontalCenter: hardOptionText.horizontalCenter
            anchors.top: hardOptionText.bottom
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                hardOptionArea.isActivated = true
                entrance.gameSettings.gridSize = 7
            }
        }
    }

    // Clear All
    function deactiveAll() {
        easyOptionArea.isActivated = false;
        mediumOptionArea.isActivated = false;
        hardOptionArea.isActivated = false;
    }


}

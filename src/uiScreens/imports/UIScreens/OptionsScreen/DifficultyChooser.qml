import QtQuick 2.15
import QtGraphicalEffects 1.15

import Core.Data 1.0

Item {
    id: root
    width: parent.width
    height: parent.height

    property int optionSpacing: 50

    signal deactiveAllItems();

    // EASY OPTION AREA
    Item {
        id: easyOptionArea
        width: parent.height
        height: parent.height
        anchors.right: mediumOptionArea.left
        anchors.rightMargin: root.optionSpacing

        property bool isActivated: true

        Image {
            id: easyOption
            width: parent.height / 4
            height: parent.height / 2
            source: easyOptionArea.isActivated ? "qrc:/imports/Theme/images/Difficulty/DifficultyEasyActive.svg"
                                               : "qrc:/imports/Theme/images/Difficulty/DifficultyEasy.svg"
            anchors.bottom: easyOptionText.top
            anchors.bottomMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // TITLE TEXT
        Text {
            id: easyOptionText
            width: parent.width
            text: "easy"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 28
            font.letterSpacing: 0.7
            color: "#FFFFFF"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                easyOptionArea.isActivated = true
                entrance.appConfig.gameDifficulty.difficulty = GameDifficulty.Easy
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

        Image {
            id: mediumOption
            width: parent.height / 2
            height: parent.height / 2
            source: mediumOptionArea.isActivated ? "qrc:/imports/Theme/images/Difficulty/DifficultyMediumActive.svg"
                                             : "qrc:/imports/Theme/images/Difficulty/DifficultyMedium.svg"
            anchors.bottom: mediumOptionText.top
            anchors.bottomMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // TITLE TEXT
        Text {
            id: mediumOptionText
            width: parent.width
            text: "medium"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 28
            font.letterSpacing: 0.7
            color: "#FFFFFF"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                mediumOptionArea.isActivated = true
                entrance.appConfig.gameDifficulty.difficulty = GameDifficulty.Medium
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

        Image {
            id: hardOption
            width: parent.height / 2
            height: parent.height / 2
            source: hardOptionArea.isActivated ? "qrc:/imports/Theme/images/Difficulty/DifficultyHardActive.svg"
                                               : "qrc:/imports/Theme/images/Difficulty/DifficultyHard.svg"
            anchors.bottom: hardOptionText.top
            anchors.bottomMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // TITLE TEXT
        Text {
            id: hardOptionText
            width: parent.width
            text: "hard"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 28
            font.letterSpacing: 0.7
            color: "#FFFFFF"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // MOUSE AREA
        MouseArea {
            anchors.fill: parent
            onClicked: {
                deactiveAll()
                hardOptionArea.isActivated = true
                entrance.appConfig.gameDifficulty.difficulty = GameDifficulty.Hard
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

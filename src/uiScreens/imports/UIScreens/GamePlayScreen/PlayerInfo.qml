import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
    id: root
    width: 200
    height: 300

    property string playerTypeText: "Player 2"
    property string playerNameText: "JANE123"
    property string playerShapeImage: "qrc:/imports/Theme/images/Tiles/TileO.svg"
    property string turnText: "Your turn"
    property bool isTurnActive: true

    property string turnActiveColor: "#6C4AB2"
    property string backgroundColor: "#3E198D"

    // PLAYER NAME TEXT
    Text {
        id: innerTurnText
        text: root.turnText
        visible: root.isTurnActive
        font.family: "Chalkboard SE"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 22
        font.weight: Font.ExtraBold
        color: "#FFFFFF"
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.horizontalCenter: parent.horizontalCenter
    }

    // INNER BACKGROUND
    Rectangle {
        id: innerBackground
        width: parent.width * 3 / 5
        height: parent.width * 3 / 5 + 30
        color: root.isTurnActive ? root.turnActiveColor
                                 : root.backgroundColor
        radius: parent.width / 5
        anchors.top: parent.top
        anchors.topMargin: parent.height * 2 / 7
        anchors.horizontalCenter: parent.horizontalCenter

        // USER PROFILE
        Rectangle {
            id: playerProfile
            width: 50
            height: 50
            color: "#3E198D"
            radius: width / 2
            clip: true

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: -height / 2

            Image {
                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                source: "qrc:/imports/Theme/images/Player/PlayerProfile.svg"
            }
        }

        // PLAYER TYPE TEXT
        Text {
            id: innerPlayerTypeText
            text: root.playerTypeText
            font.family: "Chalkboard SE"
            font.bold: false
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
            color: "#FFFFFF"
            anchors.top: parent.top
            anchors.topMargin: 36
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // PLAYER NAME TEXT
        Text {
            id: innerPlayerNameText
            text: root.playerNameText
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
            color: "#FFFFFF"
            anchors.top: innerPlayerTypeText.bottom
            anchors.topMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // SELECTED TILE SHAPE
        Image {
            id: selectedTileShape
            width: 40
            height: 40
            source: root.playerShapeImage

            anchors.top: innerPlayerNameText.bottom
            anchors.topMargin: 8
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // DROP SHADOW
        DropShadow {
            anchors.fill: selectedTileShape
            horizontalOffset: 3
            verticalOffset: 3
            radius: 8.0
            samples: 17
            color: "#80000000"
            source: selectedTileShape
        }
    }

    // PLAYER SCORE
    PlayerScore {
        id: playerScore
        width: innerBackground.width
        height: 60
        shapeStrokeWidth: 2

        anchors.top: innerBackground.bottom
        anchors.topMargin: 16
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

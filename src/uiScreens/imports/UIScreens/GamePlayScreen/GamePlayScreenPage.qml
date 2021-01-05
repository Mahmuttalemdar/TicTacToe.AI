import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

import UIComponents.Backgrounds 1.0
import UIComponents.Buttons 1.0

Rectangle {
    id: root
    width: parent.width
    height: parent.height
    color: "yellow"

    // BACKGROUND
    Image {
        id: backgroundImage
        width: parent.width
        height: parent.height
        source: "qrc:/imports/Theme/images/Backgrounds/Background2.svg"
    }

    GamePlayScreen {
        id: gamePlayScreen
        clip: true

        // LOGO
        Logo{
            id: logo
            width: 90
            height: 100
            shapeStrokeWidth: 2
            shapeInnerDistance: 18

            anchors.left: parent.left
            anchors.leftMargin: 35
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        // AI PLAYER INFO
        PlayerInfo {
            id: aiPlayerInfo
            turnText: "AI turn"
            playerTypeText: "AI"
            playerNameText: "Basag.AI"
            isTurnActive: true

            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 35
        }

        // AI PLAYER INFO
        PlayerInfo {
            id: humanPlayerInfo
            turnText: "Your turn"
            playerTypeText: "Player"
            playerNameText: "Mahmut"
            isTurnActive: false

            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 35
        }

        GamePlayBoard {
            id: gamePlayBoard
            width: parent.height * 5 / 6
            height: parent.height * 5 / 6
        }
    }


    // BOARD
    Item {
        id: board
        width: 500
        height: 500
        visible: false

        anchors.top: parent.top
        anchors.topMargin: 120
        anchors.horizontalCenter: parent.horizontalCenter

        // BOARD BACKGROUND
        Image {
            id: boardImage
            width: parent.width
            height: parent.height
            source: "qrc:/imports/Theme/images/Backgrounds/Board.svg"
        }

        // ROW 1
        Shape {
            id: row1
            width: board.width

            ShapePath {
                strokeColor: "white"
                strokeWidth: 3
                strokeStyle: ShapePath.DashLine

                startX: 0
                startY: board.height / 3

                // PATH
                PathLine { x: board.width; y: board.height / 3 }
            }
        }

        // ROW 2
        Shape {
            id: row2
            width: board.width

            ShapePath {
                strokeColor: "white"
                strokeWidth: 3
                strokeStyle: ShapePath.DashLine

                startX: 0
                startY: board.height * (2 / 3)

                // PATH
                PathLine { x: board.width; y: board.height * (2 / 3) }
            }
        }

        // COLUMN 1
        Shape {
            id: column1
            width: board.height

            ShapePath {
                strokeColor: "white"
                strokeWidth: 3
                strokeStyle: ShapePath.DashLine

                startX: board.width / 3
                startY: 0

                // PATH
                PathLine { x: board.width / 3; y: board.height }
            }
        }

        // COLUMN 2
        Shape {
            id: column2
            width: board.height

            ShapePath {
                strokeColor: "white"
                strokeWidth: 3
                strokeStyle: ShapePath.DashLine

                startX: board.width * 2 / 3
                startY: 0

                // PATH
                PathLine { x: board.width * 2 / 3; y: board.height }
            }
        }

    }
}


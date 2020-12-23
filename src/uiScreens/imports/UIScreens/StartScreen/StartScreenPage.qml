import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtScxml 5.15

import UIComponents.Backgrounds 1.0
import UIComponents.Buttons 1.0

Rectangle {
    id: root
    width: parent.width
    height: parent.height
    color: "#121212"



    Rectangle {
        id: startScreen
        width: parent.width
        height: parent.height
        color: "red"

        // BACKGROUND
        Image {
            id: backgroundImage
            width: parent.width
            height: parent.height
            source: "qrc:/imports/Theme/images/Backgrounds/StartScreenBackground.png"
        }

        // LOGO
        Image {
            id: logo
            width: 280
            height: 406
            anchors.top: parent.top
            anchors.topMargin: 90
            anchors.horizontalCenter: parent.horizontalCenter

            fillMode: Image.PreserveAspectFit
            source: "qrc:/imports/Theme/images/Logo/Logo.svg"
        }

        // NEW GAME BUTTON
        Item{
            width: 252
            height: 91

            anchors.top: logo.bottom
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter

            // BACKGROUND
            Image {
                width: parent.width
                height: parent.height
                source: "qrc:/imports/Theme/images/Buttons/ButtonBackground.png"

                Text {
                    text: "New Game"
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                    anchors.centerIn: parent
                }
            }
        }

        // ANIMATED TILE X
        AnimatedTile {
            id: animatedTileX
            tileWidth: 200
            tileHeight: 200
            tileImage: "qrc:/imports/Theme/images/Tiles/TileX.svg"
            duration: 1400
            startCoordinateX: -tileWidth
            startCoordinateY: startScreen.height
            endCoordinateX: startScreen.width / 6
            endCoordinateY: startScreen.height * (4 / 5) - (tileHeight / 2)

            startRotation: 90
            endRotation: -15
            ongoingRotation: 20

            animationX: 100
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.0
        }

        // ANIMATED TILE M
        AnimatedTile {
            id: animatedTileM
            tileWidth: 240
            tileHeight: 240
            tileImage: "qrc:/imports/Theme/images/Tiles/TileM.svg"
            duration: 1800
            startCoordinateX: -tileWidth
            startCoordinateY: startScreen.height * (2 / 5) - (tileHeight / 5)
            endCoordinateX: -(tileWidth / 5)
            endCoordinateY: startScreen.height * (2 / 5) - (tileHeight / 5)

            startRotation: 90
            endRotation: 40
            ongoingRotation: 50

            animationX: 50
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.0
        }

        // ANIMATED TILE K
        AnimatedTile {
            id: animatedTileK
            tileWidth: 200
            tileHeight: 200
            tileImage: "qrc:/imports/Theme/images/Tiles/TileK.svg"
            duration: 700
            startCoordinateX: startScreen.width
            startCoordinateY: 0
            endCoordinateX: startScreen.width - tileWidth
            endCoordinateY: tileHeight / 7

            startRotation: 90
            endRotation: -145
            ongoingRotation: -50

            animationX: 0
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.2
        }

        // ANIMATED TILE O
        AnimatedTile {
            id: animatedTileO
            tileWidth: 200
            tileHeight: 200
            tileImage: "qrc:/imports/Theme/images/Tiles/TileO.svg"
            duration: 1400
            startCoordinateX: startScreen.width
            startCoordinateY: startScreen.height
            endCoordinateX: startScreen.width - (tileWidth * 2) + (tileWidth / 3)
            endCoordinateY: startScreen.height * (4 / 5) - (tileHeight / 2)

            startRotation: 0
            endRotation: 10
            ongoingRotation: 360

            animationX: 0
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.0
        }

        // ANIMATED TILE U
        AnimatedTile {
            id: animatedTileU
            tileWidth: 200
            tileHeight: 200
            tileImage: "qrc:/imports/Theme/images/Tiles/TileU.svg"
            duration: 1400
            startCoordinateX: -tileWidth
            startCoordinateY: -tileHeight
            endCoordinateX: tileWidth / 2
            endCoordinateY: 0

            startRotation: 0
            endRotation: 152
            ongoingRotation: 360

            animationX: 0
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.0
        }

        // ANIMATED TILE A
        AnimatedTile {
            id: animatedTileA
            tileWidth: 200
            tileHeight: 200
            tileImage: "qrc:/imports/Theme/images/Tiles/TileA.svg"
            duration: 1400
            startCoordinateX: startScreen.width
            startCoordinateY: startScreen.height * 2 / 5
            endCoordinateX: startScreen.width - tileWidth
            endCoordinateY: startScreen.height * (2 / 5)

            startRotation: 0
            endRotation: -30
            ongoingRotation: 20

            animationX: 0
            animationY: 0
            startScale: 1.0
            endScale: 1.0
            ongoingScale: 1.0
        }

    }

    Button {
        id: btn
        width: 200
        height: 30
        anchors.centerIn: parent
        text: "start"
        visible: false

        onClicked: {
            animatedTileX.state = "START"
            animatedTileM.state = "START"
            animatedTileK.state = "START"
            animatedTileO.state = "START"
            animatedTileU.state = "START"
            animatedTileA.state = "START"

        }
    }

    Button {
        width: 200
        height: 30
        anchors.top: btn.bottom
        anchors.left: btn.left
        text: "end"
        visible: false

        onClicked: {
            animatedTileX.state = "END"
            animatedTileM.state = "END"
            animatedTileK.state = "END"
            animatedTileO.state = "END"
            animatedTileU.state = "END"
            animatedTileA.state = "END"

        }
    }



}

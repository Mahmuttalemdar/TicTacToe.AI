import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtScxml 5.15

import UIComponents.Backgrounds 1.0
import UIComponents.Buttons 1.0

Item {
    id: startScreen
    width: parent.width
    height: parent.height

    // BACKGROUND
    Image {
        id: backgroundImage
        width: parent.width
        height: parent.height
        source: "qrc:/imports/Theme/images/Backgrounds/Background.png"
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
    DashedButton {
        buttonWidth: 200
        buttonHeight: 70
        buttonOpacity: 0.9
        buttonText: "New Game"
        buttonTextColor: "#FFFFFF"
        buttonBackgroundPrimaryColor: "#D7386F"
        buttonBackgroundSecondaryColor: "#8159E6"
        buttonDashColor: "#FFFFFF"
        buttonShapeInnerDistance: 8
        buttonDasherDuration: 700
        buttonFontSize: 22

        anchors.top: logo.bottom
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter

        onClicked : {
            entrance.statechart.submitEvent("openOptionScreen")
        }

    }


    // ANIMATED TILE X
    AnimatedTile {
        id: animatedTileX
        tileWidth: 240
        tileHeight: 240
        tileImage: "qrc:/imports/Theme/images/Tiles/TileX.svg"
        duration: 1400
        startCoordinateX: -tileWidth
        startCoordinateY: startScreen.height
        endCoordinateX: startScreen.width / 12
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
        tileWidth: 240
        tileHeight: 240
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
        tileWidth: 240
        tileHeight: 240
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
        tileWidth: 240
        tileHeight: 240
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
        tileWidth: 240
        tileHeight: 240
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


    // COMPONENT ON COMPLETED
    Component.onCompleted: {
        animatedTileX.state = "END"
        animatedTileM.state = "END"
        animatedTileK.state = "END"
        animatedTileO.state = "END"
        animatedTileU.state = "END"
        animatedTileA.state = "END"
    }
}


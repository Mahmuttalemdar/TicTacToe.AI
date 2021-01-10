import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

import Core.Data 1.0
import UIComponents.Buttons 1.0
import UIScreens.OptionsScreen 1.0

Popup {
    id: root
    width: 450
    height: 600
    modal: true
    focus: true
    padding: 0
    closePolicy: Popup.CloseOnEscape
    anchors.centerIn: Overlay.overlay

    property string winnerText: "YOU WON"


    enter: Transition {
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; duration: 1000 }
    }
    background: Rectangle {
        color: "transparent"
    }

    contentItem: Rectangle {
        width: root.width
        height: root.height
        color: "transparent"
        clip: true

        // BACKGROUND
        Image {
            id: background
            anchors.fill: parent
            source: "qrc:/imports/Theme/images/Backgrounds/Crystal.svg"
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: mask
            }
        }

        Rectangle {
            id: mask
            anchors.fill: parent
            radius: 60
            visible: false
        }

        // TITLE
        OptionsTitle {
            id: optionsTitle
            width: 200
            height: 70
            itemText: root.winnerText
            itemTextColor: "#FFFFFF"
            itemFontSize: 42
            dashColor: "#FFFFFF"
            dasherDuration: 700
            shapeInnerDistance: 12
            shapeStrokeWidth: 2
            shapeOpacity: 1.0

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 92
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // NEXT BUTTON
        DashedButton {
            buttonWidth: 100
            buttonHeight: 30
            buttonOpacity: 1.0
            buttonText: "REPLAY"
            buttonTextColor: "#FFFFFF"
            buttonBackgroundPrimaryColor: "transparent"
            buttonBackgroundSecondaryColor: "transparent"
            buttonDashColor: "#FFFFFF"
            buttonShapeInnerDistance: 4
            buttonDasherDuration: 700
            buttonFontSize: 18
            buttonStrokeWidth: 2
            isAnimateable: false

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 35
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked : {
                entrance.statechart.submitEvent("restartGame", {})
            }

        }
    }

    // CONNECTIONS
    Connections {
        target: entrance.gameController.gameBoard

        function onGameStateChanged(gameState){
            console.log("Game state: ", gameState)

            if(gameState === GameBoard.WON) {
                console.log("Game state: WON")
                root.winnerText = "YOU LOSE"
                root.open()
            }
            else if(gameState === GameBoard.LOSS) {
                console.log("Game state: LOSS")
                root.winnerText = "YOU WON"
                root.open()
            }
            else if(gameState === GameBoard.DRAW) {
                console.log("Game state: DRAW")
                root.winnerText = "DRAW"
                root.open()
            }
            else if(gameState === GameBoard.ONGOING) {
                console.log("Game state: ONGOING")
                root.winnerText = "ONGOING"
                root.close()
            }
        }
    }
}


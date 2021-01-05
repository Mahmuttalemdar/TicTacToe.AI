import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtGraphicalEffects 1.15
import QtScxml 5.15

import UIComponents.Backgrounds 1.0
import UIComponents.Buttons 1.0
import UIScreens.OptionsScreen 1.0


// OPTION SCREEN
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
        source: "qrc:/imports/Theme/images/Backgrounds/Background2.svg"
    }

    // OPTIONS BOARD
    OptionsBoard {
        id: optionsBoard
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

        // TITLE
        OptionsTitle {
            id: optionsTitle
            width: 140
            height: 40
            itemText: "Choose your shape"
            itemTextColor: "#FFFFFF"
            itemFontSize: 28
            dashColor: "#FFFFFF"
            dasherDuration: 700
            shapeInnerDistance: 12
            shapeStrokeWidth: 2
            shapeOpacity: 1.0

            anchors.top: parent.top
            anchors.topMargin: 45
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // OPTION STACKVIEW
        StackView {
            id: optionStack
            width: parent.width
            height: parent.height / 4
            initialItem: shapeChooserComp
            focus: true

            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.verticalCenter: parent.verticalCenter
        }

        // NEXT BUTTON
        DashedButton {
            buttonWidth: 170
            buttonHeight: 60
            buttonOpacity: 0.9
            buttonText: "NEXT"
            buttonTextColor: "#FFFFFF"
            buttonBackgroundPrimaryColor: "#D7386F"
            buttonBackgroundSecondaryColor: "#8159E6"
            buttonDashColor: "#FFFFFF"
            buttonShapeInnerDistance: 6
            buttonDasherDuration: 700
            buttonFontSize: 28
            isAnimateable: false

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 35
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked : {
                //openDifficultyPage
                //openGamePlayScreen
                //backToChooseShapePage
                entrance.statechart.submitEvent("openDifficultyPage")
            }

        }
    }

    // SHAPE CHOOSER
    Component {
        id: shapeChooserComp

        ShapeChooser {
            id: shapeChooser
            width: parent.width
            height: parent.height
            color: "#411597"
        }
    }

    // DIFFICULTY CHOOSER
    Component {
        id: difficultyChooserComp

        DifficultyChooser {
            id: difficultyChooser
            width: parent.width
            height: parent.height
        }
 }

    // EVENT: openDifficultyPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openDifficultyPage"]
        onOccurred: {
            optionsTitle.itemText = "Choose difficulty"
            optionStack.push(difficultyChooserComp)
        }
    }

    // EVENT: backToChooseShapePage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["backToChooseShapePage"]
        onOccurred: {
            optionStack.push(shapeChooserComp)
        }
    }

    // EVENT: openGamePlayScreen
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openGamePlayScreen"]
        onOccurred: {
            optionStack.push(difficultyChooserComp)
        }
    }

}


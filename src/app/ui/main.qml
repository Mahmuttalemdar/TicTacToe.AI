import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtScxml 5.15

import UIComponents.Backgrounds 1.0
import UIScreens.GamePlayScreen 1.0
import UIScreens.OptionsScreen 1.0
import UIScreens.ScoreScreen 1.0
import UIScreens.StartScreen 1.0

ApplicationWindow {
    id: appRoot
    visible: true
    title: qsTr("TicTacToeAI")
    width: 1400
    height: 900
    minimumWidth: 1400
    minimumHeight: 900

    property real appRootWidth: appRoot.width
    property real appRootHeight: appRoot.height

    // MAIN STACKVIEW
    StackView {
        id: mainStack
        width: appRootWidth
        height: appRootHeight
        initialItem: startScreenPageComp
        focus: true

        popEnter: Transition {
            XAnimator {
                from: (mainStack.mirrored ? -1 : 1) * -mainStack.width
                to: 0
                duration: 400
                easing.type: Easing.OutCubic
            }
        }

        popExit: Transition {
            XAnimator {
                from: 0
                to: (mainStack.mirrored ? -1 : 1) * mainStack.width
                duration: 400
                easing.type: Easing.OutCubic
            }
        }

        pushEnter: Transition {
            XAnimator {
                from: (mainStack.mirrored ? -1 : 1) * -mainStack.width
                to: 0
                duration: 400
                easing.type: Easing.OutCubic
            }
        }

        pushExit: Transition {
            XAnimator {
                from: 0
                to: (mainStack.mirrored ? -1 : 1) * mainStack.width
                duration: 400
                easing.type: Easing.OutCubic
            }
        }

        ScoreScreenPage {
            id: scoreScreenPage
        }
    }

    // START SCREEN PAGE
    Component {
        id: startScreenPageComp

        StartScreenPage {
            id: startScreenPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // OPTIONS SCREEN PAGE
    Component {
        id: optionsScreenPageComp

        OptionsScreenPage{
            id: optionPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // GAMEPLAY SCREEN PAGE
    Component {
        id: gamePlayScreenPageComp

        GamePlayScreenPage {
            id: gamePlayPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // EVENT: openOptionScreen
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openOptionScreen"]
        onOccurred: {
            mainStack.push(optionsScreenPageComp)
        }
    }

    // EVENT: openGamePlayScreen
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openGamePlayScreen"]
        onOccurred: {
            mainStack.push(gamePlayScreenPageComp)
        }
    }

    // EVENT: restartGame
    EventConnection {
        stateMachine: entrance.statechart
        events: ["restartGame"]
        onOccurred: {
            console.log("Main stack current item: ", mainStack.currentItem)
            mainStack.pop()
            mainStack.push(gamePlayScreenPageComp)
        }
    }

}






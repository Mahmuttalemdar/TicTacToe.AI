import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtScxml 5.15

import UIScreens.StartScreen 1.0
import UIScreens.LoginScreen 1.0
import UIScreens.DetectionScreen 1.0
import UIScreens.NFCScreen 1.0

ApplicationWindow {
    id: appRoot
    visible: true
    title: qsTr("TicTacToe.AI")

    property real appRootWidth: appRoot.width
    property real appRootHeight: appRoot.height


    // MAIN STACKVIEW
    StackView {
        objectName: "main_mainStack"
        id: mainStack
        width: appRootWidth
        height: appRootHeight
        initialItem: loginPageComp
        //initialItem: cameraTutorialPageComp
        //initialItem: mrzDetectionPageComp
        //initialItem: mrzResultPageComp
        //initialItem: nfcPageComp
        focus: true

        Keys.onReleased: {
            if (event.key === Qt.Key_Back) {
                event.accepted = true
                entrance.statechart.submitEvent("triggerPreviousPage")
            }
        }
    }

    // LOGIN PAGE
    Component {
        id: loginPageComp

        LoginPage{
            id: loginPage
            width: appRootWidth
            height: appRootHeight
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

    // CAMERA TUTORIAL PAGE
    Component {
        id: cameraTutorialPageComp

        CameraTutorialPage {
            id: cameraTutorialPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // MRZ DETECTION PAGE
    Component {
        id: mrzDetectionPageComp

        MRZDetectionPage {
            id: mrzDetectionPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // MRZ RESULT PAGE
    Component {
        id: mrzResultPageComp

        MRZResultPage {
            id: mrzResultPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // NFC PAGE
    Component {
        id: nfcPageComp

        NFCPage {
            id: nfcPPage
            width: appRootWidth
            height: appRootHeight
        }
    }

    // EVENT: triggerPreviousPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["triggerPreviousPage"]
        onOccurred: {
            console.log("triggerPreviousPage")
        }
    }

    // EVENT: openStartScreenPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openStartScreenPage"]
        onOccurred: {
            mainStack.push(startScreenPageComp)
        }
    }

    // EVENT: openHoldTheCardPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openHoldTheCardPage"]
        onOccurred: {
            mainStack.push(cameraTutorialPageComp)
        }
    }

    // EVENT: openMRZDetectionPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openMRZDetectionPage"]
        onOccurred: {
            mainStack.push(mrzDetectionPageComp)
        }
    }

    // EVENT: openMRZResultPage
    EventConnection {
        stateMachine: entrance.statechart
        events: ["openMRZResultPage"]
        onOccurred: {
            mainStack.push(mrzResultPageComp)
        }
    }

    // EVENT: triggerNFCResult
    EventConnection {
        stateMachine: entrance.statechart
        events: ["triggerNFCResult"]
        onOccurred: {
            mainStack.push(nfcPageComp)
        }
    }
}

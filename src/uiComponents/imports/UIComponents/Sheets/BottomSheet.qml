import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root

    property string sheetBackgroundColor: "#292929"
    property real sheetWidth: 375
    property real sheetHeight: 375
    property real sheetOpacity: 0.5
    property real sheetRadius: 10

    width: sheetWidth
    height: sheetHeight
    radius: sheetRadius
    opacity: sheetOpacity
    color: sheetBackgroundColor
    state: "Close"

    // STATES
    states: [
        State {
            name: "Close"
            PropertyChanges {
                target: root
                height: 0
                visible: true
            }
        },
        State {
            name: "Open"
            PropertyChanges {
                target: root
                height: sheetHeight
                visible: true
            }
        }
    ]

    // TRANSITIONS
    transitions: [
        Transition {
            from: "Close"
            to: "Open"
            NumberAnimation {
                properties: "height";
                easing.type: Easing.InOutQuad
                duration: 700;
            }
        },
        Transition {
            from: "Open"
            to: "Close"
            NumberAnimation {
                properties: "height";
                easing.type: Easing.InOutQuad
                duration: 700;
            }
        }
    ]

}







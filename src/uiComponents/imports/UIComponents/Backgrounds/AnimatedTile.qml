import QtQuick 2.15

// ANIMATED TILE
Item {
    id: root
    width: tileWidth
    height: tileHeight
    rotation: tileRotation
    scale: startScale
    state: "START"

    property int tileWidth: 0
    property int tileHeight: 0
    property int tileRotation: 0
    property string tileImage: "qrc:/imports/Theme/images/Tiles/TileX.svg"

    property int duration: 0
    property real startCoordinateX: 0
    property real startCoordinateY: 0
    property real endCoordinateX: 0
    property real endCoordinateY: 0

    property int startRotation: 0
    property int endRotation: 0
    property int ongoingRotation: 0

    property int animationX: 0
    property int animationY: 0

    property real startScale: 1
    property real endScale: 1
    property real ongoingScale: 1

    onStateChanged: {
        if(root.state === "END" && !animationTimer.running)
        {
            animationTimer.start()
        }
    }

    // BACKGROUND
    Image {
        id: tileXImage
        anchors.fill: parent
        source: tileImage
    }

    // STATES
    states: [
        State {
            name: "START"
            PropertyChanges {
                target: root
                x: startCoordinateX
                y: startCoordinateY
                rotation: startRotation
                scale: startScale
            }
        },
        State {
            name: "END"
            PropertyChanges {
                target: root
                x: endCoordinateX
                y: endCoordinateY
                rotation: endRotation
                scale: endScale
            }
        },
        State {
            name: "ONGOING"
            PropertyChanges {
                target: root
                x: endCoordinateX + animationX
                y: endCoordinateY + animationY
                rotation: ongoingRotation
                scale: ongoingScale
            }
        }
    ]

    // TRANSITIONS
    transitions: [
        Transition {
            from: "*"
            to: "START"
            NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad; duration: duration }
            NumberAnimation { properties: "scale"; easing.type: Easing.Bezier; duration: duration }
            NumberAnimation { properties: "rotation"; easing.type: Easing.Bezier; duration: duration }
        },
        Transition {
            from: "START"
            to: "END"
            NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad; duration: duration }
            NumberAnimation { properties: "scale"; easing.type: Easing.Bezier; duration: duration }
            NumberAnimation { properties: "rotation"; easing.type: Easing.Bezier; duration: duration }
        },
        Transition {
            from: "*"
            to: "ONGOING"
            reversible: true
            NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad; duration: duration }
            NumberAnimation { properties: "scale"; easing.type: Easing.Bezier; duration: duration }
            NumberAnimation { properties: "rotation"; easing.type: Easing.Bezier; duration: duration }
        }
    ]

    // TIMER
    Timer {
        id: animationTimer
        interval: root.duration
        repeat: true

        onTriggered: {
            if(root.state === "END")
            {
                root.state = "ONGOING"
            }
            else if(root.state === "ONGOING")
            {
                root.state = "END"
            }
        }
    }
}

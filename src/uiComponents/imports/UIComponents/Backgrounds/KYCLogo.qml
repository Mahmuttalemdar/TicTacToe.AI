import QtQuick 2.15

Item {
    id: root
    width: parent.width
    height: parent.height
    state: "Close"

    property int midX: (parent.width / 2) - root.width / 2
    property int midY: (parent.height / 2) - root.height / 2
    property int newY: (parent.height / 2) - (parent.height * 2 / 9) - root.height / 2
    property bool playAnimation: false

    // BACKGROUND IMAGE
    AnimatedImage {
        id: logoImage
        anchors.fill: parent
        source: "qrc:/imports/Theme/images/LoginScreen/kyc_logo.gif"
        playing: true
        speed: 0.8

        onFrameChanged: {
            if(!playAnimation) {
                if(currentFrame === (frameCount - 2)) {
                    logoImage.playing = false
                }
            }
        }
    }

    // STATES
    states: [
        State {
            name: "Close"
            PropertyChanges {
                target: root
                x: midX
                y: midY
                playAnimation: true
            }
        },
        State {
            name: "Open"
            PropertyChanges {
                target: root
                x: midX
                y: newY
                playAnimation: false
            }
        }
    ]

    // TRANSITIONS
    transitions: [
        Transition {
            from: "*"
            to: "Close"
            PropertyAnimation {
                properties: "y,x"
                easing.type: Easing.InOutQuad
                duration: 0;
            }
        },
        Transition {
            from: "Close"
            to: "Open"
            PropertyAnimation {
                properties: "y,x"
                easing.type: Easing.InOutQuad
                duration: 700;
            }
        }
    ]

}

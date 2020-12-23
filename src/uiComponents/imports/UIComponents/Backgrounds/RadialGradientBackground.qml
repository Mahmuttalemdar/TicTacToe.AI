import QtQuick 2.15
import QtGraphicalEffects 1.15

Rectangle {
    id: root
    width: parent.width
    height: parent.height

    property real duration: 1500
    property real horizontalOffset: 50
    property real verticalOffset: -60
    property string imageSource: ""

    Image {
        id: backgorundImage
        anchors.fill: parent
        source: root.imageSource
    }

    RadialGradient {
        anchors.fill: parent
        horizontalOffset: root.horizontalOffset
        verticalOffset: root.verticalOffset
        horizontalRadius: parent.width * 2 / 3
        verticalRadius: parent.height * 2 / 3
        angle: 0
        opacity: 1

        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop {
                position: 1.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "#14148c"; to: "#0E1533"; duration: root.duration }
                    ColorAnimation { from: "#0E1533"; to: "#14148c"; duration: root.duration }
                }
            }
            GradientStop {
                position: 0.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "#14aaff"; to: "#437284"; duration: root.duration }
                    ColorAnimation { from: "#437284"; to: "#14aaff"; duration: root.duration }
                }
            }
        }

        source: Image {
            source: root.imageSource
        }
    }


}

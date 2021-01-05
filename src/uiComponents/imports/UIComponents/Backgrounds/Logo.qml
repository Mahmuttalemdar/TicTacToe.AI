import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: root
    width: 175
    height: 200

    property string dashColor: "#FFFFFF"
    property int dasherDuration: 700
    property int shapeInnerDistance: 12
    property int shapeStrokeWidth: 4
    property real shapeOpacity: 0.3

    // DASHED SHAPE
    Shape {
        id: shape
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        opacity: root.shapeOpacity

        property int cornerLength: shape.width / 10
        property int shapeRadius: shape.cornerWidth / 2

        // SHAPE PATH (DASHES)
        ShapePath {
            id: dashesShapePath
            startX: shape.cornerLength
            startY: 0

            strokeWidth: root.shapeStrokeWidth
            strokeColor: root.dashColor
            strokeStyle: ShapePath.DashLine
            dashPattern: [ 3, 5 ]
            capStyle: ShapePath.RoundCap

            // TOP
            PathLine { x: shape.width - shape.cornerLength; y: 0 }

            // RIGHT-TOP
            PathArc {
                x: shape.width
                y: shape.cornerLength
                radiusX: shape.cornerLength
                radiusY: shape.cornerLength
            }

            // RIGHT
            PathLine { x: shape.width; y: shape.height - shape.cornerLength }

            // RIGHT-BOTTOM
            PathArc {
                x: shape.width - shape.cornerLength
                y: shape.height
                radiusX: shape.cornerLength
                radiusY: shape.cornerLength
            }

            // BOTTOM
            PathLine { x: shape.cornerLength; y: shape.height }

            // LEFT-BOTTOM
            PathArc {
                x: 0
                y: shape.height - shape.cornerLength
                radiusX: shape.cornerLength
                radiusY: shape.cornerLength
            }

            // BOTTOM
            PathLine { x: 0; y: shape.cornerLength }

            // LEFT-TOP
            PathArc {
                x: shape.cornerLength
                y: 0
                radiusX: shape.cornerLength
                radiusY: shape.cornerLength
            }

            // GRADIENT COLOR
            fillGradient: LinearGradient {
                x1: 0; y1: 0
                x2: shape.width; y2: shape.height
                GradientStop { position: 0; color: "transparent" }
                GradientStop { position: 1; color: "transparent" }
            }

        }
    }

    // LOGO IMAGE
    Image {
        width: parent.width - root.shapeInnerDistance
        height: parent.height- root.shapeInnerDistance
        source: "qrc:/imports/Theme/images/Logo/Logo.svg"

        anchors.centerIn: parent
    }

    // DASHER TIMER
    Timer {
        id: dasherTimer
        interval: root.dasherDuration
        repeat: true

        property int dashState: 0

        onTriggered: {
            if(dashState === 0) {
                dashesShapePath.dashPattern = [ 3, 5 ]
            }
            else if(dashState === 1)
            {
                dashesShapePath.dashPattern = [ 4, 4 ]
            }
            else if(dashState === 2)
            {
                dashesShapePath.dashPattern = [ 5, 3 ]
            }
            else if(dashState === 3)
            {
                dashesShapePath.dashPattern = [ 6, 2 ]
            }
            else if(dashState === 4)
            {
                dashesShapePath.dashPattern = [ 7, 1 ]
            }
            else if(dashState === 5)
            {
                dashesShapePath.dashPattern = [ 6, 2 ]
            }
            else if(dashState === 6)
            {
                dashesShapePath.dashPattern = [ 5, 3 ]
            }
            else if(dashState === 7)
            {
                dashesShapePath.dashPattern = [ 4, 4 ]
            }
            else if(dashState === 8)
            {
                dashesShapePath.dashPattern = [ 3, 5 ]
            }

            if(dashState < 8) {
                dashState = dashState + 1
            }
            else {
                dashState = 0
            }
        }
    }

    Component.onCompleted: dasherTimer.stop()

}

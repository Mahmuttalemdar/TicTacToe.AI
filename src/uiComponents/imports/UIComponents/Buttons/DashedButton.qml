import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

Button {
    id: root

    property real buttonWidth: 164
    property real buttonHeight: 54
    property real buttonOpacity: 1
    property string buttonText: "Button"
    property string buttonTextColor: "#FFFFFF"
    property string buttonBackgroundPrimaryColor: "#D7386F"
    property string buttonBackgroundSecondaryColor: "#8159E6"
    property string buttonDashColor: "#FFFFFF"
    property int buttonShapeInnerDistance: 12
    property int buttonDasherDuration: 700
    property int buttonFontSize: 22
    property int buttonStrokeWidth: 3
    property bool isAnimateable: false

    width: buttonWidth
    height: buttonHeight

    // BUTTON BACKGROUND
    background: Item {
        id: itemRoot
        width: root.width
        height: root.height
        opacity: root.buttonOpacity

        property string itemText: root.buttonText
        property string itemTextColor: root.buttonTextColor
        property int itemFontSize: root.buttonFontSize
        property string dashColor: root.buttonDashColor
        property string backgroundPrimaryColor: root.buttonBackgroundPrimaryColor
        property string backgroundSecondaryColor: root.buttonBackgroundSecondaryColor
        property int shapeInnerDistance: root.buttonShapeInnerDistance
        property int dasherDuration: root.buttonDasherDuration

        // DASHED SHAPE
        Shape {
            id: shape
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            property int shapeRadius: shape.height * 1 / 3

            // SHAPE PATH (DASHES)
            ShapePath {
                id: dashesShapePath
                startX: shape.shapeRadius / 2
                startY: 0

                strokeWidth: root.buttonStrokeWidth
                strokeColor: itemRoot.dashColor
                strokeStyle: ShapePath.DashLine
                dashPattern: [ 3, 5 ]
                capStyle: ShapePath.RoundCap

                // TOP
                PathLine { x: shape.width - shape.shapeRadius / 2; y: 0 }

                // RIGHT
                PathArc {
                    x: shape.width - shape.shapeRadius / 2;
                    y: shape.height
                    radiusX: shape.shapeRadius
                    radiusY: shape.shapeRadius
                }

                // BOTTOM
                PathLine { x: shape.shapeRadius / 2; y: shape.height }

                // LEFT
                PathArc {
                    x: shape.shapeRadius / 2;
                    y: 0
                    radiusX: shape.shapeRadius
                    radiusY: shape.shapeRadius
                }

                // GRADIENT COLOR
                fillGradient: LinearGradient {
                    x1: 0; y1: 0
                    x2: shape.width; y2: shape.height
                    GradientStop { position: 0; color: "transparent" }
                    GradientStop { position: 1; color: "transparent" }
                }

            }

            // SHAPE PATH (GRADIENT)
            ShapePath {
                id: gradientShapePath
                startX: dashesShapePath.startX + itemRoot.shapeInnerDistance
                startY: dashesShapePath. startY + itemRoot.shapeInnerDistance

                strokeWidth: 0
                strokeColor: "transparent"
                capStyle: ShapePath.RoundCap

                // TOP
                PathLine { x: shape.width - shape.shapeRadius / 2 - itemRoot.shapeInnerDistance; y: itemRoot.shapeInnerDistance }

                // RIGHT
                PathArc {
                    x: shape.width - shape.shapeRadius / 2;
                    y: shape.height - itemRoot.shapeInnerDistance
                    radiusX: shape.shapeRadius
                    radiusY: shape.shapeRadius
                }

                // BOTTOM
                PathLine { x: shape.shapeRadius / 2 + itemRoot.shapeInnerDistance; y: shape.height - itemRoot.shapeInnerDistance }

                // LEFT
                PathArc {
                    x: shape.shapeRadius / 2 + itemRoot.shapeInnerDistance;
                    y: itemRoot.shapeInnerDistance
                    radiusX: shape.shapeRadius
                    radiusY: shape.shapeRadius
                }

                // GRADIENT COLOR
                fillGradient: LinearGradient {
                    x1: 0; y1: 0
                    x2: shape.width; y2: shape.height
                    GradientStop { position: 0; color:  itemRoot.backgroundPrimaryColor; }
                    GradientStop { position: 1; color:  itemRoot.backgroundSecondaryColor; }
                }
            }

            // BUTTON TEXT
            Text {
                text: itemRoot.itemText
                font.family: "Chalkboard SE"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: itemRoot.itemFontSize
                font.letterSpacing: 0.7
                color: itemRoot.itemTextColor
                anchors.centerIn: parent
            }

        }

        // DASHER TIMER
        Timer {
            id: dasherTimer
            interval: itemRoot.dasherDuration
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
    }

    onIsAnimateableChanged: {
        if(isAnimateable)
        {
            dasherTimer.start()
        }
        else{
            dasherTimer.stop()
        }
    }
}







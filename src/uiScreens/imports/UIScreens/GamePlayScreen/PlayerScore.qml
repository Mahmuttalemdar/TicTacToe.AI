import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: root
    width: 175
    height: 200

    property string itemText: "Choose your shape"
    property string itemTextColor: "#FFFFFF"
    property int itemFontSize: 22
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

        // SHAPE PATH (DASHES)
        ShapePath {
            id: dashesShapePath
            startX: 0
            startY: 0

            strokeWidth: root.shapeStrokeWidth
            strokeColor: root.dashColor
            strokeStyle: ShapePath.DashLine
            dashPattern: [ 3, 5 ]
            capStyle: ShapePath.RoundCap

            // TOP
            PathLine { x: shape.width; y: 0 }

            // GRADIENT COLOR
            fillGradient: LinearGradient {
                x1: 0; y1: 0
                x2: shape.width; y2: shape.height
                GradientStop { position: 0; color: "transparent" }
                GradientStop { position: 1; color: "transparent" }
            }

        }
    }

    // TITLE TEXT
    Rectangle {
        id: scoreItem
        width: 25
        height: 25
        color: "red"
        visible: false
    }

}

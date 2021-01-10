import QtQuick 2.15
import QtQuick.Shapes 1.15

Rectangle {
    id: root
    width: parent.height
    height: parent.height
    color: "transparent"
    anchors.centerIn: parent

    property string dashColor: "#FFFFFF"
    property int dasherDuration: 700
    property int shapeInnerDistance: 12
    property int shapeStrokeWidth: 2
    property real shapeOpacity: 1.0
    property int lineSpacing: root.width / 15

    property int moveTime: 1000

    // DASHED SHAPE (OUTLINES)
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

    // HORIZONTAL LINES REPEATER
    Repeater {
        id: horizontalRepeater
        width: parent.width
        height: parent.height
        model: entrance.gameSettings.gridSize - 1

        // HORIZONTAL LINES
        Shape {
            id: horizontalLinesShape
            width: root.width
            height: root.height
            anchors.centerIn: root
            opacity: root.shapeOpacity

            // HORIZONTAL LINE
            ShapePath {
                id: horizontalLine
                startX: root.lineSpacing
                startY: (horizontalLinesShape.height / entrance.gameSettings.gridSize) * (index + 1)

                strokeWidth: root.shapeStrokeWidth
                strokeColor: root.dashColor
                strokeStyle: ShapePath.DashLine
                dashPattern: [ 3, 5 ]
                capStyle: ShapePath.RoundCap

                // LINE 1
                PathLine { x: horizontalLinesShape.width - root.lineSpacing; y: ((horizontalLinesShape.height / entrance.gameSettings.gridSize) * (index + 1)) }

                // GRADIENT COLOR
                fillGradient: LinearGradient {
                    x1: 0; y1: 0
                    x2: horizontalLinesShape.width; y2: horizontalLinesShape.height
                    GradientStop { position: 0; color: "transparent" }
                    GradientStop { position: 1; color: "transparent" }
                }
            }
        }
    }

    // VERTICAL LINES REPEATER
    Repeater {
        id: verticalRepeater
        width: parent.width
        height: parent.height
        model: entrance.gameSettings.gridSize - 1

        // HORIZONTAL LINES
        Shape {
            id: verticalLinesShape
            width: root.width
            height: root.height
            anchors.centerIn: root
            opacity: root.shapeOpacity

            // HORIZONTAL LINE
            ShapePath {
                id: verticalLine
                startY: root.lineSpacing
                startX: (verticalLinesShape.width / entrance.gameSettings.gridSize) * (index + 1)

                strokeWidth: root.shapeStrokeWidth
                strokeColor: root.dashColor
                strokeStyle: ShapePath.DashLine
                dashPattern: [ 3, 5 ]
                capStyle: ShapePath.RoundCap

                // LINE 1
                PathLine { x: ((verticalLinesShape.width / entrance.gameSettings.gridSize) * (index + 1)); y: verticalLinesShape.height - root.lineSpacing }

                // GRADIENT COLOR
                fillGradient: LinearGradient {
                    x1: 0; y1: 0
                    x2: verticalLinesShape.width; y2: verticalLinesShape.height
                    GradientStop { position: 0; color: "transparent" }
                    GradientStop { position: 1; color: "transparent" }
                }
            }
        }
    }

    // BOARD GRID VIEW
    GridView {
        id: boardGrid
        width: parent.width - gridPadding
        height: parent.height - gridPadding
        interactive: true

        cellWidth: boardGrid.width / entrance.gameSettings.gridSize
        cellHeight: boardGrid.height / entrance.gameSettings.gridSize

        property int gridPadding: 10
        property int tilePadding: 10

        model: entrance.gameSettings.gridSize * entrance.gameSettings.gridSize
        delegate: tileComp

        anchors.left: parent.left
        anchors.leftMargin: tilePadding
        anchors.top: parent.top
        anchors.topMargin: tilePadding
    }

    // TILE COMPONENT
    Component {
        id: tileComp

        Item {
            id: boardRect
            width: boardGrid.cellWidth - boardGrid.tilePadding
            height: boardGrid.cellHeight - boardGrid.tilePadding
            opacity: 1

            property int cellRow: index / entrance.gameSettings.gridSize
            property int cellColumn: index % entrance.gameSettings.gridSize
            property int clipperRectRadius: clipperRect.width

            property string defaultBackgroundColor: "#421791"
            property string selectedBackgroundColor: "#FFD652"

            // DYNAMIC RECTANGLE WITH CORNER
            Rectangle {
                id: clipperRect
                width: parent.width / 4
                height: parent.height / 4
                color: "transparent"
                clip: true

                Rectangle {
                    id: clippedRect
                    width: parent.width * 3
                    height: parent.height * 3
                    radius: boardRect.clipperRectRadius
                    color: boardRect.defaultBackgroundColor
                }
            }

            // SUB-DYNAMIC RECTANGLE
            Rectangle {
                anchors.left: clipperRect.right
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                color: clippedRect.color
            }

            // SUB-DYNAMIC RECTANGLE
            Rectangle {
                anchors.top: clipperRect.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                color: clippedRect.color
            }

            // TILE IMAGE
            Item {
                id: tileImageItem
                rotation: -boardRect.rotation
                width: parent.width * 3 / 4
                height: parent.height * 3 / 4
                anchors.centerIn: parent

                Image {
                    id: tileImage
                    source: ""
                    fillMode: Image.PreserveAspectFit
                    asynchronous: false
                    anchors.fill: parent
                }
            }

            // MOUSE AREA
            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.log("Clicked :: X: ", cellRow)
                    console.log("Clicked :: Y: ", cellColumn)

                    if(!entrance.gameController.isPlayed(cellRow, cellColumn))
                    {
                        tileImage.source = entrance.gameSettings.humanTile.image
                        entrance.gameController.isPlayLock = true;
                        root.delay(root.moveTime, function() {
                            entrance.gameController.humanPlayedAt(cellRow, cellColumn)
                        })
                    }
                    else {
                        console.log("Tile already played: X: ", cellRow, " Y: ",cellColumn)
                    }
                }
            }

            // CONNECTIONS
            Connections {
                target: entrance.gameController
                function onUpdateAIPlayerOnUI(row, column)
                {
                    if(entrance.gameController.isPlayed(cellRow, cellColumn)
                            && boardRect.cellRow === row
                            && boardRect.cellColumn === column)
                    {
                        tileImage.source = entrance.gameSettings.aiTile.image
                    }
                }
            }

            // COMPONENT ONCOMPLETED
            Component.onCompleted: {
                // TOP-LEFT
                if(boardRect.cellRow === 0 && boardRect.cellColumn === 0) {
                    boardRect.rotation = 0;
                }
                else if(boardRect.cellRow === 0 && boardRect.cellColumn === (entrance.gameSettings.gridSize - 1)) {
                    boardRect.rotation = 90;
                }
                else if(boardRect.cellRow === (entrance.gameSettings.gridSize - 1) && boardRect.cellColumn === 0) {
                    boardRect.rotation = -90;
                }
                else if(boardRect.cellRow === (entrance.gameSettings.gridSize - 1) && boardRect.cellColumn === (entrance.gameSettings.gridSize - 1)) {
                    boardRect.rotation = 180;
                }
                else {
                    boardRect.rotation = 0;
                    boardRect.clipperRectRadius = 0
                }
            }
        }
    }

    // TIMER FOR MOVE
    Timer {
        id: moveTimer
    }

    // Delay function for tile move
    function delay(delayTime, cb) {
        moveTimer.interval = delayTime;
        moveTimer.repeat = false;
        moveTimer.triggered.connect(cb);
        moveTimer.start();
    }

}

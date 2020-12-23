import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtScxml 5.15
import QtQuick.Shapes 1.15

import UIComponents.Backgrounds 1.0

import UIScreens.StartScreen 1.0
import UIScreens.LoginScreen 1.0
import UIScreens.DetectionScreen 1.0
import UIScreens.NFCScreen 1.0

ApplicationWindow {
    id: appRoot
    visible: true
    title: qsTr("TicTacToe.AI")
    width: 1400
    height: 900
    minimumWidth: 1400
    minimumHeight: 900

    property real appRootWidth: appRoot.width
    property real appRootHeight: appRoot.height

    // START SCREEN
    Rectangle {
        id: startScreen
        width: parent.width
        height: parent.height
        color: "red"

        // BACKGROUND
        Image {
            id: backgroundImage
            width: parent.width
            height: parent.height
            source: "qrc:/imports/Theme/images/Backgrounds/Background2.svg"
        }

        // BOARD
        Item {
            id: board
            width: 500
            height: 500

            anchors.top: parent.top
            anchors.topMargin: 120
            anchors.horizontalCenter: parent.horizontalCenter

            // BOARD BACKGROUND
            Image {
                id: boardImage
                width: parent.width
                height: parent.height
                source: "qrc:/imports/Theme/images/Backgrounds/Board.svg"
            }

            // ROW 1
            Shape {
                id: row1
                width: board.width

                ShapePath {
                    strokeColor: "white"
                    strokeWidth: 3
                    strokeStyle: ShapePath.DashLine

                    startX: 0
                    startY: board.height / 3

                    // PATH
                    PathLine { x: board.width; y: board.height / 3 }
                }
            }

            // ROW 2
            Shape {
                id: row2
                width: board.width

                ShapePath {
                    strokeColor: "white"
                    strokeWidth: 3
                    strokeStyle: ShapePath.DashLine

                    startX: 0
                    startY: board.height * (2 / 3)

                    // PATH
                    PathLine { x: board.width; y: board.height * (2 / 3) }
                }
            }

            // COLUMN 1
            Shape {
                id: column1
                width: board.height

                ShapePath {
                    strokeColor: "white"
                    strokeWidth: 3
                    strokeStyle: ShapePath.DashLine

                    startX: board.width / 3
                    startY: 0

                    // PATH
                    PathLine { x: board.width / 3; y: board.height }
                }
            }

            // COLUMN 2
            Shape {
                id: column2
                width: board.height

                ShapePath {
                    strokeColor: "white"
                    strokeWidth: 3
                    strokeStyle: ShapePath.DashLine

                    startX: board.width * 2 / 3
                    startY: 0

                    // PATH
                    PathLine { x: board.width * 2 / 3; y: board.height }
                }
            }

            // GRID
            Grid {
                id: boardGrid
                width: parent.width
                height: parent.height
                flow: Grid.LeftToRight
                layoutDirection: Qt.LeftToRight

                rows: entrance.gameController.gridSize
                columns: entrance.gameController.gridSize
                spacing: 6

                // REPEATER
                Repeater{
                    id: boardRepeater
                    model: boardGrid.rows * boardGrid.columns

                    Rectangle {
                        id: boardRect
                        width: boardGrid.width / boardGrid.columns - boardGrid.spacing
                        height: boardGrid.height / boardGrid.rows - boardGrid.spacing
                        color: "purple"

                        property int cellRow: index / boardGrid.rows
                        property int cellColumn: index % boardGrid.columns

                        Item {
                            id: tileImageItem
                            anchors.fill: parent

                            Image {
                                id: tileImage
                                source: ""
                                fillMode: Image.PreserveAspectFit
                                asynchronous: false
                                anchors.fill: parent
                            }
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                console.log("Clicked :: X: ", cellRow)
                                console.log("Clicked :: Y: ", cellColumn)

                                if(!entrance.gameController.isPlayed(cellRow, cellColumn))
                                {
                                    tileImage.source = "qrc:/imports/Theme/images/Tiles/TileX.svg"
                                    entrance.gameController.humanPlayedAt(cellRow, cellColumn)
                                }
                                else {
                                    console.log("Tile already played: X: ", cellRow, " Y: ",cellColumn)
                                }
                            }
                        }


                        Connections {
                            target: entrance.gameController
                            function onUpdateAIPlayerOnUI(row, column)
                            {
                                if(entrance.gameController.isPlayed(cellRow, cellColumn)
                                        && boardRect.cellRow === row
                                        && boardRect.cellColumn === column)
                                {
                                    tileImage.source = "qrc:/imports/Theme/images/Tiles/TileO.svg"
                                }
                                else {
                                    console.log("Tile already played: X: ", cellRow, " Y: ",cellColumn)
                                }
                            }
                        }

                    }

                }
            }
        }
    }
}






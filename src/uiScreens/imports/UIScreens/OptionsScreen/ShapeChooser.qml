import QtQuick 2.15
import QtGraphicalEffects 1.15

import UIComponents.Buttons 1.0

// OPTION BOARD
Rectangle {
    id: root
    color: boardColor

    property string boardColor: "#411597"
    property int shapeSize: root.height

    // TOP RECT
    Rectangle {
        width: parent.width
        height: 20
        opacity: 0.3
        color: boardColor

        anchors.top: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }

    // BOTTOM RECT
    Rectangle {
        width: parent.width
        height: 20
        opacity: 0.3
        color: boardColor

        anchors.bottom: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }

    // SHAPE LIST
    ListView {
        id: shapeList
        width: (parent.height * shapeList.count) + (spacing * shapeList.count)
        height: parent.height
        spacing: 20
        orientation: ListView.Horizontal
        delegate: shapeComponent
        model: entrance.gameController.tileShapeModel
        anchors.horizontalCenter: parent.horizontalCenter

        signal clearAll();
    }

    // SHAPE COMPONENT
    Component {
        id: shapeComponent

        Item {
            id: shapeItem
            width: root.shapeSize
            height: root.shapeSize

            property bool isSelected: false

            Image {
                id: shapeItemImage
                source: shapeImage
                width: root.shapeSize - shapeList.spacing
                height: root.shapeSize - shapeList.spacing
                anchors.centerIn: parent

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: {
                        chooseItem();
                    }

                    onEntered: {
                        if(shapeItem.isSelected === true) {
                            defaultChooseArea.source = mockSource;
                            innerChooseArea.source = shapeItemImage;
                            outerChooseArea.source = shapeItemImage;
                        }
                        else {
                            shapeItemImage.width = shapeItemImage.width + shapeList.spacing * 2
                            shapeItemImage.height = shapeItemImage.height + shapeList.spacing * 2

                            defaultChooseArea.source = shapeItemImage;
                            innerChooseArea.source = mockSource;
                            outerChooseArea.source = mockSource;
                        }
                    }

                    onExited: {
                        if(shapeItem.isSelected === true) {
                            defaultChooseArea.source = mockSource;
                            innerChooseArea.source = shapeItemImage;
                            outerChooseArea.source = shapeItemImage;
                        }
                        else {
                            shapeItemImage.width = root.shapeSize - shapeList.spacing
                            shapeItemImage.height = root.shapeSize - shapeList.spacing

                            defaultChooseArea.source = shapeItemImage;
                            innerChooseArea.source = mockSource;
                            outerChooseArea.source = mockSource;
                        }
                    }
                }

                transitions: Transition {
                    from: "*"; to: "*";
                    NumberAnimation { properties: "width,height"; easing.type: Easing.InOutQuad; duration: 700}
                }
            }

            Connections {
                target: shapeList
                function onClearAll() {
                    shapeItem.isSelected = false
                    shapeItemImage.width = root.shapeSize - shapeList.spacing
                    shapeItemImage.height = root.shapeSize - shapeList.spacing
                    defaultChooseArea.source = shapeItemImage;
                    innerChooseArea.source = mockSource;
                    outerChooseArea.source = mockSource;
                }
            }

            // DROP SHADOW
            DropShadow {
                id: defaultChooseArea
                anchors.fill: shapeItemImage
                horizontalOffset: 3
                verticalOffset: 3
                radius: 8.0
                samples: 17
                color: "#80000000"
                source: shapeItemImage
            }

            // DROP SHADOW
            DropShadow {
                id: innerChooseArea
                anchors.fill: shapeItemImage
                horizontalOffset: 0
                verticalOffset: 0
                radius: 12
                samples: 40
                spread: 1.0
                color: "#03EEA9"
                source: mockSource
            }

            // DROP SHADOW
            DropShadow {
                id: outerChooseArea
                anchors.fill: shapeItemImage
                horizontalOffset: 0
                verticalOffset: 0
                radius: 20
                samples: 40
                spread: 1.0
                color: "#8003EEA9"
                source: mockSource
            }

            // MOCK IMAGE SOURCE
            Item {
                id: mockSource
            }


            // FIST ITEM CHOOSE ON COMPLETED
            Component.onCompleted: {
                if(index === 0) {
                    chooseItem();
                }
            }

            // Choose Item
            function chooseItem() {
                // Clear all choosed shapes
                shapeList.clearAll();

                shapeItem.isSelected = true
                shapeItemImage.width = shapeItemImage.width + shapeList.spacing * 2
                shapeItemImage.height = shapeItemImage.height + shapeList.spacing * 2

                defaultChooseArea.source = mockSource;
                innerChooseArea.source = shapeItemImage;
                outerChooseArea.source = shapeItemImage;

                entrance.gameController.selectShapeByIndex(index);
            }
        }

    }

}

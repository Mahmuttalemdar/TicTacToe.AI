import QtQuick 2.15

Rectangle {
    id: root
    width: parent.width
    height: parent.height

    property string imageSource: ""

    Image {
        id: backgorundImage
        anchors.fill: parent
        source: root.imageSource
    }

}

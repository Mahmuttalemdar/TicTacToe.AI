import QtQuick 2.15

// OPTION BOARD
Item {
    id: root
    width: parent.width - (parent.width * 2 / 9 )
    height: parent.height - (parent.height / 3)

    anchors.left: parent.left
    anchors.leftMargin: parent.width / 9
    anchors.top: parent.top
    anchors.topMargin: parent.height / 12
}

import QtQuick 2.15
import QtGraphicalEffects 1.15

import Core.Data 1.0

Item {
    id: root
    width: parent.width
    height: parent.height

    // MEDIUM OPTION AREA
    Item {
        id: mediumOptionArea
        width: parent.height
        height: parent.height
        anchors.centerIn: parent

        Image {
            id: mediumOption
            width: parent.height / 2
            height: parent.height / 2
            source: "qrc:/imports/Theme/images/Player/PlayerProfile.svg"
            anchors.bottom: mediumOptionText.top
            anchors.bottomMargin: 2
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // TITLE TEXT
        TextEdit {
            id: mediumOptionText
            width: parent.width
            text: "Player1"
            font.family: "Chalkboard SE"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 28
            font.letterSpacing: 0.7
            color: "#FFFFFF"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }

}

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Label {
    id: control
    property Action action: null
    property alias acceptedButtons: area.acceptedButtons
    property alias mouseArea: area
    Accessible.role: Accessible.Button
    Accessible.name: text
    Accessible.onPressAction: control.clicked(null)

    text: action ? action.text : ""
    enabled: !action || action.enabled
    onClicked: if (action) action.trigger()

    font.family: "Montserrat"
    font.pixelSize: 16
    font.weight: Font.Medium
    font.letterSpacing: 0
    font.underline: control.enabled && area.containsMouse
    color: enabled ? "#D8D8D8" : "#7B7F85"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    elide: Text.ElideRight

    signal pressed(QtObject mouse)
    signal clicked(QtObject mouse)

    MouseArea {
        id: area
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: control.clicked(mouse)
        onPressed: control.pressed(mouse)
    }
}







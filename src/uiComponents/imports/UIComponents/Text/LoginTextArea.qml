import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Item {
    id: root

    property string iconSource: "qrc:/imports/Theme/images/LoginScreen/icon_user.svg"
    property string placeholderText: "Username"
    property string textBackgroundColor: "#121212"
    property string textBorderColor: "#3C3C3C"
    property string textColor: "#7B7F85"
    property real textMargin: 32
    property real textRadius: 10
    property bool isPassword: false
    property bool canShow: !isPassword

    height: 54
    anchors.left: parent.left
    anchors.leftMargin: textMargin
    anchors.right: parent.right
    anchors.rightMargin: textMargin

    onCanShowChanged: {
        if(canShow) {
            textField.echoMode = TextInput.Normal
        }
        else {
            textField.echoMode = TextInput.Password
        }
    }

    TextField {
        id: textField
        anchors.fill: parent
        font.family: "Montserrat"
        font.pixelSize: 16
        font.weight: Font.Medium
        color: textColor

        leftPadding: 56
        rightPadding: isPassword ? 56 : 16
        placeholderText: root.placeholderText
        placeholderTextColor: textColor
        echoMode: isPassword ? TextInput.Password : TextInput.Normal

        background: Rectangle {
            color:textBackgroundColor
            radius: textRadius
            border.color: textBorderColor
            border.width: 1

            // LEFT ICON
            Image {
                source: root.iconSource
                anchors.left: parent.left
                anchors.leftMargin: 16
                anchors.verticalCenter: parent.verticalCenter
            }

            // RIGHT ICON
            Image {
                visible: isPassword
                source: root.canShow ?
                          "qrc:/imports/Theme/images/LoginScreen/icon_show_hide_show.svg"
                        : "qrc:/imports/Theme/images/LoginScreen/icon_show_hide_hide.svg"
                anchors.right: parent.right
                anchors.rightMargin: 16
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.canShow = !root.canShow
                    }
                }
            }
        }
    }
}







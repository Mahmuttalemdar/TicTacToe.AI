import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

import Core.Vision 1.0
import UIComponents.Buttons 1.0

Rectangle {
    id : root
    color: "black"

    // CAMERA
    Camera {
        id: camera
        captureMode: Camera.CaptureVideo
    }

    // VIDEO OUTPUT
    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        source: camera
        focus: visible
        autoOrientation: true
        visible: true
        fillMode: VideoOutput.PreserveAspectCrop;
        filters: [entrance.engineController.mrzDetectionFilter]
    }

    Connections {
        target: entrance.engineController.mrzDetectionFilter
        function onObjectDetected(result, x, y, w, h)
        {
            console.log("RESULT :: ", result)
            if((w === 0) || (h === 0))
            {
                resultText.visible = false;
            }
            else
            {
                var r = videoOutput.mapNormalizedRectToItem(Qt.rect(x, y, w, h));
                resultText.x = r.x;
                resultText.y = r.y;
                resultText.width = r.width;
                resultText.height = r.height;
                resultText.visible = true;
                resultText.text = result;
            }
        }
    }

//    MRZDetectionFilter
//    {
//        id: mrzDetectionFilter
//        onObjectDetected:
//        {
//            if((w == 0) || (h == 0))
//            {
//                resultText.visible = false;
//            }
//            else
//            {
//                var r = videoOutput.mapNormalizedRectToItem(Qt.rect(x, y, w, h));
//                resultText.x = r.x;
//                resultText.y = r.y;
//                resultText.width = r.width;
//                resultText.height = r.height;
//                resultText.visible = true;
//                resultText.text = result;
//            }
//        }
//    }

    // MRZ RESULT TEXT
    Text {
        id: resultText
        text: ""
        font.pointSize: 12
        color: "green"
        visible: false
    }


    // BACK BUTTON
    IconButton {
        id: backButton
        buttonIcon: "qrc:/imports/Theme/images/StartScreen/icon_back.svg"
        buttonIconColor: "#FFFFFF"
        buttonBackgroundColor: "#292929"
        buttonSize: 40
        buttonOpacity: 1

        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.top: parent.top
        anchors.topMargin: 36

        onClicked: entrance.statechart.submitEvent("triggerPreviousPage")
    }


}







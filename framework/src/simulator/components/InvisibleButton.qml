import QtQuick
import QtQuick.Controls

Rectangle {
    id: button
    signal clicked
    signal pressed
    signal released

    color: "black"
    opacity: 0
    radius: 10

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
        onPressed: button.pressed()
        onReleased: button.released()
    }

    Behavior on color {
        ColorAnimation {
            duration: 120
            easing.type: Easing.OutElastic
        }
    }

    states: [
        State {
            when: mouseArea.pressed
            PropertyChanges {
                target: button
                opacity: 0.30
            }
        }
    ]
}

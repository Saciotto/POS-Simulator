import QtQuick
import QtQuick.Controls

Rectangle {
    id: button
    signal clicked

    color: "black"
    opacity: 0
    radius: 10

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
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

import QtQuick 6.4
import QtQuick.Controls 6.4

Button {
    id: button
    background: Rectangle {
        color: "#00000000"
        radius: 10
        Behavior on color {
            ColorAnimation {
                duration: 120
                easing.type: Easing.OutElastic
            }
        }
    }
    states: [
        State {
            name: "pressed"
            when: button.pressed
            PropertyChanges {
                target: button.background
                color: "#40000000"
            }
        }
    ]
}

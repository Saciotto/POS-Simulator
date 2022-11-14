import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import skins

ApplicationWindow {
    width: 480
    height: 720
    visible: true
    title: qsTr("POS Simulator")

    D200 {
        anchors.fill: parent
        image: pos.display.image
        onClicked: function(isPressed, keyCode) {
            pos.keypad.keyEvent(isPressed, keyCode);
        }
        onTouched: function(isPressed, x, y) {
            pos.touchscreen.touch(isPressed, x, y);
        }
    }
}

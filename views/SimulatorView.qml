import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Layouts 6.4

import "components"

ApplicationWindow {
    width: 480
    height: 720
    visible: true
    title: qsTr("POS Simulator")

    D200 {
        anchors.fill: parent
    }
}

import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Layouts 6.4

ApplicationWindow {
    width: 480
    height: 720
    visible: true
    title: qsTr("POS Simulator")

    Rectangle {
        id: display
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 8
        height: parent.height / 3
        border.color: "#000000"
    }

    GridLayout {
        anchors.top: display.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 8

        columns: 3
        columnSpacing: 8
        rowSpacing: 8

        Button {
            text: "F1"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "F2"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "<"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "1"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "2"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "3"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "4"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "5"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "6"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "7"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "8"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "9"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "X"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "0"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Button {
            text: "O"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}

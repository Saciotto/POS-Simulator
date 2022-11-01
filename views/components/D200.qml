import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    function scaleX(image, position) {
        const aspectRatio = image.paintedWidth / image.sourceSize.width
        return (image.width - image.paintedWidth) / 2 + position * aspectRatio
    }

    function scaleY(image, position) {
        const aspectRatio = image.paintedHeight / image.sourceSize.height
        return (image.height - image.paintedHeight) / 2 + position * aspectRatio
    }

    function scaleWidth(image, width) {
        const aspectRatio = image.paintedWidth / image.sourceSize.width
        return width * aspectRatio
    }

    function scaleHeight(image, height) {
        const aspectRatio = image.paintedHeight / image.sourceSize.height
        return height * aspectRatio
    }

    Image {
        source: "qrc:/POS_Simulator/assets/images/D200.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        clip:true

        Rectangle {
            x: scaleX(parent, 101)
            y: scaleY(parent, 108)
            width: scaleWidth(parent, 367)
            height: scaleHeight(parent, 275)
        }

        InvisibleButton {
            id: f1
            x: scaleX(parent, 81)
            y: scaleY(parent, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("F1 clicked")
        }

        InvisibleButton {
            id: f2
            x: scaleX(parent, 240)
            y: scaleY(parent, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("F2 clicked")
        }

        InvisibleButton {
            id: backspace
            x: scaleX(parent, 393)
            y: scaleY(parent, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("Backspace clicked")
        }

        InvisibleButton {
            id: key1
            x: scaleX(parent, 81)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("1 clicked")
        }

        InvisibleButton {
            id: key2
            x: scaleX(parent, 240)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("2 clicked")
        }

        InvisibleButton {
            id: key3
            x: scaleX(parent, 393)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("3 clicked")
        }

        InvisibleButton {
            id: key4
            x: scaleX(parent, 81)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("4 clicked")
        }

        InvisibleButton {
            id: key5
            x: scaleX(parent, 240)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("5 clicked")
        }

        InvisibleButton {
            id: key6
            x: scaleX(parent, 393)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("6 clicked")
        }

        InvisibleButton {
            id: key7
            x: scaleX(parent, 81)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("7 clicked")
        }

        InvisibleButton {
            id: key8
            x: scaleX(parent, 240)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("8 clicked")
        }

        InvisibleButton {
            id: key9
            x: scaleX(parent, 393)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("9 clicked")
        }

        InvisibleButton {
            id: cancel
            x: scaleX(parent, 81)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("Cancel clicked")
        }

        InvisibleButton {
            id: key0
            x: scaleX(parent, 240)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("0 clicked")
        }

        InvisibleButton {
            id: enter
            x: scaleX(parent, 393)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: console.log("Enter clicked")
        }
    }
}

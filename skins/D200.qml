import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import assets
import components

Item {
    id: d200
    signal clicked(keyCode: int)
    property alias image: display.image

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
        source: "qrc:/assets/images/D200.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        clip:true

        Display {
            id: display
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
            onClicked: d200.clicked(Key.d200F1)
        }

        InvisibleButton {
            id: f2
            x: scaleX(parent, 240)
            y: scaleY(parent, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.d200F2)
        }

        InvisibleButton {
            id: back
            x: scaleX(parent, 393)
            y: scaleY(parent, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.back)
        }

        InvisibleButton {
            id: num1
            x: scaleX(parent, 81)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num1)
        }

        InvisibleButton {
            id: num2
            x: scaleX(parent, 240)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num2)
        }

        InvisibleButton {
            id: num3
            x: scaleX(parent, 393)
            y: scaleY(parent, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num3)
        }

        InvisibleButton {
            id: num4
            x: scaleX(parent, 81)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num4)
        }

        InvisibleButton {
            id: num5
            x: scaleX(parent, 240)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num5)
        }

        InvisibleButton {
            id: num6
            x: scaleX(parent, 393)
            y: scaleY(parent, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num6)
        }

        InvisibleButton {
            id: num7
            x: scaleX(parent, 81)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num7)
        }

        InvisibleButton {
            id: num8
            x: scaleX(parent, 240)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num8)
        }

        InvisibleButton {
            id: num9
            x: scaleX(parent, 393)
            y: scaleY(parent, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num9)
        }

        InvisibleButton {
            id: cancel
            x: scaleX(parent, 81)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.cancel)
        }

        InvisibleButton {
            id: num0
            x: scaleX(parent, 240)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.num0)
        }

        InvisibleButton {
            id: enter
            x: scaleX(parent, 393)
            y: scaleY(parent, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onClicked: d200.clicked(Key.enter)
        }
    }
}

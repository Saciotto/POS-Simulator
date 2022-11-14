import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import assets
import components

Item {
    id: d200
    signal clicked(isPressed: bool, keyCode: int)
    signal touched(isPressed: bool, x: int, y: int)
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

    function scaleDisplayX(maxX, position) {
        const displayWidth = 320;
        const aspectRatio = displayWidth / maxX
        return position * aspectRatio
    }

    function scaleDisplayY(maxY, position) {
        const displayHeight = 240;
        const aspectRatio = displayHeight / maxY
        return position * aspectRatio
    }

    Image {
        id: image
        source: "qrc:/assets/images/D200.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        clip:true

        Display {
            id: display
            x: scaleX(image, 101)
            y: scaleY(image, 108)
            width: scaleWidth(parent, 367)
            height: scaleHeight(parent, 275)

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onPressed: function (mouse) {
                    const x = scaleDisplayX(mouseArea.width, mouse.x);
                    const y = scaleDisplayY(mouseArea.height, mouse.y);
                    d200.touched(true, x, y);
                }
                onPositionChanged: function (mouse) {
                    const x = scaleDisplayX(mouseArea.width, mouse.x);
                    const y = scaleDisplayY(mouseArea.height, mouse.y);
                    d200.touched(true, x, y);
                }
                onReleased: function (mouse) {
                    const x = scaleDisplayX(mouseArea.width, mouse.x);
                    const y = scaleDisplayY(mouseArea.height, mouse.y);
                    d200.touched(false, x, y);
                }
            }
        }

        InvisibleButton {
            id: f1
            x: scaleX(image, 81)
            y: scaleY(image, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.d200F1)
            onReleased: d200.clicked(false, Key.d200F1)
        }

        InvisibleButton {
            id: f2
            x: scaleX(image, 240)
            y: scaleY(image, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.d200F2)
            onReleased: d200.clicked(false, Key.d200F2)
        }

        InvisibleButton {
            id: back
            x: scaleX(image, 393)
            y: scaleY(image, 453)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.back)
            onReleased: d200.clicked(false, Key.back)
        }

        InvisibleButton {
            id: num1
            x: scaleX(image, 81)
            y: scaleY(image, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num1)
            onReleased: d200.clicked(false, Key.num1)
        }

        InvisibleButton {
            id: num2
            x: scaleX(image, 240)
            y: scaleY(image, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num2)
            onReleased: d200.clicked(false, Key.num2)
        }

        InvisibleButton {
            id: num3
            x: scaleX(image, 393)
            y: scaleY(image, 532)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num3)
            onReleased: d200.clicked(false, Key.num3)
        }

        InvisibleButton {
            id: num4
            x: scaleX(image, 81)
            y: scaleY(image, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num4)
            onReleased: d200.clicked(false, Key.num4)
        }

        InvisibleButton {
            id: num5
            x: scaleX(image, 240)
            y: scaleY(image, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num5)
            onReleased: d200.clicked(false, Key.num5)
        }

        InvisibleButton {
            id: num6
            x: scaleX(image, 393)
            y: scaleY(image, 611)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num6)
            onReleased: d200.clicked(false, Key.num6)
        }

        InvisibleButton {
            id: num7
            x: scaleX(image, 81)
            y: scaleY(image, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num7)
            onReleased: d200.clicked(false, Key.num7)
        }

        InvisibleButton {
            id: num8
            x: scaleX(image, 240)
            y: scaleY(image, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num8)
            onReleased: d200.clicked(false, Key.num8)
        }

        InvisibleButton {
            id: num9
            x: scaleX(image, 393)
            y: scaleY(image, 690)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num9)
            onReleased: d200.clicked(false, Key.num9)
        }

        InvisibleButton {
            id: cancel
            x: scaleX(image, 81)
            y: scaleY(image, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.cancel)
            onReleased: d200.clicked(false, Key.cancel)
        }

        InvisibleButton {
            id: num0
            x: scaleX(image, 240)
            y: scaleY(image, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.num0)
            onReleased: d200.clicked(false, Key.num0)
        }

        InvisibleButton {
            id: enter
            x: scaleX(image, 393)
            y: scaleY(image, 769)
            width: scaleWidth(parent, 111)
            height: scaleHeight(parent, 79)
            onPressed: d200.clicked(true, Key.enter)
            onReleased: d200.clicked(false, Key.enter)
        }
    }
}

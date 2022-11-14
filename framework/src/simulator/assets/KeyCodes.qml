pragma Singleton

import QtQuick

Item {
    // Action keys
    readonly property int enter: 10;
    readonly property int back: 11;
    readonly property int cancel: 12;

    // Numpad
    readonly property int num0: '0'.codePointAt(0);
    readonly property int num1: '1'.codePointAt(0);
    readonly property int num2: '2'.codePointAt(0);
    readonly property int num3: '3'.codePointAt(0);
    readonly property int num4: '4'.codePointAt(0);
    readonly property int num5: '5'.codePointAt(0);
    readonly property int num6: '6'.codePointAt(0);
    readonly property int num7: '7'.codePointAt(0);
    readonly property int num8: '8'.codePointAt(0);
    readonly property int num9: '9'.codePointAt(0);

    // D200 keys
    readonly property int d200F1: 101
    readonly property int d200F2: 102
}

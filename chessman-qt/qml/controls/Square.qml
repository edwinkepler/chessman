import QtQuick 2.8

Rectangle {
    property color col

    width: parent.width / 8
    height: parent.height / 8
    color: col

    MouseArea {
        anchors.fill: parent;
        hoverEnabled: true;
        onEntered: parent.color = Qt.darker(col, 1.1)
        onExited: parent.color = col
    }
}
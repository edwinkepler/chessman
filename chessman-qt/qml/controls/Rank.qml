import QtQuick 2.8

Item {
    id: root

    Rectangle {
        id: rank_8
        height: parent.height / 8
        width: parent.width
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "8"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_7
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_8.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "7"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_6
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_7.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "6"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_5
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_6.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "5"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_4
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_5.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "4"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_3
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_4.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "3"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_2
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_3.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "2"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: rank_1
        height: parent.height / 8
        width: parent.width
        anchors.top: rank_2.bottom
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "1"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }
}

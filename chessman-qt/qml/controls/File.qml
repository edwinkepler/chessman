import QtQuick 2.8

Item {
    id: root

    Rectangle {
        id: fillerLeft
        height: parent.height
        width: parent.height
        color: "#2F2F2F"
    }

    Rectangle {
        id: file_a
        height: parent.height
        width: parent.width / 8
        anchors.left: fillerLeft.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "A"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_b
        height: parent.height
        width: parent.width / 8
        anchors.left: file_a.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "B"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_c
        height: parent.height
        width: parent.width / 8
        anchors.left: file_b.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "C"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_d
        height: parent.height
        width: parent.width / 8
        anchors.left: file_c.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "D"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_e
        height: parent.height
        width: parent.width / 8
        anchors.left: file_d.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "E"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_f
        height: parent.height
        width: parent.width / 8
        anchors.left: file_e.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "F"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_g
        height: parent.height
        width: parent.width / 8
        anchors.left: file_f.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "G"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: file_h
        height: parent.height
        width: parent.width / 8
        anchors.left: file_g.right
        color: "#2F2F2F"
        Text {
            anchors.fill: parent
            text: "H"
            color: "#F2F2F2"
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    Rectangle {
        id: fillerRight
        height: parent.height
        width: parent.height
        anchors.left: file_h.right
        color: "#2F2F2F"
    }
}

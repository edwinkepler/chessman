import QtQuick 2.8
import "./"

Item {
    id: root
    width: (parent.height > parent.width) ? parent.width : parent.height
    height: (parent.height > parent.width) ? parent.width : parent.height

    property int boardMargin: 12

    Rank {
        y: boardMargin
        width: boardMargin
        height: parent.height - boardMargin * 2
        anchors.left: parent.left
    }

    Rank {
        y: boardMargin
        width: boardMargin
        height: parent.height - boardMargin * 2
        anchors.right: parent.right
    }

    File {
        width: parent.height - boardMargin * 2
        height: boardMargin
        anchors.top: parent.top
    }

    File {
        width: parent.height - boardMargin * 2
        height: boardMargin
        anchors.bottom: parent.bottom
    }

    Rectangle {
        x: boardMargin; y: boardMargin
        width: root.width - boardMargin * 2
        height: root.height - boardMargin * 2

        Square {
            id: square_1_1
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            col: "#d18b47"
        }

        Square {
            id: square_2_1
            anchors.left: square_1_1.right
            anchors.bottom: parent.bottom
            col: "#ffce9e"
        }

        Square {
            id: square_3_1
            anchors.left: square_2_1.right
            anchors.bottom: parent.bottom
            col: "#d18b47"
        }

        Square {
            id: square_4_1
            anchors.left: square_3_1.right
            anchors.bottom: parent.bottom
            col: "#ffce9e"
        }

        Square {
            id: square_5_1
            anchors.left: square_4_1.right
            anchors.bottom: parent.bottom
            col: "#d18b47"
        }

        Square {
            id: square_6_1
            anchors.left: square_5_1.right
            anchors.bottom: parent.bottom
            col: "#ffce9e"
        }

        Square {
            id: square_7_1
            anchors.left: square_6_1.right
            anchors.bottom: parent.bottom
            col: "#d18b47"
        }

        Square {
            id: square_8_1
            anchors.left: square_7_1.right
            anchors.bottom: parent.bottom
            col: "#ffce9e"
        }

        Square {
            id: square_1_2
            anchors.left: parent.left
            anchors.bottom: square_1_1.top
            col: "#ffce9e"
        }

        Square {
            id: square_2_2
            anchors.left: square_1_2.right
            anchors.bottom: square_2_1.top
            col: "#d18b47"
        }

        Square {
            id: square_3_2
            anchors.left: square_2_2.right
            anchors.bottom: square_3_1.top
            col: "#ffce9e"
        }

        Square {
            id: square_4_2
            anchors.left: square_3_2.right
            anchors.bottom: square_4_1.top
            col: "#d18b47"
        }

        Square {
            id: square_5_2
            anchors.left: square_4_2.right
            anchors.bottom: square_5_1.top
            col: "#ffce9e"
        }

        Square {
            id: square_6_2
            anchors.left: square_5_2.right
            anchors.bottom: square_6_1.top
            col: "#d18b47"
        }

        Square {
            id: square_7_2
            anchors.left: square_6_2.right
            anchors.bottom: square_7_1.top
            col: "#ffce9e"
        }

        Square {
            id: square_8_2
            anchors.left: square_7_2.right
            anchors.bottom: square_8_1.top
            col: "#d18b47"
        }

        Square {
            id: square_1_3
            anchors.left: parent.left
            anchors.bottom: square_1_2.top
            col: "#d18b47"
        }

        Square {
            id: square_2_3
            anchors.left: square_1_3.right
            anchors.bottom: square_2_2.top
            col: "#ffce9e"
        }

        Square {
            id: square_3_3
            anchors.left: square_2_3.right
            anchors.bottom: square_3_2.top
            col: "#d18b47"
        }

        Square {
            id: square_4_3
            anchors.left: square_3_3.right
            anchors.bottom: square_4_2.top
            col: "#ffce9e"
        }

        Square {
            id: square_5_3
            anchors.left: square_4_3.right
            anchors.bottom: square_5_2.top
            col: "#d18b47"
        }

        Square {
            id: square_6_3
            anchors.left: square_5_3.right
            anchors.bottom: square_6_2.top
            col: "#ffce9e"
        }

        Square {
            id: square_7_3
            anchors.left: square_6_3.right
            anchors.bottom: square_7_2.top
            col: "#d18b47"
        }

        Square {
            id: square_8_3
            anchors.left: square_7_3.right
            anchors.bottom: square_8_2.top
            col: "#ffce9e"
        }

        Square {
            id: square_1_4
            anchors.left: parent.left
            anchors.bottom: square_1_3.top
            col: "#ffce9e"
        }

        Square {
            id: square_2_4
            anchors.left: square_1_4.right
            anchors.bottom: square_2_3.top
            col: "#d18b47"
        }

        Square {
            id: square_3_4
            anchors.left: square_2_4.right
            anchors.bottom: square_3_3.top
            col: "#ffce9e"
        }

        Square {
            id: square_4_4
            anchors.left: square_3_4.right
            anchors.bottom: square_4_3.top
            col: "#d18b47"
        }

        Square {
            id: square_5_4
            anchors.left: square_4_4.right
            anchors.bottom: square_5_3.top
            col: "#ffce9e"
        }

        Square {
            id: square_6_4
            anchors.left: square_5_4.right
            anchors.bottom: square_6_3.top
            col: "#d18b47"
        }

        Square {
            id: square_7_4
            anchors.left: square_6_4.right
            anchors.bottom: square_7_3.top
            col: "#ffce9e"
        }

        Square {
            id: square_8_4
            anchors.left: square_7_4.right
            anchors.bottom: square_8_3.top
            col: "#d18b47"
        }

        Square {
            id: square_1_5
            anchors.left: parent.left
            anchors.bottom: square_1_4.top
            col: "#d18b47"
        }

        Square {
            id: square_2_5
            anchors.left: square_1_5.right
            anchors.bottom: square_2_4.top
            col: "#ffce9e"
        }

        Square {
            id: square_3_5
            anchors.left: square_2_5.right
            anchors.bottom: square_3_4.top
            col: "#d18b47"
        }

        Square {
            id: square_4_5
            anchors.left: square_3_5.right
            anchors.bottom: square_4_4.top
            col: "#ffce9e"
        }

        Square {
            id: square_5_5
            anchors.left: square_4_5.right
            anchors.bottom: square_5_4.top
            col: "#d18b47"
        }

        Square {
            id: square_6_5
            anchors.left: square_5_5.right
            anchors.bottom: square_6_4.top
            col: "#ffce9e"
        }

        Square {
            id: square_7_5
            anchors.left: square_6_5.right
            anchors.bottom: square_7_4.top
            col: "#d18b47"
        }

        Square {
            id: square_8_5
            anchors.left: square_7_5.right
            anchors.bottom: square_8_4.top
            col: "#ffce9e"
        }

        Square {
            id: square_1_6
            anchors.left: parent.left
            anchors.bottom: square_1_5.top
            col: "#ffce9e"
        }

        Square {
            id: square_2_6
            anchors.left: square_1_6.right
            anchors.bottom: square_2_5.top
            col: "#d18b47"
        }

        Square {
            id: square_3_6
            anchors.left: square_2_6.right
            anchors.bottom: square_3_5.top
            col: "#ffce9e"
        }

        Square {
            id: square_4_6
            anchors.left: square_3_6.right
            anchors.bottom: square_4_5.top
            col: "#d18b47"
        }

        Square {
            id: square_5_6
            anchors.left: square_4_6.right
            anchors.bottom: square_5_5.top
            col: "#ffce9e"
        }

        Square {
            id: square_6_6
            anchors.left: square_5_6.right
            anchors.bottom: square_6_5.top
            col: "#d18b47"
        }

        Square {
            id: square_7_6
            anchors.left: square_6_6.right
            anchors.bottom: square_7_5.top
            col: "#ffce9e"
        }

        Square {
            id: square_8_6
            anchors.left: square_7_6.right
            anchors.bottom: square_8_5.top
            col: "#d18b47"
        }

        Square {
            id: square_1_7
            anchors.left: parent.left
            anchors.bottom: square_1_6.top
            col: "#d18b47"
        }

        Square {
            id: square_2_7
            anchors.left: square_1_7.right
            anchors.bottom: square_2_6.top
            col: "#ffce9e"
        }

        Square {
            id: square_3_7
            anchors.left: square_2_7.right
            anchors.bottom: square_3_6.top
            col: "#d18b47"
        }

        Square {
            id: square_4_7
            anchors.left: square_3_7.right
            anchors.bottom: square_4_6.top
            col: "#ffce9e"
        }

        Square {
            id: square_5_7
            anchors.left: square_4_7.right
            anchors.bottom: square_5_6.top
            col: "#d18b47"
        }

        Square {
            id: square_6_7
            anchors.left: square_5_7.right
            anchors.bottom: square_6_6.top
            col: "#ffce9e"
        }

        Square {
            id: square_7_7
            anchors.left: square_6_7.right
            anchors.bottom: square_7_6.top
            col: "#d18b47"
        }

        Square {
            id: square_8_7
            anchors.left: square_7_7.right
            anchors.bottom: square_8_6.top
            col: "#ffce9e"
        }

        Square {
            id: square_1_8
            anchors.left: parent.left
            anchors.bottom: square_1_7.top
            col: "#ffce9e"
        }

        Square {
            id: square_2_8
            anchors.left: square_1_8.right
            anchors.bottom: square_2_7.top
            col: "#d18b47"
        }

        Square {
            id: square_3_8
            anchors.left: square_2_8.right
            anchors.bottom: square_3_7.top
            col: "#ffce9e"
        }

        Square {
            id: square_4_8
            anchors.left: square_3_8.right
            anchors.bottom: square_4_7.top
            col: "#d18b47"
        }

        Square {
            id: square_5_8
            anchors.left: square_4_8.right
            anchors.bottom: square_5_7.top
            col: "#ffce9e"
        }

        Square {
            id: square_6_8
            anchors.left: square_5_8.right
            anchors.bottom: square_6_7.top
            col: "#d18b47"
        }

        Square {
            id: square_7_8
            anchors.left: square_6_8.right
            anchors.bottom: square_7_7.top
            col: "#ffce9e"
        }

        Square {
            id: square_8_8
            anchors.left: square_7_8.right
            anchors.bottom: square_8_7.top
            col: "#d18b47"
        }
    }
}

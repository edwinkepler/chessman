import QtQuick 2.8
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    visible: true
    height: 450
    width: 800
    x: 0; y: 0
    
    Item {
        id: chessboard
        width: (parent.height > parent.width) ? parent.width : parent.height
        height: (parent.height > parent.width) ? parent.width : parent.height

        Rectangle {
            anchors.fill: chessboard
            color: "#FF0000"

            Rectangle {
                id: square_1_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                color: "#d18b47"
            }

            Rectangle {
                id: square_2_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_1_1.right
                anchors.bottom: parent.bottom
                color: "#ffce9e"
            }

            Rectangle {
                id: square_3_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_2_1.right
                anchors.bottom: parent.bottom
                color: "#d18b47"
            }

            Rectangle {
                id: square_4_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_3_1.right
                anchors.bottom: parent.bottom
                color: "#ffce9e"
            }

            Rectangle {
                id: square_5_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_4_1.right
                anchors.bottom: parent.bottom
                color: "#d18b47"
            }

            Rectangle {
                id: square_6_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_5_1.right
                anchors.bottom: parent.bottom
                color: "#ffce9e"
            }

            Rectangle {
                id: square_7_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_6_1.right
                anchors.bottom: parent.bottom
                color: "#d18b47"
            }

            Rectangle {
                id: square_8_1
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_7_1.right
                anchors.bottom: parent.bottom
                color: "#ffce9e"
            }

            Rectangle {
                id: square_1_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: parent.left
                anchors.bottom: square_1_1.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_2_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_1_2.right
                anchors.bottom: square_2_1.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_3_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_2_2.right
                anchors.bottom: square_3_1.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_4_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_3_2.right
                anchors.bottom: square_4_1.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_5_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_4_2.right
                anchors.bottom: square_5_1.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_6_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_5_2.right
                anchors.bottom: square_6_1.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_7_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_6_2.right
                anchors.bottom: square_7_1.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_8_2
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_7_2.right
                anchors.bottom: square_8_1.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_1_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: parent.left
                anchors.bottom: square_1_2.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_2_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_1_3.right
                anchors.bottom: square_2_2.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_3_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_2_3.right
                anchors.bottom: square_3_2.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_4_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_3_3.right
                anchors.bottom: square_4_2.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_5_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_4_3.right
                anchors.bottom: square_5_2.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_6_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_5_3.right
                anchors.bottom: square_6_2.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_7_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_6_3.right
                anchors.bottom: square_7_2.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_8_3
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_7_3.right
                anchors.bottom: square_8_2.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_1_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: parent.left
                anchors.bottom: square_1_3.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_2_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_1_4.right
                anchors.bottom: square_2_3.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_3_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_2_4.right
                anchors.bottom: square_3_3.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_4_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_3_4.right
                anchors.bottom: square_4_3.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_5_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_4_4.right
                anchors.bottom: square_5_3.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_6_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_5_4.right
                anchors.bottom: square_6_3.top
                color: "#d18b47"
            }

            Rectangle {
                id: square_7_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_6_4.right
                anchors.bottom: square_7_3.top
                color: "#ffce9e"
            }

            Rectangle {
                id: square_8_4
                width: parent.width / 8
                height: parent.height / 8
                anchors.left: square_7_4.right
                anchors.bottom: square_8_3.top
                color: "#d18b47"
            }
        }
    }
}

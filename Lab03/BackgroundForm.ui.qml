import QtQuick 2.4
import QtQuick.Layouts 1.0

Item {
    Rectangle {
        id: bgRect
        color: "#ff0000"
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        GridLayout {
            anchors.fill: parent
            anchors.rightMargin: 0
            rowSpacing: 2
            columnSpacing: 2
            rows: 1
            columns: 2

            Rectangle {
                id: bgTopLeft
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Image {
                    id: saywhat
                    anchors.fill: parent
                    source: "saywhat.jpg"
                    anchors.rightMargin: 33
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    id: movieNight
                    width: 427
                    height: 164
                    color: "#000000"
                    text: qsTr("It's Movie Night!")
                    anchors.top: parent.top
                    font.pixelSize: 20
                    anchors.horizontalCenterOffset: 129
                    anchors.topMargin: 116
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Rectangle {
                id: bgTopRight
                color: "#00ffffff"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Text {
                    id: whatText
                    text: qsTr("You have")
                    anchors.top: parent.top
                    font.pixelSize: 20
                    fontSizeMode: Text.HorizontalFit
                    font.styleName: "Bold"
                    anchors.topMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: moreText
                    text: qsTr("more times!")
                    anchors.bottom: parent.bottom
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    fontSizeMode: Text.HorizontalFit
                    anchors.bottomMargin: 5
                }
            }

            Rectangle {
                id: bgBotLeft
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200
            }

            Rectangle {
                id: bgBotRight
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Image {
                    id: bigSurprise
                    anchors.fill: parent
                    source: "BigSurprise.JPG"
                    anchors.bottomMargin: 116
                    anchors.topMargin: -7
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.5;height:480;width:640}
}
##^##*/


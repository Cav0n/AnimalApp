import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property var animal

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height

        PullDownMenu {
            MenuItem {
                text: animal.favourite?qsTr("Remove Favourite"):qsTr("Set as Favourite")
                onClicked: animal.setFavourite ( ! animal.favourite )
            }
        }

        Column {
            id: column
            spacing: 0
            width: parent.width

            PageHeader {
                title: animal.name
            }

            DetailItem {
                label: qsTr("Animal name")
                value: name.name
                visible: ( animal.name.length > 32 ) ? true : false
            }

            TextArea {
                text: animal.description
 //               textFormat: TextEdit.RichText
                font.pixelSize: Theme.fontSizeSmall
                readOnly: true
                width: parent.width
                wrapMode: TextEdit.Wrap

                Component.onCompleted: {
                                _editor.textFormat = TextEdit.RichText
                }
            }

            Button {
                text: qsTr("See Online")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    console.log(("https://www.google.fr"))
                    pageStack.push(webview, { url: "https://www.google.fr"} )
                }
                //visible: animal.url.toString() !== ""

                Component {
                    id: webview
                    FullAnimalDescription { }
                }
            }

        }
    }
}

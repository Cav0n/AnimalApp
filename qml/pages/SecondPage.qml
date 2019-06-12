import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        model: animals
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("[TEST] liste d'animaux")
        }

        delegate: ListItem {
            id: delegate
            height:  Theme.itemSizeExtraSmall

            Label {
                x: Theme.horizontalPageMargin
                font.bold: spell.favourite
                text: animal.name
                anchors.verticalCenter: parent.verticalCenter
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
            onClicked: {
                console.log("Clicked " + index)
            }
        }
        VerticalScrollDecorator {}
    }
}

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    property bool searchVisible: true

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        model: animalMode
        anchors.fill: parent
        spacing: 0  // Delegate height will do the job

        header: PageHeader {
            id: head
            title: manager.selectedClasse

            SearchField {
                id: searchField
                parent: head.extraContent

                width: parent.width
                placeholderText: qsTr("Name")

                onTextChanged: {
                    spellModel.nameFilter = text
                }
                visible: page.searchVisible
                onVisibleChanged: {
                    if ( ! visible ) {
                        text=""
                        focus=false
                    }
                }
            }

        }

        // prevent newly added list delegates from stealing focus away from the search field
        currentIndex: -1

        PushUpMenu {
            MenuItem {
                text: qsTr("Compare Animals Lists")
                onClicked: pageStack.push(Qt.resolvedUrl("ComparePage.qml"))
            }
            MenuItem {
                text: qsTr("Reset user preferences (Including Favourites!)")
                onClicked: remorse.execute("Reset preference", function() {manager.resetUserPrefs() } )
            }
        }

        RemorsePopup { id: remorse }

        delegate: ListItem {
            id: delegate
            height:  Theme.itemSizeExtraSmall

            Label {
                x: Theme.horizontalPageMargin
                font.bold: animals.favourite
                text: name + " " + animal.levelRequired(manager.selectedClasse)
                anchors.verticalCenter: parent.verticalCenter
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
            onClicked: {
                pageStack.push(animalPage, { animal: animal } )
            }

            menu: ContextMenu {
                MenuItem {
                    text: "Change Favourite"
                    onClicked: animal.setFavourite ( ! animal.favourite )
                }
            }
        }
        VerticalScrollDecorator {}

        Component {
            id: animalPage
            Animal {  }

        }

    }
}

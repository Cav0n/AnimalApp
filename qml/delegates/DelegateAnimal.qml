import QtQuick 2.0
import Sailfish.Silica 1.0
import "../pages"

ListItem {
    id: animalItem
    width: listView.width
    Label {
        text: name
    }

    menu: ContextMenu {
        MenuItem {
            text: "Supprimer l'animal de la liste"
            onClicked: listView.model.removeRow(index)
        }
        MenuItem {
            text: "Supprimer animal"
            onClicked: remorse.remorseDelete()

            RemorseItem {
                id: remorse
                function remorseDelete() {
                    var idx = index
                    remorse.execute(personnageItem, "Suppression de l'animal", function() { listView.model.removeRow(idx) }, 2000 )
                }
            }
        }
    }
    onClicked: pageStack.push( animalPage, { animal: animal }  )
    Component {
        id: animalPage
        Animal {}
    }
}

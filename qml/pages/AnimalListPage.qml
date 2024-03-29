import QtQuick 2.0
import Sailfish.Silica 1.0
import AnimalModel 1.0
import '../delegates'

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent

        header: PageHeader {
            title: qsTr("Mes animaux chef !")
        }

        model: AnimalModel {
            list: animalList
        }

        delegate: DelegateAnimal { }
    }
}

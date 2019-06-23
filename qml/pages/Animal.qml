import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property var animal
    Component.onCompleted: {
        request('http://fr.wikipedia.org/w/api.php?action=query&format=json&uselang=fr&prop=info%7Cpageprops%7Cdescription&inprop=url&pageids='+animal.id, function (o) {
                // log the json response
                var test = o.responseText.slice(41+animal.id.length, -3);
                console.log(animal.id.lenght + " ---- " + test);
                // translate response into object
                var d = eval('new Object(' + test + ')');

                // access elements inside json object with dot notation
                //emailLabel.text = d.query.pages;
                console.log("QUERY : " + d.pageid);
                animalDescription.text = d.description;
            });
    }

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

            Image {
                id: animalImage
                width: parent.width
                height: parent.width
                fillMode: Image.PreserveAspectFit
                source: animal.imageName
            }

            DetailItem {
                label: qsTr("Animal name")
                value: animal.name
                visible: ( animal.name.length > 32 ) ? true : false
            }

            TextArea {
                id: animalDescription;
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
    function request(url, callback) {
        console.log(url);
            var xhr = new XMLHttpRequest();

            xhr.onreadystatechange = (function(myxhr) {
                return function() {
                    if(myxhr.readyState === 4) callback(myxhr);
                }
            })(xhr);
            xhr.open('GET', url, true);
            xhr.send('');
        }

}





import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property var animal
    Component.onCompleted: {
        request('http://fr.wikipedia.org/w/api.php?action=query&format=json&uselang=fr&prop=info%7Cpageprops%7Cdescription&inprop=url&pageids='+animal.id, function (o){
            var response = o.responseText;
            var jsonConverted = eval('new Object(' + response + ')');
            console.log("DESCRIPTION : " + jsonConverted.query.pages[animal.id].description);
            console.log("IMAGE : " + jsonConverted.query.pages[animal.id].pageprops.page_image_free);

            var description = jsonConverted.query.pages[animal.id].description;
            animal.url = jsonConverted.query.pages[animal.id].fullurl;
            var imageName = jsonConverted.query.pages[animal.id].pageprops.page_image_free;

            animalDescription.text = description;

            request('http://fr.wikipedia.org/w/api.php?action=query&format=json&uselang=fr&prop=imageinfo&titles=Fichier:' + imageName + '&iiprop=user%7Curl', function(p) {
                var response = p.responseText;
                response = response.replace('[', '');
                response = response.replace(']', '');
                console.log("LE JSON : " + response.replace('[', '').replace(']', ''));
                var jsonConverted = eval('new Object(' + response.replace('[', '').replace(']', '') + ')');
                console.log("VERITABLE IMAGE : " + jsonConverted.query.pages["-1"].imageinfo);

                var imageURL = jsonConverted.query.pages["-1"].imageinfo.url;
                animalImage.source = imageURL;
            });
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
                id: webPageButton;
                text: qsTr("Voir la page Wikipedia")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    console.log((animal.url))
                    pageStack.push(webview, { url: animal.url} )
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





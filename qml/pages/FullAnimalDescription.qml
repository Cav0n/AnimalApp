import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property url url
    SilicaWebView {
        anchors.fill: parent
        url: parent.url
    }
}

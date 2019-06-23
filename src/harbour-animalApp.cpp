#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "animal.h"
#include "animalmodel.h"
#include "animallist.h"
#include "animalsfactory_wikipedia.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/harbour-animalApp.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    auto app = SailfishApp::application(argc, argv);
    auto view = SailfishApp::createView();

    AnimalsFactory_wikipedia reader;
    reader.parseFile(":/data/wikipedia/animals.json");

    qmlRegisterType<AnimalModel>("AnimalModel", 1, 0, "AnimalModel");
    qmlRegisterUncreatableType<AnimalList>("AnimalList", 1, 0, "AnimalList", QStringLiteral("ATTENTION : Ne définissez pas AnimalList dans le QML."));
    qmlRegisterUncreatableType<Animal>("Animal", 1, 0, "Animal", QStringLiteral("ATTENTION : Ne définissez pas Animal dans le QML."));

    view->rootContext()->setContextProperty("animalList", reader.animals());
    view->setSource(SailfishApp::pathToMainQml());
    view->show();

    return app->exec();
}

# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-animalApp

CONFIG += sailfishapp

SOURCES += src/harbour-animalApp.cpp \
    animal.cpp \
    animallist.cpp \
    animalmodel.cpp \
    animalsfactory.cpp \
    animalsfactory_wikipedia.cpp \

DISTFILES += qml/harbour-animalApp.qml \
    qml/cover/CoverPage.qml \
    rpm/harbour-animalApp.changes.in \
    rpm/harbour-animalApp.changes.run.in \
    rpm/harbour-animalApp.spec \
    rpm/harbour-animalApp.yaml \
    translations/*.ts \
    harbour-animalApp.desktop \
    qml/pages/AnimalListPage.qml \
    qml/pages/Animal.qml \
    qml/pages/FullAnimalDescription.qml \
    qml/delegates/DelegateAnimal.qml \
    data/wikipedia/animals.json

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-animalApp-de.ts

HEADERS += \
    animal.h \
    animallist.h \
    animalmodel.h \
    animalsfactory.h \
    animalsfactory_wikipedia.h \

RESOURCES += \
    animals_resources.qrc

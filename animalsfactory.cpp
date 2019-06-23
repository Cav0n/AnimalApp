#include "animalsfactory.h"

AnimalsFactory::AnimalsFactory(AnimalList *animalList, QObject *parent) : QObject(parent),
    m_animals(animalList)
{

}

QString AnimalsFactory::capitalize(const QString &string)
{
    QString capitalized = string.toLower();
    capitalized[0] = capitalized[0].toUpper();

    return capitalized;
}

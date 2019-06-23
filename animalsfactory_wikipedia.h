#ifndef ANIMALSFACTORY_WIKIPEDIA_H
#define ANIMALSFACTORY_WIKIPEDIA_H

#include <QObject>

#include "animalsfactory.h"
#include "animallist.h"

class Animal;

class AnimalsFactory_wikipedia : public AnimalsFactory
{
    Q_OBJECT
public:
    using AnimalsFactory::AnimalsFactory;
    void parseFile(QString filename) override;

    void parse(const QByteArray &raw);
    void parseAnimal(const QJsonObject &animal);

signals:
public slots:
private:
};

#endif // ANIMALSFACTORY_WIKIPEDIA_H

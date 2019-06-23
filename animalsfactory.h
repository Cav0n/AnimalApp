#ifndef ANIMALSFACTORY_H
#define ANIMALSFACTORY_H

#include <QObject>
#include "animallist.h"

class AnimalsFactory : public QObject
{
    Q_OBJECT
public:
    explicit AnimalsFactory(AnimalList *animalList = new AnimalList{}, QObject *parent = nullptr);

    virtual void parseFile(QString filename) = 0;

    AnimalList *animals() const { return m_animals; }

signals:

public slots:

protected:
    AnimalList *m_animals;

    static QString capitalize(const QString &string);
};

#endif // ANIMALSFACTORY_H

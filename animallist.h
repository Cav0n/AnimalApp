#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include <QObject>
#include <QList>
#include "animal.h"

class AnimalList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Animal*> animals READ animals WRITE setAnimals NOTIFY animalsChanged)
    QList<Animal*> m_animals;

public:
    explicit AnimalList(QObject *parent = nullptr);
    void append(Animal* animal);
    QList<Animal *> animals() const;
    Animal *at(int place) const;
    int count() const;

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);

    void animalsChanged(QList<Animal*> animals);

public slots:
    void setAnimals(QList<Animal*> animals);
};

#endif // ANIMALLIST_H

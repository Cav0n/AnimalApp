#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include <QObject>
#include <QList>
#include "animal.h"

class Animal;

class AnimalList : public QObject
{
    Q_OBJECT
    QList<Animal*> m_animals;

public:
    explicit AnimalList(QObject *parent = nullptr);

    Animal *at(int place) const;
    void append(Animal* animal);
    void createAnimal(QString nom,QString imageName, QString description);
    void removeAnimal(int position);
    int count() const;

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);

public slots:
};

#endif // ANIMALLIST_H

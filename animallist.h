#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include <QObject>

class AnimalList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Animal*> animals READ animals WRITE setAnimals NOTIFY animalsChanged)
    QList<Animal*> m_animals;
public:
    explicit AnimalList(QObject *parent = nullptr);
    void append(Animal* animal);
    QList<Animal *> animals() const;

signals:

public slots:
};

#endif // ANIMALLIST_H

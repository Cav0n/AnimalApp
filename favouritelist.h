#ifndef FAVOURITELIST_H
#define FAVOURITELIST_H

#include <QObject>
#include "animal.h"

class favouriteList : public QObject
{
    Q_OBJECT
    QList<Animal*> m_favAnimals;

public:
    explicit favouriteList(QObject *parent = nullptr);

    Animal *at(int index) const;
    void append(Animal* animal);
    void remove(int index);
    int count() const;

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved();
    void postItemRemoved();

    void itemChanged(int index);

public slots:
};

#endif // FAVOURITELIST_H

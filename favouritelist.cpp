#include "favouritelist.h"

favouriteList::favouriteList(QObject *parent) : QObject(parent)
{

}

Animal *favouriteList::at(int index) const
{
    return m_favAnimals[index];
}

void favouriteList::append(Animal *animal)
{
    emit preItemAppended();

    int index = count();
    connect(animal, &Animal::animalChanged,this,[=](){
        emit favouriteList::itemChanged(index);
    });

    m_favAnimals.append(animal);
    emit postItemAppended();
}

void favouriteList::remove(int index)
{
    emit preItemRemoved();

    disconnect(m_favAnimals.at(index),&Animal::animalChanged, this,0);

    m_favAnimals.removeAt(index);

    for ( ; index < count(); ++index) {
        disconnect(m_favAnimals[index],&Animal::animalChanged,this,0);
        connect(m_favAnimals[index],&Animal::animalChanged,this, [=](){
            emit favouriteList::itemChanged(index);
        });
    }

    emit postItemRemoved();
}

int favouriteList::count() const
{
    return m_favAnimals.size();
}

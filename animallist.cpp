#include "animallist.h"
#include "animal.h"

AnimalList::AnimalList(QObject *parent) : QObject(parent)
{

}

void AnimalList::append(Animal *animal)
{
    emit preItemAppended();
    int position = count();
    connect(animal, &Animal::animalChanged, this, [=](){
        emit AnimalList::itemChanged(position);
    });
    m_animals.append(animal);
    emit postItemAppended();
}

int AnimalList::count() const
{
    return m_animals.size();
}

Animal *AnimalList::at(int place) const
{
    return m_animals.at(place);
}

void AnimalList::createAnimal(QString id, QString nom, QString imageName, QString description)
{
    append(new Animal(id, nom, imageName, description));
}

void AnimalList::removeAnimal(int position)
{
    emit preItemRemoved(position);

    // No longer care for the file change
    disconnect ( m_animals[position], &Animal::animalChanged, this, 0);

    m_animals.removeAt(position);

    // Reconnect to good positions
    for ( ; position < count() ; ++position ) {
        disconnect ( m_animals[position], &Animal::animalChanged, this, 0);
        connect( m_animals[position], &Animal::animalChanged, this, [=](){
            emit AnimalList::itemChanged( position );
        });
    }
    emit postItemRemoved();
}

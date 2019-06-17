#include "animallist.h"

AnimalList::AnimalList(QObject *parent) : QObject(parent)
{

}

QList<Animal *> AnimalList::animals() const
{
    return m_animals;
}

void AnimalList::append(Animal *animal)
{
    m_animals.append(animal);
}

int AnimalList::count() const
{
    return m_animals.size();
}

Animal *AnimalList::at(int place) const
{
    return m_animals.at(place);
}

void AnimalList::setAnimals(QList<Animal *> animals)
{
    if (m_animals == animals)
        return;

    m_animals = animals;
    emit animalsChanged(m_animals);
}

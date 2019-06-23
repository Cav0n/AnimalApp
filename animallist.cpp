#include "animallist.h"
#include "animal.h"

AnimalList::AnimalList(QObject *parent) : QObject(parent)
{
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
    append(new Animal("Tigre","https://upload.wikimedia.org/wikipedia/commons/2/2e/Tigerramki.jpg","Un magnifique fauve qui peut attendre des vitesses de barges !"));
    append(new Animal("Lion","https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Lion_d%27Afrique.jpg/440px-Lion_d%27Afrique.jpg","C'est le roi de la savane mec."));
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

void AnimalList::createAnimal(QString nom, QString imageName, QString description)
{
    append(new Animal(nom, imageName, description));
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

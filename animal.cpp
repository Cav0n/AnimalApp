#include "animal.h"

Animal::Animal(QString name, QString description)
    :
    m_name(name),
    m_description(description)
{

}

void Animal::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Animal::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}

QString Animal::name() const
{
    return m_name;
}

QString Animal::description() const
{
    return m_description;
}

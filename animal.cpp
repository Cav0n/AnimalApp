#include "animal.h"

Animal::Animal(QString name)
    :
    m_name(name)
{

}

void Animal::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

QString Animal::name() const
{
    return m_name;
}

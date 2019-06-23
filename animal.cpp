#include "animal.h"

Animal::Animal(QString id, QString name,QString imageName,QString description)
    :
    m_id(id),
    m_name(name),
    m_imageName(imageName),
    m_description(description)
{

}

void Animal::setId(QString id)
{
    if(m_id == id)
        return;

    m_id = id;
    emit idChanged(m_id);
}

void Animal::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

/* <imageName> need to be an URL because no image is stored in application
 * <imageName> will come from an api call to Wikipedia API
*/
void Animal::setImageName(QString imageName)
{
    if (m_imageName == m_imageName)
        return;

    m_imageName = imageName;
    emit imageNameChanged(m_imageName);
}

void Animal::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}

void Animal::setUrl(QString url)
{
    if (m_url == url)
        return;

    m_url = url;
    emit urlChanged(m_url);
}

QString Animal::id() const
{
    return m_id;
}

QString Animal::name() const
{
    return m_name;
}

QString Animal::imageName() const
{
    return m_imageName;
}

QString Animal::description() const
{
    return m_description;
}

QString Animal::url() const
{
    return m_url;
}

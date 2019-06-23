#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>

class Animal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString imageName READ imageName WRITE setImageName NOTIFY imageNameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

    QString m_id;
    QString m_name;
    QString m_imageName;
    QString m_description;

public:
    Animal(QString id, QString name, QString imageName,QString description);
    QString id() const;
    QString name() const;
    QString imageName() const;
    QString description() const;

public slots:
    void setId(QString id);
    void setName(QString name);
    void setImageName(QString imageName);
    void setDescription(QString description);

signals:
    void idChanged(QString id);
    void nameChanged(QString name);
    void imageNameChanged(QString imageName);
    void descriptionChanged(QString description);
    void animalChanged();
};

#endif // ANIMAL_H

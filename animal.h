#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>

class Animal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    QString m_name;

public:
    Animal(QString name);
    QString name() const;
public slots:
    void setName(QString name);
signals:
    void nameChanged(QString name);
    void animalChanged();
};

#endif // ANIMAL_H

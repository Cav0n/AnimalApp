#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H


#include <QObject>
#include <QAbstractListModel>
#include "animallist.h"
#include "animal.h"

class Animal;
class AnimalList;


class AnimalModel : public QAbstractListModel
{
    Q_OBJECT

public:
    AnimalModel( AnimalList *AnimalList, QObject *parent = nullptr);

    Q_PROPERTY(AnimalList *list READ list WRITE setList )

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    AnimalList *list() const;

    void setList(AnimalList *AnimalList);

    enum {
        Name  = Qt::UserRole,
        Animal
    };

protected:
    AnimalList *m_AnimalList;


};

#endif // ANIMALMODEL_H

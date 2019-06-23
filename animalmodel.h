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

    Q_PROPERTY(AnimalList *list READ list WRITE setList )
    AnimalList *m_AnimalList;

public:
    explicit AnimalModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    AnimalList *list() const;

    void setList(AnimalList *AnimalList);

    Q_INVOKABLE void newElement();
    Q_INVOKABLE void removeRow(int index);

    virtual QHash<int, QByteArray> roleNames() const override;
    enum {
        Id,
        Name,
        Description,
        Animal
    };
};


#endif // ANIMALMODEL_H

#include "animalmodel.h"

#include "animal.h"
#include "animallist.h"

#include <QDebug>
#include <QSettings>

AnimalModel::AnimalModel(QObject *parent)
    : QAbstractListModel(parent), m_AnimalList(nullptr)
{
}

AnimalList *AnimalModel::list() const
{
    return m_AnimalList;
}

void AnimalModel::setList(AnimalList *AnimalList)
{
    beginResetModel();

    if (m_AnimalList)
        m_AnimalList->disconnect(this);

    m_AnimalList = AnimalList;

    if (m_AnimalList) {
        connect(m_AnimalList, &AnimalList::preItemAppended, this, [=]() {
            const int index = m_AnimalList->count();        // Append implies end
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(m_AnimalList, &AnimalList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(m_AnimalList, &AnimalList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(m_AnimalList, &AnimalList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
        connect(m_AnimalList, &AnimalList::itemChanged,
                this, [=](int row){ qDebug()<< "itemChanged " << row; emit AnimalModel::dataChanged(this->index(row), this->index(row)); });
    }

    endResetModel();
}

void AnimalModel::newElement()
{
    QString nom(tr("Unknown"));
    QString imageName(tr("Unknow"));
    QString description(tr("Unknow"));

    m_AnimalList->createAnimal(nom, imageName, description);
}

void AnimalModel::removeRow(int index)
{
    m_AnimalList->removeAnimal(index);
}

int AnimalModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if ( parent.isValid())
        return 0;

    return m_AnimalList->count();
}

QVariant AnimalModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto animal = m_AnimalList->at(index.row());

    switch (role) {
    case Name:
        return animal->name();
    case Animal:
        return QVariant::fromValue(animal);
    }
    return QVariant();
}

bool AnimalModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto Animal = m_AnimalList->at(index.row());

        switch (role) {
        case Name:
            Animal->setName(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case Description:
            Animal->setDescription(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

Qt::ItemFlags AnimalModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> AnimalModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name]      = "name";
    roles[Description] = "description";
    roles[Animal]    = "animal";

    return roles;
}

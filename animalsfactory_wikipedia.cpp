#include "animalsfactory_wikipedia.h"
#include "animal.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QUrl>

#include <QDebug>


void AnimalsFactory_wikipedia::parse(const QByteArray &raw)
{
    QJsonDocument jdoc { QJsonDocument::fromJson(raw) };
    QJsonObject json { jdoc.object() };
    if(json.contains("animals") && json["animals"].isArray()) {
        QJsonArray animals = json["animals"].toArray();

        for(int isp = 0; isp < animals.size(); ++isp){
            parseAnimal(animals[isp].toObject());
        }
    }
}
void AnimalsFactory_wikipedia::parseFile(QString filename)
{
    QByteArray data;
    {
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw "Impossible d'ouvrir le fichier " + filename;
        }

        data = file.readAll();
    }

    parse(data);
}

void AnimalsFactory_wikipedia::parseAnimal(const QJsonObject &animal)
{
    QString id = animal["pageid"].toString();
    QString name = animal["title"].toString();
    QString description = animal["snippet"].toString();
    qInfo() << id;

    (*m_animals).append(new Animal(id, name, "https://upload.wikimedia.org/wikipedia/commons/thumb/0/03/Question_mark_grey.svg/439px-Question_mark_grey.svg.png", description));
}

#include "animalsfactory_wikipedia.h"

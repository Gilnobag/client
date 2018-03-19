#include "racemanager.h"
#include "race.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDebug>

RaceManager::RaceManager(QObject *parent) : QObject(parent)
{
    QFile file(":/assets/units/races.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString race_name = in.readLine();

    while(!in.atEnd()) {
        if (races_.count(race_name) != 0) {
            qWarning() << "Warning! found double occurences of races in raceslist.txt";
            continue;
        }
        if (race_name.length() < 2)
            continue;
        qDebug() << available_races_;
        available_races_.push_back(race_name);
        races_[race_name] = new Race(race_name);
        race_name = in.readLine();
    }

    if (race_name.length() >= 2) {
        qDebug() << available_races_;
        available_races_.push_back(race_name);
        races_[race_name] = new Race(race_name);
        race_name = in.readLine();
    }

}

Race* RaceManager::getRace(QString race_name) {
    if (races_.count(race_name) == 0) {
        qWarning() << "Error! Not found race with name " << race_name;
        return nullptr;
    }

    return races_[race_name];
}

const std::vector<QString>& RaceManager::getAvailableRacesList() {
    return available_races_;
}

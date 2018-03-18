#include "race.h"
#include "units/unit.h"
#include "units/warrior.h"
#include "units/mage.h"

#include <QFile>
#include <QTextStream>
#include <QString>

#include <cassert>
#include <vector>
#include <algorithm>

Race::Race(QString race_name, QObject *parent) : QObject(parent)
{
    race_name_ = race_name;

    QFile file(":/assets/units/" + race_name + "/units.txt");
    QTextStream in(&file);
    QString unit_name = in.readLine();

    units_factory_.addClass<Warrior, QString>("Warrior");
    units_factory_.addClass<Warrior, QString>("Mage");

    while (!in.atEnd()) {
        available_units_list_.push_back(unit_name);
        race_name = in.readLine();
    }
}


Unit* Race::createUnit(QString unit_name) {
    assert(std::count(available_units_list_.begin(), available_units_list_.end(), unit_name) != 0);

    QFile file(":/asserts/units/" + race_name_ + "/" + unit_name + "/baseclass.txt");
    QTextStream in(&file);
    QString class_id = in.readLine();

    return units_factory_.createObject<QString>(class_id, race_name_ + "|" + unit_name);
}

const std::vector<QString>& Race::getAvailableUnitsList() {
    return available_units_list_;
}

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
    race_id_ = race_name;

    units_factory_.addClass<Warrior, QString>("Warrior");
    units_factory_.addClass<Warrior, QString>("Mage");

    QFile file(":/assets/units/" + race_name + "/units.txt");
    QTextStream in(&file);
    QString unit_name = in.readLine();

    while (!in.atEnd()) {
        all_units_list_.push_back(createUnit(unit_name));
        available_units_list_.push_back(unit_name);
        unit_name = in.readLine();
    }

    QFile file0(":/assets/units/" + race_name + "/racename.txt");
    QTextStream in0(&file);
    race_name_ = in0.readLine();

    QFile file1(":/assets/units/" + race_name + "/descr.txt");
    QTextStream in1(&file);
    race_descr_ = in1.readAll();

    race_icon_.load(":/assets/units/" + race_name + "/descr.txt");
}

QString Race::getRaceId() {
    return race_id_;
}

QString Race::getRaceName() {
    return race_name_;
}

QImage Race::getRaceIcon() {
    return race_icon_;
}

QString Race::getRaceDescr() {
    return race_descr_;
}

Unit* Race::createUnit(QString unit_name) {
    assert(std::count(available_units_list_.begin(), available_units_list_.end(), unit_name) != 0);

    QFile file(":/asserts/units/" + race_id_ + "/" + unit_name + "/baseclass.txt");
    QTextStream in(&file);
    QString class_id = in.readLine();

    return units_factory_.createObject<QString>(class_id, race_id_ + "|" + unit_name);
}

const std::vector<QString>& Race::getAvailableUnitsList() {
    return available_units_list_;
}

const std::vector<Unit*> &Race::getAllUnitsList() {
    return all_units_list_;
}

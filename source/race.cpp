#include "race.h"
#include "units/unit.h"
#include "units/warrior.h"
#include "units/mage.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

#include <cassert>
#include <vector>
#include <algorithm>

Race::Race(QString race_name, QObject *parent) : QObject(parent)
{
    race_id_ = race_name;

    units_factory_.addClass<Warrior, QString>("Warrior");
    units_factory_.addClass<Warrior, QString>("Mage");
    units_factory_.addClass<Warrior, QString>("Rider");
    units_factory_.addClass<Warrior, QString>("Rogue");
    units_factory_.addClass<Warrior, QString>("Archer");

    QFile file(":/assets/units/" + race_name + "/units.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString unit_name = in.readLine();

    while (!in.atEnd()) {
        available_units_list_.push_back(unit_name);
        all_units_list_.push_back(createUnit(unit_name));
        unit_name = in.readLine();
    }

    if (unit_name.length() > 2) {
        available_units_list_.push_back(unit_name);
        all_units_list_.push_back(createUnit(unit_name));
    }

    QFile file0(":/assets/units/" + race_name + "/racename.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream in0(&file0);
    race_name_ = in0.readLine();

    QFile file1(":/assets/units/" + race_name + "/descr.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    race_descr_ = in1.readAll();

    race_icon_.load(":/assets/units/" + race_name + "/icon.png");
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
    qDebug() << unit_name;
    QFile file(":/assets/units/" + race_id_ + "/" + unit_name + "/baseclass.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString class_id = in.readLine();
    qDebug() << "Creating unit of base class " << class_id << " and major class" <<  race_id_ + "|" + unit_name;
    return units_factory_.createObject<QString>(class_id, race_id_ + "|" + unit_name);
}

const std::vector<QString>& Race::getAvailableUnitsList() {
    return available_units_list_;
}

const std::vector<Unit*> &Race::getAllUnitsList() {
    return all_units_list_;
}

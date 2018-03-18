#include "race.h"
#include "units/unit.h"

#include <QFile>
#include <QTextStream>
#include <QString>

Race::Race(QString race_name, QObject *parent) : QObject(parent)
{
    QFile file(":/assets/units/" + race_name + "/units.txt");
    QTextStream in(&file);
    QString unit_name = in.readLine();

    //units_factory_.registerClass();

    while (!in.atEnd()) {
        available_units_list_.push_back(unit_name);
        race_name = in.readLine();
    }
}


Unit* createUnit(QString unit_name);

std::vector<QString> getAvailableUnitsList();

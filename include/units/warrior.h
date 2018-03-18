#ifndef UNITS_WARRIOR_H
#define UNITS_WARRIOR_H

#include "units/unit.h"

#include <QObject>
#include <QString>

class Warrior : public Unit
{
public:
    explicit Warrior(QString unit_name);
};

#endif // UNITS_WARRIOR_H

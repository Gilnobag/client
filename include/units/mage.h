#ifndef UNITS_MAGE_H
#define UNITS_MAGE_H

#include "units/unit.h"

#include <QObject>

class Mage : public Unit
{
public:
    explicit Mage(QString parameters);
};

#endif // UNITS_MAGE_H

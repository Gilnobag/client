#ifndef INCLUDEACE_H
#define INCLUDEACE_H

#include <QObject>
#include <QString>

#include <vector>

#include "abstractfactory.h"

class Unit;

class Race : public QObject
{
    Q_OBJECT
public:
    explicit Race(QString race_name, QObject *parent = nullptr);

    Unit* createUnit(QString unit_name);

    const std::vector<QString> &getAvailableUnitsList();

private:
    ObjectFactory<Unit, QString> units_factory_;
    std::vector<QString> available_units_list_;

signals:

public slots:
};

#endif // INCLUDEACE_H

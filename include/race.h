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
    explicit Race(QObject *parent = nullptr);

    Unit* createUnit(QString race_name);

    std::vector<QString> getAvailableUnitsList();

private:
    ObjectFactory<Unit, QString> units_factory_;
signals:

public slots:
};

#endif // INCLUDEACE_H

#ifndef INCLUDEACE_H
#define INCLUDEACE_H

#include <QObject>
#include <QString>
#include <QImage>

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
    const std::vector<Unit*> &getAllUnitsList();

    QString getRaceId();
    QString getRaceName();
    QImage getRaceIcon();
    QString getRaceDescr();

private:
    QString race_id_;
    QString race_name_;
    QImage race_icon_;
    QString race_descr_;
    ObjectFactory<Unit, QString> units_factory_;
    std::vector<QString> available_units_list_;
    std::vector<Unit*> all_units_list_;

signals:

public slots:
};

#endif // INCLUDEACE_H

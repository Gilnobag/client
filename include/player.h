#ifndef INCLUDEPLAYER_H
#define INCLUDEPLAYER_H

#include "units/unit.h"
#include "racemanager.h"

#include <QObject>
#include <QDebug>

#include <set>

class Race;

template<class Obj, class Identifier>
class ObjectFactory;

class Player {
    struct unit_comparator {
        bool operator() (const Unit* lhs, const Unit* rhs) const {
            if (rhs == nullptr)
                return true;
            if (lhs->getUnitBaseClassId() != rhs->getUnitBaseClassId())
                return lhs->getUnitBaseClassId() < rhs->getUnitBaseClassId();
            return lhs->getUnitId() < rhs->getUnitId();
        }
    };

public:
    Player() {
        init(1);
    }

    void init(int id) {
        player_name_ = "Игрок " + QString::number(id + 1);
        race_ = RaceManager::getInstance().getRace(
                    RaceManager::getInstance().getAvailableRacesList()[0]
                );
        units_.clear();
    }

    QString getPlayerName() {
        return player_name_;
    }

    const std::multiset<Unit*, unit_comparator>& getUnits() {
        return units_;
    }

    std::vector<Unit*> getUnitsAsVector() {
        std::vector<Unit*> result;
        for (auto unit: units_)
            result.push_back(unit);
        return result;
    }

    void addUnit(Unit *a) {
        if (units_.size() >= 10)
            return;
        units_.insert(a);
    }

    void deleteUnit(Unit *a) {
        qDebug() << "deleting unit " << a->getUnitName();
        auto unit = units_.find(a);
        if (unit != units_.end())
            units_.erase(unit);
    }

    void clearUnits() {
        units_.clear();
    }

    Race* getRace() {
        return race_;
    }

    void setRace(Race* race) {
        race_ = race;
    }

signals:

public slots:

private:
    QString player_name_;
    std::multiset<Unit*, unit_comparator> units_;
    Race* race_;
};

#endif // INCLUDEPLAYER_H

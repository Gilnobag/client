#ifndef INCLUDEPLAYER_H
#define INCLUDEPLAYER_H

#include "units/unit.h"
#include "racemanager.h"

#include <QObject>

#include <set>

class Race;

template<class Obj, class Identifier>
class ObjectFactory;

class Player {
public:
    Player() {

    }

    void init(int id) {
        player_name_ = "Игрок " + QString::number(id);
        race_ = RaceManager::getInstance().getRace(
                    RaceManager::getInstance().getAvailableRacesList()[0]
                );
        units_.clear();
    }

    QString getPlayerName() {
        return player_name_;
    }

    const std::set<Unit>& getUnits() {
        return units_;
    }

    Race* getRace() {
        return race_;
    }

signals:

public slots:

private:
    QString player_name_;
    std::set<Unit> units_;
    Race* race_;
};

#endif // INCLUDEPLAYER_H

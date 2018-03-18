#ifndef INCLUDEPLAYER_H
#define INCLUDEPLAYER_H

#include "units/unit.h"

#include <QObject>

#include <set>

class Race;

template<class Obj, class Identifier>
class ObjectFactory;

template<int id>
class Player {
private:
    Player() {

    }

public:
    static Player& getInstance() {
        static Player<id> instance;
        return instance;
    }

    void init() {
        player_name_ = "Игрок " + QString::number(id);
        race_ = nullptr;
        units_.clear();
    }

signals:

public slots:

private:
    QString player_name_;
    std::set<Unit> units_;
    Race* race_;
};

#endif // INCLUDEPLAYER_H

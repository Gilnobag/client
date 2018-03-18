//
// Created by IgorBat on 17.03.2018.
//

#ifndef THE_GAME_SPELL_H
#define THE_GAME_SPELL_H

#pragma once
#include <iostream>
#include <vector>
//#include "AbstractFactory.h"
#include "effect.h"
class Cell;

class Spell {

protected:
    std::vector <Effect> effects_;

private:
    int distance_;
    bool forCell_;
public:
    Spell() = delete;
    Spell(std::string path) {

    }
    virtual ~Spell() = delete;

    int getDistance();
    void setDistance(int value);

    bool getForCell();
    void setForCell(bool value);

    int lenOfActualPath(Cell* destination);

    virtual bool canCastForDistance(int distance);

    virtual bool canCastToCell(Cell* destination);

    virtual void castToCell(Cell* destination);
};
#endif //THE_GAME_SPELL_H

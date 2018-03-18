//
// Created by IgorBat on 17.03.2018.
//

#ifndef THE_GAME_EFFECT_H
#define THE_GAME_EFFECT_H

#pragma once
#include <iostream>
#include <vector>
//#include "AbstractFactory.h"
enum typeEffect{damage, strength};
class Effect {

private:
    int count_;
    typeEffect typeEffect_;
public:
    Effect() = delete;
    Effect(std::string path) {

    }
    virtual ~Effect() = delete;

    int getCount();
    void setCount(int value);

    typeEffect getType();
    void setType(typeEffect value);
};
#endif //THE_GAME_EFFECT_H

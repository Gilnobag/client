#pragma once
#include <iostream>
#include <cassert>
#include "unit.h"

class Warrior : public Unit {
	Warrior() = delete;
	Warrior(std::string id);
	~Warrior();

	double reduceIncomingDamage(std::string damageType, int damage);

	bool canAttackForDistance(int distance);

	bool canAttackToCell(Cell* destination);

	bool canAttackUnit(Unit* target);
};
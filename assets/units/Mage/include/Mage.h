#pragma once
#pragma once
#include <iostream>
#include <cassert>
#include "unit.h"

class Mage : public Unit {
	Mage() = delete;
	Mage(std::string id);
	~Mage();

	bool canAttackForDistance(int distance);

	bool canAttackToCell(Cell* destination);

	bool canAttackUnit(Unit* target);
};

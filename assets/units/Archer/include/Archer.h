#pragma once
#include <iostream>
#include <cassert>
#include "unit.h"

class Archer : public Unit {
	Archer() = delete;
	Archer(std::string id);
	~Archer();

	bool canAttackForDistance(int distance);

	bool canAttackToCell(Cell* destination);

	bool canAttackUnit(Unit* target);
};

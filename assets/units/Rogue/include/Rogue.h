#pragma once
#include <iostream>
#include <cassert>
#include "unit.h"

class Rogue : public Unit {
	Rogue() = delete;
	Rogue(std::string id);
	~Rogue();

	//backstab

	bool canAttackForDistance(int distance);

	bool canAttackToCell(Cell* destination);

	bool canAttackUnit(Unit* target);
};

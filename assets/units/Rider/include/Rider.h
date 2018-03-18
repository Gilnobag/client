#pragma once
#include <iostream>
#include <cassert>
#include "unit.h"

class Rider : public Unit {
	Rider() = delete;
	Rider(std::string id);
	~Rider();

	//increase dmg with len of movement path

	bool canAttackForDistance(int distance);

	bool canAttackToCell(Cell* destination);

	bool canAttackUnit(Unit* target);
};

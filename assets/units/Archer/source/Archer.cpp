#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "unit.h"
#include "Archer.h"

Archer::Archer(std::string id) {
}

Archer::~Archer() {}

bool Archer::canAttackForDistance(int distance) { 
	//this is a dummy
	srand(time(0));
	return rand() % 2;
}

bool Archer::canAttackToCell(Cell * destination) {
	return canAttackForDistance(lenOfActualPath(destination) + getAttackCost() * getMovementSpeed());
}

bool Archer::canAttackUnit(Unit * target) {
	return canAttackToCell(target->getLocation());
}

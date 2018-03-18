#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "unit.h"
#include "Rogue.h"

Rogue::Rogue(std::string id) {
}

Rogue::~Rogue() {}

bool Rogue::canAttackForDistance(int distance) {
	return (canMoveForDistance(attack_cost_ * getMovementSpeed() + distance - attack_range_));
}

bool Rogue::canAttackToCell(Cell * destination) {
	return lenOfActualPath(destination) != 0 &&
		canAttackForDistance(lenOfActualPath(destination));
}

bool Rogue::canAttackUnit(Unit * target) {
	return canAttackToCell(target->getLocation());
}
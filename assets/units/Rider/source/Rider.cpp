#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "unit.h"
#include "Rider.h"

Rider::Rider(std::string id) {
}

Rider::~Rider(){}

bool Rider::canAttackForDistance(int distance) {
	return (canMoveForDistance(attack_cost_ * getMovementSpeed() + distance - attack_range_));
}

bool Rider::canAttackToCell(Cell * destination) {
	return lenOfActualPath(destination) != 0 &&
		canAttackForDistance(lenOfActualPath(destination));
}

bool Rider::canAttackUnit(Unit * target) {
	return canAttackToCell(target->getLocation());
}
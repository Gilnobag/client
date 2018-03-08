#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include "unit.h"

Unit::Unit() {}

double Unit::getExperience() {
	return experience_;
}
void Unit::setExperience(double value) {
	experience_ = value;
}

double Unit::getLevel() {
	return level_;
};
void Unit::setLevel(double value) {
	level_ = value;
}

double Unit::getHealthPoints() {
	return health_points_;
};
void Unit::setHealthPoints(double value) {
	health_points_ = value;
}

double Unit::getManaPoints() {
	return mana_points_;
}
void Unit::setManaPoints(double value) {
	mana_points_ = value;
}

double Unit::getEnergyPoints() {
	return energy_points_;
}
void Unit::setEnergyPoints(double value) {
	energy_points_ = value;
}

double Unit::getAttackRange() {
	return attack_range_;
}
void Unit::setAttackRange(double value) {
	attack_range_ = value;
}

Cell* Unit::getLocation() {
	return location_;
}
void Unit::setLocation(Cell* to) {
	location_ = to;
}

int Unit::getMovementPoints() {
	return movement_points_;
}
void Unit::setMovementPoints(int value) {
	movement_points_ = value;
}

double Unit::getInitiative() {
	return initiative_;
}
void Unit::setInitiative(double value) {
	initiative_ = value;
}

double Unit::getDamagePerHit() {
	return damage_per_hit_;
}
void Unit::setDamagePerHit(double value) {
	damage_per_hit_ = value;
}

double Unit::getIntelligence() {
	return intelligence_;
}
void Unit::setIntelligence(double value) {
	intelligence_ = value;
}

double Unit::getStrength() {
	return strength_;
}
void Unit::setStrength(double value) {
	strength_ = value;
}

double Unit::getAgility() {
	return agility_;
}
void Unit::setAgility(double value) {
	agility_ = value;
}

double Unit::getMagicDefence() {
	return magic_defence_;
}
void Unit::setMagicDefence(double value) {
	magic_defence_ = value;
}

double Unit::getPhysicDefence() {
	return physic_defence_;
}
void Unit::setPhysicDefence(double value) {
	physic_defence_ = value;
}

std::string Unit::getRace() {
	return race_;
}
void Unit::setRace(std::string new_race) {
	race_ = new_race;
}

double Unit::getRealX() {
	return real_x_;
}
void Unit::setRealX(double x) {
	real_x_ = x;
}

double Unit::getRealY() {
	return real_y_;
}
void Unit::setRealY(double y) {
	real_y_ = y;
}

void Unit::calculateDamagePerHit() {
	damage_per_hit_ = 0.5 * std::max(getAgility(), std::max(getStrength(), getIntelligence()));
}

double Unit::reduceIncomingDamage(std::string damageType, int damage) { //returns damage after reducing by defence
	assert("Incorrect damage type in call reduceIncomingDamage(), expected" &&
		damageType[0] == 'p' || damageType[0] == 'P' || damageType[0] == 'm' || damageType[0] == 'M');
	assert("Magic defence of unit is incorrectly high (>40), but must be" && magic_defence_ <= 40);
	assert("Physic defence of unit is incorrectly high (>40), but must be" && physic_defence_ <= 40);
	if (damageType[0] == 'p' || damageType[0] == 'P') {
		return (1 - 2.5 * physic_defence_ / 100) * damage;
	}
	else if (damageType[0] == 'm' || damageType[0] == 'M') {
		return (1 - 2.5 * magic_defence_ / 100) * damage;
	}
}

int Unit::lenOfActualPath(Cell* destination) {
	return getLocation()->actualPath(destination).size();
}

bool Unit::canMoveForDistance(int distance) {
	return (movement_points_ >= distance);
}

bool Unit::canMoveToCell(Cell* destination) {
	return (destination->isEmpty() && canMoveForDistance(lenOfActualPath(destination)));
}

void Unit::moveToCell(Cell* destination) {
	if (!canMoveToCell)
		return;	//here could be a gui-message about failed move (x-mark, for example)
	else {
		int decreasedValue = getMovementPoints() - lenOfActualPath(destination);
		setMovementPoints(decreasedValue);
		setLocation(destination);
	}
}



/*bool canAttack(int distance) {

}*/

//TODO: real_x_, real_y_

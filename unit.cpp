#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include "unit.h"

Unit::Unit(){}

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

double Unit::getActivePoints() {
	return active_points_;
}
void Unit::setActivePoints(double value) {
	active_points_ = value;
}

double Unit::getAttackRange() {
	return attack_range_;
}
void Unit::setAttackRange(double value) {
	attack_range_ = value;
}

std::pair<int, int> Unit::getLocation() {
	return location_;
}
void Unit::setLocation(double x, double y) {
	location_ = std::make_pair(x, y);
}

double Unit::getMovementSpeed() {
	return movement_speed_;
}
void Unit::setMovementSpeed(double value) {
	movement_speed_ = value;
}

double Unit::getInitiative_() {
	return initiative_;
}
void Unit::setInitiative_(double value) {
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

int main() {
	//testing correctness of formul
	int a, b;
	Unit* test = new Unit();
	test->setMagicDefence(5);
	test->setPhysicDefence(40);
	std::cout << test->reduceIncomingDamage("m", 100) << std::endl;
	std::cout << test->reduceIncomingDamage("p", 100);
}
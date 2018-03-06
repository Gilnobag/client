#pragma once
#include <iostream>
#include "unit.h"

Unit::Unit(){}

int Unit::getExperience() {
	return experience_;
}
void Unit::setExperience(int value) {
	experience_ = value;
}

int Unit::getExperience() {
	return experience_;
}
void Unit::setExperience(int value) {
	experience_ = value;
}

int Unit::getExperience() {
	return experience_;
}
void Unit::setExperience(int value) {
	experience_ = value;
}

int Unit::getExperience() {
	return experience_;
}
void Unit::setExperience(int value) {
	experience_ = value;
}

int Unit::getLevel() {
	return level_;
};
void Unit::setLevel(int value) {
	level_ = value;
}

int Unit::getHealthPoints() {
	return health_points_;
};
void Unit::setHealthPoints(int value) {
	health_points_ = value;
}

int Unit::getManaPoints() {
	return mana_points_;
}
void Unit::setManaPoints(int value) {
	mana_points_ = value;
}

int Unit::getEnergyPoints() {
	return energy_points_;
}
void Unit::setEnergyPoints(int value) {
	energy_points_ = value;
}

int Unit::getActivePoints() {
	return active_points_;
}
void Unit::setActivePoints(int value) {
	active_points_ = value;
}

int Unit::getAttackRange() {
	return attack_range_;
}
void Unit::setAttackRange(int value) {
	attack_range_ = value;
}

std::pair<int, int> Unit::getLocation() {
	return location_;
}
void Unit::setLocation(int x, int y) {
	location_ = std::make_pair(x, y);
}

int Unit::getMovementSpeed() {
	return movement_speed_;
}
void Unit::setMovementSpeed(int value) {
	movement_speed_ = value;
}

int Unit::getInitiative_() {
	return initiative_;
}
void Unit::setInitiative_(int value) {
	initiative_ = value;
}

int Unit::getDamagePerHit() {
	return damage_per_hit_;
}
void Unit::setDamagePerHit(int value) {
	damage_per_hit_ = value;
}

int Unit::getIntelligence() {
	return intelligence_;
}
void Unit::setIntelligence(int value) {
	intelligence_ = value;
}

int Unit::getStrength() {
	return strength_;
}
void Unit::setStrength(int value) {
	strength_ = value;
}

int Unit::getAgility() {
	return agility_;
}
void Unit::setAgility(int value) {
	agility_ = value;
}

int Unit::getMagicDefence() {
	return magic_defence_;
}
void Unit::setMagicDefence(int value) {
	magic_defence_ = value;
}

int Unit::getPhysicDefence() {
	return physic_defence_;
}
void Unit::setPhysicDefence(int value) {
	physic_defence_ = value;
}
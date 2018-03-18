#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>

#include "AbstractFactory.h"
#include "units/unit.h"

Unit::Unit(QString unit_name) {

}

int Unit::getCost(){
	return cost_;
}


std::string Unit::getParentSpec(){
	return parent_spec_;
}



std::vector<std::string> Unit::getUpgradeSpecs(){
	return upgrade_specs_;
}



double Unit::getExperience() {
	return experience_;
}


double Unit::getLevel() {
	return level_;
}


double Unit::getHealthPoints() {
	return health_points_;
}


double Unit::getAttackRange() {
	return attack_range_;
}


int Unit::getActivityPoints(){
	return activity_points_;
}


Cell* Unit::getLocation() {
	return location_;
}
void Unit::setLocation(Cell* to) {
	location_ = to;
}

int Unit::getMovementSpeed() {
	return movement_speed_;
}


int Unit::getAttackCost(){
	return attack_cost_;
}


double Unit::getInitiative() {
	return initiative_;
}


double Unit::getDamagePerHit() {
	return damage_per_hit_;
}


double Unit::getIntelligence() {
	return intelligence_;
}


double Unit::getStrength() {
	return strength_;
}


double Unit::getAgility() {
	return agility_;
}


int Unit::getAttackPoints(){
	return attack_cost_;
}


double Unit::getMagicDefence() {
	return magic_defence_;
}


double Unit::getPhysicDefence() {
	return physic_defence_;
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
	return (movement_speed_ >= distance);
}

bool Unit::canMoveToCell(Cell* destination) {
	return (destination->isEmpty() && lenOfActualPath(destination) > 0 && canMoveForDistance(lenOfActualPath(destination)));
}	

void Unit::moveToCell(Cell* destination) {
	if (!canMoveToCell(destination))
		return;	//here could be a gui-message about failed move (x-mark, for example)
	else {
        movement_speed_ -= lenOfActualPath(destination);
		setLocation(destination);
	}
}

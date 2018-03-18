#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "unit.h"
#include "Warrior.h"

Warrior::Warrior(std::string id){
}

Warrior::~Warrior(){}

double Warrior::reduceIncomingDamage(std::string damageType, int damage) {//returns damage after reducing by defence
	assert("Incorrect damage type in call reduceIncomingDamage(), expected" &&
		damageType[0] == 'p' || damageType[0] == 'P' || damageType[0] == 'm' || damageType[0] == 'M');
	assert("Magic defence of unit is incorrectly high (>40), but must be" && magic_defence_ <= 40);
	assert("Physic defence of unit is incorrectly high (>40), but must be" && physic_defence_ <= 40);
	if (damageType[0] == 'p' || damageType[0] == 'P') {
		srand(time(0));
		double reduced = (1 - 2.5 * physic_defence_ / 100) * damage;
		if (rand() % 10 == 0) {
			reduced = reduced / 2.0;
		}
		return reduced;
	}
	else if (damageType[0] == 'm' || damageType[0] == 'M') {
		return (1 - 2.5 * magic_defence_ / 100) * damage;
	}
}

bool Warrior::canAttackForDistance(int distance){
	return (canMoveForDistance(attack_cost_ * getMovementSpeed() + distance - attack_range_));
}

bool Warrior::canAttackToCell(Cell * destination){
	return lenOfActualPath(destination) != 0 && 
				canAttackForDistance(lenOfActualPath(destination));
}

bool Warrior::canAttackUnit(Unit * target){
	return canAttackToCell(target->getLocation());
}

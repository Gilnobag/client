#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "unit.h"
#include "Mage.h"

Mage::Mage(std::string id){
}

Mage::~Mage(){}

bool Mage::canAttackForDistance(int distance){ //this is a dummy
	srand(time(0));
	return rand() % 2;
}

bool Mage::canAttackToCell(Cell * destination){
	return canAttackForDistance(lenOfActualPath(destination) + getAttackCost() * getMovementSpeed());
}

bool Mage::canAttackUnit(Unit * target){
	return canAttackToCell(target->getLocation());
}

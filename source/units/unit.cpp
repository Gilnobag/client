#include "AbstractFactory.h"
#include "units/unit.h"

#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>

#include <QFile>
#include <QString>
#include <QTextStream>

Unit::Unit(QString parameters) {
    QStringList params = parameters.split("|");

    assert(params.size() >= 2);

    unit_id_ = params[0];
    race_id_ = params[1];

    QString unit_folder = ":/assets/units/" + race_id_ + "/" + unit_id_ + "/";

    loadUnitName(unit_folder);
    loadUnitDescr(unit_folder);
    loadUnitBaseClass(unit_folder);
    loadUnitTraits(unit_folder);
    loadUnitIcon(unit_folder);
    loadUnitPrevSpecs(unit_folder);
    loadUnitUpgradeSpecs(unit_folder);
}

void Unit::loadUnitName(QString unit_folder) {
    QFile file(unit_folder + "unitname.txt");
    QTextStream in(&file);
    unit_name_ = in.readLine();
}

void Unit::loadUnitDescr(QString unit_folder) {
    QFile file(unit_folder + "descr.txt");
    QTextStream in(&file);
    unit_descr_ = in.readAll();
}

void Unit::loadUnitBaseClass(QString unit_folder) {
    QFile file(unit_folder + "baseclass.txt");
    QTextStream in(&file);
    base_class_id_ = in.readLine();
}

void Unit::loadUnitTraits(QString unit_folder) {
   // TO BE DONE!!!
    health_points_ = rand();
    activity_points_ = rand();
    attack_cost_ = rand();
    attack_range_ = rand();
}

void Unit::loadUnitIcon(QString unit_folder) {
    unit_icon_.load(unit_folder + "icon.png");
}

void Unit::loadUnitPrevSpecs(QString unit_folder) {
    QFile file(unit_folder + "prevgrades.txt");
    QTextStream in(&file);
    QString line = in.readLine();
    while (in.atEnd()) {
        parent_specs_.push_back(line);
        line = in.readLine();
    }
}

void Unit::loadUnitUpgradeSpecs(QString unit_folder) {
    QFile file(unit_folder + "nextgrades.txt");
    QTextStream in(&file);
    QString line = in.readLine();
    while (in.atEnd()) {
        upgrade_specs_.push_back(line);
        line = in.readLine();
    }
}

int Unit::getCost(){
	return cost_;
}

std::vector<QString> Unit::getParentSpecs(){
    return parent_specs_;
}

std::vector<QString> Unit::getUpgradeSpecs(){
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

int Unit::getStartingActivityPoints() {
	return starting_activity_points_;
}
void Unit::setStartingActivityPoints(int value) {
	starting_activity_points_ = value;
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
	return (activity_points_ * movement_speed_ >= distance);
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

QString Unit::getUnitName() const {
    return unit_name_;
}

QString Unit::getUnitDescr() const {
    return unit_descr_;
}

QString Unit::getUnitBaseClassId() const {
    return base_class_id_;
}

std::vector<QString> Unit::getUnitTraits() const {
    return {
            QString::number(health_points_),
            QString::number(attack_range_),
            QString::number(activity_points_),
            QString::number(initiative_)
    };
}

QImage Unit::getUnitIcon() const {
    return unit_icon_;
}

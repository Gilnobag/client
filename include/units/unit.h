#pragma once

#include "AbstractFactory.h"

#include <QObject>
#include <QString>

#include <iostream>
#include <vector>

class Spell {
public:
    int a;
};

class Cell {
	//waiting for a realisation
public:
	//must be in cell.h
	bool isEmpty() { 
		return true;
	}
	std::vector <Cell*> actualPath(Cell* destination) { //the shortest existing path from (*this) to (*destination)
		std::vector <Cell*> path;
		return path;
	}
};

class Unit : public QObject {
    Q_OBJECT

public:
    explicit Unit(QString unit_name);

    virtual ~Unit() {}

    //---------------------------------------------//
    //---------Basic traits getters section--------//
    //---------------------------------------------//

	double getExperience();
	double getLevel();
    int    getMovementSpeed();
	double getInitiative();
	double getDamagePerHit();

	double getIntelligence();
	double getStrength();
	double getAgility();

    int    getActivityPoints();
    int    getAttackPoints();
    int    getAttackCost();
    double getAttackRange();

    double getHealthPoints();

    double getMagicDefence();
	double getPhysicDefence();

    int getCost();
    void setCost(int value);

    std::string              getParentSpec();
    std::vector<std::string> getUpgradeSpecs();

    //---------------------------------------------//
    //------------Unit location section------------//
    //---------------------------------------------//

    Cell* getLocation();
    void setLocation(Cell* to);

	double getRealX();
	void setRealX(double x);

	double getRealY();
	void setRealY(double y);


    //---------------------------------------------//
    //--------Damage checkers & calculators--------//
    //---------------------------------------------//

    virtual void calculateDamagePerHit();

    virtual double reduceIncomingDamage(std::string damageType, int value);

    virtual	bool canAttackForDistance(int distance) {}

    virtual bool canAttackToCell(Cell* destination) {}

    virtual bool canAttackUnit(Unit* target) {}

    //---------------------------------------------//
    //-------Movement checkers & calculators-------//
    //---------------------------------------------//


    int lenOfActualPath(Cell* destination);

    virtual bool canMoveForDistance(int distance);

    virtual bool canMoveToCell(Cell* destination);

    virtual void moveToCell(Cell* destination);

protected:
    std::vector <Spell> skills_;

    //personal information
    int cost_;
    std::string parent_spec_;
    std::vector<std::string> upgrade_specs_;
    double experience_;
    double level_;
    std::string race_; //lower case

    //actions and events
    double initiative_;
    int activity_points_;

    //movement
    Cell* location_;
    int movement_speed_;	//how many cells can move for one activity point
    double real_x_;
    double real_y_;

    //attack action
    double agility_;
    double attack_range_;
    double damage_per_hit_;
    double intelligence_;
    double strength_;
    int attack_cost_;     //how many activity points does attack cost

    //durability
    double health_points_;
    double magic_defence_;  //less or equal 40
    double physic_defence_; //less or equal 40

};

#pragma once
#include <iostream>
#include <vector>

class Spell {
	//waiting
};
class Cell {
	//waiting for a realisation
public:
	bool isEmpty() {
		return true;
	}
	std::vector <Cell*> actualPath(Cell* destination) { //the shortest existing path from (*this) to (*destination)
		std::vector <Cell*> path;
		return path;
	}
};

class Unit {

protected:
	std::vector <Spell> skills_;

private:
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

public:
	Unit() = delete;
	Unit(std::string path) {

	}
	virtual ~Unit() = delete;

	int getCost();
	void setCost(int value);

	std::string getParentSpec();
	void setParentSpec(std::string specId);

	std::vector<std::string> getUpgradeSpecs();
	void setUpgradeSpecs(std::vector <std::string> specs);

	double getExperience();
	void setExperience(double value);

	double getLevel();
	void setLevel(double value);

	double getHealthPoints();
	void setHealthPoints(double value);

	double getAttackRange();
	void setAttackRange(double value);

	int getActivityPoints();
	void setActivityPoints(int value);

	Cell* getLocation();
	void setLocation(Cell* to);

	int getMovementSpeed();
	void setMovementSpeed(int value);

	int getAttackCost();
	void setAttackCost(int value);

	double getInitiative();
	void setInitiative(double value);

	double getDamagePerHit();
	void setDamagePerHit(double value);

	double getIntelligence();
	void setIntelligence(double value);

	double getStrength();
	void setStrength(double value);

	double getAgility();
	void setAgility(double value);

	int getAttackPoints();
	void setAttackPoints(int value);

	double getMagicDefence();
	void setMagicDefence(double value);

	double getPhysicDefence();
	void setPhysicDefence(double value);

	std::string getRace();
	void setRace(std::string new_race);

	double getRealX();
	void setRealX(double x);

	double getRealY();
	void setRealY(double y);

	virtual void calculateDamagePerHit();

	virtual double reduceIncomingDamage(std::string damageType, int value);

	int lenOfActualPath(Cell* destination);

	virtual bool canMoveForDistance(int distance);

	virtual bool canMoveToCell(Cell* destination);

	virtual void moveToCell(Cell* destination);

	virtual	bool canAttackForDistance(int distance) = 0;

	virtual bool canAttackToCell(Cell* destination) = 0;

	virtual bool canAttackUnit(Unit* target) = 0;
};
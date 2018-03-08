#pragma once
#include <iostream>
#include <vector>

class Spell {
	//waiting for a realisation
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
	double experience_;
	double level_;
	std::string race_; //lower case

	//actions and events
	double initiative_;

	//movement
	Cell* location_;
	double movement_points_; //how many cells can move for one activity point
	double real_x_;
	double real_y_;

	//attack action
	double agility_;
	double attack_range_;
	double damage_per_hit_;
	double energy_points_;  //for physical attacks
	double intelligence_;
	double mana_points_;    //for magic attacks
	double strength_;

	//durability
	double health_points_;
	double magic_defence_;  //less or equal 40
	double physic_defence_; //less or equal 40

public:
	Unit();
	virtual ~Unit() = delete;

	double getExperience();
	void setExperience(double value);

	double getLevel();
	void setLevel(double value);

	double getHealthPoints();
	void setHealthPoints(double value);

	double getManaPoints();
	void setManaPoints(double value);

	double getEnergyPoints();
	void setEnergyPoints(double value);

	double getAttackRange();
	void setAttackRange(double value);

	Cell* getLocation();
	void setLocation(Cell* to);

	int getMovementPoints();
	void setMovementPoints(int value);

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
	
//	bool canAttackForDistance(int distance);
};
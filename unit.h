#pragma once
#include <iostream>
#include <vector>

class Spell {
	//empty for allow to compile
};

class Unit {

protected:
	std::vector <Spell> skills_;

private:
	//personal growth
	int experience_;
	int level_;

	//connect with events
	int active_points_;
	int initiative_;

	//movement
	std::pair <int, int> location_; //x - first, y - second
	int movement_speed_;

	//attack action
	int agility_;
	int attack_range_;
	int damage_per_hit_;
	int energy_points_;  //for physical attacks
	int intelligence_;
	int mana_points_;    //for magic attacks
	int strength_;

	//durability
	int health_points_;
	int magic_defence_;
	int physic_defence_;

public:
	Unit();
	virtual ~Unit() = delete;

	int getExperience();
	void setExperience(int value);

	int getLevel();
	void setLevel(int value);

	int getHealthPoints();
	void setHealthPoints(int value);

	int getManaPoints();
	void setManaPoints(int value);

	int getEnergyPoints();
	void setEnergyPoints(int value);

	int getActivePoints();
	void setActivePoints(int value);

	int getAttackRange();
	void setAttackRange(int value);

	std::pair<int, int> getLocation();
	void setLocation(int x, int y);

	int getMovementSpeed();
	void setMovementSpeed(int value);

	int getInitiative_();
	void setInitiative_(int value);

	int getDamagePerHit();
	void setDamagePerHit(int value);

	int getIntelligence();
	void setIntelligence(int value);

	int getStrength();
	void setStrength(int value);

	int getAgility();
	void setAgility(int value);

	int getMagicDefence();
	void setMagicDefence(int value);

	int getPhysicDefence();
	void setPhysicDefence(int value);
};
#pragma once
#include <iostream>
#include <vector>

class Spell {
	//empty for allow to compile
};

class Unit {
protected:
	int expirience_;
	int level_;
	int hit_points_;
	int mana_points_;
	int energy_points_;
	int active_points_;
	int atack_range_;
	std::pair <int, int> location_; //x - first, y - second
	std::vector <Spell> skills_;
private:
	

public:
	Unit();
	virtual ~Unit();
};
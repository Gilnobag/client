#pragma once
#include <iostream>
#include <vector>

class Spell {
	//empty for allow to compile
};

class Unit {
private:
	int expirience_;
	int level_;
	int hit_points_;
	int mana_points_;
	int energy_points_;
	int active_points_;
	std::vector <Spell> skills_;
public:
	virtual Unit();
	virtual ~Unit();
};
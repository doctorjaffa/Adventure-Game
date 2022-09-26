#pragma once
#include <string>

class Player
{
	std::string name;
	std::string description;
	int health;
	int attack;
	std::string weapon;
	std::string armour;
	std::string inventory[];
};


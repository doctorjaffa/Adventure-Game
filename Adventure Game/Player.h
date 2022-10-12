#pragma once
#include <string>
#include <vector>
#include "Area.h"

class Player
{
public:

	//Constructors/Destructors.
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour);
	~Player();

	//Class functions.
	void Go(Area newArea);

	//Class variables.
	std::string name;
	std::string description;
	int health;
	int attack;
	std::string weapon;
	std::string armour;
	std::vector<std::string> inventory;

	Area currentArea;
};


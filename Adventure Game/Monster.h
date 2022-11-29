#pragma once
#include <string>

class Monster
{
public:

	//Constructors/Destructors.
	Monster();
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);

	~Monster();

	//Getters/Setters.
	//int GetAttack();
	//void SetHealth();

private:

	//Private variables.
	std::string name;
	std::string description;
	int health;
	int attack;
};


#pragma once
#include <string>

class Area;

class Monster
{
public:

	//Constructors/Destructors.
	Monster();
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);

	~Monster();
	
	//Class functions.
	void PrintStats();

	//Getters/Setters.
	std::string GetName();
	int GetAttack();
	int GetHealth();
	void DecreaseHealth(int playerAttack);

	bool isDead;

private:

	//Private variables.
	std::string name;
	std::string description;
	int health;
	int attack;

};


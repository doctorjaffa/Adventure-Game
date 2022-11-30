#pragma once
#include <string>
#include <vector>

class Area;

class Player
{
public:

	//Constructors/Destructors.
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour, Area* currentArea);
	~Player();

	//Class functions.

	//Getters/Setters.
	Area* GetCurrentArea();
	void SetCurrentArea(Area* newArea);

	void DealDamage(std::string monsterName);


private:

	//Class variables.
	std::string name;
	std::string description;
	int health;
	int attack;
	std::string weapon;
	std::string armour;
	std::vector<std::string> inventory;

	Area* currentArea;
};


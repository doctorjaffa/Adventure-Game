#pragma once
#include <string>
#include <vector>
#include "Creature.h"
#include "Item.h"
#include "Potion.h"

class Area;

class Player : public Creature
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

	//Public functions.
	void DealDamage(std::string monsterName);
	void AddItem(Item* targetItem);
	void PrintInventory();


private:

	//Class variables.
	std::string weapon;
	std::string armour;
	std::vector<Item*> inventory;

	Area* currentArea;
};


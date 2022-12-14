#pragma once
#include <string>
#include <vector>
#include "Thing.h"
#include "Item.h"

class Player;
class Monster;

class Area : public Thing
{
public:

	//Constructors/Destructors.
	Area();
	Area(std::string newName, std::string newDescription);
	~Area();

	//Class functions.
	void Look();
	void Go(Player* player, std::string userArea);
	void Grab(Player* player, std::string targetItem);
	void UpdateMonsters();
	void UpdateItems();
	void AddMonster(Monster* newMonster);

	//Getters/Setters.
	Monster* GetMonster(std::string targetMonster);
	Item* GetItem(std::string targetItem);

	void SetExits(Area* newExit);
	void SetItems(Item* newItem);


private:

	//Class variables.
	std::vector<Area*> exits;
	std::vector<Monster*> monsters;
	std::vector<Item*> items;
};


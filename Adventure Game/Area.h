#pragma once
#include <string>
#include <vector>
#include "Thing.h"

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
	void UpdateMonsters();

	//Getters/Setters.
	void SetExits(Area* newExit);
	void AddMonster(Monster* newMonster);
	Monster* GetMonster(std::string targetMonster);


private:

	//Class variables.
	std::vector<Area*> exits;
	std::vector<Monster*> monsters;
};


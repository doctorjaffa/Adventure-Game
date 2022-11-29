#pragma once
#include <string>
#include <vector>

class Player;
//class Monster;

class Area
{
public:

	//Constructors/Destructors.
	Area();
	Area(std::string newName, std::string newDescription, std::string newContents/*, Monster* newMonster*/);
	~Area();

	//Class functions.
	void Look();
	void Go(Player* player, std::string userArea);

	//Getters/Setters.
	void SetExits(Area* newExit);
	//Monster GetMonster();


private:

	//Class variables.
	std::string name;
	std::string description;
	std::string contents;
	std::vector<Area*> exits;
};


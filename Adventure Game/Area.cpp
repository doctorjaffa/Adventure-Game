#include "Area.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <vector>

//Default constructor.
Area::Area()
	: name("")
	, description("")
	, exits()
{
}

//Data populated constructor.
Area::Area(std::string newName, std::string newDescription)
	: name(newName)
	, description(newDescription)
{
}

//Default destructor.
Area::~Area()
{
	//std::cout << "\nArea has been destroyed!";
}

//Print the description of the current area and a list of each area available from the current one.
void Area::Look()
{
	std::cout << "\n" << description;

	std::cout << "\nExits:\n";

	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i]->name << "\n";
	}

	std::cout << "\n\n";

	std::cout << "Monsters in Area:\n";

	for (int i = 0; i < monsters.size(); ++i)
	{
		monsters[i]->PrintStats();
	}
}

void Area::Go(Player* player, std::string userArea)
{
		//Loop through the exits available from the current area.
		for (int i = 0; i < exits.size(); ++i)
		{
			//If the user-inputted area matches one of the exit names, pass that exit into the Go() function.
			if (exits[i]->name == userArea)
			{
				player->SetCurrentArea(exits[i]);
				std::cout << "\nNew Area: " << player->GetCurrentArea()->name << "\n";
				std::cout << player->GetCurrentArea()->description << "\n";
			}
		}
}

void Area::UpdateMonsters()
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (monsters[i]->isDead)
		{
			monsters.erase(monsters.begin() + i);
			//monsters.erase(std::remove_if(monsters.begin(), monsters.end(), monsters[i]->isDead), monsters.end());
			std::cout << "\nMonster has died!\n";
		}
	}
}

void Area::SetExits(Area* newExit)
{
	exits.push_back(newExit);
}

void Area::AddMonster(Monster* newMonster)
{
	monsters.push_back(newMonster);
}


Monster* Area::GetMonster(std::string targetMonster)
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (monsters[i]->GetName() == targetMonster)
		{
			return monsters[i];
		}
	}
}



#include "Area.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <vector>

//Default constructor.
Area::Area()
	: Thing()
	, exits()
{
}

//Data populated constructor.
Area::Area(std::string newName, std::string newDescription)
	: Thing(newName, newDescription)
{
}

//Default destructor.
Area::~Area()
{
	//std::cout << "\nArea has been destroyed!";
}

//Print the description of the current area.
void Area::Look()
{
	std::cout << "\n" << description;

	std::cout << "\nExits:\n";

	//Print the names of available exits from the current area.
	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i]->GetName() << "\n";
	}

	std::cout << "\n\n";

	//Print any monsters available within the current area.
	std::cout << "Monsters in Area:";

	for (int i = 0; i < monsters.size(); ++i)
	{
		std::cout << "\n" << monsters[i]->GetName();
	}

	std::cout << "\n\n";

	//Print any items available within the current area.
	std::cout << "Items in Area:";

	for (int i = 0; i < items.size(); ++i)
	{
		std::cout << "\n" << items[i]->GetName();
	}
}

void Area::Go(Player* player, std::string userArea)
{
		//Loop through the exits available from the current area.
		for (int i = 0; i < exits.size(); ++i)
		{
			//If the user-inputted area matches one of the exit names, set the current area to the new one.
			if (exits[i]->GetName() == userArea)
			{
				player->SetCurrentArea(exits[i]);

				//Print the name and description of the new area.
				std::cout << "\nNew Area: " << player->GetCurrentArea()->GetName() << "\n";
				std::cout << player->GetCurrentArea()->GetDescription() << "\n";
			}
		}
}

void Area::Grab(Player* player, std::string targetItem)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->GetName() == targetItem)
		{
			player->AddItem(items[i]);
			items.erase(items.begin() + i);
			std::cout << "\nYou have collected: " << items[i]->GetName();
		}
	}
}

//If a monster dies, remove it from the list of available monsters in that area.
void Area::UpdateMonsters()
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (monsters[i]->GetStatus())
		{
			monsters.erase(monsters.begin() + i);
			std::cout << "\nMonster has died!\n";
		}
	}
}


void Area::SetExits(Area* newExit)
{
	exits.push_back(newExit);
}

void Area::SetItems(Item* newItem)
{
	items.push_back(newItem);
}

void Area::AddMonster(Monster* newMonster)
{
	monsters.push_back(newMonster);
}


//Retrieve a monster from a vector of monsters, if the user-inputted name matches one in the vector.
Monster* Area::GetMonster(std::string targetMonster)
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (monsters[i]->GetName() == targetMonster)
		{
			return monsters[i];
		}
		else
		{
			std::cout << "\nThere are no monsters by that name.";
		}
	}
}

Item* Area::GetItem(std::string targetItem)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->GetName() == targetItem)
		{
			Item* toReturn = items[i];

			items.erase(items.begin() + i);
			return toReturn;
		}
	}
}



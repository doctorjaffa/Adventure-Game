#include "Area.h"
#include "Player.h"
#include <iostream>
#include <vector>

//Default constructor.
Area::Area()
	: name("")
	, description("")
	, contents("")
	, exits()
{
}

//Data populated constructor.
Area::Area(std::string newName, std::string newDescription, std::string newContents/*Monster newMonster*/)
	: name(newName)
	, description(newDescription)
	, contents(newContents)
	//, exits()
	//monster(newMonster)
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

void Area::SetExits(Area* newExit)
{
	exits.push_back(newExit);
}

/*
Monster Area::GetMonster()
{
	return Monster;
}
*/

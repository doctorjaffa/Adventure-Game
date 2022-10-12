#include "Area.h"
#include <iostream>

//Default constructor.
Area::Area()
	: name("")
	, description("")
	, contents("")
	, exits()
{
}

//Data populated constructor.
Area::Area(std::string newName, std::string newDescription, std::string newContents)
	: name(newName)
	, description(newDescription)
	, contents(newContents)
	, exits()
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

	std::cout << std::endl << "\nExits:" << std::endl;

	for (int i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i].name << std::endl;
	}
}

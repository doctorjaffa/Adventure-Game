#include "Item.h"
#include <iostream>

Item::Item()
	: Thing()
{
}

Item::Item(std::string newName, std::string newDescription)
	: Thing(newName, newDescription)
{
}

Item::~Item()
{
}

void Item::Use()
{
	std::string userIn = "";
	std::cout << "\nUse what? ";
	std::cin >> userIn;
}

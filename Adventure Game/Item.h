#pragma once
#include <string>
#include "Thing.h"

class Item : public Thing
{
	
	//Constructors/Destructors.
	Item();
	Item(std::string newName, std::string newDescription);

	~Item();
};


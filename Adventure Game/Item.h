#pragma once
#include <string>
#include "Thing.h"

class Item : public Thing
{
public:

	//Constructors/Destructors.
	Item();
	Item(std::string newName, std::string newDescription);

	virtual ~Item();
};
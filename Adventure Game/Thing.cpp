#include "Thing.h"
#include <iostream>

//Default constructor.
Thing::Thing()
	: name("")
	, description("")
{
}

//Data populated constructor.
Thing::Thing(std::string newName, std::string newDescription)
	: name(newName)
	, description(newDescription)
{
}

//Default destructor.
Thing::~Thing()
{
}

std::string Thing::GetName()
{
	return name;
}

std::string Thing::GetDescription()
{
	return description;
}

void Thing::Look()
{
	std::cout << "\nName: " << name;
	std::cout << "\nDescription: " << description;
}

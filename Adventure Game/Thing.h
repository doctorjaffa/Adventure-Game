#pragma once
#include <string>

class Thing
{
public:

	//Constructors/Destructors.
	Thing();
	Thing(std::string newName, std::string newDescription);

	~Thing();

	//Getters/Setters.
	std::string GetName();
	std::string GetDescription();

	//Public functions.
	void Look();

protected:

	//Protected variables.
	std::string name;
	std::string description;
};


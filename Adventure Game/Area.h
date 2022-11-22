#pragma once
#include <string>
#include <vector>

class Area
{
public:

	//Constructors/Destructors.
	Area();
	Area(std::string newName, std::string newDescription, std::string newContents);
	~Area();

	//Class functions.
	void Look();

	//Class variables.
	std::string name;
	std::string description;
	std::string contents;
	std::vector<Area*> exits;
};


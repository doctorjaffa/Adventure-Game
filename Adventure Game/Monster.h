#pragma once
#include <string>
#include "Creature.h"

class Area;

class Monster : public Creature
{
public:

	//Constructors/Destructors.
	Monster();
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);

	~Monster();

};


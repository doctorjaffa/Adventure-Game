#include "Monster.h"
#include "Area.h"
#include <iostream>

//Default constructor.
Monster::Monster()
	: Creature()
{
}

//Data populated constructor.
Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Creature(newName, newDescription, newHealth, newAttack)
{
}

//Default destructor.
Monster::~Monster()
{
}




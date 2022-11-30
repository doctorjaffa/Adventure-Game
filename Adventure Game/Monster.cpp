#include "Monster.h"
#include "Area.h"
#include <iostream>

Monster::Monster()
	: name("")
	, description("")
	, health(0)
	, attack(0)
	, isDead(false)
{
}

Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack /*Area* newArea*/)
	: name(newName)
	, description(newDescription)
	, health(newHealth)
	, attack(newAttack)
	, isDead(false)
{
}

Monster::~Monster()
{
}

void Monster::PrintStats()
{
	std::cout << "\nName: " << name;
	std::cout << "\nDescription: " << description;
	std::cout << "\nHealth: " << health;
	std::cout << "\nAttack: " << attack << "\n";
}

std::string Monster::GetName()
{
	return name;
}


int Monster::GetAttack()
{
	return attack;
}

int Monster::GetHealth()
{
	return health;
}

void Monster::DecreaseHealth(int playerAttack)
{
	health -= playerAttack;

	if (health < 1)
	{
		isDead = true;
	}

}


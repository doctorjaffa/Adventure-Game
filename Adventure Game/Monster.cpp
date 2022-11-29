#include "Monster.h"

Monster::Monster()
	: name("")
	, description("")
	, health(0)
	, attack(0)
{
}

Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: name(newName)
	, description(newDescription)
	, health(newHealth)
	, attack(newAttack)
{
}

Monster::~Monster()
{
}

/*
int Monster::GetAttack()
{
	return attack;
}

void Monster::SetHealth(int playerAttack)
{
	health -= playerAttack;

	if (health < 1)
	{
		~Monster();
	}

}
*/

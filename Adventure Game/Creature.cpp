#include "Creature.h"
#include <iostream>

//Default constructor.
Creature::Creature()
	: Thing()
	, health(0)
	, attack(0)
	, isDead(false)
{
}

Creature::Creature(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Thing(newName, newDescription)
	, health(newHealth)
	, attack(newAttack)
	, isDead(false)
{
}

Creature::~Creature()
{
}

int Creature::GetHealth()
{
	return health;
}

int Creature::GetAttack()
{
	return attack;
}

bool Creature::GetStatus()
{
	return isDead;
}

//Decrement the monster's health by the player's attack.
void Creature::DecreaseHealth(int damage)
{
	health -= damage;

	//If the monster's health drops to 0, kill it.
	if (GetHealth() < 1)
	{
		isDead = true;
	}

}

void Creature::Look()
{
	//Print creature details to console.
		std::cout << "\nName: " << name;
		std::cout << "\nDescription: " << description;
		std::cout << "\nHealth: " << health;
		std::cout << "\nAttack: " << attack << "\n";
}

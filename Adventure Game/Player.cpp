#include "Player.h"
#include "Area.h"
#include "Monster.h"
#include <iostream>

//Default constructor.
Player::Player()
	: Creature()
	, weapon("")
	, armour("")
	, inventory()
	, currentArea(nullptr)
{
}

//Data populated constructor.
Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour, Area* newArea)
	: Creature(newName, newDescription, newHealth, newAttack)
	, weapon(newWeapon)
	, armour(newArmour)
	, inventory()
	, currentArea(newArea)
{
}

//Default destructor.
Player::~Player()
{
	
	if (currentArea != nullptr)
	{
		delete currentArea;
		currentArea = nullptr;
	}
	//std::cout << "\nPlayer has been destroyed!"
}

Area* Player::GetCurrentArea()
{
	return currentArea;
}

void Player::SetCurrentArea(Area* newArea)
{
	currentArea = newArea;
}

void Player::DealDamage(std::string monsterName)
{
	Monster* currentMonster = currentArea->GetMonster(monsterName);

	while (GetHealth() > 0 && currentMonster->GetHealth() > 0)
	{

		currentMonster->DecreaseHealth(attack);

		DecreaseHealth(currentMonster->GetAttack());

		if (health < 1)
		{
			std::cout << "\nGame is Over. You lose.\n";
			//QUIT GAME LOOP.
		}

		currentArea->UpdateMonsters();

		if (currentMonster->GetStatus())
		{
			std::cout << "\nPlayer health: " << health;
			std::cout << "\nMonster health:" << currentMonster->GetHealth();
		}
	}
}



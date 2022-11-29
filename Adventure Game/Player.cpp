#include "Player.h"
#include "Area.h"
#include <iostream>

//Default constructor.
Player::Player()
	: name("")
	, description("")
	, health(0)
	, attack(0)
	, weapon("")
	, armour("")
	, inventory()
	, currentArea(nullptr)
{
}

//Data populated constructor.
Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour, Area* newArea)
	: name(newName)
	, description(newDescription)
	, health(newHealth)
	, attack(newAttack)
	, weapon(newWeapon)
	, armour(newArmour)
	, inventory()
	, currentArea(newArea)
{
}

//Default destructor.
Player::~Player()
{
	/*
	if (currentArea != nullptr)
	{
		delete currentArea;
		currentArea = nullptr;
	}
	*/
	//std::cout << "\nPlayer has been destroyed!"
}

Area* Player::GetCurrentArea()
{
	return currentArea;
}

/*Update the current area to the new area the player enters, if that area is available.
void Player::Go(Area* newArea)
{
	currentArea = newArea;
}
*/


void Player::SetCurrentArea(Area* newArea)
{
	currentArea = newArea;
}

/*
void Player::DealDamage()
{
	Monster& currentMonster = currentArea->GetMonster();

	currentMonster.SetHealth(attack);

	health -= currentMonster.GetAttack();

	if (health < 1)
	{
		std::cout << "\nGame is Over. You lose.\n";
		//QUIT GAME LOOP.
	}
}
*/


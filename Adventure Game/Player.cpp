#include "Player.h"
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
{
}

//Data populated constructor.
Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour)
	: name(newName)
	, description(newDescription)
	, health(newHealth)
	, attack(newAttack)
	, weapon(newWeapon)
	, armour(newArmour)
	, inventory()
{
}

//Default destructor.
Player::~Player()
{
	//std::cout << "\nPlayer has been destroyed!"
}

//Update the current area to the new area the player enters, if that area is available.
void Player::Go(Area newArea)
{
	currentArea = newArea;
}

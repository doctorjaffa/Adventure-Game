#pragma once
#include "Thing.h"
#include <string>

class Creature : public Thing
{
public:

	//Constructors/Destructors.
	Creature();
	Creature(std::string newName, std::string newDescription, int newHealth, int newAttack);

	~Creature();

	//Getters/Setters.
	int GetHealth();
	int GetAttack();
	bool GetStatus();
	
	//Public functions.
	void DecreaseHealth(int damage);
	void Look();

protected:

	//Protected variables.
	int health;
	int attack;

	bool isDead;
};


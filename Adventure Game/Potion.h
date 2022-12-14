#pragma once
#include <string>
#include "Item.h"
#include "Thing.h"

class Potion : public Item
{
public:

	//Constructors/Destructors.
	Potion();
	Potion(std::string newName, std::string newDescription, int newHealthChangeAmount);

	~Potion();

	//Getters/Setters.
	int GetPotionStrength();

protected:

	int healthChangeAmount;
};


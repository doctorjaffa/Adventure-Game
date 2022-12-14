#include "Potion.h"

Potion::Potion()
	: Item()
	, healthChangeAmount(0)
{
}

Potion::Potion(std::string newName, std::string newDescription, int newHealthChangeAmount)
	: Item(newName, newDescription)
	, healthChangeAmount(newHealthChangeAmount)
{
}

Potion::~Potion()
{
}

int Potion::GetPotionStrength()
{
	return healthChangeAmount;
}

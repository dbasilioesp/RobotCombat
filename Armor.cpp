#include "Armor.h"


Armor::Armor(void)
{
	type = "Armor";
}


Armor::~Armor(void)
{
}


void Armor::setDefense(int _defense)
{
	defense = _defense;
}

int Armor::getDefense()
{
	return defense;
}

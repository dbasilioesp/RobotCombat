#include "Weapon.h"


Weapon::Weapon(void)
{
	type = "Weapon";
	attack = 1;
	damage = 1;
	range = 1;
}


Weapon::~Weapon(void)
{
}


int Weapon::getAttack()
{
	return attack;
}


int Weapon::getDamage()
{
	return damage;
}


int Weapon::getRange()
{
	return range;
}

void Weapon::setAttack(int _attack)
{
	attack = _attack;
}


void Weapon::setDamage(int _damage)
{
	damage = _damage;
}


void Weapon::setRange(int _range)
{
	range = _range;
}

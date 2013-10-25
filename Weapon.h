#pragma once
#include <fstream>
#include "Item.h"


class Weapon : public Item
{
public:
	Weapon(void);
	~Weapon(void);

	int getAttack();
	int getDamage();
	int getRange();

	void setAttack(int attack);
	void setDamage(int damage);
	void setRange(int range);

protected:
	int attack;
	int damage;
	int range;
};


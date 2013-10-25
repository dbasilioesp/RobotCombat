#pragma once
#include "item.h"

class Armor :
	public Item
{
public:
	Armor(void);
	~Armor(void);

	void setDefense(int defense);
	int getDefense();
	
protected:
	int defense;

};


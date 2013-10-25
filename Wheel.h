#pragma once
#include "item.h"
class Wheel :
	public Item
{
public:
	Wheel(void);
	~Wheel(void);

	void setMovement(int movement);
	int getMovement();

protected:

	int movement;

};


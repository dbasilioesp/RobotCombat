#include "Wheel.h"


Wheel::Wheel(void)
{
	type = "Wheel";
}


Wheel::~Wheel(void)
{
}


void Wheel::setMovement(int _movement)
{
	movement = _movement;
}


int Wheel::getMovement()
{
	return movement;
}
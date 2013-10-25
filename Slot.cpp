#include "Slot.h"


Slot::Slot(void)
{
	id = 0;
}


Slot::~Slot(void)
{
}


void Slot::setId(int _id)
{
	id = _id;
}


int Slot::getId()
{
	return id;
}


void Slot::setPlayer(Player _player)
{
	player = _player;
}


Player * Slot::getPlayer()
{
	return &player;
}
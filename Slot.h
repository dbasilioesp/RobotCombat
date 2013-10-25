#include <fstream>
#include "Player.h"

#ifndef SLOT_H
#define SLOT_H

class Slot
{
public:
	Slot(void);
	~Slot(void);

	void setId(int id);
	void setPlayer(Player player);

	Player * getPlayer();
	int getId();

protected:

	int id;
	Player player;
};

#endif
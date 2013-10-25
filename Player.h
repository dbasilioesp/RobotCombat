#pragma once
#include "Robot.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player(void);
	~Player(void);

	void setMoney(int money);
	void setLevel(int level);
	void setWins(int wins);
	void setLoses(int loses);
	void setRobot(Robot robot);

	int getMoney();
	int getLevel();
	int getWins();
	int getLoses();
	Robot * getRobot();

protected:

	int money;
	int level;
	int wins;
	int loses;

	Robot robot;
};

#endif
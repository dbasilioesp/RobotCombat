#include "Player.h"


Player::Player(void)
{
	money = 0;
	level = 1;
	wins = 0;
	loses = 0;
}


Player::~Player(void)
{
}


void Player::setMoney(int _money)
{
	money = _money;
}


void Player::setLevel(int _level)
{
	level = _level;
}


void Player::setWins(int _wins)
{
	wins = wins;
}


void Player::setLoses(int _loses)
{
	loses = _loses;
}


void Player::setRobot(Robot _robot)
{
	robot = _robot;
}


int Player::getMoney()
{
	return money;
}


int Player::getLevel()
{
	return level;
}


int Player::getWins()
{
	return wins;
}


int Player::getLoses()
{
	return loses;
}


Robot * Player::getRobot()
{
	return &robot;
}

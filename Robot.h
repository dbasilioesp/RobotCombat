#pragma once
#include <vector>
#include "Inventory.h"
#include "Sprite.h"
#include "Matriz.h"

#ifndef ROBOT_H
#define ROBOT_H

class Robot : public Sprite
{
public:
	Robot(void);
	~Robot(void);

	void setId(int id);
	int getId();

	void setName(string name);
	void setHealth(int health_points);
	
	string getName();
	int getAttack();
	int getDamage();
	int getRange();
	int getDefense();
	int getMovement();
	int getHealth();
	
	void setMoveMatriz(Matriz * matriz, int *size, int line, int column, int max_lines, int max_columns);
	void setAttackMatriz(Matriz * matriz, int *size, int line, int column, int max_lines, int max_columns);

	void setWeapon(Weapon weapon);
	void setArmor(Armor armor);
	void setWheel(Wheel wheel);

	Weapon getWeapon();
	Armor getArmor();
	Wheel getWheel();

protected:
	
	Weapon weapon;
	Armor armor;
	Wheel wheel;

	int id;
	int health_points;
	string name;
	int defense;
	int attack;
	int damage;
	int attack_range;
	int movement;
};

#endif
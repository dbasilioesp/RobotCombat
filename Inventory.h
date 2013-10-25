#pragma once
#include <vector>
#include "Weapon.h"
#include "Armor.h"
#include "Wheel.h"

class Inventory
{
public:
	Inventory(void);
	~Inventory(void);

	void setWeapons(vector<Weapon> weapons);
	void setArmors(vector<Armor> armors);
	void setWheels(vector<Wheel> wheel);

	void addWeapon(Weapon weapon);
	void addArmor(Armor armor);
	void addWheel(Wheel wheel);

	vector<Weapon> getWeapons();
	vector<Armor> getArmors();
	vector<Wheel> getWheels();

	Weapon findWeaponById(int id);
	Armor findArmorById(int id);
	Wheel findWheelById(int id);

	void saveInFileText(ofstream *file);
	//void loadFromFileText(ifstream *file, vector<Weapon>, vector<Armor>, vector<Wheel>);
protected:

	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Wheel> wheels;
};

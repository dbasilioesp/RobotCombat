#pragma once
#include <vector>
#include "Weapon.h"
#include "Inventory.h"
#include "Robot.h"

class ItemsLoader
{
public:
	ItemsLoader(void);
	~ItemsLoader(void);

	void load();
	
	vector<Weapon> getWeapons();
	vector<Armor> getArmors();
	vector<Wheel> getWheels();
	Inventory getInventory();

protected:

	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Wheel> wheels;

	void loadWeaponsFromText();
	void loadArmorsFromText();
	void loadWheelsFromText();
};


#pragma once
#include <vector>
#include "Inventory.h"
#include "Slot.h"

#ifndef FILE_LOADER_H
#define FILE_LOADER_H

class FileLoader
{
public:
	FileLoader(void);
	~FileLoader(void);

	void load();
	
	Inventory getInventory();

	vector<Slot> getSlots();

	void loadSlots();
	void saveSlots(vector<Slot> * slots);

	vector<Weapon> getWeapons();
	vector<Armor> getArmors();
	vector<Wheel> getWheels();
	vector<Robot> getRobots();
	void setRobotPlayer(int index, Player * player);

protected:

	int token_int;
	string token_str;

	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Wheel> wheels;
	vector<Robot> robots;
	vector<Slot> slots;

	Inventory inventory;

	void loadItem(ifstream * file, Item * item);
	void loadWeapon(ifstream * file, Weapon * weapon);
	void loadArmor(ifstream * file, Armor * armor);
	void loadWheel(ifstream * file, Wheel * wheel);
	void loadRobot(ifstream *file, Robot * robot);
	void loadPlayer(ifstream *file, Player * player);
	void loadSlot(ifstream *file, Slot * slot);

	void loadWeaponsFromText();
	void loadArmorsFromText();
	void loadWheelsFromText();
	void loadRobotsFromText();

	void saveSprite(ofstream *file, Sprite * sprite);
	void saveRobot(ofstream *file, Robot * robot);
	void savePlayer(ofstream *file, Player * player);
};

#endif

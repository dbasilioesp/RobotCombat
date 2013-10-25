#include "ItemsLoader.h"


ItemsLoader::ItemsLoader(void)
{
}


ItemsLoader::~ItemsLoader(void)
{
}


void ItemsLoader::load()
{
	loadWeaponsFromText();
	loadArmorsFromText();
	loadWheelsFromText();
}


vector<Weapon> ItemsLoader::getWeapons()
{
	return weapons;
}


vector<Armor> ItemsLoader::getArmors()
{
	return armors;
}


vector<Wheel> ItemsLoader::getWheels()
{
	return wheels;
}

void ItemsLoader::loadWeaponsFromText()
{
	ifstream file("weapons.txt");
	
	if(!file){
		cout << "File not found!" << endl;
	}else{

		while(!file.eof())
		{
			Weapon weapon;
			weapon.loadFromFileText(&file);
			weapons.push_back(weapon);
		}

		file.close();
	}
}


void ItemsLoader::loadArmorsFromText()
{
	ifstream file("armors.txt");
	Armor *armor;

	if(!file){
		cout << "File not found!" << endl;
	}else{

		while(!file.eof())
		{
			armor = new Armor();
			armor->loadFromFileText(&file);
			armors.push_back(*armor);
		}

		file.close();
	}
}


void ItemsLoader::loadWheelsFromText()
{
	ifstream file("wheels.txt");
	Wheel *wheel;

	if(!file){
		cout << "File not found!" << endl;
	}else{

		while(!file.eof())
		{
			wheel = new Wheel();
			wheel->loadFromFileText(&file);
			wheels.push_back(*wheel);
		}

		file.close();
	}
}


Inventory ItemsLoader::getInventory()
{
	Inventory inventory;

	inventory.setWeapons(weapons);
	inventory.setArmors(armors);
	inventory.setWheels(wheels);

	return inventory;
}
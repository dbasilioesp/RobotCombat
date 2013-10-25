#include "Inventory.h"


Inventory::Inventory(void)
{
}


Inventory::~Inventory(void)
{
}


Weapon Inventory::findWeaponById(int id)
{
	for(unsigned int i = 0; i < weapons.size(); i++){
		if(weapons[i].getId() == id){
			return weapons[i];
		}
	}
}


Armor Inventory::findArmorById(int id)
{
	for(unsigned int i = 0; i < armors.size(); i++){
		if(armors[i].getId() == id){
			return armors[i];
		}
	}
}


Wheel Inventory::findWheelById(int id)
{
	for(unsigned int i = 0; i < wheels.size(); i++){
		if(wheels[i].getId() == id){
			return wheels[i];
		}
	}
}


void Inventory::addWeapon(Weapon _weapon)
{
	weapons.push_back(_weapon);
}


void Inventory::addArmor(Armor _armor)
{
	armors.push_back(_armor);
}


void Inventory::addWheel(Wheel wheel)
{
	wheels.push_back(wheel);
}


vector<Weapon> Inventory::getWeapons()
{
	return weapons;
}


vector<Armor> Inventory::getArmors()
{
	return armors;
}


vector<Wheel> Inventory::getWheels()
{
	return wheels;
}


void Inventory::setWeapons(vector<Weapon> _weapons)
{
	weapons = _weapons;
}


void Inventory::setWheels(vector<Wheel> _wheels)
{
	wheels = _wheels;
}


void Inventory::setArmors(vector<Armor> _armors)
{
	armors = _armors;
}


void Inventory::saveInFileText(ofstream *file)
{
	// WEAPONS
	*file << weapons.size() << " ";
	for(unsigned int i = 0; i < weapons.size(); i++)
	{
		*file << weapons[i].getId();
		if(i < weapons.size() - 1){
			*file << " ";
		}
	}

	// ARMORS
	*file << endl;
	*file << armors.size() << " ";
	for(unsigned int i = 0; i < armors.size(); i++)
	{
		*file << armors[i].getId();
		if(i < armors.size() - 1){
			*file << " ";
		}
	}
	
	// WHEELS
	*file << endl;
	*file << wheels.size() << " ";
	for(unsigned int i = 0; i < wheels.size(); i++)
	{
		*file << wheels[i].getId();
		if(i < wheels.size() - 1){
			*file << " ";
		}
	}
}
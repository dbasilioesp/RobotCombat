#include "RobotsLoader.h"


RobotsLoader::RobotsLoader(Inventory * _all_items)
{
	all_items = _all_items;
}


RobotsLoader::~RobotsLoader(void)
{
}


vector<Robot> RobotsLoader::getRobots()
{
	return robots;
}


void RobotsLoader::loadRobotsFromText()
{
	ifstream file(".\\data\\robots.txt");
	Robot * robot;
	int size = 0;
	int id = 0;

	if(!file){
		cout << "File not found!" << endl;
		egl_depurar("File not found!", 0);
	}else{

		while(!file.eof())
		{
			robot = new Robot();
			robot->loadFromFileText(&file);
			
			file >> size;
			for(int i = 0; i < size; i++)
			{
				file >> id;
				Weapon weapon = all_items->findWeaponById(id);
				robot->addWeapon(weapon);
			}

			file >> size;
			for(int i = 0; i < size; i++)
			{
				file >> id;
				Armor armor = all_items->findArmorById(id);
				robot->addArmor(armor);
			}

			file >> size;
			for(int i = 0; i < size; i++)
			{
				file >> id;
				Wheel wheel = all_items->findWheelById(id);
				robot->addWheel(wheel);
			}

			robots.push_back(*robot);
		}

		file.close();
	}
}
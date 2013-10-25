#include "FileLoader.h"


FileLoader::FileLoader(void)
{
	token_int = 0;
	token_str = "";
}

FileLoader::~FileLoader(void)
{
}

void FileLoader::load()
{
	loadWeaponsFromText();
	loadArmorsFromText();
	loadWheelsFromText();

	inventory.setWeapons(weapons);
	inventory.setArmors(armors);
	inventory.setWheels(wheels);

	loadRobotsFromText();
}

void FileLoader::loadItem(ifstream * file, Item * item)
{
	*file >> token_int;
	item->setId(token_int);

	*file >> token_str;
	item->setName(token_str);

	*file >> token_int;
	item->setValue(token_int);
}

void FileLoader::loadWeapon(ifstream * file, Weapon * weapon)
{
	loadItem(file, weapon);

	*file >> token_int;
	weapon->setAttack(token_int);
	
	*file >> token_int;
	weapon->setDamage(token_int);
	
	*file >> token_int;
	weapon->setRange(token_int);
}

void FileLoader::loadArmor(ifstream * file, Armor * armor)
{
	loadItem(file, armor);

	*file >> token_int;
	armor->setDefense(token_int);
}

void FileLoader::loadWheel(ifstream * file, Wheel * wheel)
{
	loadItem(file, wheel);

	*file >> token_int;
	wheel->setMovement(token_int);
}

void FileLoader::loadRobot(ifstream *file, Robot * robot)
{
	*file >> token_int;
	robot->setId(token_int);

	*file >> token_str;
	robot->setName(token_str);

	*file >> token_int;
	Weapon * weapon = &inventory.findWeaponById(token_int);
	robot->setWeapon(*weapon);

	*file >> token_int;
	Armor * armor = &inventory.findArmorById(token_int);
	robot->setArmor(*armor);
			
	*file >> token_int;
	Wheel * wheel = &inventory.findWheelById(token_int);
	robot->setWheel(*wheel);
	
	int size = 0, size2 = 0;
	string sprite_name;

	*file >> size;
	
	robot->setSpritesSize(size);

	for(int i = 0; i < size; i++){
		
		*file >> size2;

		for(int j = 0; j < size2; j++){
			*file >> sprite_name;
			robot->addSprite(i, sprite_name);
		}

	}
}

void FileLoader::loadPlayer(ifstream *file, Player * player)
{
	*file >> token_int;
	player->setLevel(token_int);

	*file >> token_int;
	player->setMoney(token_int);
	
	*file >> token_int;
	player->setWins(token_int);

	*file >> token_int;
	player->setLoses(token_int);

	Robot robot;
	loadRobot(file, &robot);
	player->setRobot(robot);
}

void FileLoader::loadSlot(ifstream *file, Slot * slot)
{
	*file >> token_int;
	slot->setId(token_int);

	Player * player = new Player;
	loadPlayer(file, player);
	slot->setPlayer(*player);
}

void FileLoader::saveRobot(ofstream *file, Robot * robot)
{
	*file << robot->getId() << " ";
	*file << robot->getName() << " ";
	*file << robot->getWeapon().getId() << " ";
	*file << robot->getArmor().getId() << " ";
	*file << robot->getWheel().getId() << endl;
	
	saveSprite(file, robot);
}

void FileLoader::saveSprite(ofstream *file, Sprite * sprite)
{
	/*	Format
		1
		1 robot-01-1.png
	*/

	vector<string> sprites_names = sprite->getSpritesNames();

	int size, size2;

	size = sprites_names.size();
	*file << size << endl;

	for(int i = 0; i < size; i++){
		*file << i+1 << " ";
		*file << sprites_names.at(i);
		if(i < size-1){
			*file << " ";
		}
	}
}

void FileLoader::savePlayer(ofstream *file, Player * player)
{
	*file << player->getLevel() << " ";
	*file << player->getMoney() << " ";
	*file << player->getWins() << " ";
	*file << player->getLoses() << endl;

	saveRobot(file, player->getRobot());
}

vector<Weapon> FileLoader::getWeapons()
{
	return weapons;
}

vector<Armor> FileLoader::getArmors()
{
	return armors;
}

vector<Wheel> FileLoader::getWheels()
{
	return wheels;
}

vector<Slot> FileLoader::getSlots()
{
	return slots;
}

vector<Robot> FileLoader::getRobots()
{
	return robots;
}

void FileLoader::setRobotPlayer(int index, Player * player)
{
	player->setRobot(robots[index]);
}

void FileLoader::loadWeaponsFromText()
{
	ifstream file(".\\data\\weapons.txt");
	
	if(!file){
		cout << "File not found!" << endl;
		egl_depurar("File not found!", 0);
	}else{

		while(!file.eof())
		{
			Weapon weapon;
			loadWeapon(&file, &weapon);
			weapons.push_back(weapon);
		}

		file.close();
	}
}

void FileLoader::loadArmorsFromText()
{
	ifstream file(".\\data\\armors.txt");
	
	if(!file){
		cout << "File not found!" << endl;
		egl_depurar("File not found!", 0);
	}else{

		while(!file.eof())
		{
			Armor armor;
			loadArmor(&file, &armor);
			armors.push_back(armor);
		}

		file.close();
	}
}

void FileLoader::loadWheelsFromText()
{
	ifstream file(".\\data\\wheels.txt");
	
	if(!file){
		cout << "File not found!" << endl;
		egl_depurar("File not found!", 0);
	}else{

		while(!file.eof())
		{
			Wheel wheel;
			loadWheel(&file, &wheel);
			wheels.push_back(wheel);
		}

		file.close();
	}
}

void FileLoader::loadRobotsFromText()
{
	
	ifstream file(".\\data\\robots.txt");
	
	if(!file){
		cout << "File not found!" << endl;
		egl_depurar("File not found!", 0);
	}else{

		while(!file.eof())
		{
			Robot robot;
			loadRobot(&file, &robot);
			robots.push_back(robot);
		}

		file.close();
	}
}

void FileLoader::loadSlots()
{
	ifstream file(".\\data\\slots.txt");
	
	if(!file){
		cout << "File slots.txt not found!" << endl;
		egl_depurar("File slots.txt not found!", 0);
	}else{

		int token;
		file >> token;

		if(token > 0){

			while(!file.eof())
			{
				Slot slot;
				loadSlot(&file, &slot);
				slots.push_back(slot);
			}
		}

		file.close();
	}
}

void FileLoader::saveSlots(vector<Slot> * slots)
{
	ofstream file(".\\data\\slots.txt");
	Slot * slot;
	
	if(!file){
		cout << "File slots.txt not found!" << endl;
		egl_depurar("File slots.txt not found!", 0);
	}else{

		int size = slots->size();

		file << size;

		if(size > 0){
			file << endl;
		}

		for(int i = 0; i < size; i++)
		{
			file << (i+1) << " ";
			slot = &slots->at(i);
			savePlayer(&file, slot->getPlayer());

			if(i < size-1){
				file << " ";
			}

		}
		
		file.close();
	}
}


Inventory FileLoader::getInventory()
{
	return inventory;
}

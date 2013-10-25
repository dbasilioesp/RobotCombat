#pragma once
#include <vector>
#include "Robot.h"
#include "Inventory.h"

#ifndef ROBOTS_LOADER_H
#define ROBOTS_LOADER_H

class RobotsLoader
{
public:
	RobotsLoader(Inventory * all_items);
	~RobotsLoader(void);

	void loadRobotsFromText();

	vector<Robot> getRobots();

protected:

	Inventory * all_items;
	vector<Robot> robots;
};

#endif
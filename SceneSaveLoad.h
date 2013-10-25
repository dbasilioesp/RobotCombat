#include "Scene.h"

#ifndef SCENE_SAVELOAD_H
#define SCENE_SAVELOAD_H

class SceneSaveLoad : public Scene
{
public:
	SceneSaveLoad(GameObject * _game_obj);
	~SceneSaveLoad(void);

	void load();
	void unload();

	void play(GameObject * game_obj);
	void draw();

	void saveSlot(int position);
	void loadSlot(int position);

protected:

	vector<Slot> slots;
	Interface * menu;

	int level;
	int money;
};

#endif
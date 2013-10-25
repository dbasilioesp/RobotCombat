#include "Scene.h"

#ifndef SCENE_MENU_H
#define SCENE_MENU_H

class SceneMenu : public Scene
{
public:
	SceneMenu(void);
	~SceneMenu(void);

	void load();
	void unload();

	void play(GameObject * game_obj);
	void draw();
};

#endif

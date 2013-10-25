#include "Scene.h"

#ifndef SCENE_WORKSHOP_H
#define SCENE_WORKSHOP_H

class SceneWorkshop : public Scene
{
public:
	SceneWorkshop(GameObject * game_obj);
	~SceneWorkshop(void);

	void load();
	void unload();

	void play(GameObject * game_obj);
	void draw();
};

#endif

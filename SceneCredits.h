#pragma once
#include "Scene.h"


class SceneCredits : public Scene
{
public:
	SceneCredits(void);
	~SceneCredits(void);

	void load();
	void unload();

	void play(GameObject * game_obj);
	void draw();
};


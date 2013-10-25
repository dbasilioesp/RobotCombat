#pragma once
#include "Scene.h"

#ifndef SCENE_LOADING_H
#define SCENE_LOADING_H


class SceneLoading : public Scene
{
public:
	SceneLoading(void);
	~SceneLoading(void);

	void load();
	void unload();
	void play(GameObject * game_obj);
	void draw();

protected:
	fonte arial_font_30;
};

#endif

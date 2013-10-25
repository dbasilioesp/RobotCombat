#pragma once
#include "engcomp_glib.h"
#include "FileLoader.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

	void nextScene(int scene);

	imagem * cursor;

	int scene_actual;
	int scene_next;
	int scene_previous;
	bool exit;
	bool stop_game;
	bool game_over;
	bool fullscreen;
	int width_screen;
	int height_screen;
	int frames;
	int delay;
	int interval;

	FileLoader * file_loader;
	Player * player;
	vector<Robot> enemies;
};

#endif
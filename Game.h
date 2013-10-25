#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "engcomp_glib.h"
#include "Scene.h"
#include "SceneMenu.h"
#include "SceneCredits.h"
#include "SceneWorkshop.h"
#include "SceneBattle.h"
#include "SceneLoading.h"
#include "SceneSaveLoad.h"
#include "GameObject.h"
#include "FileLoader.h"
#define INTERVAL_MOVE 300

using namespace std;


class Game
{

public:
	Game(void);
	~Game(void);

	void initialize();
	void play();
	void finalize();

	void loadNextScene();
	void setEnemies();

	void resetGame();
	void stopGame();

	bool initDelay();
	bool initDelay(int time);

protected:

	Scene ** scenes;
	GameObject * game_obj;
	bool loading_scene;
	FileLoader file_loader;
};


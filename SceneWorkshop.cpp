#include "SceneWorkshop.h"


SceneWorkshop::SceneWorkshop(GameObject * _game_obj)
{
	game_obj = _game_obj;
}


SceneWorkshop::~SceneWorkshop(void)
{
	Scene::~Scene();
}


void SceneWorkshop::load()
{
	background = new imagem;
	background->carregar(".\\backgrounds\\background_purple1024.png");

	int wscreen = game_obj->width_screen;
	int hscreen = game_obj->height_screen;

	panel = new Interface;

	ItemMenu * menu_play = new ItemMenu(SceneActual::BATTLE, "Play", wscreen/2 - 50, hscreen/2 - 50, 200, 35);
	menu_play->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_play);

	ItemMenu * menu_sair = new ItemMenu(SceneActual::OPEN, "Exit", wscreen - 220, hscreen - 50, 200, 35);
	menu_sair->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_sair);

	ItemMenu * menu_saveload = new ItemMenu(SceneActual::SAVE_LOAD, "Save & Load", 20, 50, 200, 35);
	menu_saveload->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_saveload);

	music = NULL;
	is_loaded = true;
}


void SceneWorkshop::unload()
{
}


void SceneWorkshop::play(GameObject * _game_obj)
{
	game_obj = _game_obj;

	button_press = panel->verificaEventos(EGL_CLIQUE_ESQ);

	switch(button_press){
		case SceneActual::BATTLE:
			nextScene(SceneActual::BATTLE);
			break;
		case SceneActual::SAVE_LOAD:
			nextScene(SceneActual::SAVE_LOAD);
			break;
		case SceneActual::OPEN:
			nextScene(SceneActual::OPEN);
			break;
	}
}

void SceneWorkshop::draw()
{
	background->desenha(0, 0);
	panel->desenha();
}
#include "SceneMenu.h"


SceneMenu::SceneMenu(void)
{
}


SceneMenu::~SceneMenu(void)
{
}


void SceneMenu::load()
{
	background = new imagem;
	background->carregar(".\\backgrounds\\background_blue1024.png");

	int y = 400;

	panel = new Interface;

	ItemMenu * menu_start = new ItemMenu(SceneActual::WORKSHOP, "New Game", 20, y, 200, 35);
	menu_start->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_start);

	ItemMenu * menu_load = new ItemMenu(SceneActual::LOADING, "Load Game", 20, y + 40, 200, 35);
	menu_load->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_load);

	ItemMenu * menu_ranking = new ItemMenu(SceneActual::RANKING, "Ranking", 20, y + 40*2, 200, 35);
	menu_ranking->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_ranking);

	ItemMenu * menu_credits = new ItemMenu(SceneActual::CREDITS, "Credits", 20, y + 40*3, 200, 35);
	menu_credits->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_credits);

	ItemMenu * menu_exit = new ItemMenu(SceneActual::EXIT, "Exit", 20, y + 40*4, 200, 35);
	menu_exit->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_exit);

	music = NULL;
	is_loaded = true;
}


void SceneMenu::unload()
{
}


void SceneMenu::play(GameObject * game_obj)
{
	button_press = panel->verificaEventos(EGL_CLIQUE_ESQ);

	switch(button_press){
		case SceneActual::WORKSHOP: 
			game_obj->scene_actual = SceneActual::WORKSHOP;
			break;
		case SceneActual::CREDITS: 
			game_obj->scene_actual = SceneActual::CREDITS;
			break;
		case SceneActual::SAVE_LOAD: 
			game_obj->scene_actual = SceneActual::SAVE_LOAD;
			break;
		case SceneActual::EXIT:
			game_obj->exit = true;
			break;
	}
}


void SceneMenu::draw()
{
	background->desenha(0, 0);
	panel->desenha();
}
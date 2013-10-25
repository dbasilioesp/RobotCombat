#include "SceneCredits.h"


SceneCredits::SceneCredits(void)
{
	background = new imagem;
	background->carregar(".\\backgrounds\\background_green1024.png");

	panel = new Interface;

	ItemMenu * menu_start = new ItemMenu(SceneActual::OPEN, "Menu", 20, 450, 200, 35);
	menu_start->setarFonte(".\\fonts\\digimon.ttf", 16, true);
	panel->adicionaComponente(menu_start);

	music = new musica;
}


SceneCredits::~SceneCredits(void)
{
	Scene::~Scene();
}


void SceneCredits::load()
{

}


void SceneCredits::unload()
{
}


void SceneCredits::play(GameObject * game_obj)
{
	button_press = panel->verificaEventos(EGL_CLIQUE_ESQ);

	switch(button_press){
		case SceneActual::OPEN: 
			game_obj->scene_actual = SceneActual::OPEN;
			break;
	}
}


void SceneCredits::draw()
{
	background->desenha(0, 0);
	panel->desenha();
}
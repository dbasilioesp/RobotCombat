#include "Scene.h"


Scene::Scene(void)
{
	button_press = -1;
	is_loaded = false;
	standard_font.carregar(".\\fonts\\arial\\arial.ttf", 30);
}


Scene::~Scene(void)
{
	delete background;
	delete panel;
	delete music;
}

string Scene::concatenate(string text, int number)
{
	_itoa_s (number, buffer, 10);
	return string(text) + string(buffer);
}


bool Scene::isLoaded()
{
	return is_loaded;
}


void Scene::nextScene(SceneActual scene)
{
	if(game_obj->scene_actual >= 0){
		game_obj->scene_previous = game_obj->scene_actual;
	}

	game_obj->scene_next = scene;
	game_obj->scene_actual = SceneActual::LOADING;
	game_obj->delay = 300;
}

void Scene::unload()
{
}
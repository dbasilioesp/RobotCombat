#include "SceneLoading.h"


SceneLoading::SceneLoading(void)
{
}


SceneLoading::~SceneLoading(void)
{
	Scene::~Scene();
}


void SceneLoading::load()
{
	background = NULL;
	panel = NULL;
	music = NULL;

	is_loaded = true;
}


void SceneLoading::unload()
{
}


void SceneLoading::play(GameObject * _game_obj)
{
	game_obj = _game_obj;
	
	if(key[SDLK_ESCAPE]){
        game_obj->exit = true;
    }
}


void SceneLoading::draw()
{
	standard_font.desenha_texto("Loading . . .", 10, 10, 255, 255, 255);
}

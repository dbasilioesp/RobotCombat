#include "SceneSaveLoad.h"


SceneSaveLoad::SceneSaveLoad(GameObject * _game_obj)
{
	game_obj = _game_obj;
	menu = NULL;
}


SceneSaveLoad::~SceneSaveLoad(void)
{
	Scene::~Scene();
	delete menu;
}


void SceneSaveLoad::load()
{
	background = new imagem;
	background->carregar(".\\backgrounds\\background_save_load.png");

	int width = game_obj->width_screen;
	int height = game_obj->height_screen;

	panel = new Interface;
	panel->adicionaComponente(new Botao(SceneActual::WORKSHOP, width-120, height-76, ".\\buttons\\back1.png",".\\buttons\\back2.png",".\\buttons\\back2.png"));

	menu = new Interface;
	menu->adicionaComponente(new Botao(0, 288, 133, ".\\buttons\\save1.png", ".\\buttons\\save3.png", ".\\buttons\\save2.png"));
	menu->adicionaComponente(new Botao(1, 288, 180, ".\\buttons\\load1.png", ".\\buttons\\load3.png", ".\\buttons\\load2.png"));
	
	music = NULL;
	
	game_obj->file_loader->loadSlots();
	slots = game_obj->file_loader->getSlots();
	
	is_loaded = true;
}


void SceneSaveLoad::unload()
{
}


void SceneSaveLoad::play(GameObject * _game_obj)
{
	game_obj = _game_obj;
	
	button_press = menu->verificaEventos(EGL_CLIQUE_ESQ);

	switch(button_press){
		case 0:
			saveSlot(1);
			break;
		case 1:
			loadSlot(1);
			break;
	}

	button_press = panel->verificaEventos(EGL_CLIQUE_ESQ);
	
	switch(button_press){
		case SceneActual::WORKSHOP:
			nextScene(SceneActual::WORKSHOP);
			break;
	}

	if(key[SDLK_ESCAPE]){
        game_obj->exit = true;
    }
}


void SceneSaveLoad::saveSlot(int position)
{
	// First save at that position
	if(slots.size() < position){
		Slot slot;
		slot.setPlayer(*game_obj->player);
		slots.push_back(slot);
	}
	// Update save
	else{
		Slot slot = slots[position-1];
		slot.setPlayer(*game_obj->player);
		slots[position-1] = slot;
	}

	game_obj->file_loader->saveSlots(&slots);
}


void SceneSaveLoad::loadSlot(int position)
{
	game_obj->player = slots[position-1].getPlayer();
}


void SceneSaveLoad::draw()
{
	background->desenha(0, 0);
	panel->desenha();
	menu->desenha();

	if(slots.size() > 0){

		level = slots.at(0).getPlayer()->getLevel();
		money = slots.at(0).getPlayer()->getMoney();
	
		standard_font.desenha_texto(concatenate("", level), 130, 171, 255, 255, 255);
		standard_font.desenha_texto(concatenate("", money), 142, 215, 255, 255, 255);

	}
}
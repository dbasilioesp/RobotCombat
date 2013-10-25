#pragma once
#include "engcomp_glib.h"
#include "GameObject.h"

enum SceneActual {OPEN, WORKSHOP, BATTLE, CREDITS, LOADING, GAMEOVER, RANKING, SAVE_LOAD, EXIT, SIZE};

static bool mouse_pressed;

class Scene
{
public:
	Scene(void);
	~Scene(void);

	virtual void load() = 0;
	virtual void unload();

	virtual void play(GameObject * game_obj) = 0;
	virtual void draw() = 0;

	virtual void nextScene(SceneActual scene);

	string concatenate(string text, int number);

	bool isLoaded();

	bool onMouseClick(EGL_EVENTOS button)
	{
		if((mouse_b & SDL_BUTTON(button)) && (!mouse_pressed))
		{
			mouse_pressed = true;
			return true;
		}        
		else if (!mouse_b)
		{
			mouse_pressed = false;
			return false;
		}
		return false;
	}

protected:

	GameObject * game_obj;

	imagem * background;
	Interface * panel;
	musica * music;
	fonte standard_font;

	int button_press;
	char buffer[50];
	bool is_loaded;
};


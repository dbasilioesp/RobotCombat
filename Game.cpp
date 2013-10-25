#include "Game.h"


Game::Game(void)
{
	game_obj = new GameObject;

	// controls states
	game_obj->scene_actual = SceneActual::BATTLE;
	game_obj->scene_next = -1;
	game_obj->scene_previous = -1;
	game_obj->exit = false;
	game_obj->stop_game = false;
	game_obj->game_over = false;
	game_obj->width_screen = 800; //1024;
	game_obj->height_screen = 600; //768;
	game_obj->fullscreen = true;
	game_obj->frames = 0;
	game_obj->delay = 0;
	game_obj->interval = 0;
	game_obj->player = new Player;
	game_obj->player->setWins(0);
	game_obj->player->setLoses(0);
	game_obj->player->setLevel(1);
	game_obj->player->setMoney(0);

	loading_scene = false;
}


Game::~Game(void)
{
	delete [] scenes;
	delete game_obj;
}


void Game::initialize()
{
	egl_inicializar(game_obj->width_screen, game_obj->height_screen, game_obj->fullscreen);

	game_obj->file_loader = new FileLoader;
	game_obj->file_loader->load();
	game_obj->file_loader->setRobotPlayer(0, game_obj->player);
	
	setEnemies();

	// Initialize Scenes
	scenes = new Scene*[SceneActual::SIZE];
	scenes[SceneActual::OPEN] = new SceneMenu();
	scenes[SceneActual::CREDITS] = new SceneCredits();
	scenes[SceneActual::WORKSHOP] = new SceneWorkshop(game_obj);
	scenes[SceneActual::BATTLE] = new SceneBattle(game_obj);
	scenes[SceneActual::SAVE_LOAD] = new SceneSaveLoad(game_obj);
	scenes[SceneActual::LOADING] = new SceneLoading();

	// Initialize Cursor
	game_obj->cursor = new imagem;
	game_obj->cursor->carregar(".\\sprites\\cursor_win_hand.png");
}


void Game::play()
{
	while(!game_obj->exit)
	{

		// Load actual scene
		if(!scenes[game_obj->scene_actual]->isLoaded()){
			scenes[game_obj->scene_actual]->load();
		}

		// Play Scene
		if(game_obj->delay <= 0){
			scenes[game_obj->scene_actual]->play(game_obj);
		}else{
			game_obj->delay -= 1;
		}

		// Draw Scene
		if(scenes[game_obj->scene_actual]->isLoaded()){
			scenes[game_obj->scene_actual]->draw();
		}
		
		// Load next scene
		if(game_obj->scene_next != -1 && game_obj->delay <= 0){
			loadNextScene();
		}

		// Draw Cursor
		SDL_ShowCursor(SDL_DISABLE);
		game_obj->cursor->desenha(mouse_x-5, mouse_y-5);

		// Frames
		game_obj->frames += 1;
		egl_desenha_frame();
	}
}


void Game::loadNextScene()
{
	if(!scenes[game_obj->scene_next]->isLoaded()){
		scenes[game_obj->scene_next]->load();
		game_obj->delay = 600;
	} else {
		if(game_obj->scene_previous >= SceneActual::BATTLE){
			scenes[game_obj->scene_previous]->unload();
		}
		game_obj->scene_actual = game_obj->scene_next;
		game_obj->scene_next = -1;
	}
}


void Game::setEnemies()
{
	vector<Robot> robots;
	vector<Robot> enemies;

	robots = game_obj->file_loader->getRobots();

	for(int i = 1; i < robots.size(); i++)
	{
		enemies.push_back(robots[i]);
	}

	game_obj->enemies = enemies;
}


void Game::resetGame()
{
	game_obj->stop_game = false;
	game_obj->game_over = false;
}



void Game::finalize()
{
	egl_finalizar();
}
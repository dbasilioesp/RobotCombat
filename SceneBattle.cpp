#include "SceneBattle.h"


SceneBattle::SceneBattle(GameObject * _game_obj)
{
	game_obj = _game_obj;
	button_press = -1;
	is_loaded = false;

	w_offset = 75;
	h_offset = 15;
	max_lines = 5;
	max_columns = 7;
	move_positions = NULL;
	attack_positions = NULL;
	number_moves = new int(0);
	number_attack = new int(0);
	is_to_show_moves = false;
	is_to_show_attack = false;
	is_to_show_damage = false;
	has_attacked = false;
	has_moved = false;
	has_winned_prize = false;
	has_losed_prize = false;
	line_move = 1;
	column_move = 1;
	number_move = 1;
	damage_taken = 0;

	london_font.carregar(".\\fonts\\LondonTwo.ttf", 60);
}


SceneBattle::~SceneBattle(void)
{
	Scene::~Scene();
	delete square;
	delete square_light;
	delete number_moves;
	delete number_attack;
	delete move_positions;
	delete attack_positions;
	delete player_robot;
	delete other_robot;
	delete winner;
}


void SceneBattle::load(){

	int width = game_obj->width_screen;
	int height = game_obj->height_screen;

	background = new imagem;
	background->carregar(".\\backgrounds\\blank.fw.png");

	square = new imagem;
	square->carregar(".\\sprites\\square.fw.png");

	square_light = new imagem;
	square_light->carregar(".\\sprites\\square_light.1.png");
	square_light->carregar(".\\sprites\\square_light.2.png");
	square_light->setar_tempo_animacao(360);

	square_red = new imagem;
	square_red->carregar(".\\sprites\\square_red.png");
	square_red->setar_tempo_animacao(360);

	icon_player = new imagem;
	icon_player->carregar(".\\sprites\\icon1.png");
	
	menu = new Interface;

	menu->adicionaComponente(new Botao(EBattleMenu::ATTACK, 0, 29, ".\\buttons\\menu_attack1.png",".\\buttons\\menu_attack2.png",".\\buttons\\menu_attack2.png"));
	menu_attack_disable = new imagem;
	menu_attack_disable->carregar(".\\buttons\\menu_attack_disable.png");

	menu->adicionaComponente(new Botao(EBattleMenu::MOVE, 0, 89, ".\\buttons\\menu_move1.png",".\\buttons\\menu_move2.png",".\\buttons\\menu_move2.png"));
	menu_move_disable = new imagem;
	menu_move_disable->carregar(".\\buttons\\menu_move_disable.png");
	
	menu->adicionaComponente(new Botao(EBattleMenu::PASS, 0, 149, ".\\buttons\\pass1.png",".\\buttons\\pass2.png",".\\buttons\\pass2.png"));

	panel = new Interface;
	panel->adicionaComponente(new Botao(SceneActual::WORKSHOP, 0, 209, ".\\buttons\\menu_exit1.png",".\\buttons\\menu_exit2.png",".\\buttons\\menu_exit2.png"));
	
	sprite_damage = new imagem;
	sprite_damage->carregar(".\\sprites\\attack6.png");
	
	music = NULL;
	winner = NULL;

	robot = *game_obj->player->getRobot();
	//robot = new Robot();
	/*robot->setSpritesSize(1);
	robot->addSprite(0, "robot-01-1.png");*/
	robot.loadSprites();
	robot.setX(getPosX(4));
	robot.setY(getPosY(3));
	
	enemy = game_obj->enemies.at(game_obj->player->getLevel()-1);
	//enemy = new Robot;
	/*enemy->setSpritesSize(1);
	enemy->addSprite(0, "robot-02-1.png");*/
	enemy.loadSprites();
	enemy.setX(getPosX(5));
	enemy.setY(getPosY(3));
	
	player_robot = &robot;
	other_robot = &enemy;

	winner = NULL;
	is_loaded = true;
}


void SceneBattle::unload(){
	background = NULL;
	square = NULL;
	square_light = NULL;
	square_red = NULL;
	icon_player = NULL;
	sprite_damage = NULL;
	menu = NULL;
	panel = NULL;
	music = NULL;
	winner = NULL;
	player_robot = NULL;
	other_robot = NULL;
	is_loaded = false;
}


void SceneBattle::play(GameObject * _game_obj)
{
	game_obj = _game_obj;

	if(is_to_show_damage){
		is_to_show_damage = false;
	}

	if(has_attacked && has_moved){
		tradeTurn();
	}

	if(winner == &robot && !has_winned_prize){
		int level = game_obj->player->getLevel();
		int money = game_obj->player->getMoney();
		int wins = game_obj->player->getWins();

		game_obj->player->setLevel(level+1);
		game_obj->player->setMoney(money+100);
		game_obj->player->setWins(wins+1);

		has_winned_prize = true;
	}

	if(winner == &enemy && !has_losed_prize){
		int loses = game_obj->player->getLoses();
		game_obj->player->setLoses(loses+1);
		has_losed_prize = false;
	}

	button_press = panel->verificaEventos(EGL_CLIQUE_ESQ);
	switch(button_press){
		case SceneActual::WORKSHOP:
			nextScene(SceneActual::WORKSHOP);
			break;
	}

	button_press = menu->verificaEventos(EGL_CLIQUE_ESQ);
	switch(button_press)
	{
		case EBattleMenu::ATTACK:
			if(!is_to_show_moves && !has_attacked){
				showAttacks();
			}
			break;
		case EBattleMenu::MOVE: 
			if(!is_to_show_attack && !has_moved){
				showMoves();
			}
			break;
		case EBattleMenu::PASS:
			tradeTurn();
			break;
	}

	if(onMouseClick(EGL_CLIQUE_ESQ))
	{
		// Mover robot
		if(is_to_show_moves){
			moveRobot();
		}

		if(is_to_show_attack){
			attackRobot();
		}
	}

	if(key[SDLK_ESCAPE]){
        game_obj->exit = true;
    }
}


void SceneBattle::tradeTurn()
{
	is_to_show_attack = false;
	is_to_show_moves = false;
	has_attacked = false;
	has_moved = false;
	Robot * temp = player_robot;
	player_robot = other_robot;
	other_robot = temp;
}


void SceneBattle::showMoves()
{
	if(!is_to_show_moves){
		is_to_show_moves = true;
				
		delete [] move_positions;
		move_positions = new Matriz[max_lines*max_columns];

		int line = getLine(player_robot->getY());
		int column = getColumn(player_robot->getX());
				
		player_robot->setMoveMatriz(move_positions, number_moves, line, column, max_lines, max_columns);
	}
	else {
		is_to_show_moves = false;
	}
}


void SceneBattle::showAttacks()
{
	if(!is_to_show_attack){
		is_to_show_attack = true;
				
		delete [] attack_positions;
		attack_positions = new Matriz[max_lines*max_columns];

		int line = getLine(player_robot->getY());
		int column = getColumn(player_robot->getX());
				
		player_robot->setAttackMatriz(attack_positions, number_attack, line, column, max_lines, max_columns);

	}else{
		is_to_show_attack = false;
	}
}


void SceneBattle::moveRobot()
{
	int line = getLine(mouse_y);
	int column = getColumn(mouse_x);

	for (int i = 0; i < *number_moves; i++)
	{
		if(move_positions[i].line == line && move_positions[i].column == column){
			is_to_show_moves = false;
			has_moved = true;
			player_robot->setX(getPosX(column));
			player_robot->setY(getPosY(line));
			break;
		}
	}
}


void SceneBattle::attackRobot()
{
	imagem * cursor = game_obj->cursor;
	if(cursor->colide(mouse_x, mouse_y, cursor->getResX(), cursor->getResY(), other_robot->getX(), 
		other_robot->getY(), other_robot->getWidth(), other_robot->getHeight(), *other_robot->getSprite()))
	{
		int line = getLine(mouse_y);
		int column = getColumn(mouse_x);

		for (int i = 0; i < *number_attack; i++)
		{
			if(attack_positions[i].line == line && attack_positions[i].column == column){
				
				is_to_show_attack = false;
				is_to_show_damage = true;
				has_attacked = true;
				game_obj->delay = 200;
				
				int attack_power = (rand() % (player_robot->getAttack() * 30));
				int defense = (rand() % (other_robot->getDefense() * 15));
				int health = other_robot->getHealth();

				if(attack_power > defense){
					health = other_robot->getHealth();
					damage_taken = (rand() % player_robot->getDamage()) + 1;
					health -= damage_taken;
					other_robot->setHealth(health);
				} else {
					damage_taken = 0;
				}
				
				if(health <= 0){
					winner = player_robot;
				}

				break;
			}
		}
	}
}


void SceneBattle::draw()
{
	background->desenha(0, 0);

	for (int i = 0; i < max_columns; i++)
	{
		for (int j = 0; j < max_lines; j++)
		{
			square->desenha(w_offset + i * (square->getResX() + 1), h_offset + j * (square->getResY() + 1));
		}
	}

	panel->desenha();
	menu->desenha();
	
	standard_font.desenha_texto(robot.getName(), w_offset + 50, 525, 255, 255, 255);
	standard_font.desenha_texto(concatenate("Health 1: ", robot.getHealth()), w_offset + 20, 555, 255, 255, 255);
	standard_font.desenha_texto(enemy.getName(), game_obj->width_screen - 170, 525, 255, 255, 255);
	standard_font.desenha_texto(concatenate("Health 2: ", enemy.getHealth()), game_obj->width_screen - 200, 555, 255, 255, 255);

	if(has_attacked || is_to_show_moves){
		menu_attack_disable->desenha(0, 29);
	}

	if(is_to_show_moves){

		for (int i = 0; i < *number_moves; i++)
		{
			square_light->desenha(getPosX(move_positions[i].column), getPosY(move_positions[i].line));
		}
	}

	if(has_moved || is_to_show_attack){
		menu_move_disable->desenha(0, 89);
	}

	if(is_to_show_attack){

		for (int i = 0; i < *number_attack; i++)
		{
			square_red->desenha(getPosX(attack_positions[i].column), getPosY(attack_positions[i].line));
		}
	}

	robot.draw();
	enemy.draw();

	if(is_to_show_damage){
		float middle_x = (other_robot->getWidth()/3);
		float middle_y = (other_robot->getHeight()/3);
		if(damage_taken > 0){
			standard_font.desenha_texto(concatenate("", damage_taken), other_robot->getX() + middle_x, other_robot->getY() - middle_x, 255, 40, 40);
			sprite_damage->desenha_rotacionado(other_robot->getX() + middle_x, other_robot->getY() + middle_y, game_obj->frames % 360);
		}else{
			standard_font.desenha_texto("MISS", other_robot->getX() + middle_x, other_robot->getY() - middle_x, 255, 40, 40);
		}
	}

	icon_player->desenha(player_robot->getX() + player_robot->getWidth() - 5, player_robot->getY());

	if(winner != NULL){
		string message = string("Robot ") + string(winner->getName()) + string(" Win!!");
		london_font.desenha_texto(message, game_obj->width_screen/4, game_obj->height_screen/4, 255, 255, 40);
	}
}


int SceneBattle::getPosY(int line)
{
	return ((line-1) * square->getResY()) + h_offset + 2;
}


int SceneBattle::getPosX(int column)
{
	return ((column-1) * square->getResX()) + w_offset + 2;
}


int SceneBattle::getLine(int y)
{
	if(y >= h_offset){
		return 1 + ((y - h_offset) / square->getResY());
	}else{
		return 0;
	}
}


int SceneBattle::getColumn(int x)
{
	if(x >= w_offset){
		return 1 + ((x - w_offset) / square->getResX());
	}else{
		return 0;
	}
}

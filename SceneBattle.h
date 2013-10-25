#pragma once
#include "Scene.h"
#include "Robot.h"
#include "Matriz.h"

#ifndef SCENE_BATTLE_H
#define SCENE_BATTLE_H

enum EBattleMenu {ATTACK, MOVE, PASS};

class SceneBattle : public Scene
{
public:
	SceneBattle(GameObject * game_obj);
	~SceneBattle(void);

	void load();
	void unload();

	void play(GameObject * game_obj);
	void draw();	
	void tradeTurn();

	int getPosY(int line);
	int getPosX(int column);

	int getLine(int y);
	int getColumn(int x);

	void showMoves();
	void showAttacks();

	void moveRobot();
	void attackRobot();

protected:

	imagem * square;
	imagem * square_light;
	imagem * square_red;
	imagem * sprite_damage;
	imagem * icon_player;
	
	imagem * menu_move_disable;
	imagem * menu_attack_disable;

	fonte london_font;

	Robot robot;
	Robot enemy;

	Robot * player_robot;
	Robot * other_robot;
	Robot * winner;

	int w_offset;
	int h_offset;
	int max_lines;
	int max_columns;
	int * number_moves;
	int * number_attack;
	Matriz * move_positions;
	Matriz * attack_positions;
	
	bool is_to_show_moves;
	bool is_to_show_attack;
	bool is_to_show_damage;
	bool has_moved;
	bool has_attacked;
	bool has_winned_prize;
	bool has_losed_prize;
	int line_move;
	int column_move;
	int number_move;
	int damage_taken;

	Interface * menu;
};

#endif
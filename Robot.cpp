#include "Robot.h"


Robot::Robot(void)
{
	health_points = 30;
	attack = 1;
	damage = 1;
	attack_range = 1;
	defense = 1;
	movement = 2;
}


Robot::~Robot(void)
{
}

void Robot::setId(int _id)
{
	id = _id;
}

void Robot::setHealth(int _health_points)
{
	health_points = _health_points;
	if(health_points <= 0){
		health_points = 0;
	}
}

void Robot::setName(string _name)
{
	name = _name;
}

int Robot::getId()
{
	return id;
}

string Robot::getName()
{
	return name;
}

int Robot::getAttack()
{
	return attack;
}

int Robot::getDamage()
{
	return damage;
}

int Robot::getRange()
{
	return attack_range;
}

int Robot::getDefense()
{
	return defense;
}

int Robot::getMovement()
{
	return movement;
}

int Robot::getHealth()
{
	return health_points;
}

void Robot::setMoveMatriz(Matriz * matriz, int *size, int line, int column, int max_lines, int max_columns){
	
	*size = 0;
	
	for(int move = 1; move <= movement; move++){
		
		for(int i = column - move; i <= column + move; i++){
			for(int j = line - move; j <= line + move; j++){
				
				// Verifica o tamanho do campo
				if((i > 0 && i <= max_columns) && (j > 0 && j <= max_lines)){
					
					// Verifica os quadrados que nao devem ser pintados
					if(move != movement || (move == movement && (i == column || j == line))){
						matriz[*size].line = j;
						matriz[*size].column = i;
						*size += 1;
					}
				}

			}
		}
	}
}

void Robot::setAttackMatriz(Matriz * matriz, int *size, int line, int column, int max_lines, int max_columns){
	
	*size = 0;
	
	for(int range = 1; range <= attack_range; range++){
		
		for(int i = column - range; i <= column + range; i++){
			for(int j = line - range; j <= line + range; j++){
				
				// Verifica o tamanho do campo
				if((i > 0 && i <= max_columns) && (j > 0 && j <= max_lines)){
					
					// Verifica os quadrados que nao devem ser pintados
					if(range != attack_range || (range == attack_range && (i == column || j == line))){
						matriz[*size].line = j;
						matriz[*size].column = i;
						*size += 1;
					}
				}

			}
		}
	}
}

void Robot::setWeapon(Weapon _weapon)
{
	attack = _weapon.getAttack();
	damage = _weapon.getDamage();
	attack_range = _weapon.getRange();
	weapon = _weapon;
}

void Robot::setArmor(Armor _armor)
{
	defense = _armor.getDefense();
	armor = _armor;
}

void Robot::setWheel(Wheel _wheel)
{
	movement = _wheel.getMovement();
	wheel = _wheel;
}

Weapon Robot::getWeapon()
{
	return weapon;
}

Armor Robot::getArmor()
{
	return armor;
}

Wheel Robot::getWheel()
{
	return wheel;
}


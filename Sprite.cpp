#include "Sprite.h"


Sprite::Sprite(void)
{
	index = 0;
	speed = 0;
	x = 0;
	y = 0;
	sprites = NULL;
}


Sprite::~Sprite(void)
{
	delete sprites;
}


float Sprite::getX(){
	return x;
}


float Sprite::getY(){
	return y;
}


void Sprite::setX(float _x)
{
	x = _x;
}


void Sprite::setY(float _y)
{
	y = _y;
}


int Sprite::getWidth(){
	return sprites[index].getResX();
}


int Sprite::getHeight(){
	return sprites[index].getResY();
}


imagem * Sprite::getSprite()
{
	return &sprites[index];
}


void Sprite::setSpritesSize(int size)
{
	sprites_names_size = size;
	sprites_names = new vector<string>*[size];
	for(int i = 0; i < size; i++){
		sprites_names[i] = new vector<string>;
	}
}

void Sprite::addSprite(int index, string filename)
{
	sprites_names[index]->push_back(filename);
}

void Sprite::loadSprites()
{
	sprites = new imagem[sprites_names_size];
	
	for(int i = 0; i < sprites_names_size; i++){
		for(int j = 0; j < sprites_names[i]->size(); j++){
			string filename = ".\\sprites\\robots\\" + sprites_names[i]->at(j);
			sprites[i].carregar(filename);
		}
	}
	
}


vector<string> Sprite::getSpritesNames()
{
	return **sprites_names;
}


void Sprite::draw()
{
	sprites[index].desenha(x, y);
}
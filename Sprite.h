#pragma once
#include <vector>
#include "engcomp_glib.h"

#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
public:
	Sprite(void);
	~Sprite(void);

	float getX();
    float getY();

	void setX(float x);
    void setY(float y);
    
    int getWidth();
    int getHeight();
    
    imagem * getSprite();

	void setSpritesSize(int size);
	void addSprite(int index, string filename);
	void loadSprites();

	virtual vector<string> getSpritesNames();

	void draw();

protected:

	imagem * sprites;
	int sprites_names_size;
	vector<string> ** sprites_names;

	int index;
	float x, y;
	float speed;
};

#endif
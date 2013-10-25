#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Item
{
public:
	Item(void);
	~Item(void);
	
	int getId();
	int getValue();
	string getName();
	string getType();

	virtual void setId(int id);
	virtual void setName(string nome);
	virtual void setValue(int value);
	virtual void setType(int type);

protected:

	int id;
	string name;
	string type;
	int value;
};

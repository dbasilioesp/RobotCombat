#include "Item.h"


Item::Item(void)
{
}


Item::~Item(void)
{
}


int Item::getId()
{
	return id;
}


string Item::getName()
{
	return name;
}


string Item::getType()
{
	return type;
}


int Item::getValue()
{
	return value;
}


void Item::setId(int _id)
{
	id = _id;
}


void Item::setName(string _name)
{
	name = _name;
}


void Item::setValue(int _value)
{
	value = _value;
}


void Item::setType(int _type)
{
	type = _type;
}

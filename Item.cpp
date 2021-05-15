#include "Item.h"

// PRIVATE METHODS

// CONSTRUCTORS
Item::Item(string n)
	:_name(n)
	{}

BasicSword::BasicSword()
	: Item("Basic Sword")
	{}

BasicBow::BasicBow()
	: Item("Basic Bow")
	{}

BasicWand::BasicWand()
	: Item("Basic Wand")
	{}

// METHODS
// Base Class
string Item::getItemNameBase() const
{
	return _name;
}

// Basic Sword
void BasicSword::use()
{

}

// Basic Bow
void BasicBow::use()
{

}

// Basic Wand
void BasicWand::use()
{

}
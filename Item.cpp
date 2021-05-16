#include "Item.h"

// PRIVATE METHODS

// CONSTRUCTORS
Item::Item(string n, bool u, bool a)
	:_name(n), _canUse(u), _canAttack(a)
	{}

BasicSword::BasicSword()
	: Item("Basic Sword", false, true)
	{}

BasicBow::BasicBow()
	: Item("Basic Bow", false, true)
	{}

BasicWand::BasicWand()
	: Item("Basic Wand", false, true)
	{}

// METHODS
// Base Class
string Item::getItemNameBase() const
{
	return _name;
}

bool Item::getIfUsable() const
{
	return _canUse;
}

bool Item::getIfCanAttack() const
{
	return _canAttack;
}

// Basic Sword
void BasicSword::use()
{

}

void BasicSword::attack()
{

}

// Basic Bow
void BasicBow::use()
{

}

void BasicBow::attack()
{

}

// Basic Wand
void BasicWand::use()
{

}

void BasicWand::attack()
{

}
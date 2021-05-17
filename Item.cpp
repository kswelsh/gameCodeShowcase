#include "Item.h"

// PRIVATE METHODS

// CONSTRUCTORS
Item::Item(string n, bool u, bool a, int d, int p)
	:_name(n), _canUse(u), _canAttack(a), _durability(d), _power(p)
	{}

Sword::Sword()
	: Item("Basic Sword", false, true, -1, 1)
	{}

Bow::Bow()
	: Item("Basic Bow", false, true, -1, 10)
	{}

Wand::Wand()
	: Item("Basic Wand", false, true, -1, 1)
	{}

// METHODS
// Base Class
string Item::getItemName() const
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

bool Item::checkAndDecDestory()
{
	if (!_canAttack)
	{
		_durability--;
		if (_durability == 0)
			return true;
	}
	return false;
}

int Item::getPower() const
{
	return _power;
}

string Item::use()
{
	return "Item cannot be used!";
}

string Item::attack()
{
	return "Item cannot be used in an attack!";
}

// Basic Sword
string Sword::attack()
{
	int attackNum;
	int attackMin;
	string returnValue;
	string attackText;
	string attackDamage;

	// calculate attack, min being 1/2 attack power
	attackMin = getPower() / 2;
	attackNum = rand() % getPower() + 1;
	if (attackNum < attackMin)
		attackNum = attackMin;
	
	// creating attack text
	string attackType = "slash";
	if (attackNum == 1)
	{
		attackDamage = "_1_";
		attackText = "Your " + getItemName() + " grazes the _";
	}
	else if (attackNum == 2)
	{
		attackDamage = "_2_";
		attackText = "Your " + getItemName() + " slits the _";
	}
	else if (attackNum == 3)
	{
		attackDamage = "_3_";
		attackText = "Your " + getItemName() + " slices the _";
	}
	else if (attackNum == 4)
	{
		attackDamage = "_4_";
		attackText = "Your " + getItemName() + " cuts through the _";
	}
	else if (attackNum == 5)
	{
		attackDamage = "_5_";
		attackText = "Your " + getItemName() + " impales the _";
	}
	else if (attackNum == 6)
	{
		attackDamage = "_6_";
		attackText = "Your " + getItemName() + " rips through the _";
	}
	else if (attackNum == 7)
	{
		attackDamage = "_7_";
		attackText = "Your " + getItemName() + " heavily damages the _";
	}
	else if (attackNum == 8)
	{
		attackDamage = "_8_";
		attackText = "Your " + getItemName() + " chops down the _";
	}
	else if (attackNum == 9)
	{
		attackDamage = "_9_";
		attackText = "Your " + getItemName() + " utterly destroys the _";
	}
	else
	{
		attackDamage = "_10_";
		attackText = "Your " + getItemName() + " obliterates the _";
	}

	// appending to one return value
	returnValue.append(attackType);
	returnValue.append(attackDamage);
	returnValue.append(attackText);

	return returnValue;
}

// Basic Bow
string Bow::attack()
{
	int attackNum;
	int attackMin;
	int attackMiss;
	int randomFlavorText;
	bool miss = false;
	string returnValue;
	string attackText;
	string attackDamage;

	// calculate attack, min being 1/3 attack power
	attackMin = getPower() / 3;
	attackNum = rand() % getPower() + 1;
	if (attackNum < attackMin)
		attackNum = attackMin;

	// chance to miss with bows
	attackMiss = rand() % 10 + 1;
	if (attackMiss == 1 || attackMiss == 2)
	{
		miss = true;
		attackDamage = "_0_";
		if (attackMiss == 1)
			attackText = "Your aim proves to be faulty! You miss the _";
		else
			attackText = "You completely miss the _";
	}

	// creating attack text
	string attackType = "pierce";
	randomFlavorText = rand() % 3 + 1;
	if (!miss)
	{
		if (attackNum == 1)
		{
			attackDamage = "_1_";
			if (randomFlavorText == 1)
				attackText = "Your arrow nearly misses the _";
			else if (randomFlavorText == 2)
				attackText = "You nearly miss the _";
			else
				attackText = "Your arrow almost misses the _";
		}
		else if (attackNum == 2)
		{
			attackDamage = "_3_";
			if (randomFlavorText == 1)
				attackText = "Your arrow somewhat hits the _";
			else 
				attackText = "Your arrow kind of hits the _";
		}
		else if (attackNum == 3)
		{
			attackDamage = "_3_";
			if (randomFlavorText == 1)
				attackText = "The arrow from your " + getItemName() + " infirmly hits the _";
			else
				attackText = "The arrow from your " + getItemName() + " weakly hits the _";
		}
		else if (attackNum == 4)
		{
			attackDamage = "_6_";
			if (randomFlavorText == 1)
				attackText = "Your arrow damages the _";
			else
				attackText = "Your arrow pierces the _";
		}
		else if (attackNum == 5)
		{
			attackDamage = "_6_";
			attackText = "Your arrow lodges in the _";
		}
		else if (attackNum == 6)
		{
			attackDamage = "_9_";
			attackText = "Your arrow almost goes straight through the _";
		}
		else if (attackNum == 7)
		{
			attackDamage = "_9_";
			if (randomFlavorText == 1)
				attackText = "The arrow from your " + getItemName() + " strongly damages the _";
			else
				attackText = "The arrow from your " + getItemName() + " heavily damages the _";
		}
		else if (attackNum == 8)
		{
			attackDamage = "_11_";
			attackText = "Your arrow sets ablaze mid-air, inflaming the _";
		}
		else if (attackNum == 9)
		{
			attackDamage = "_11_";
			if (randomFlavorText == 1)
				attackText = "Your arrow fires twice as fast and utterly annihilates the _";
			else
				attackText = "Your arrow extirpates the _";
		}
		else
		{
			attackDamage = "_13_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " fires 5 arrows, obliterating the _";
			else if (randomFlavorText = 2)
				attackText = "Your " + getItemName() + " seaks your target, eradicating the _";
			else 
				attackText = "Your " + getItemName() + " rapidly fires , liquidating the _";
		}
	}

	// appending to one return value
	returnValue.append(attackType);
	returnValue.append(attackDamage);
	returnValue.append(attackText);

	return returnValue;
}

// Basic Wand
string Wand::attack()
{
	string hold;
	return hold;
}
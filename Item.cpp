#include "Item.h"

// PRIVATE METHODS

// CONSTRUCTORS
Item::Item(string n, bool u, bool a, int d, int p, string i)
	:_name(n), _canUse(u), _canAttack(a), _durability(d), _power(p), _info(i)
	{}

Sword::Sword(string n, bool u, bool a, int d, int p, string i)
	: Item(n, u, a, d, p, i)
	{}

Bow::Bow(string n, bool u, bool a, int d, int p, string i)
	: Item(n, u, a, d, p, i)
	{}

Wand::Wand(string n, bool u, bool a, int d, int p, string i)
	: Item(n, u, a, d, p, i)
	{}

HealthPotion::HealthPotion(string n, bool u, bool a, int d, int p, string i)
	: Item(n, u, a, d, p, i)
	{}

Book::Book(string n, bool u, bool a, int d, int p, string i)
	: Item(n, u, a, d, p, i)
	{}

// METHODS
// Base Class
string Item::getItemName() const
{
	return _name;
}

string Item::getInfo() const
{
	return _info;
}

bool Item::getIfUsable() const
{
	return _canUse;
}

bool Item::getIfCanAttack() const
{
	return _canAttack;
}

bool Item::checkAndDecDur()
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

// Sword
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
		attackText = "Your " + getItemName() + " grazes the ";
	}
	else if (attackNum == 2)
	{
		attackDamage = "_2_";
		attackText = "Your " + getItemName() + " slits the ";
	}
	else if (attackNum == 3)
	{
		attackDamage = "_3_";
		attackText = "Your " + getItemName() + " slices the ";
	}
	else if (attackNum == 4)
	{
		attackDamage = "_4_";
		attackText = "Your " + getItemName() + " cuts through the ";
	}
	else if (attackNum == 5)
	{
		attackDamage = "_5_";
		attackText = "Your " + getItemName() + " impales the ";
	}
	else if (attackNum == 6)
	{
		attackDamage = "_6_";
		attackText = "Your " + getItemName() + " rips through the ";
	}
	else if (attackNum == 7)
	{
		attackDamage = "_7_";
		attackText = "Your " + getItemName() + " heavily damages the ";
	}
	else if (attackNum == 8)
	{
		attackDamage = "_8_";
		attackText = "Your " + getItemName() + " chops down the ";
	}
	else if (attackNum == 9)
	{
		attackDamage = "_9_";
		attackText = "Your " + getItemName() + " utterly destroys the ";
	}
	else
	{
		attackDamage = "_10_";
		attackText = "Your " + getItemName() + " obliterates the ";
	}

	// appending to one return value
	returnValue.append(attackType);
	returnValue.append(attackDamage);
	returnValue.append(attackText);

	return returnValue;
}

// Bow
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
			attackText = "Your aim proves to be faulty! You miss the ";
		else
			attackText = "You completely miss the ";
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
				attackText = "Your arrow nearly misses the ";
			else if (randomFlavorText == 2)
				attackText = "You nearly miss the _";
			else
				attackText = "Your arrow almost misses the ";
		}
		else if (attackNum == 2)
		{
			attackDamage = "_3_";
			if (randomFlavorText == 1)
				attackText = "Your arrow somewhat hits the ";
			else 
				attackText = "Your arrow kind of hits the ";
		}
		else if (attackNum == 3)
		{
			attackDamage = "_3_";
			if (randomFlavorText == 1)
				attackText = "The arrow from your " + getItemName() + " infirmly hits the ";
			else
				attackText = "The arrow from your " + getItemName() + " weakly hits the ";
		}
		else if (attackNum == 4)
		{
			attackDamage = "_6_";
			if (randomFlavorText == 1)
				attackText = "Your arrow damages the ";
			else
				attackText = "Your arrow pierces the ";
		}
		else if (attackNum == 5)
		{
			attackDamage = "_6_";
			attackText = "Your arrow lodges in the ";
		}
		else if (attackNum == 6)
		{
			attackDamage = "_9_";
			attackText = "Your arrow almost goes straight through the ";
		}
		else if (attackNum == 7)
		{
			attackDamage = "_9_";
			if (randomFlavorText == 1)
				attackText = "The arrow from your " + getItemName() + " strongly damages the ";
			else
				attackText = "The arrow from your " + getItemName() + " heavily damages the ";
		}
		else if (attackNum == 8)
		{
			attackDamage = "_11_";
			attackText = "Your arrow sets ablaze mid-air, inflaming the ";
		}
		else if (attackNum == 9)
		{
			attackDamage = "_11_";
			if (randomFlavorText == 1)
				attackText = "Your arrow fires twice as fast and utterly annihilates the ";
			else
				attackText = "Your arrow extirpates the ";
		}
		else
		{
			attackDamage = "_13_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " fires 5 arrows, obliterating the ";
			else if (randomFlavorText == 2)
				attackText = "Your " + getItemName() + " seaks your target, eradicating the ";
			else 
				attackText = "Your " + getItemName() + " rapidly fires, liquidating the ";
		}
	}

	// appending to one return value
	returnValue.append(attackType);
	returnValue.append(attackDamage);
	returnValue.append(attackText);

	return returnValue;
}

// Wand
string Wand::attack()
{
	int attackNum;
	int attackMin;
	int attackFocus;
	int randomFlavorText;
	bool focus = false;
	string returnValue;
	string attackText;
	string attackDamage;

	// calculate attack, min being 1/4 attack power
	attackMin = getPower() / 4;
	attackNum = rand() % getPower() + 1;
	if (attackNum < attackMin)
		attackNum = attackMin;

	// chance to lose focus with wands
	attackFocus = rand() % 10 + 1;
	if (attackFocus == 1 || attackFocus == 2 || attackFocus == 3 || attackFocus == 10)
	{
		focus = true;
		if (attackFocus == 1)
		{
			attackDamage = "_0_";
			attackText = "You complete lose focus! You miss the ";
		}
		else if (attackFocus == 2)
		{
			attackDamage = "_0_";
			attackText = "You get distracted and miss the ";
		}
		else if (attackFocus == 3)
		{
			attackDamage = "_1_";
			attackText = "You get somewhat distracted! You almost miss the ";
		}
		else
		{
			attackDamage = "_5_";
			attackText = "Your focus is completely in tune, casting fear upon the  ";
		}
	}

	// creating attack text
	string attackType = "magic";
	randomFlavorText = rand() % 3 + 1;
	if (!focus)
	{
		if (attackNum == 1)
		{
			attackDamage = "_2_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " shoots a fireball at the ";
			else if (randomFlavorText == 2)
				attackText = "Your " + getItemName() + " shoots ice at the ";
			else
				attackText = "Your " + getItemName() + " shoots electricity at the ";
		}
		else if (attackNum == 2)
		{
			attackDamage = "_3_";
			if (randomFlavorText == 1)
				attackText = "You cast flame on the ";
			else
				attackText = "You cast freeze on the ";
		}
		else if (attackNum == 3)
		{
			attackDamage = "_5_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " sprays molten lava at the ";
			else
				attackText = "Your " + getItemName() + " sprays frozen rocks at the ";
		}
		else if (attackNum == 4)
		{
			attackDamage = "_6_";
			if (randomFlavorText == 1)
				attackText = "You cast fire storm on the ";
			else
				attackText = "You cast ice storm on the ";
		}
		else if (attackNum == 5)
		{
			attackDamage = "_8_";
			attackText = "You cast seering burn on the ";
		}
		else if (attackNum == 6)
		{
			attackDamage = "_9_";
			attackText = "Your " + getItemName() + " inflicts a sharp pain on the ";
		}
		else if (attackNum == 7)
		{
			attackDamage = "_11_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " fires shattered earth at the ";
			else
				attackText = "Your " + getItemName() + " fires magic missles at the ";
		}
		else if (attackNum == 8)
		{
			attackDamage = "_12_";
			attackText = "You cast unforgiving death on the ";
		}
		else if (attackNum == 9)
		{
			attackDamage = "_14_";
			if (randomFlavorText == 1)
				attackText = "You cast earthshatter on the ";
			else
				attackText = "You cast demolish on the ";
		}
		else
		{
			attackDamage = "_15_";
			if (randomFlavorText == 1)
				attackText = "Your " + getItemName() + " fires death missles, obliterating the ";
			else if (randomFlavorText == 2)
				attackText = "You cast demoralize on the ";
			else
				attackText = "Your " + getItemName() + " takes over control, obliterating the ";
		}
	}

	// appending to one return value
	returnValue.append(attackType);
	returnValue.append(attackDamage);
	returnValue.append(attackText);

	return returnValue;
}

// Book
string Book::use()
{
	return ("love_" + to_string(getPower()));
}

// Health Potion
string HealthPotion::use()
{
	return ("heal_" + to_string(getPower()));
}

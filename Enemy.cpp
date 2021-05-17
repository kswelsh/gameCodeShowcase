#include "Enemy.h"

// PRIVATE METHODS

// CONSTRUCTORS
Enemy::Enemy(string n, int d, int hp, double mr, double ar, double pr)
	:_name(n), _difficulty(d), _health(hp), _magicResitance(mr), _armor(ar), _piercingResitance(pr)
	{}

LesserGoblin::LesserGoblin()
	: Enemy("Lesser Goblin", 0, 3, 0, 0, 0)
	{}

Goblin::Goblin()
	: Enemy("Goblin", 1, 5, 0, 0.20, 0)
	{}

GreaterGoblin::GreaterGoblin()
	: Enemy("Greater Goblin", 2, 6, 0.20, 0.30, 0.20)
	{}

// METHODS
// Base Class
void Enemy::displayEnemyText(const string& text, bool displaySizeDouble)
{
	if (displaySizeDouble)
		cout << "\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n\n\n";

	int centerCount;
	string center = "";
	bool error = false;

	// calculations for centering the text
	centerCount = (35 - (text.size() / 2));
	center.resize(centerCount);
	for (int i = 0; i < center.size(); i++)
	{
		center[i] = ' ';
	}

	// printing text in unique fashion
	cout << center;
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i];
		Sleep(50);
	}
	Sleep(500);

	if (displaySizeDouble)
		cout << "\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n\n\n";
}

bool Enemy::takeDamage(string type, int amount)
{
	double percentage = 1.00;
	bool defeated = false;

	if (type == "slash")
	{
		percentage = percentage - _armor;
		amount = amount * percentage;
		displayEnemyText("You deal " + to_string(amount) + " slashing damage!", false);
	}
	else if (type == "pierce")
	{
		percentage = percentage - _piercingResitance;
		amount = amount * percentage;
		displayEnemyText("You deal " + to_string(amount) + " piercing damage!", false);
	}
	else if (type == "magic")
	{
		percentage = percentage - _magicResitance;
		amount = amount * percentage;
		displayEnemyText("You deal " + to_string(amount) + " magic damage!", false);
	}
	else
	{
		displayEnemyText("You deal " + to_string(amount) + type + " damage!", false);
	}
	system("CLS");

	_health = _health - amount;
	if (_health > 0)
	{
		displayEnemyText("The " + _name + " still lives!", true);
	}
	else
	{
		displayEnemyText("The " + _name + " was defeated!", true);
		defeated = true;
	}

	return defeated;
}

string Enemy::getEnemyName() const
{
	return _name;
}

int Enemy::getDifficulty() const
{
	return _difficulty;
}

int Enemy::getHealth() const
{
	return _health;
}

int Enemy::getMagicResitance() const
{
	return _magicResitance;
}

int Enemy::getArmor() const
{
	return _armor;
}

int Enemy::getPiercingResitance() const
{
	return _piercingResitance;
}

void Enemy::setHealth(int newHealth)
{
	_health = newHealth;
}

// Lesser Goblin
int LesserGoblin::attack()
{
	int randomAttack;
	randomAttack = rand() % 4 + 1;

	// punch
	if (randomAttack == 1)
	{
		displayEnemyText("The Lesser Goblin punches you in the face!", false);
		system("CLS");
		displayEnemyText("You take 1 damage.", true);
		return 1;
	}
	// dagger
	else if (randomAttack == 2)
	{
		displayEnemyText("The Lesser Goblin stabs you in the arm!", false);
		system("CLS");
		displayEnemyText("You take 2 damage.", true);
		return 2;
	}
	// bite
	else if (randomAttack == 3)
	{
		displayEnemyText("The Lesser Goblin bites your face!", false);
		system("CLS");
		displayEnemyText("You take 1 damage.", true);
		return 1;
	}
	// miss
	else
	{
		displayEnemyText("The Lesser Goblin attempts to bite you but misses!", false);
		system("CLS");
		displayEnemyText("You take 0 damage.", true);
		return 0;
	}
	
}

// Goblin
int Goblin::attack()
{
	int hold = 0;
	return hold;
}

// GreaterGoblin
int GreaterGoblin::attack()
{
	int hold = 0;
	return hold;
}


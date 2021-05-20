#include "Enemy.h"

// PRIVATE METHODS

// CONSTRUCTORS
Enemy::Enemy(string n, int d, int hp, double mr, double ar, double pr)
	:_name(n), _difficulty(d), _health(hp), _magicResitance(mr), _armor(ar), _piercingResitance(pr), _maxAttacks(0)
	{}

// METHODS
// Base Class
void Enemy::displayEnemyText(const string& text, bool displaySizeDouble) const
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
		Sleep(35);
	}
	Sleep(700);
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
		displayEnemyText("You deal " + to_string(amount) + " " + type + " damage!", false);
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

int Enemy::attack() const
{
	int randomAttack;
	string flavorText;
	string damageText;
	string hold;
	randomAttack = rand() % _maxAttacks;

	flavorText = _attackText[randomAttack];
	hold = to_string(_damage[randomAttack]);
	damageText = "You take " + hold + " damage.";

	displayEnemyText(flavorText, false);
	system("CLS");
	displayEnemyText(damageText, true);

	return _damage[randomAttack];
}

void Enemy::addAttack(string flavorText, int damage)
{
	_damage.push_back(damage);
	_attackText.push_back(flavorText);
	_maxAttacks++;
	if (_maxAttacks > 10)
	{
		cout << "ERROR: ATTACK WONT EVER BE USED, ATTACKS ARE FULL" << endl;
		_maxAttacks == 10;
	}
}


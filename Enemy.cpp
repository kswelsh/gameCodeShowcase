#include "Enemy.h"

// PRIVATE METHODS

// CONSTRUCTORS
Enemy::Enemy(string n, int d, int hp, int mr, int ar, int pr)
	:_name(n), _difficulty(d), _health(hp), _magicResitance(mr), _armor(ar), _piercingResitance(pr)
	{}

LesserGoblin::LesserGoblin()
	: Enemy("Lesser Goblin", 0, 3, 0, 0, 0)
	{}

Goblin::Goblin()
	: Enemy("Goblin", 1, 5, 0, 1, 0)
	{}

GreaterGoblin::GreaterGoblin()
	: Enemy("Greater Goblin", 2, 6, 1, 2, 1)
	{}

// METHODS
// Base Class
string Enemy::getEnemyNameBase() const
{
	return _name;
}

int Enemy::getDifficultyBase() const
{
	return _difficulty;
}

int Enemy::getHealthBase() const
{
	return _health;
}

int Enemy::getMagicResitanceBase() const
{
	return _magicResitance;
}

int Enemy::getArmorBase() const
{
	return _armor;
}

int Enemy::getPiercingResitanceBase() const
{
	return _piercingResitance;
}

void Enemy::setHealthBase(int newHealth)
{
	_health = newHealth;
}

// Lesser Goblin
void LesserGoblin::attack()
{

}

void LesserGoblin::takeDamage()
{

}

int LesserGoblin::getDifficulty() const
{
	return this->getDifficultyBase();
}

// Goblin
void Goblin::attack()
{

}

void Goblin::takeDamage()
{

}

int Goblin::getDifficulty() const
{
	return this->getDifficultyBase();
}

// GreaterGoblin
void GreaterGoblin::attack()
{

}

void GreaterGoblin::takeDamage()
{

}

int GreaterGoblin::getDifficulty() const
{
	return this->getDifficultyBase();
}
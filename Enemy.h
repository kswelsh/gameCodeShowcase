#ifndef __ENEMY_H_
#define __ENEMY_H_

#include <iostream>
#include <string>
using namespace std;

class Enemy
{
private:
	string _name;
	int _difficulty;
	int _health;
	int _magicResitance;
	int _armor;
	int _piercingResitance;
public:
	Enemy(string, int, int, int, int, int);

	virtual ~Enemy() {};
	virtual void attack() = 0;
	virtual void takeDamage() = 0;
	virtual int getDifficulty() const = 0;

	string getEnemyNameBase() const;
	int getDifficultyBase() const;
	int getHealthBase() const;
	int getMagicResitanceBase() const;
	int getArmorBase() const;
	int getPiercingResitanceBase() const;

	// pre: 1st parm is num _health will be set to
	// post: _health is set to passed in int
	void setHealthBase(int);
	
};

class LesserGoblin : public Enemy
{
public:
	LesserGoblin();
	virtual ~LesserGoblin() {};
	void attack();
	void takeDamage();
	int getDifficulty() const;
};

class Goblin : public Enemy
{
public:
	Goblin();
	virtual ~Goblin() {};
	void attack();
	void takeDamage();
	int getDifficulty() const;
};

class GreaterGoblin : public Enemy
{
public:
	GreaterGoblin();
	virtual ~GreaterGoblin() {};
	void attack();
	void takeDamage();
	int getDifficulty() const;
};

#endif

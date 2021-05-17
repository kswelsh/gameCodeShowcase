#ifndef __ENEMY_H_
#define __ENEMY_H_

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// CLASS ENEMY IS IN CHARGE OF COMBAT/COMBAT DISPLAY
// CHANGES TO ANY VARS UNRELATED TO ENEMY ARE DONE
// THROUGH RETURNING VALUES
class Enemy
{
private:
	string _name;
	int _difficulty;
	int _health;

	// resistances are stored in percentage, example: 0.30 = 30% resitance to specific type
	double _magicResitance;
	double _armor;
	double _piercingResitance;
public:
	Enemy(string, int, int, double, double, double);
	virtual ~Enemy() {};

	// pre: none
	// post: displays attack done and damage done, returns damage amount
	virtual int attack() = 0;

	string getEnemyName() const;
	int getDifficulty() const;
	int getHealth() const;
	int getMagicResitance() const;
	int getArmor() const;
	int getPiercingResitance() const;

	// pre: 1st parm is num _health will be set to
	// post: _health is set to passed in int
	void setHealth(int);

	// pre: 1st parm is text you want to display, 2nd parm is true if you want spacing to be doubled on display
	// post: displays text passed in
	void displayEnemyText(const string&, bool);

	// pre: 1st parm is type of damage, 2nd parm is amount of damage
	//		type defined as either: "slash" (Armor) : "pierce" (Piercing Resitance) : "magic" (Magic Resitance)
	//		all other types of damage enemies cannot have resitance to
	// post: damage type is compared against enemies attributes and damage amount is calculated
	//		 returns true if the enemy is defeated, false otherwise
	bool takeDamage(string, int);
};

// All inherited methods documentation is written in "Enemy" abstract base class
class LesserGoblin : public Enemy
{
public:
	LesserGoblin();
	virtual ~LesserGoblin() {};
	virtual int attack();
};

class Goblin : public Enemy
{
public:
	Goblin();
	virtual ~Goblin() {};
	virtual int attack();
};

class GreaterGoblin : public Enemy
{
public:
	GreaterGoblin();
	virtual ~GreaterGoblin() {};
	virtual int attack();
};

#endif

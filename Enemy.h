#ifndef __ENEMY_H_
#define __ENEMY_H_

#include <iostream>
#include <string>
#include <vector>
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

	// enemy attacks, both same size always, _maxAttacks size of vector
	vector<int> _damage;
	vector<string> _attackText;
	int _maxAttacks;
public:
	// pre: 1st parm is enemy name, 2nd parm is enemy difficulty, 3rd parm is enemy health
	//		4th parm is magic resistance, 5th parm is armor, 6th parm is pierce resisitance
	// post: object is created
	Enemy(string, int, int, double, double, double);
	virtual ~Enemy() {};

	// pre: none
	// post: displays attack done and damage done, returns damage amount
	int attack() const;

	string getEnemyName() const;
	int getDifficulty() const;
	int getHealth() const;
	int getMagicResitance() const;
	int getArmor() const;
	int getPiercingResitance() const;

	// pre: 1st parm is attack flavor text, 2nd parm is attack damage
	// post: attack is added to vectors to be used when attack() is called
	void addAttack(string, int);

	// pre: 1st parm is num _health will be set to
	// post: _health is set to passed in int
	void setHealth(int);

	// pre: 1st parm is text you want to display, 2nd parm is true if you want spacing to be doubled on display
	// post: displays text passed in
	void displayEnemyText(const string&, bool) const;

	// pre: 1st parm is type of damage, 2nd parm is amount of damage
	//		type defined as either: "slash" (Armor) : "pierce" (Piercing Resitance) : "magic" (Magic Resitance)
	//		all other types of damage enemies cannot have resitance to
	// post: damage type is compared against enemies attributes and damage amount is calculated
	//		 returns true if the enemy is defeated, false otherwise
	bool takeDamage(string, int);
};

#endif

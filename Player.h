#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;
#include "Item.h"

class Player
{
private:
	int _maxHealth;
	int _health;
	int _love;
	string _name;
	vector<Item*> _items;

	// pre:
	// post:
	void useItem();

	// pre:
	// post:
	void useAttack();

	// pre: 1st parm is vector of attack choices that one wants to print
	// post: contents of vector are displayed
	void displayAttackChoicesPrint(const vector<string>&);
public:
	Player();

	// pre: 1st parm is text one would like to display
	// post: text is displayed in a unique fashion
	void displayText(string);

	// pre:
	// post:
	void displayInventory();

	// pre: none
	// post: attack choices are displayed and user can decide what attack to use
	//		 returns damage amount
	void displayAttackChoices();

	// pre: 1st parm is pointer to item one would like to add to vector of items a player holds
	// post: item pointer is added to vector
	void addItem(Item*);
};

#endif

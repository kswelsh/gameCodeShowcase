#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <sstream>
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
	void displayChoicesPrint(const vector<string>&, const string&) const;

	// pre: 1st parm is text one would like to display, 2nd parm is true if want variation, false if not
	// post: text is displayed in a unique fashion
	void displayText(string, bool) const;

	// pre: 1st parm is description of item, 2nd parm is item name
	// post: info is printed
	void parseAndPrintInfo(string&, string);
public:
	Player();



	// pre:
	// post:
	void displayInventory();

	// pre: none
	// post: attack choices are displayed and user can decide what attack to use
	//		 returns _ delimited damage type, damage amount, and flavor text (in order)
	string handleAttack() const;

	// pre: 1st parm is pointer to item one would like to add to vector of items a player holds
	// post: item pointer is added to vector
	void addItem(Item*);
};

#endif

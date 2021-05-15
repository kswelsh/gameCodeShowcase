#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Item.h"

class Player
{
private:
	int _maxHealth;
	int _health;
	int _love;
	string _name;
	vector<Item> _items;
public:
	Player();

};

#endif

#ifndef __ITEM_H_
#define __ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	string _name;
	int _durability;
	string _info;

	// if item can be used as an attack or use effect item
	bool _canUse;
	bool _canAttack;
	
	// power used for deciding what abilities whatever the
	// item is can use, used in all random calculations
	int _power;
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	// post: item is created
	Item(string, bool, bool, int, int, string);
	virtual ~Item() {};

	// pre: item must be usable
	// post: corresponding use effect happens
	virtual string use();

	// pre: item must be able to attack
	// post: corresponding attack effect happens
	virtual string attack();

	string getItemName() const;
	string getInfo() const;
	bool getIfUsable() const;
	bool getIfCanAttack() const;
	int getPower() const;

	// pre: none
	// post: item durability is subtracted by one
	//		 if _durability == 0, returns true, otherwise, returns false
	//		 items with _canAttack parm set to true will not be deincremented
	bool checkAndDecDestory();
};

// WEAPON ITEMS
// NOTE: WEAPON ITEMS CAN NEVER BE DESTROYED
//		 MEANING ANY ITEM WITH CANATTACK VALUE OF TRUE
//		 SHOULD NOT BE ABLE TO BE DESTROYED
class Sword : public Item
{
public:
	Sword();
	virtual ~Sword() {};
	virtual string attack();
};

class Bow : public Item
{
public:
	Bow();
	virtual ~Bow() {};
	virtual string attack();
};

class Wand : public Item
{
public:
	Wand();
	virtual ~Wand() {};
	virtual string attack();
};

#endif

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

	// info must be in format "description_rarity_damagePossible_healingPossible_lore"
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
	//		5th parm is _info
	// post: item is created
	Item(string, bool, bool, int, int, string);
	virtual ~Item() {};

	// pre: item must be usable
	// post: corresponding use effect happens
	virtual string use();

	// pre: item must be able to attack
	// post: returns "damageType_damageAmount_flavorText"
	virtual string attack();

	string getInfo() const;
	string getItemName() const;
	bool getIfUsable() const;
	bool getIfCanAttack() const;
	int getPower() const;

	// pre: none
	// post: item durability is subtracted by one
	//		 if _durability == 0, returns true, otherwise, returns false
	//		 items with _canAttack parm set to true will not be deincremented
	bool checkAndDecDur();
};

// WEAPON ITEMS
// NOTE: WEAPON ITEMS CAN NEVER BE DESTROYED
//		 MEANING ANY ITEM WITH CANATTACK VALUE OF TRUE
//		 SHOULD NOT BE ABLE TO BE DESTROYED
class Sword : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Sword(string, bool, bool, int, int, string);
	virtual ~Sword() {};
	virtual string attack();
};

class Bow : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Bow(string, bool, bool, int, int, string);
	virtual ~Bow() {};
	virtual string attack();
};

class Wand : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Wand(string, bool, bool, int, int, string);
	virtual ~Wand() {};
	virtual string attack();
};

class Book : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Book(string, bool, bool, int, int, string);
	virtual ~Book() {};
	virtual string use();
};

class HealthPotion : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	HealthPotion(string, bool, bool, int, int, string);
	virtual ~HealthPotion() {};
	virtual string use();
};

#endif

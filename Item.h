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
	int _cost;

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
	//		5th parm is _info, 6th parm is cost
	// post: item is created
	Item(string, bool, bool, int, int, string, int);
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
	int getCost() const;
	string getCostString() const;

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
	Sword(string, bool, bool, int, int, string, int);
	virtual ~Sword() {};
	virtual string attack();

	// Consistent weapon with max power of 10
};

class Bow : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Bow(string, bool, bool, int, int, string, int);
	virtual ~Bow() {};
	virtual string attack();

	// Less consistent weapon with max power of 10, has chance to miss
};

class Wand : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Wand(string, bool, bool, int, int, string, int);
	virtual ~Wand() {};
	virtual string attack();

	// High range of damage with max power of 10, has chance to miss and power up (focus)
};

class Dagger : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Dagger(string, bool, bool, int, int, string, int);
	virtual ~Dagger() {};
	virtual string attack();

	// Very consistent weapon with a max power of 5
};

class Book : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	Book(string, bool, bool, int, int, string, int);
	virtual ~Book() {};
	virtual string use();

	// Used to increase love
};

class HealthPotion : public Item
{
public:
	// pre: 1st parm is item name, 2nd parm is if item can be "used"
	//		3rd parm is if item can "attack", 4th parm is item durability, set to -1 if cannot be destroyed
	//		5th parm is _info
	// post: item is created
	HealthPotion(string, bool, bool, int, int, string, int);
	virtual ~HealthPotion() {};
	virtual string use();

	// Used to heal
};

#endif

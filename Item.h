#ifndef __ITEM_H_
#define __ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	string _name;
	bool _canUse;
	bool _canAttack;
public:
	Item(string, bool, bool);
	virtual ~Item() {};
	virtual void use() = 0;
	virtual void attack() = 0;

	string getItemNameBase() const;
	bool getIfUsable() const;
	bool getIfCanAttack() const;
};

class BasicSword : public Item
{
public:
	BasicSword();
	virtual ~BasicSword() {};
	virtual void use();
	virtual void attack();
};

class BasicBow : public Item
{
public:
	BasicBow();
	virtual ~BasicBow() {};
	virtual void use();
	virtual void attack();
};

class BasicWand : public Item
{
public:
	BasicWand();
	virtual ~BasicWand() {};
	virtual void use();
	virtual void attack();
};

#endif

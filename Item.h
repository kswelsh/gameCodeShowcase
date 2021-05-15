#ifndef __ITEM_H_
#define __ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	string _name;
public:
	Item(string);
	virtual ~Item() {};
	virtual void use() = 0;

	string getItemNameBase() const;
};

class BasicSword : public Item
{
public:
	BasicSword();
	virtual ~BasicSword() {};
	void use();
};

class BasicBow : public Item
{
public:
	BasicBow();
	virtual ~BasicBow() {};
	void use();
};

class BasicWand : public Item
{
public:
	BasicWand();
	virtual ~BasicWand() {};
	void use();
};

#endif

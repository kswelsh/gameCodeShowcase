#include "Player.h"

// PRIVATE METHODS
void Player::displayChoicesPrint(const vector<string> &displayList, const string &headerText) const
{
	int verticleLength;
	int centerCount;

	// center verticle
	verticleLength = (displayList.size() * 2) - 1;
	verticleLength = verticleLength + 3;
	centerCount = (32 - verticleLength) / 2;
	for (int i = 0; i < centerCount; i++)
		cout << endl;

	// display list
	displayText(headerText, false);
	cout << "\n";
	displayText("________________________", false);
	cout << "\n\n";
	for (int i = 0; i < displayList.size(); i++)
	{
		displayText(displayList[i], false);
		if ((i + 1) != displayList.size())
			cout << "\n\n";
		else
			cout << endl;
	}
}

void Player::displayText(string text, bool variation) const
{
	int centerCount;
	string center = "";
	bool error = false;

	if (variation)
	{
		system("CLS");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	// calculations for centering the text
	centerCount = (35 - (text.size() / 2));
	center.resize(centerCount);
	for (int i = 0; i < center.size(); i++)
	{
		center[i] = ' ';
	}

	cout << center;
	if (variation)
	{
		for (int i = 0; i < text.size(); i++)
		{
			cout << text[i];
			Sleep(10);
		}
	}
	else
	{
		cout << text;
	}
}

void Player::parseAndPrintInfo(string& a, string n)
{
	// parse info
	string hold;
	vector<string> parsed;
	stringstream ss(a);
	while (getline(ss, hold, '_'))
		parsed.push_back(hold);

	// set text in front
	parsed[1].insert(0, "Rarity: ");
	parsed[2].insert(0, "Damage: ");
	parsed[3].insert(0, "Healing: ");

	system("CLS");
	displayChoicesPrint(parsed, n);
}

// CONSTRUCTORS
Player::Player()
	:_maxHealth(10), _health(10), _love(0), _name("")
	{}

// METHODS
void Player::displayInventory()
{
	bool value = 0;
	vector<string> inventory;
	int cursorIndex = 0;
	string input;
	string headerText = "Inventory";
	string info;
	bool empty = false;

	// 0 for attack, 1 for use
	vector<int> useOrAttack;

	// adds all items to vector, seperating by attack or use through parallel vector
	for (int i = 0; i < _items.size(); i++)
	{
		value = _items[i]->getIfCanAttack();
		if (value)
		{
			// 0 for attack
			useOrAttack.push_back(!value);
		}
		value = _items[i]->getIfUsable();
		if (value)
		{
			// 1 for use
			useOrAttack.push_back(value);
		}
		inventory.push_back(_items[i]->getItemName());
	}
	system("CLS");

	// checks if inventory is empty
	if (inventory.size() == 0)
		empty = true;
	else
		inventory[0].append(" -");

	displayChoicesPrint(inventory, headerText);

	// accept keyboard input to make choice
	while (input != "q")
	{
		input = "";
		input = _getch();
		
		// move down
		if (input == "s")
		{
			if ((cursorIndex + 1) < inventory.size())
			{
				inventory[cursorIndex].pop_back();
				inventory[cursorIndex].pop_back();
				cursorIndex++;
				inventory[cursorIndex].append(" -");
			}
		}
		// move up
		else if (input == "w")
		{
			if ((cursorIndex - 1) >= 0)
			{
				inventory[cursorIndex].pop_back();
				inventory[cursorIndex].pop_back();
				cursorIndex--;
				inventory[cursorIndex].append(" -");
			}
		}
		// use item
		else if (input == "e")
		{
			if (useOrAttack[cursorIndex] == 1)
			{
				_items[cursorIndex]->use();
			}
			else
			{
				displayText("This item is not useable!", true);
				Sleep(700);
			}
		}
		// info on item
		else if (input == "i")
		{
			string info = _items[cursorIndex]->getInfo();
			parseAndPrintInfo(info, _items[cursorIndex]->getItemName());
			while (input != "q")
			{
				input = _getch();
			}
			input = ".";
		}
		system("CLS");
		displayChoicesPrint(inventory, headerText);
	}
	system("CLS");
}


string Player::handleAttack() const
{
	bool canAttack = false;
	vector<string> attackList;
	int cursorIndex = 0;
	string input;
	string returnValue;
	string headerText = "Choose your attack!";

	// checks what items can attack
	for (int i = 0; i < _items.size(); i++)
	{
		canAttack = _items[i]->getIfCanAttack();
		if (canAttack)
		{
			attackList.push_back(_items[i]->getItemName());
		}
	}
	system("CLS");

	// if no attack possible (somehow) adds in basic attack
	if (attackList.size() <= 0)
	{
		attackList.push_back("Punch -");
		while (input != "e")
		{
			input = "";
			displayChoicesPrint(attackList, headerText);
			input = _getch();
			system("CLS");
			
		}
		returnValue = "physical_0_Your weak punch misses the ";
		return returnValue;
	}
	else
	{
		attackList[0].append(" -");
	}

	displayChoicesPrint(attackList, headerText);

	// accept keyboard input to make choice
	while (input != "e")
	{
		input = "";
		input = _getch();
		system("CLS");

		// move down
		if (input == "s")
		{
			if ((cursorIndex + 1) < attackList.size())
			{
				attackList[cursorIndex].pop_back();
				attackList[cursorIndex].pop_back();
				cursorIndex++;
				attackList[cursorIndex].append(" -");
			}
		}
		// move up
		else if (input == "w")
		{
			if ((cursorIndex - 1) >= 0)
			{
				attackList[cursorIndex].pop_back();
				attackList[cursorIndex].pop_back();
				cursorIndex--;
				attackList[cursorIndex].append(" -");
			}
		}
		// use attack
		else if (input == "e")
		{
			returnValue = _items[cursorIndex]->attack();
		}
		displayChoicesPrint(attackList, headerText);
	}

	system("CLS");
	return returnValue;
}

void Player::addItem(Item* item)
{
	_items.push_back(item);
}
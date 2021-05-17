#include "Player.h"

// PRIVATE METHODS
void Player::displayAttackChoicesPrint(const vector<string> &attackList) const
{
	int verticleLength;
	int centerCount;

	// center verticle
	verticleLength = (attackList.size() * 2) - 1;
	verticleLength = verticleLength + 3;
	centerCount = (32 - verticleLength) / 2;
	for (int i = 0; i < centerCount; i++)
		cout << endl;

	// display attacks
	displayText("Choose your attack!");
	cout << "\n";
	displayText("------------------------");
	cout << "\n\n";
	for (int i = 0; i < attackList.size(); i++)
	{
		displayText(attackList[i]);
		if ((i + 1) != attackList.size())
			cout << "\n\n";
		else
			cout << endl;
	}
}

// CONSTRUCTORS
Player::Player()
	:_maxHealth(10), _health(10), _love(0), _name("")
	{}

// METHODS
void Player::displayText(string text) const
{
	int centerCount;
	string center = "";
	bool error = false;

	// calculations for centering the text
	centerCount = (35 - (text.size() / 2));
	center.resize(centerCount);
	for (int i = 0; i < center.size(); i++)
	{
		center[i] = ' ';
	}

	// printing text in unique fashion
	cout << center;
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i];
	}
}

void Player::displayInventory()
{

}


string Player::handleAttack() const
{
	bool canAttack = false;
	vector<string> attackList;
	int cursorIndex = 0;
	string input;
	string returnValue;

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
			input = _getch();
		}
		returnValue = "slash_0_Your weak punch misses the ";
		return returnValue;
	}
	else
	{
		attackList[0].append(" -");
	}

	displayAttackChoicesPrint(attackList);

	// accept keyboard input to make choice
	while (input != "e")
	{
		input = "";
		input = _getch();
		system("CLS");

		if (input == "s")
		{
			if ((cursorIndex + 1) >= attackList.size())
			{
				displayAttackChoicesPrint(attackList);
			}
			else
			{
				attackList[cursorIndex].pop_back();
				attackList[cursorIndex].pop_back();
				cursorIndex++;
				attackList[cursorIndex].append(" -");
				displayAttackChoicesPrint(attackList);
			}
		}
		else if (input == "w")
		{
			if ((cursorIndex - 1) < 0)
			{
				displayAttackChoicesPrint(attackList);
			}
			else
			{
				attackList[cursorIndex].pop_back();
				attackList[cursorIndex].pop_back();
				cursorIndex--;
				attackList[cursorIndex].append(" -");
				displayAttackChoicesPrint(attackList);
			}
		}
		else if (input == "e")
		{
			attackList[cursorIndex].pop_back();
			attackList[cursorIndex].pop_back();
			for (int i = 0; i < _items.size(); i++)
			{
				if (attackList[cursorIndex] == _items[i]->getItemName())
				{
					returnValue = _items[i]->attack();
				}
			}
		}
		else
		{
			displayAttackChoicesPrint(attackList);
		}
	}
	return returnValue;
}

void Player::addItem(Item* item)
{
	_items.push_back(item);
}
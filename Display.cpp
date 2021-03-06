#include "Display.h"
// PRIVATE METHODS

void Display::displayTimedText(const string& usedText, const bool &wantToCenter, int charSleep, int finalSleep) const
{
	int centerCount;
	string center = "";
	bool error = false;

	// checking max length
	if (usedText.size() > 70)
		error = true;

	// calculations for centering the text
	if (wantToCenter && !error)
	{ 
		centerCount = (35 - (usedText.size() / 2));
		center.resize(centerCount);
		for (int i = 0; i < center.size(); i++)
		{
			center[i] = ' ';
		}
	}

	// printing text in unique fashion
	if (!error)
	{
		cout << center;
		for (int i = 0; i < usedText.size(); i++)
		{
			cout << usedText[i];
			Sleep(charSleep);
		}
		Sleep(finalSleep);
	}
}

void Display::displayChoicesPrint(const vector<string>& displayList, const string& headerText, bool oneLess, int &currentCoin) const
{
	int verticleLength;
	int centerCount;

	// center verticle
	verticleLength = (displayList.size() * 2) - 1;
	verticleLength = verticleLength + 3;
	centerCount = (32 - verticleLength) / 2;

	// for if user just choose item they cannot afford
	if (oneLess)
		centerCount--;

	// print center
	for (int i = 0; i < centerCount; i++)
		cout << endl;

	// display list
	displayTimedText(headerText, true, 0, 0);
	cout << "\n";
	displayTimedText("________________________", true, 0, 0);
	cout << "\n\n";
	for (int i = 0; i < displayList.size(); i++)
	{
		displayTimedText(displayList[i], true, 0, 0);
		if ((i + 1) != displayList.size())
			cout << "\n\n";
		else
			cout << endl;
	}

	// display coin
	cout << "\n\n\n\n\n";
	displayTimedText("Coin: " + to_string(currentCoin), true, 0, 0);
	cout << endl;
}

// METHODS
string Display::displayTextWithChoice(const string &text, const string &question)
{
	string choice;

	cout << "\n\n\n\n\n\n";
	displayTimedText(text, true, 20, 900);
	cout << "\n\n\n\n\n\n";
	cout << "______________________________________________________________________\n\n";
	displayTimedText(question, true, 20, 900);
	choice = _getch();

	return choice;
}

void Display::displayText(const string &text)
{
	if (text.size() <= 70)
	{
		cout << "\n\n\n\n\n\n\n";
		displayTimedText(text, true, 20, 1200);
	}
	else if (text.size() <= 140)
	{
		string newText1;
		string newText2;
		string hold;
		bool space = false;

		for (int i = 0; i < text.size(); i++)
		{
			if (i <= 55)
			{
				hold = text[i];
				newText1.append(hold);
			}
			else if (i > 55)
			{
				if (text[i] == ' ')
				{
					space = true;
				}
					
				if (space == true)
				{
					hold = text[i];
					newText2.append(hold); 
				}
				else
				{
					hold = text[i];
					newText1.append(hold);
				}
			}
		}
		cout << "\n\n\n\n\n\n";
		displayTimedText(newText1, true, 20, 0);
		cout << "\n";
		displayTimedText(newText2, true, 20, 1000);
	}
}

string Display::displayForestChunk(string seed, int sizeOfDisplay)
{
	const int size = 15;
	string* forest[size];
	int chunkSelect;
	bool newSeed = false;
	string hold;

	if (seed.length() != sizeOfDisplay)
	{
		seed = "";
	}
	if (seed == "")
	{
		newSeed = true;
	}

	for (int i = 0; i < size; i++)
	{
		forest[i] = new string("");
	}

	for (int j = 0; j < sizeOfDisplay; j++)
	{
		if (newSeed)
		{
			chunkSelect = rand() % 6;
			seed.append(to_string(chunkSelect));
		}
		else
		{
			hold = "";
			hold += seed[j];
			chunkSelect = stoi(hold);
		}

		if (chunkSelect == 0)
		{
			for (int i = 0; i < 7; i++)
			{
				forest[i]->append("          ");
			}
			forest[7]->append("    ##    ");
			forest[8]->append("   ####   ");
			forest[9]->append("  #####   ");
			forest[10]->append("  ######  ");
			forest[11]->append(" ######## ");
			forest[12]->append("    ||    ");
			forest[13]->append("    ||    ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (chunkSelect == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				forest[i]->append("          ");
			}
			forest[4]->append("    ##    ");
			forest[5]->append("   ####   ");
			forest[6]->append("  #####   ");
			forest[7]->append("  #####   ");
			forest[8]->append("  ######  ");
			forest[9]->append("  ######  ");
			forest[10]->append(" #######  ");
			forest[11]->append(" ######## ");
			forest[12]->append("    ||    ");
			forest[13]->append("    ||    ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (chunkSelect == 2)
		{
			for (int i = 0; i < 12; i++)
			{
				forest[i]->append("          ");
			}
			forest[12]->append("      __  ");
			forest[13]->append("      ||  ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (chunkSelect == 3)
		{
			for (int i = 0; i < 12; i++)
			{
				forest[i]->append("          ");
			}
			forest[12]->append(" __       ");
			forest[13]->append(" ||       ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (chunkSelect == 4)
		{
			for (int i = 0; i < 14; i++)
			{
				forest[i]->append("          ");
			}
			forest[14]->append("@@@@@@@@@@");
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				forest[i]->append("          ");
			}
			forest[6]->append("    #     ");
			forest[7]->append("   ###    ");
			forest[8]->append("   ####   ");
			forest[9]->append("  #####   ");
			forest[10]->append("  ######  ");
			forest[11]->append(" #######  ");
			forest[12]->append("    ||    ");
			forest[13]->append("    ||    ");
			forest[14]->append("@@@@@@@@@@");
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (i == 14)
			cout << *(forest[i]);
		else
			cout << *(forest[i]) << endl;
	}
	cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		delete forest[i];
	}

	return seed;
}

string Display::displayOceanChunk(string seed, int sizeOfDisplay)
{
	const int size = 15;
	string* ocean[size];
	int chunkSelect;
	bool newSeed = false;
	string hold;

	if (seed.length() != sizeOfDisplay)
	{
		seed = "";
	}
	if (seed == "")
	{
		newSeed = true;
	}

	for (int i = 0; i < size; i++)
	{
		ocean[i] = new string("");
	}

	for (int j = 1; j < sizeOfDisplay; j++)
	{
		if (newSeed)
		{
			chunkSelect = rand() % 6;
			seed.append(to_string(chunkSelect));
		}
		else
		{
			hold = "";
			hold += seed[j];
			chunkSelect = stoi(hold);
		}

		if (chunkSelect == 0)
		{
			for (int i = 0; i < 14; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[14]->append("~~~~~~~~~~");
		}
		else if (chunkSelect == 1)
		{
			for (int i = 0; i < 14; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[14]->append("~^~~~^~~~~");
		}
		else if (chunkSelect == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[10]->append("    ~.    ");
			ocean[11]->append("    /|    ");
			ocean[12]->append("   /_|_   ");
			ocean[13]->append(" \\------/ ");
			ocean[14]->append("~~~~~~~~~~");
		}
		else if (chunkSelect == 3)
		{
			for (int i = 0; i < 14; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[14]->append("~^~^~^~^~^");
		}
		else if (chunkSelect == 4)
		{
			for (int i = 0; i < 14; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[14]->append("^~^~^~^~^~");
		}
		else
		{
			for (int i = 0; i < 14; i++)
			{
				ocean[i]->append("          ");
			}
			ocean[14]->append("~^~~~^~~^~");
		}
	}

	// all have sun chunk
	ocean[0]->append("          ");
	ocean[1]->append("    \\|/   ");
	ocean[2]->append("   **O**  ");
	ocean[3]->append("    /|\\   ");
	for (int i = 4; i < 14; i++)
	{
		ocean[i]->append("          ");
	}
	ocean[14]->append("~~~~~~~~~~");
	seed.append("0");

	for (int i = 0; i < size; i++)
	{
		if (i == 14)
			cout << *(ocean[i]);
		else
			cout << *(ocean[i]) << endl;
	}
	cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		delete ocean[i];
	}

	return seed;
}

string Display::displayDesertChunk(string seed, int sizeOfDisplay)
{
	const int size = 15;
	string* desert[size];
	int chunkSelect;
	bool newSeed = false;
	string hold;

	if (seed.length() != sizeOfDisplay)
	{
		seed = "";
	}
	if (seed == "")
	{
		newSeed = true;
	}

	for (int i = 0; i < size; i++)
	{
		desert[i] = new string("");
	}

	// all have sun chunk
	desert[0]->append("          ");
	desert[1]->append("    \\|/   ");
	desert[2]->append("   **O**  ");
	desert[3]->append("    /|\\   ");
	for (int i = 4; i < 10; i++)
	{
		desert[i]->append("          ");
	}
	desert[10]->append("  _$$-    ");
	desert[11]->append("   $$*    ");
	desert[12]->append("  _$$     ");
	desert[13]->append("   $$-    ");
	desert[14]->append("%%%%%%%%%%");
	seed.append("0");

	for (int j = 1; j < sizeOfDisplay; j++)
	{
		if (newSeed)
		{
			chunkSelect = rand() % 6;
			seed.append(to_string(chunkSelect));
		}
		else
		{
			hold = "";
			hold += seed[j];
			chunkSelect = stoi(hold);
		}

		if (chunkSelect == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				desert[i]->append("          ");
			}
			desert[10]->append("     _$$  ");
			desert[11]->append("      $$- ");
			desert[12]->append("     -$$_ ");
			desert[13]->append("     -$$  ");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (chunkSelect == 1)
		{
			for (int i = 0; i < 13; i++)
			{
				desert[i]->append("          ");
			}
			desert[13]->append("     %%%%%");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (chunkSelect == 2)
		{
			for (int i = 0; i < 12; i++)
			{
				desert[i]->append("          ");
			}
			desert[12]->append("      $$- ");
			desert[13]->append("%%%   $$  ");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (chunkSelect == 3)
		{
			for (int i = 0; i < 11; i++)
			{
				desert[i]->append("          ");
			}
			desert[11]->append("  $$-     ");
			desert[12]->append(" _$$*     ");
			desert[13]->append("  $$-     ");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (chunkSelect == 4)
		{
			for (int i = 0; i < 14; i++)
			{
				desert[i]->append("          ");
			}
			desert[14]->append("%%%%%%%%%%");
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				desert[i]->append("          ");
			}
			desert[12]->append("          ");
			desert[13]->append("%%%%%%    ");
			desert[14]->append("%%%%%%%%%%");
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (i == 14)
			cout << *(desert[i]);
		else
			cout << *(desert[i]) << endl;
	}
	cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		delete desert[i];
	}

	return seed;
}

string Display::displayRuinsChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

string Display::displayDarkForestChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

string Display::displayVoidChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

string Display::displayBeachChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

string Display::displayGrasslandChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

string Display::displayFarmChunk(string seed, int sizeOfDisplay)
{
	return seed;
}

int Display::displayAndUseShop(Item* item1, Item* item2, Item* item3, int currentCoin)
{
	vector<Item*> items;
	vector<string> shopList;
	vector<int> parallelCost;
	int cursorIndex = 0;
	string input;
	int choice = -1;
	string headerText = "The Humble Shoppe";

	// push item names and cost to shop list/cost list
	items.push_back(item1);
	items.push_back(item2);
	items.push_back(item3);
	for (int i = 0; i < items.size(); i++)
	{
		shopList.push_back(items[i]->getItemName());
		shopList[i].append(" (");
		shopList[i].append(items[i]->getCostString());
		shopList[i].append(" Coin)");
		parallelCost.push_back(items[i]->getCost());
	}
	shopList[0].append(" -");

	// display shop
	displayChoicesPrint(shopList, headerText, false, currentCoin);

	// accept keyboard input to make choice
	while ((input != "e") && (input != "q"))
	{
		input = "";
		input = _getch();
		system("CLS");

		// move down
		if (input == "s")
		{
			if ((cursorIndex + 1) < shopList.size())
			{
				shopList[cursorIndex].pop_back();
				shopList[cursorIndex].pop_back();
				cursorIndex++;
				shopList[cursorIndex].append(" -");
			}
		}
		// move up
		else if (input == "w")
		{
			if ((cursorIndex - 1) >= 0)
			{
				shopList[cursorIndex].pop_back();
				shopList[cursorIndex].pop_back();
				cursorIndex--;
				shopList[cursorIndex].append(" -");
			}
		}
		// buy item
		else if (input == "e")
		{
			if (currentCoin < items[cursorIndex]->getCost())
			{
				cout << endl;
				displayTimedText("You cannot afford this item!", true, 0, 0);
				input = ".";
			}
			else
			{
				choice = cursorIndex;
			}
		}
		else if (input == "q")
		{
			choice = -1;
		}

		if (input == ".")
			displayChoicesPrint(shopList, headerText, true, currentCoin);
		else
			displayChoicesPrint(shopList, headerText, false, currentCoin);
	}

	system("CLS");
	return choice;
}


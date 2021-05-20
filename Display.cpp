#include "Display.h"
// PRIVATE METHODS

bool Display::displayTimedText(const string& usedText, const bool &wantToCenter)
{
	int centerCount;
	string center = "";
	bool error = false;

	// calculations for centering the text
	if (wantToCenter)
	{ 
		centerCount = (35 - (usedText.size() / 2));
		center.resize(centerCount);
		for (int i = 0; i < center.size(); i++)
		{
			center[i] = ' ';
		}
	}

	// checking max length
	if (usedText.size() > 70)
		error = true;

	// printing text in unique fashion
	if (!error)
	{
		cout << center;
		for (int i = 0; i < usedText.size(); i++)
		{
			cout << usedText[i];
			Sleep(45);
		}
		Sleep(900);
	}
	return error;
}

// CONSTRUCTORS
Display::Display() 
	:_zone(0) 
	{}

// METHODS
string Display::displayTextWithChoice(const string &text, const string &question)
{
	string choice;

	cout << "\n\n\n\n\n\n";
	displayTimedText(text, true);
	cout << "\n\n\n\n\n\n";
	cout << "______________________________________________________________________\n\n";
	displayTimedText(question, true);
	choice = _getch();

	return choice;
}

void Display::displayText(const string &text)
{
	cout << "\n\n\n\n\n\n\n";
	displayTimedText(text, true);
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
#include "Landscape.h"
// PRIVATE METHODS

bool Landscape::displayTimedText(const string& usedText, const bool &wantToCenter)
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
			Sleep(75);
		}
		Sleep(1000);
	}
	return error;
}

// CONSTRUCTORS
Landscape::Landscape() 
	:_zone(0) 
	{}

// METHODS
string Landscape::displayTextWithChoice(const string &text, const string &question)
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

void Landscape::displayText(const string &text)
{
	cout << "\n\n\n\n\n\n\n";
	displayTimedText(text, true);
	cout << "\n\n\n\n\n\n\n";
}

void Landscape::displayForestChunk()
{
	const int size = 15;
	string* forest[size];
	int randomChunk;

	for (int i = 0; i < size; i++)
	{
		forest[i] = new string("");
	}

	for (int j = 0; j < 7; j++)
	{
		randomChunk = rand() % 6;

		if (randomChunk == 0)
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
		else if (randomChunk == 1)
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
		else if (randomChunk == 2)
		{
			for (int i = 0; i < 12; i++)
			{
				forest[i]->append("          ");
			}
			forest[12]->append("      __  ");
			forest[13]->append("      ||  ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (randomChunk == 3)
		{
			for (int i = 0; i < 12; i++)
			{
				forest[i]->append("          ");
			}
			forest[12]->append(" __       ");
			forest[13]->append(" ||       ");
			forest[14]->append("@@@@@@@@@@");
		}
		else if (randomChunk == 4)
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
	Sleep(2500);

	for (int i = 0; i < size; i++)
	{
		delete forest[i];
	}
}

void Landscape::displayOceanChunk()
{

}

void Landscape::displayDesertChunk()
{
	const int size = 15;
	string* desert[size];
	int randomChunk;

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

	for (int j = 0; j < 6; j++)
	{
		randomChunk = rand() % 6;

		if (randomChunk == 0)
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
		else if (randomChunk == 1)
		{
			for (int i = 0; i < 13; i++)
			{
				desert[i]->append("          ");
			}
			desert[13]->append("     %%%%%");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (randomChunk == 2)
		{
			for (int i = 0; i < 12; i++)
			{
				desert[i]->append("          ");
			}
			desert[12]->append("      $$- ");
			desert[13]->append("%%%   $$  ");
			desert[14]->append("%%%%%%%%%%");
		}
		else if (randomChunk == 3)
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
		else if (randomChunk == 4)
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
	Sleep(2500);

	for (int i = 0; i < size; i++)
	{
		delete desert[i];
	}
}

void Landscape::displayRuinsChunk()
{

}

void Landscape::displayDarkForestChunk()
{

}

void Landscape::displayVoidChunk()
{

}

void Landscape::displayBeachChunk()
{

}

void Landscape::displayGrasslandChunk()
{

}

void Landscape::displayFarmChunk()
{

}
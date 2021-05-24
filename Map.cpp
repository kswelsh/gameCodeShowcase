#include "Map.h"

// PRIVATE METHODS
void Map::setLandscapeVar(const int &column, const int &row) 
{
	int zoneNum;
	zoneNum = rand() % 9 + 1;

	if (zoneNum == 1)
		_map[column][row] = "forest";
	else if (zoneNum == 2)
		_map[column][row] = "ocean";
	else if (zoneNum == 3)
		_map[column][row] = "desert";
	else if (zoneNum == 4)
		_map[column][row] = "ruins";
	else if (zoneNum == 5)
		_map[column][row] = "darkForest";
	else if (zoneNum == 6)
		_map[column][row] = "void";
	else if (zoneNum == 7)
		_map[column][row] = "beach";
	else if (zoneNum == 8)
		_map[column][row] = "grassland";
	else 
		_map[column][row] = "farm";	
}

void Map::displayText(string text)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

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
		Sleep(35);
	}
	Sleep(700);
}

void Map::setStart()
{
	int randomStartC;
	randomStartC = rand() % _columnSize;

	int randomStartR;
	randomStartR = rand() % _rowSize;

	_map[randomStartC][randomStartR] = "start";
	_currentColumn = randomStartC;
	_currentRow = randomStartR;
	_beenToColumn.push_back(_currentColumn);
	_beenToRow.push_back(_currentRow);
}

void Map::setEnd()
{
	bool endPlaced = false;

	while (!endPlaced) 
	{
		int randomEndC;
		randomEndC = rand() % _columnSize;

		int randomEndR;
		randomEndR = rand() % _rowSize;

		if (_map[randomEndC][randomEndR] != "start")
		{
			_map[randomEndC][randomEndR] = "end";
			endPlaced = true;
		}
	}
}

void Map::displayMap()
{
	string explored = "%";
	// row column, 1:1 = 1, 1:2 = 2, 1:3 = 3; 1:4 = 4, 2:1 = 5,
	// 2:2 = 6, 2:3 = 7, 2:4 = 8, 3:1 = 9, 3:2 = 10, 3:3 = 11,
	// 3:4 = 12, 4:1 = 13, 4:2 = 14, 4:3 = 15, 4:4 = 16.
	string where[16] = { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#" };

	// find where now and explored
	for (int i = 0; i < _beenToColumn.size(); i++)
	{
		// change to current position if last
		if (i == (_beenToColumn.size() - 1))
			explored = "o";

		// replace array
		if (_beenToRow[i] == 1)
		{
			if (_beenToColumn[i] == 1)
				where[0] = explored;
			else if (_beenToColumn[i] == 2)
				where[1] = explored;
			else if (_beenToColumn[i] == 2)
				where[2] = explored;
			else
				where[3] = explored;
		}
		else if (_beenToRow[i] == 2)
		{
			if (_beenToColumn[i] == 1)
				where[4] = explored;
			else if (_beenToColumn[i] == 2)
				where[5] = explored;
			else if (_beenToColumn[i] == 2)
				where[6] = explored;
			else
				where[7] = explored;
		}
		else if (_beenToRow[i] == 3)
		{
			if (_beenToColumn[i] == 1)
				where[8] = explored;
			else if (_beenToColumn[i] == 2)
				where[9] = explored;
			else if (_beenToColumn[i] == 2)
				where[10] = explored;
			else
				where[11] = explored;
		}
		else
		{
			if (_beenToColumn[i] == 1)
				where[12] = explored;
			else if (_beenToColumn[i] == 2)
				where[13] = explored;
			else if (_beenToColumn[i] == 2)
				where[14] = explored;
			else
				where[15] = explored;
		}
	}

	// print map
	system("CLS");
	cout << endl;
	cout << "          KEY      " << endl;
	cout << "    _______________" << endl;
	cout << "    o = Player     " << endl;
	cout << "    # = Unexplored " << endl;
	cout << "    % = Explored   " << endl << endl << endl;
	cout << "       CONTROLS    " << endl;
	cout << "    _______________" << endl;
	cout << "    W = Move North " << endl;
	cout << "    S = Move South " << endl;
	cout << "    A = Move West  " << endl;
	cout << "    D = Move East  " << endl << endl << endl << endl;
	cout << "                                 MAP " + to_string(_zone) << endl;
	cout << "                     ____________________________" << endl;
	cout << "                     |                          |" << endl;
	cout << "                     |  [" + where[0] + "]   [" + where[1] + "]    [" + where[2] + "]   [" + where[3] + "]  |" << endl;
	cout << "                     |                          |" << endl;        
	cout << "                     |  [" + where[4] + "]   [" + where[5] + "]    [" + where[6] + "]   [" + where[7] + "]  |" << endl;
	cout << "                     |                          |" << endl;
	cout << "                     |  [" + where[8] + "]   [" + where[9] + "]    [" + where[10] + "]   [" + where[11] + "]  |" << endl;
	cout << "                     |                          |" << endl;
	cout << "                     |  [" + where[12] + "]   [" + where[13] + "]    [" + where[14] + "]   [" + where[15] + "]  |" << endl;
	cout << "                     |__________________________|" << endl;
}

// CONSTRUCTORS
Map::Map() 
{
	for (int i = 0; i < _columnSize; i++)
	{
		for (int j = 0; j < _rowSize; j++)
		{
			setLandscapeVar(i, j);
		}
	}
	setStart();
	setEnd();
	_zone = 1;
}

// METHODS

bool Map::move()
{
	string userConfirm = "";
	string userInput;

	displayMap();
	while (userConfirm != "e")
	{
		userInput = "";
		userInput = _getch();
		system("CLS");

		// move down
		if (userInput == "w")
		{
			displayText("Press E to Confirm or any other Key to Cancel!");
			userConfirm = _getch();
		}
		// move up
		else if (userInput == "s")
		{
			displayText("Press E to Confirm or any other Key to Cancel!");
			userConfirm = _getch();
		}
		// use attack
		else if (userInput == "d")
		{
			displayText("Press E to Confirm or any other Key to Cancel!");
			userConfirm = _getch();
		}
		else if (userInput == "a")
		{
			displayText("Press E to Confirm or any other Key to Cancel!");
			userConfirm = _getch();
		}
		system("CLS");
		displayMap();
	}
	return true;
}
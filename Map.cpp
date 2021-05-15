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

void Map::setStart()
{
	int randomStartC;
	randomStartC = rand() % _columnSize;

	int randomStartR;
	randomStartR = rand() % _rowSize;

	_map[randomStartC][randomStartR] = "start";
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
}

// METHODS
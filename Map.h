#ifndef __MAP_H_
#define __MAP_H_

#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Map
{
private:
	static const int _columnSize = 4;
	static const int _rowSize = 4;
	int _currentColumn;
	int _currentRow;
	string _map[_columnSize][_rowSize];
	int _zone;
	vector<int> _beenToColumn;
	vector<int> _beenToRow;
	

	// pre: 1st parm is i variable in loop, 2nd parm is j variable in loop
	// post: map is populated with random area strings
	void setLandscapeVar(const int&, const int&);

	// pre: setLandscapeVar() must have already been called in current scope
	// post: map is populated with a single area "start"
	void setStart();

	// pre: setStart() must have already been called in current scope
	// post: map is populated with a single area "end" that does not replace a "start" area
	void setEnd();

	// pre: none
	// post: displays the map in unique format
	void displayMap();

	// pre: 1st parm is text one wants to display
	// post: text is displayed in unique format
	void displayText(string);
public:
	Map();
	
	// pre: none
	// post: allows the user to move on the map, returns true if they move to postition they have been to, false otherwise
	bool move();

	// pre: none
	// post: returns current row
	int getCurrentRow() const;

	// pre: none
	// post: returns current column
	int getCurrentColumn() const;

	// pre: 1st parm is column, 2nd parm is row
	// post: returns zone at passed in location
	string getZoneType(int, int) const;

	// pre: none
	// post: returns zone type based off values of _currentRow and _currentColumn
	string getZoneTypeCurrent() const;
};

#endif

#ifndef __MAP_H_
#define __MAP_H_

#include <iostream>
#include <time.h>
using namespace std;

class Map
{
private:
	static const int _columnSize = 4;
	static const int _rowSize = 4;
	// Map size has basic size of 4, if changed, must change default constructor.
	string _map[_columnSize][_rowSize];

	// pre: 1st parm is i variable in loop, 2nd parm is j variable in loop
	// post: map is populated with random area strings
	void setLandscapeVar(const int&, const int&);

	// pre: setLandscapeVar() must have already been called in current scope
	// post: map is populated with a single area "start"
	void setStart();

	// pre: setStart() must have already been called in current scope
	// post: map is populated with a single area "end" that does not replace a "start" area
	void setEnd();
public:
	Map();
	
};

#endif

#ifndef __LANDSCAPE_H_
#define __LANDSCAPE_H_

#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

// A CHUNK IS CONSIDERED 10 CHARS LENGTH AND 15 LINES HEIGHT
class Landscape
{
private:
	int _zone;

	// pre: 1st parm is text you want to display, must not be greater than 70 characters
	// post: passed in parm is displayed in timed fashion, if greater than 70 chatacters, returns true
	bool displayTimedText(const string&, const bool&);
public:
	Landscape();

	// pre: 1st parm is text you want to display, 2nd parm is text you want to display for choice
	// post: displays text and asks for user input, user choice is returned
	string displayTextWithChoice(const string&, const string&);

	// pre: 1st parm is text you want to display
	// post: displays text passed in
	void displayText(const string&);

	// pre: none
	// post: 7 chunks of type forest are displayed
	void displayForestChunk();

	// pre: none
	// post: 7 chunks of type ocean are displayed
	void displayOceanChunk();

	// pre: none
	// post: 7 chunks of type desert are displayed
	void displayDesertChunk();

	// pre: none
	// post: 7 chunks of type ruins are displayed
	void displayRuinsChunk();

	// pre: none
	// post: 7 chunks of type dark forest are displayed
	void displayDarkForestChunk();

	// pre: none
	// post: 7 chunks of type void are displayed
	void displayVoidChunk();

	// pre: none
	// post: 7 chunks of type beach are displayed
	void displayBeachChunk();

	// pre: none
	// post: 7 chunks of type grassland are displayed
	void displayGrasslandChunk();

	// pre: none
	// post: 7 chunks of type farm are displayed
	void displayFarmChunk();

};

#endif
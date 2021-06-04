#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
using namespace std;
#include "Item.h"

#pragma comment(lib, "winmm.lib")

// CLASS DISPLAY IS IN CHARGE OF AREA DISPLAY AND
// TEXT DISPLAY, ANY OTHER TYPE OF DISPLAY IS
// HANDLED BY CORRESPONDING OBJECTS
class Display
{
private:
	// pre: 1st parm is text you want to display, must not be greater than 140 characters
	//		2nd parm is if one wants to center, 3rd parm is char sleep, 4th parm is final sleep
	// post: passed in parm is displayed in timed fashion, if greater than 140 chatacters does not display
	void displayTimedText(const string&, const bool&, int, int) const;

	// pre: 1st parm is vector of attack choices that one wants to print, 2nd parm is header text, 3rd parm is true for one less new line
	// post: contents of vector are displayed
	void displayChoicesPrint(const vector<string>&, const string&, bool, int&) const;
public:
	Display() {};

	// pre: 1st parm is text you want to display, 2nd parm is text you want to display for choice
	// post: displays text and asks for user input, user choice is returned
	string displayTextWithChoice(const string&, const string&);

	// pre: 1st parm is text you want to display
	// post: displays text passed in
	void displayText(const string&);

	// pre: 1st parm is seed, if passed in "0" new seed is created, if passed in seed of size wanted
	//		corresponding seed is created, otherwise, new seed is created
	//		2nd parm is the size of seed you want to created
	// post: size chunks of type ~methodName~ are displayed based on seed/new seed
	//		 if passed in seed is not possible, new seed is created
	string displayForestChunk(string, int);
	string displayOceanChunk(string, int);
	string displayDesertChunk(string, int);
	string displayRuinsChunk(string, int);
	string displayDarkForestChunk(string, int);
	string displayVoidChunk(string, int);
	string displayBeachChunk(string, int);
	string displayGrasslandChunk(string, int);
	string displayFarmChunk(string, int);

	// pre: 1st-3rd parm are items one wants in shop, 4th parm is player current currency
	// post: player choice (0,1,2) is returned if item is bought, corresponding to parms, -1 is returned if no item bought
	int displayAndUseShop(Item*, Item*, Item*, int);
};

#endif

#include <iostream>
#include <Windows.h>
using namespace std;
#include "Player.h"
#include "Map.h"
#include "Display.h"
#include "Enemy.h"

void refreshConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 595, 565, TRUE);
    system("CLS");
}

void gameSetup()
{
    refreshConsole();
    SetConsoleTitle(TEXT("Game"));
    srand(time(NULL));
}

int main()
{
    gameSetup();

    string seed = "";
    Display display;
    LesserGoblin enemy;

    seed = display.displayForestChunk(seed, 7);
    display.displayText("A Lesser Goblin approaches you!");
    refreshConsole();

    seed = display.displayForestChunk(seed, 7);
    display.displayTextWithChoice("Would you like to attempt to fight it?", "Click 'Y' for YES or 'N' for NO");
    refreshConsole();
    
    seed = display.displayForestChunk(seed, 7);
    enemy.takeDamage("slash", 1);
    refreshConsole();

    seed = display.displayForestChunk(seed, 7);
    enemy.attack();
    refreshConsole();

    seed = display.displayForestChunk(seed, 7);
    enemy.takeDamage("slash", 2);
    refreshConsole();

    seed = "";
    seed = display.displayDesertChunk(seed, 7);
    display.displayText("You arrive at a new nearby desert!");
    refreshConsole();

    seed = display.displayDesertChunk(seed, 7);
    display.displayTextWithChoice("Would you like to rest for a bit?", "Click 'Y' for YES or 'N' for NO");
}
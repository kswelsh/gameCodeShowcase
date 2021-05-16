#include <iostream>
#include <Windows.h>
using namespace std;
#include "Player.h"
#include "Map.h"
#include "Landscape.h"
#include "Enemy.h"

void refreshConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 600, 300, TRUE);
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

    Landscape display;
    LesserGoblin enemy;
    display.displayText("You are approached by a Lesser Goblin!");
    refreshConsole();
    display.displayTextWithChoice("Would you like to attempt to fight it?", "Click 'Y' for YES or 'N' for NO");
    refreshConsole();
    enemy.takeDamage("slash", 1);
    refreshConsole();
    enemy.attack();
    refreshConsole();
    enemy.takeDamage("slash", 2);
    refreshConsole();
    display.displayText("You arrive at a nearby forest!");
    refreshConsole();
    display.displayForestChunk();
    refreshConsole();
    display.displayTextWithChoice("Would you like to rest for a bit?", "Click 'Y' for YES or 'N' for NO");
}
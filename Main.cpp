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

    Landscape landscape;
    landscape.displayDesertChunk();
    refreshConsole();
    string n = landscape.displayTextWithChoice("hey", "Did you want to do that?");
    refreshConsole();
}
#include <iostream>
#include <Windows.h>
using namespace std;
#include "Player.h"
#include "Map.h"
#include "Display.h"
#include "Enemy.h"


// pre: none
// post: console is refreshed and set back to required size
void refreshConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 595, 565, TRUE);
    system("CLS");
}

// pre: none
// post: random set up and console set up
void gameSetup()
{
    refreshConsole();
    SetConsoleTitle(TEXT("Game"));
    srand(time(NULL));
}

// pre: 1st parm is base attackValue _ delimited, 2nd parm is attackValue var
//      3rd parm is attackType var, 4th parm is attackText flavortext
//      5th parm is enemy one is fighting (for flavor text)
// post: attack value, type, and text are set to correct values
void handlePlayerAttack(const string &a, int &v, string &t, string &f, Enemy &e)
{
    int i = 0;
    string hold;

    // clear vars
    v = 0;
    t.clear();
    f.clear();

    // split and append
    while (a[i] != '_')
    {
        t.push_back(a[i]);
        i++;
    }
    i++;
    while (a[i] != '_')
    {
        hold.push_back(a[i]);
        i++;
    }
    v = stoi(hold);
    i++;
    while (i < a.size())
    {
        f.push_back(a[i]);
        i++;
    }
    f.append(e.getEnemyName() + "!");
}

int main()
{
    gameSetup();

    string playerAttack;
    int attackValue = 0;
    string attackType;
    string attackText;

    string seed = "";

    Display display;
    LesserGoblin enemy;
    Player player;
    
    Sword* basicSword = new Sword();
    Bow* basicBow = new Bow();
    Wand* basicWand = new Wand();
    player.addItem(basicSword);
    player.addItem(basicBow);
    player.addItem(basicWand);

    player.displayInventory();


    seed = display.displayForestChunk(seed, 7);
    display.displayText("A Lesser Goblin approaches you!");
    refreshConsole();
    
    // current attack code for player
    playerAttack = player.handleAttack();
    handlePlayerAttack(playerAttack, attackValue, attackType, attackText, enemy);
    seed = display.displayForestChunk(seed, 7);
    display.displayText(attackText);
    refreshConsole();
    seed = display.displayForestChunk(seed, 7);
    enemy.takeDamage(attackType, attackValue);
    refreshConsole();

    // current attack code for enemy
    seed = display.displayForestChunk(seed, 7);
    enemy.attack();
    refreshConsole();

    // cycle attack
    playerAttack = player.handleAttack();
    handlePlayerAttack(playerAttack, attackValue, attackType, attackText, enemy);
    seed = display.displayForestChunk(seed, 7);
    display.displayText(attackText);
    refreshConsole();
    seed = display.displayForestChunk(seed, 7);
    enemy.takeDamage(attackType, attackValue);
    refreshConsole();

    // display new area
    seed = "";
    seed = display.displayDesertChunk(seed, 7);
    display.displayText("You arrive at a new nearby desert!");
    refreshConsole();

    seed = display.displayDesertChunk(seed, 7);
    display.displayTextWithChoice("Would you like to rest for a bit?", "Click 'Y' for YES or 'N' for NO");
}
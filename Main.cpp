#include <iostream>
#include <Windows.h>
#include <sstream>
using namespace std;
#include "Player.h"
#include "Map.h"
#include "Display.h"
#include "Enemy.h"

#pragma comment(lib, "winmm.lib")

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
void handlePlayerAttack(string &a, int &v, string &t, string &f, Enemy &e)
{
    string hold;

    // clear vars
    v = 0;
    t.clear();
    f.clear();

    // split
    vector<string> parsed;
    stringstream ss(a);
    while (getline(ss, hold, '_'))
        parsed.push_back(hold);

    // change vars
    t = parsed[0];
    v = stoi(parsed[1]);
    f = parsed[2];
    f.append(e.getEnemyName() + "!");
}

int main()
{
    gameSetup();

    // initilization
    string playerAttack;
    int attackValue = 0;
    string attackType;
    string attackText;
    bool visited = false;
    string seed = "";
    Display display;
    Player player;
    Map map1;
    int shopChoice = -1;

    // enemy creation
    Enemy enemy("Lesser Goblin", 1, 3, 0.00, 0.00, 0.00);
    enemy.addAttack("The Lesser Goblin punches you in the face!", 1);
    enemy.addAttack("The Lesser Goblin stabs you in the arm!", 2);
    enemy.addAttack("The Lesser Goblin bites your face!", 1);
    enemy.addAttack("The Lesser Goblin attempts to bite you but misses!", 0);
    
    // item creation
    Sword* basicSword = new Sword("Basic Sword", false, true, -1, 1, "Just a Basic Sword._Common_1-2" \
        "_Non-Healing_Said to be the strongest sword in the land, by beginners...", 1);
    Bow* basicBow = new Bow("Basic Bow", false, true, -1, 3, "Just a Basic Bow._Common_0-3" \
        "_Non-Healing_Your aim must be good.", 1);
    Wand* basicWand = new Wand("Basic Wand", false, true, -1, 5, "Just a Basic Wand._Common_5-7" \
        "_Non-Healing_Chances are you don't know how to use it.", 2);
    HealthPotion* lesserHealthPotion = new HealthPotion("Lesser Health Potion", true, false, 1, 1, "Just a Lesser Health Potion._Common_Non-Damaging_" \
        "1_Really doesn't do all too much.", 2);
    Book* lovePoem = new Book("Love Poem", true, false, 1, 1, "Just a love poem._Common_Non-Damaging_1_I love you.", 2);
    player.addItem(basicSword);
    player.addItem(basicBow);
    player.addItem(basicWand);
    player.addItem(lovePoem);
    player.addItem(lesserHealthPotion);

    PlaySound(TEXT("shopSoundtrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    // current code for shop
    shopChoice = display.displayAndUseShop(basicSword, basicBow, lesserHealthPotion, player.getCurrency());
    if (shopChoice == 0)
    {
        player.subtractCurrency(basicSword->getCost());
        player.addItem(basicSword);
    }
    else if (shopChoice == 1)
    {
        player.subtractCurrency(basicBow->getCost());
        player.addItem(basicBow);
    }
    else if (shopChoice == 2)
    {
        player.subtractCurrency(lesserHealthPotion->getCost());
        player.addItem(lesserHealthPotion);
    }

    // music and sound
    PlaySound(TEXT("darkSoundtrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    
    // current code for map movement
    visited = map1.move();
    visited = map1.move();

    // current code for inventory
    player.displayInventory();

    // test display
    seed = display.displayOceanChunk(seed, 7);
    refreshConsole();

    // music and sound
    PlaySound(TEXT("forestSoundTrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    // current code for display with text
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

    // display question
    seed = display.displayDesertChunk(seed, 7);
    display.displayTextWithChoice("Would you like to rest for a bit?", "Click 'Y' for YES or 'N' for NO");
}

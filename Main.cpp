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

// pre: 1st parm is vector one wants to get random Item* from
// post: returns random Item*
Item* getRandomItem(vector<Item*>& itemVector)
{
    int random = rand() % itemVector.size();
    return itemVector[random];
}

// pre: 1st parm is display, 2nd parm is player, 3rd parm is item pool
// post: if item bought, it is added to player inventory and currency is reduced
//       otherwise nothing happens
void handleShop(Display* d, Player* p, vector<Item*> &itemVector)
{
    PlaySound(TEXT("shopSoundtrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    int shopChoice = -1;
    Item* item1 = getRandomItem(itemVector);
    Item* item2 = getRandomItem(itemVector);
    Item* item3 = getRandomItem(itemVector);

    shopChoice = d->displayAndUseShop(item1, item2, item3, p->getCurrency());
    if (shopChoice == 0)
    {
        p->subtractCurrency(item1->getCost());
        p->addItem(item1);
    }
    else if (shopChoice == 1)
    {
        p->subtractCurrency(item2->getCost());
        p->addItem(item1);
    }
    else if (shopChoice == 2)
    {
        p->subtractCurrency(item3->getCost());
        p->addItem(item1);
    }

}

// pre: 1st parm is vector of item pointers to hold items, 2nd parm is size wanted
// post: vector is filled with Item*'s
void fillZoneOneItems(vector<Item*> &zoneOneItems, int itemVectorSize)
{
    for (int i = 0; i < itemVectorSize; i++)
    {
        int randomItem = rand() % 12;

        if (randomItem == 0)
        {
            Sword* basicSword = new Sword("Basic Sword", false, true, -1, 1, "Just a basic sword._Common_1" \
                "_Non-Healing_At least it is trustworthy.", 1);
            zoneOneItems.push_back(basicSword);
        }
        else if (randomItem == 1)
        {
            Bow* basicBow = new Bow("Basic Bow", false, true, -1, 2, "Just a basic bow._Common_0-3" \
                "_Non-Healing_You'll need good aim to make this bow work.", 2);
            zoneOneItems.push_back(basicBow);
        }
        else if (randomItem == 2)
        {
            Wand* basicWand = new Wand("Basic Wand", false, true, -1, 1, "Just a basic wand._Common_0-5" \
                "_Non-Healing_Chances are you don't know how to use it.", 3);
            zoneOneItems.push_back(basicWand);
        }
        else if (randomItem == 3)
        {
            HealthPotion* randomHeal = new HealthPotion("Random Healing Mixture", true, false, 1, 1, "Just a mixture of items that may heal you._Common_Non-Damaging_" \
                "1_Could give you a little boost.", 1);
            zoneOneItems.push_back(randomHeal);
        }
        else if (randomItem == 4)
        {
            Book* lovePoem = new Book("Sonnet 116", true, false, 1, 1, "Could make you feel a bit better._Common_Non-Damaging_1_A classic.", 2);
            zoneOneItems.push_back(lovePoem);
        }
        else if (randomItem == 5)
        {
            ArmorPotion* beerCan = new ArmorPotion("Can of Beer", true, false, 1, 1, "Could make you stronger._Common_Non-Damaging_Non-Healing_" \
                "A nice cold can of PBR.", 3);
            zoneOneItems.push_back(beerCan);
        }
        else if (randomItem == 6)
        {
            Dagger* basicDagger = new Dagger("Basic Dagger", false, true, -1, 2, "Just a basic dagger._Common_1-2_Non-Healing_Consistent.", 2);
            zoneOneItems.push_back(basicDagger);
        }
        else if (randomItem == 7)
        {
            Sword* basicSword = new Sword("Fencing Sword", false, true, -1, 2, "Not good, but better than a basic sword._Common_1-2" \
                "_Non-Healing_Pointy.", 2);
            zoneOneItems.push_back(basicSword);
        }
        else if (randomItem == 8)
        {
            Bow* basicBow = new Bow("Cedarwood Bow", false, true, -1, 3, "Just a little more consistent._Uncommon_0-3" \
                "_Non-Healing_Has a nice clear coat on it.", 3);
            zoneOneItems.push_back(basicBow);
        }
        else if (randomItem == 9)
        {
            HealthPotion* lesserHealthPotion = new HealthPotion("Lesser Health Potion", true, false, 1, 2, "Heals a bit more._Common_Non-Damaging_" \
                "2_Has a funny taste.", 2);
            zoneOneItems.push_back(lesserHealthPotion);
        }
        else if (randomItem == 10)
        {
            HealthPotion* healthPotion = new HealthPotion("Health Potion", true, false, 1, 3, "Heals pretty well._Uncommon_Non-Damaging_" \
                "1_Tastes a bit like strawberries.", 3);
            zoneOneItems.push_back(healthPotion);
        }
        else
        {
            Dagger* vinniesDagger = new Dagger("Vinnie's Dagger", false, true, -1, 3, "Pretty consistent._Rare_2-4_Non_Healing_Used to be in the Sewers.", 6);
            zoneOneItems.push_back(vinniesDagger);
        }
    }
}

// pre: 1st parm is vector of item pointers to hold items, 2nd parm is size wanted
// post: vector is filled with Item*'s
void fillZoneTwoItems(vector<Item*>& zoneTwoItems, int itemVectorSize)
{
    for (int i = 0; i < itemVectorSize; i++)
    {
        int randomItem = rand() % 12;

        if (randomItem == 0)
        {
            Sword* greatSword = new Sword("Great Sword", false, true, -1, 3, "A bit stronger than a basic sword._Common_1-3" \
                "_Non-Healing_Four feet in length.", 2);
            zoneTwoItems.push_back(greatSword);
        }
        else if (randomItem == 1)
        {
            Bow* greatBow = new Bow("Basic Bow", false, true, -1, 4, "A bit stronger than a basic bow._Common_0-6" \
                "_Non-Healing_The arrows come out pretty quick.", 4);
            zoneTwoItems.push_back(greatBow);
        }
        else if (randomItem == 2)
        {
            Wand* greaterWand = new Wand("Greater Wand", false, true, -1, 4, "A bit stronger than a basic wand._Common_0-6" \
                "_Non-Healing_Much easier to use.", 4);
            zoneTwoItems.push_back(greaterWand);
        }
        else if (randomItem == 3)
        {
            HealthPotion* randomHeal = new HealthPotion("Random Healing Mixture", true, false, 1, 1, "Just a mixture of items that may heal you._Common_Non-Damaging_" \
                "1_Could give you a little boost.", 1);
            zoneTwoItems.push_back(randomHeal);
        }
        else if (randomItem == 4)
        {
            Book* lovePoem = new Book("Sun Goes Down", true, false, 1, 1, "Could make you feel a bit better._Common_Non-Damaging_2_Really a song.", 3);
            zoneTwoItems.push_back(lovePoem);
        }
        else if (randomItem == 5)
        {
            ArmorPotion* wine = new ArmorPotion("Bottle of Wine", true, false, 1, 2, "Could make you stronger._Common_Non-Damaging_Non-Healing_" \
                "A decent bottle of wine.", 5);
            zoneTwoItems.push_back(wine);
        }
        else if (randomItem == 6)
        {
            Dagger* poisenDagger = new Dagger("Poisen Dagger", false, true, -1, 3, "Just a basic dagger._Uncommon_2-4_Non-Healing_The poisen doesn't seem to work.", 4);
            zoneTwoItems.push_back(poisenDagger);
        }
        else if (randomItem == 7)
        {
            Sword* lordsBlade = new Sword("Lords Blade", false, true, -1, 6, "Fairly strong._Uncommon_3-6" \
                "_Non-Healing_Pointy.", 5);
            zoneTwoItems.push_back(lordsBlade);
        }
        else if (randomItem == 8)
        {
            Bow* recurveBow = new Bow("Recurve Bow", false, true, -1, 6, "Fairly strong._Uncommon_0-9" \
                "_Non-Healing_Made out of fine metal.", 6);
            zoneTwoItems.push_back(recurveBow);
        }
        else if (randomItem == 9)
        {
            HealthPotion* healthElixir = new HealthPotion("Health Elixir", true, false, 1, 4, "Heals quite a bit._Rare_Non-Damaging_" \
                "4_A taste that is hard to pin down.", 4);
            zoneTwoItems.push_back(healthElixir);
        }
        else if (randomItem == 10)
        {
            HealthPotion* healthPotion = new HealthPotion("Health Potion", true, false, 1, 3, "Heals pretty well._Uncommon_Non-Damaging_" \
                "1_Tastes a bit like strawberries.", 3);
            zoneTwoItems.push_back(healthPotion);
        }
        else
        {
            int epicCheck = rand() % 2;

            if (epicCheck = 0)
            {
                HealthPotion* medicsBlood = new HealthPotion("Medics Blood", true, false, 1, 7, "Heals a ton._Epic_Non-Damaging_" \
                    "4_A taste that is hard to get used to.", 7);
                zoneTwoItems.push_back(medicsBlood);
            }
            else
            {
                HealthPotion* healthElixir = new HealthPotion("Health Elixir", true, false, 1, 4, "Heals quite a bit._Rare_Non-Damaging_" \
                    "4_A taste that is hard to pin down.", 4);
                zoneTwoItems.push_back(healthElixir);
            }
        }
    }
}

// pre: 1st parm is vector of item pointers to hold items, 2nd parm is size wanted
// post: vector is filled with Item*'s
void fillZoneThreeItems(vector<Item*>& zoneThreeItems, int itemVectorSize)
{
    for (int i = 0; i < itemVectorSize; i++)
    {
        int randomItem = rand() % 12;

        if (randomItem == 0)
        {
            HealthPotion* healthElixir = new HealthPotion("Health Elixir", true, false, 1, 4, "Heals quite a bit._Rare_Non-Damaging_" \
                "4_A taste that is hard to pin down.", 4);
            zoneThreeItems.push_back(healthElixir);
        }
        else if (randomItem == 1)
        {
            Bow* greatBow = new Bow("Basic Bow", false, true, -1, 4, "A bit stronger than a basic bow._Common_0-6" \
                "_Non-Healing_The arrows come out pretty quick.", 4);
            zoneThreeItems.push_back(greatBow);
        }
        else if (randomItem == 2)
        {
            Book* lovePoem = new Book("Sonnet 116 (Revised)", true, false, 1, 5, "A much better version._Common_Non-Damaging_1_Revamp of a classic.", 5);
            zoneThreeItems.push_back(lovePoem);
        }
        else if (randomItem == 3)
        {
            HealthPotion* randomHeal = new HealthPotion("Random Healing Mixture", true, false, 1, 1, "Just a mixture of items that may heal you._Common_Non-Damaging_" \
                "1_Could give you a little boost.", 1);
            zoneThreeItems.push_back(randomHeal);
        }
        else if (randomItem == 4)
        {
            Book* lovePoem = new Book("Sonnet 116", true, false, 1, 1, "Could make you feel a bit better._Common_Non-Damaging_1_A classic.", 2);
            zoneThreeItems.push_back(lovePoem);
        }
        else if (randomItem == 5)
        {
            ArmorPotion* strengthPotion = new ArmorPotion("Strength Potion", true, false, 1, 4, "Will make you stronger._Uncommon_Non-Damaging_Non-Healing_" \
                "Strength is needed.", 3);
            zoneThreeItems.push_back(strengthPotion);
        }
        else if (randomItem == 6)
        {
            Dagger* roguesDagger = new Dagger("Rogues Dagger", false, true, -1, 6, "Extremely consistent._Uncommon_3-6_Non-Healing_Used by the lands best assassins.", 7);
            zoneThreeItems.push_back(roguesDagger);
        }
        else if (randomItem == 7)
        {
            int legendaryCheck = rand() % 3;

            if (legendaryCheck == 0)
            {
                Sword* basicSword = new Sword("Nihilirs Demise", false, true, -1, 8, "Extremely powerful._Legendary_4-8" \
                    "_Non-Healing_Said to have slain many leaders.", 11);
                zoneThreeItems.push_back(basicSword);
            }
            else
            {
                Sword* lordsBlade = new Sword("Lords Blade", false, true, -1, 6, "Fairly strong._Uncommon_3-6" \
                    "_Non-Healing_Pointy.", 5);
                zoneThreeItems.push_back(lordsBlade);
            }
        }
        else if (randomItem == 8)
        {
            int epicCheck = rand() % 2;

            if (epicCheck == 0)
            {
                Wand* unspokenWand = new Wand("Unspoken Wand", false, true, -1, 7, "Extremely powerful._Epic_0-11" \
                    "_Non-Healing_Death is near.", 9);
                zoneThreeItems.push_back(unspokenWand);
            }
            else
            {
                Bow* recurveBow = new Bow("Recurve Bow", false, true, -1, 6, "Fairly strong._Uncommon_0-9" \
                    "_Non-Healing_Made out of fine metal.", 6);
                zoneThreeItems.push_back(recurveBow);
            }
        }
        else if (randomItem == 9)
        {
            HealthPotion* lesserHealthPotion = new HealthPotion("Lesser Health Potion", true, false, 1, 2, "Heals a bit more._Common_Non-Damaging_" \
                "2_Has a funny taste.", 2);
            zoneThreeItems.push_back(lesserHealthPotion);
        }
        else if (randomItem == 10)
        {
            HealthPotion* healthPotion = new HealthPotion("Health Potion", true, false, 1, 3, "Heals pretty well._Uncommon_Non-Damaging_" \
                "1_Tastes a bit like strawberries.", 3);
            zoneThreeItems.push_back(healthPotion);
        }
        else
        {
            HealthPotion* healthElixir = new HealthPotion("Health Elixir", true, false, 1, 4, "Heals quite a bit._Rare_Non-Damaging_" \
                "4_A taste that is hard to pin down.", 4);
            zoneThreeItems.push_back(healthElixir);
        }
    }
}

// pre: 1st parm is display, 2nd parm is value for story (to listen or not)
// post: story is played based on user choice
void initialStory(Display &d, bool &listenStory)
{
    string input;
    string seed = "0";

    // ask user choice
    d.displayText("Would you like to listen to the story?");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    d.displayText("Press 'e' to listen, any other key to skip.");
    input = _getch();
    refreshConsole();

    // set user choice
    if (input == "e")
        listenStory = true;
    else
        listenStory = false;
    
    // play story if user wants story
    if (listenStory)
    {
        PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        seed = d.displayForestChunk(seed, 7);
        d.displayText("*Ring ring*... *ring ring*...");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("Hello, can you hear me?");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("Hey, yeah, it's me... I need you to come to me.");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("No, I can't pick you up, I sent you the directions on your phone.");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("What do you mean you're a long ways out?");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("Well that doesn't matter, get here fast, there is a girl who wants you here.");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("Really, the first thing you ask is her name? Names don't matter anyway.");
        refreshConsole();

        seed = d.displayForestChunk(seed, 7);
        d.displayText("Just follow the path, I'll call you in a bit.");
        refreshConsole();
    }
}

int main()
{
    gameSetup();

    // initilization
    Display* display = new Display();
    Player* player = new Player();
    Map* map1 = new Map();

    string playerAttack;
    string attackType;
    string attackText;
    string seed = "";

    int attackValue = 0;
    int itemVectorSize = 20;
    bool visited = false;
    bool listenStory = false;

    vector<Item*> zoneOneItems;
    vector<Item*> zoneTwoItems;
    vector<Item*> zoneThreeItems;
    vector<Item*> zoneFourItems;

    // start game
    initialStory(*display, listenStory);
    fillZoneOneItems(zoneOneItems, itemVectorSize);

    // enemy creation
    Enemy enemy("Lesser Goblin", 1, 3, 0.00, 0.00, 0.00);
    enemy.addAttack("The Lesser Goblin punches you in the face!", 1);
    enemy.addAttack("The Lesser Goblin stabs you in the arm!", 2);
    enemy.addAttack("The Lesser Goblin bites your face!", 1);
    enemy.addAttack("The Lesser Goblin attempts to bite you but misses!", 0);
    
    player->addItem(getRandomItem(zoneOneItems));
    player->addItem(getRandomItem(zoneOneItems));
    player->addItem(getRandomItem(zoneOneItems));
    player->addItem(getRandomItem(zoneOneItems));
    player->addItem(getRandomItem(zoneOneItems));

    handleShop(display, player, zoneOneItems);

    // music and sound
    PlaySound(TEXT("darkSoundtrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    
    // current code for map movement
    visited = map1->move();
    visited = map1->move();

    // current code for inventory
    player->displayInventory();

    // test display
    seed = display->displayOceanChunk(seed, 7);
    refreshConsole();

    // music and sound
    PlaySound(TEXT("forestSoundTrack.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    // current code for display with text
    seed = display->displayForestChunk(seed, 7);
    display->displayText("A Lesser Goblin approaches you!");
    refreshConsole();
    
    // current attack code for player
    playerAttack = player->handleAttack();
    handlePlayerAttack(playerAttack, attackValue, attackType, attackText, enemy);
    seed = display->displayForestChunk(seed, 7);
    display->displayText(attackText);
    refreshConsole();
    seed = display->displayForestChunk(seed, 7);
    enemy.takeDamage(attackType, attackValue);
    refreshConsole();

    // current attack code for enemy
    seed = display->displayForestChunk(seed, 7);
    enemy.attack();
    refreshConsole();

    // cycle attack
    playerAttack = player->handleAttack();
    handlePlayerAttack(playerAttack, attackValue, attackType, attackText, enemy);
    seed = display->displayForestChunk(seed, 7);
    display->displayText(attackText);
    refreshConsole();
    seed = display->displayForestChunk(seed, 7);
    enemy.takeDamage(attackType, attackValue);
    refreshConsole();

    // display new area
    seed = "";
    seed = display->displayDesertChunk(seed, 7);
    display->displayText("You arrive at a new nearby desert!");
    refreshConsole();

    // display question
    seed = display->displayDesertChunk(seed, 7);
    display->displayTextWithChoice("Would you like to rest for a bit?", "Click 'Y' for YES or 'N' for NO");

    for (int i = 0; i < zoneOneItems.size(); i++)
    {
        delete zoneOneItems[i];
        delete zoneTwoItems[i];
        delete zoneThreeItems[i];
        delete zoneFourItems[i];
    }
}

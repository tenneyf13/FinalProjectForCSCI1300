#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include<cstdlib>
//for random numbers library.
using namespace std;
#include "Trainer.h"
/*Join the world of discovering new dragons by exploring a new land! You will experience being a trainer, 
by moving around this new land collecting, fighting dragons. You win the game by collecting 15 dragons or acquiring 400 points. 
During battle your dragon may lose health points, there are elixirs scattered through out the land. 
Each elixir is worth 1 point and will health your dragon. Some dragons will need more than one elixir to fully heal. 
There are 3 chests and if all three are collected you get +20 bonus points. 

-Map and wild dragon array set from start. 
P = plain d = wild dragon e = elixir c = chest
25 wild dragons, 40 single elixirs, 3 chest containing 5 elixirs.
-wild dragon start with index 0 and move up index after each battle. 
Read in file to set wild dragon array. 
-Active dragon array holds the trainers dragons. 
- fight
Each dragon has hp attack name and attack strength.
depending on hp, dragon with lowest hp goes first, if equal wild dragon gets first hit. 
during battle menu shows attack names but attack strength num is hidden.
hp goes down by the num of attack strength of opposing dragon.
e.g. 
dragon 1 has an attack tailcrush which is strength 5 and dragon 2 has hp of 25.
when dragon 1 attacks dragon 2 result will be dragon 2 with hp 20. 
can use max of 3 dragons per battle. 
when wild dragon's hp is zero automatically capture then restored to full health.
trainer choses the dragon they want during battle.

write to a file player name and score.

add ons if there is time, add type to dragons which will effect the strenght of attacks depending on which types are in battle.
crystal cave when found will fully heal all dragons in trainers dragon arr. 
swamp of despair when found first three dragons in trainers dragon arr lose half of their health. 
 */
class DragonGame
{
    public:
        DragonGame();
        void gameMenu(int); 
        void createMap(string file);
        void printMap();
        void setName();
        void loadDragons(string file);
        void move();
        void printDragons();
        void printpoints();
        void printelixirs();
        void analyzePosition();
        void printUserPosition();
        int selectDragon(); 
      //  Dragon findDragon(string);
        void healDragon();
        void fightWildDragon(Dragon* , Dragon* , int , bool );
        void fightMenu();
        int fightAttackMenu(int dragonIndex);
        bool whoGoesFirst(int indexOfDragonSelected);
        bool checkHpAndDragonsUsedInBattle(int); 
        bool movenorth(int spaces);
        bool moveeast(int spaces);
        bool movesouth(int spaces);
        bool movewest(int spaces);
        bool canTrainerFightWildDragon();
        bool checkIfDragonHasHpZero(int );
        void finalscores();
        bool winner();
    private:
        char mapArr[25][16];
        Dragon WildDragonArr[25];
        int numDragons;
        Dragon TrainersDragonArr[25];
        Trainer user;
        int numWildDragon;
        int numDragonsUsedInBattle;
        int numPoints;
        
    
        
};


 
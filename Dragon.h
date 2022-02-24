#ifndef DRAGON
#define DRAGON
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Dragon
{
    public:
        Dragon();
        int healDragon(int potion);
        void setDragon(string name, string name1, string name2, string name3, string name4, int HP, int attack1, int attack2, int attack3, int attack4 );
        void setHp(int hp);
        int getHp();
        void printHp();
        void printDragonName();
        string getDragonName();
        //void setAttackArr(int attack1, int attack2, int attack3, int attack4);
        //A feature may be added later so users can create and add a new dragon
        //void setNameAttackArr(string name1, string name2, string name3, string name4);
        //A feature may be added later so users can create and add a new dragon
        void getAttackName(int index);
        int getAttackStrength(int index);
        
    private:
        int startingHP; 
        int HP;
        int attackArr[4];
        string nameAttackArr[4];
        string name;
};
#endif


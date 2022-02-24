#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Dragon.h"

class Trainer
{
    public:
        Trainer();
        void setplayer(string username);
        string getPlayerName();
        int getNumElixirs();
        void updateNumElixirs();
        //This is updates when a elixir is found on the map. 
        void updateElixirs(int elixir);
        //This is due to healing dragons
        void foundChest();
        int getPositionX();
        int getPositionY();
        bool setPositionX(int x);
        bool setPositionY(int y);
         
        
    private:
        string playerName; 
        int numElixirs;
        int trainerx;
        int trainery;
       
};


 

 #include "Trainer.h"
 Trainer::Trainer()
 {
     playerName = ""; 
     numElixirs = 0 ;
     trainerx = 0;
     trainery = 0;
 }
void Trainer::setplayer(string username)
{
   playerName = username;    
}
string Trainer::getPlayerName()
{
   return playerName; 
}
int Trainer::getNumElixirs()
{
   return numElixirs; 
}
void Trainer::updateNumElixirs()
{
     numElixirs++;
}

void Trainer::updateElixirs(int elixir)
{
     numElixirs = elixir; 
}

void Trainer::foundChest()
{
     numElixirs = numElixirs + 3; 
}
int Trainer::getPositionX()
{
    return trainerx;
}
int Trainer::getPositionY()
{
    return trainery; 
}
bool Trainer::setPositionX(int x)
{
    trainerx = x;
    return true;
}
bool Trainer::setPositionY(int y)
{
   trainery = y;
   return true; 
}

 
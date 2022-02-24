#include "Dragon.h"
Dragon::Dragon()
{
        startingHP = 0;
        HP = 0;
        name = "";
        for(int i=0; i<4; i++)
        {
            attackArr[i] = 0;
            nameAttackArr[i] = "";
        }
        
}
void Dragon::setDragon(string n, string name1, string name2, string name3, string name4, int hp, int attack1, int attack2, int attack3, int attack4 )
{
    name = n;
    HP = hp;
   startingHP = hp;
   attackArr[0] = attack1;
   attackArr[1] = attack2;
   attackArr[2] = attack3;
   attackArr[3] = attack4;
   nameAttackArr[0] = name1;
   nameAttackArr[1] = name2;
   nameAttackArr[2] = name3;
   nameAttackArr[3] = name4;
}
void Dragon::setHp(int hp)
{
    HP = hp;
}
int Dragon::getHp()
{
    return HP; 
}
void Dragon::printHp()
{
    cout << "HP is currently: " << HP << endl;
    cout << "Total HP this dragon can have is " << startingHP << endl; 
}

void Dragon::printDragonName()
{
    cout<< "Dragon's name: " << name << endl;
}
string Dragon::getDragonName()
{
   return name;
}
int Dragon::healDragon(int potion)
{ 
  int elixirsUsed = 0;
  int heal = 0; 
  if(HP == startingHP)
  {
      cout << "Your dragon does not need to be healed since it is at full health already." << endl;
  }
  else 
  {
      for(int i = 0; i < potion; i++)
      {
            if(HP == startingHP)
            {
                cout << "Your dragon is now fully healed!" << endl; 
            }
            else
            {
               
                heal = rand() % (10);
                //This will create a random number from 0 to 9
                if(heal > 5)
                //this creates a 40% chance the total amount of healing is 5
                {
                    heal = 5;
                }
                else
                // This creates a 60% chance the total amount of healing is 8
                {
                    heal = 8;
                }
                 HP = HP + heal;
                if(HP > startingHP)
                {
                    HP = startingHP; 
                    cout << name << "Is fully healed!" << endl; 
                }
                cout << name << " says, Thank you! HP is now: " << HP << endl;
                elixirsUsed++;
            }
            
      }
    }
    return elixirsUsed;
}
void Dragon::getAttackName(int index)
{
    cout << nameAttackArr[index] << endl; 
}
int Dragon::getAttackStrength(int index)
{
    return attackArr[index]; 
}

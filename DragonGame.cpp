#include "DragonGame.h"
bool canIAppend(int sizeArray, int arrayCount , string tempString)
// This will check to see if I can append to the empty string.
{
   if(arrayCount >= sizeArray || tempString == "")
   {
       return false;
   }
   else
   {
       return true;
   }
}
int split(string userInput, char separator, string array[],int sizeArray)

{  
    int arrayDiff = 0;
    string tempString = "";
    // This is an empty string that will be used to hold elements on either side of the separator. 
    int  arrayCount = 0;
    //This counter/ index will keep track of how many elements are in the new array.
    
  
 
    for(int i=0; i < userInput.size(); i++)
    //This will loop through equal to the the size of the string the user inputs. 
    { 
       if (userInput[i] == separator)
       //if the userInput at a particular index is equal to the separator then the following will occur.
       {
          if(canIAppend(sizeArray, arrayCount , tempString))
              /* 
              *First will check to make sure the tempString can be added to the array,
              *if the tempstring is empty or arraycount is greater then array size False will be returned and the following will not execute.
              * If the tempString is has elements and the arraycount is less than or equal to array size the string will be added to the array.
              */ 
           {
               array[arrayCount++] = tempString;
               tempString = "";
           //Once the tempString has been added to the array the tempString will be reset to an empty string, so the next set of elements can be added
           }
         
        }
       else
       {
         tempString = tempString + userInput[i];
         //This will create a tempString with the elements between the separators.
            
      }
     }
     
      if (canIAppend(sizeArray, arrayCount , tempString))
      //Need to append the last tempString to the array since the end of the string maynot have a separator. 
      {
      array[arrayCount++] = tempString;
      }
     
    if(arrayCount > sizeArray)
    {
     return -1;
    }
    else
    {
      return arrayCount;
      //This is how many items are in the array. for e.g. rat,dog separator = , then rat and dog will be added for a total of 2 items in the array.
    }

}

DragonGame::DragonGame()
{
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<25; j++)
        {
            mapArr[i][j] ='a';
        }
    }
    numWildDragon = 0;
    numDragons = 0;
    numDragonsUsedInBattle = 0;
    numPoints = 0;
}
void DragonGame::gameMenu(int c )
{
    int choice = 0;
    choice = c; 
    switch(choice)
       {   
         case 1:
              move();
              break;
        case 2:
              healDragon();
              break;
            
        case 3:
              printDragons();
              break;
        case 4:
              printpoints(); 
              break;
        case 5:
              printelixirs();
              break;
        case 6:
                cout << "Wonderful quest!" << endl;
                cout << "Here is your final score!" << endl; 
                printpoints();
                finalscores();
                break;
        case 7:
               // game.printDragons();
              printMap();
              break; 
              //This is to check things uploaded correctly. 
        case 8:
              printUserPosition();
              //this is to check the users position on the map. 
        default:
                //If the value entered is not any of the given values. Values must be 1 - 7 . 
               cout<< "Invalid option."<<endl;
               break;
       }
    
}
void DragonGame::createMap(string file)
{
    ifstream mapstream;
    int rowindex = 0;
    string line = ""; 
    mapstream.open(file);
    if(mapstream.is_open())
     {
        rowindex = 0;
            while(getline(mapstream, line))
            {
                for(int i =0; i<16; i++)
                {
                    mapArr[rowindex][i] = (char)line[2*i];
                    //2*i skips the commas.
                    
                }
             rowindex++;
            }
            
       
     }
     else
     {
         cout << "did not open file" << endl;
     }
     mapstream.close();
}
void DragonGame::printMap()
{
    
        for(int rowindex =0; rowindex<25; rowindex++)
        {
        
            for(int i =0; i<16; i++)
               {
                   cout << mapArr[rowindex][i];
                }
           cout << endl;
        }  
     
}

void DragonGame::setName()
{
    string username;
    cout << "Welcome to the magical realm of Null! what's your name?" << endl;
    cin >> username;
    user.setplayer(username);
}
void DragonGame::loadDragons(string file)
{
    string n = "";
    string name1 = ""; 
    string name2 = ""; 
    string name3 = "";
    string name4 = "";
    int HP = 0; 
    int attack1 = 0; 
    int attack2 = 0; 
    int attack3 = 0; 
    int attack4 = 0;
    int i = 0;
    string line = "";
    string array[10];
    ifstream stream;
    stream.open(file);
    if(stream.is_open())
    {
       while(getline(stream, line))
        {
            if(line != "")
            {
                 split(line, ',', array, 10);
                 n = array[0];
                 name1 = array[1]; 
                 name2 = array[2]; 
                 name3 = array[3];
                 name4 = array[4];
                 HP = stoi(array[5]); 
                 attack1 = stoi(array[6]); 
                 attack2 = stoi(array[7]); 
                 attack3 = stoi(array[8]); 
                 attack4 = stoi(array[9]);
                 WildDragonArr[i].setDragon(n, name1, name2, name3, name4, HP, attack1, attack2, attack3, attack4 );
                 i++;
            }
        }    
    }
    stream.close();
}
void DragonGame::printDragons()
{
    if(numDragons == 0)
    {
        cout << "Your dragon stable is empty, go forth and wander" << endl;
    }
    else
    {
        for(int i =0; i <numDragons; i++)
        {
            TrainersDragonArr[i].printDragonName();
        }
    }
}
void DragonGame::printpoints()
{   
   
    cout << "Your current points are: " << numPoints << endl; 
}
void DragonGame::printelixirs()
{
    int elixir = 0;
    elixir = user.getNumElixirs();
    cout << "Your current number of elixirs are: " << elixir << endl;
    
}

bool DragonGame::movenorth(int spaces)
//This will move the user north hence why minus # spaces from the current position since they'll be mvoing up the array not down. 
{
    int newY = user.getPositionY() - spaces;
    return user.setPositionY(newY);
}

bool DragonGame::moveeast(int spaces)
//This will set the new x position for the 2d array of the map, it's plus spaces since they are moving to the right in the 2d array.
{
    int newX = user.getPositionX() + spaces;
    return user.setPositionX(newX);
}
bool DragonGame::movesouth(int spaces)
{
    int newY = user.getPositionY() + spaces;
    return user.setPositionY(newY);
}
bool DragonGame::movewest(int spaces)
{
    int newX = user.getPositionX() - spaces;
    return user.setPositionX(newX);
}
int DragonGame::selectDragon()
{
    int usersDragon = 0; 
    for(int i = 0; i < numDragons; i++)
            {
                cout << "Select " << i+1 << " for ";
                TrainersDragonArr[i].printDragonName();
                cout << endl;
            }
            cin >> usersDragon;
    return usersDragon;
}
int DragonGame::fightAttackMenu(int dragonIndex)
{
    int attackChoice = -1; 
    cout << "Which attack would you like to use for this round?" << endl;
    for(int i = 0; i <4; i++)
    {
        cout << "Select " << i+1 << " for ";
        TrainersDragonArr[dragonIndex].getAttackName(i);
        cout << endl;
    }
    cin >> attackChoice;
     if(attackChoice < 1 || attackChoice > 4)
    {
        cout << "Attack number . . . " << attackChoice << " that's not an attack in this world! " << endl;
        cout << "Let's try that again" << endl;
        fightAttackMenu(dragonIndex); 
    }
    return attackChoice;
}
bool DragonGame::checkHpAndDragonsUsedInBattle(int indexOfDragonSelected)
{
    if(WildDragonArr[numWildDragon].getHp() == 0)
    {
        cout << "The battle is over since you won!" << endl;
        numDragons++;
        numWildDragon++; 
        return true; 
    }
    else if( numDragonsUsedInBattle == 3 && TrainersDragonArr[indexOfDragonSelected].getHp() == 0)
    {
        cout << "Sadly you lost the battle hopefully you'll win next time." << endl; 
        return true;  
        
    }
    else if(numDragons == numDragonsUsedInBattle && TrainersDragonArr[indexOfDragonSelected].getHp() == 0)
    //This conditions covers if the trainer only has one or 2 dragons. 
    {
        cout << "Sadly you lost the battle." << endl; 
        return true;
    }
    else
    {
        return false;
    }
}
void DragonGame::fightWildDragon(Dragon* trainersDragon_pointer, Dragon* WildDragon_pointer,  int indexOfDragonSelected , bool userGoesfirst)
{
     int dragonAIndex;
     int dragonBIndex;
     int indexofAttackA = -1;
     int attackStrengthA = -1;
     int attackStrengthB = -1; 
     int damageToA = 0;
     int damageToB = 0;
     int randomAttackNum = -1;
     dragonAIndex = indexOfDragonSelected;
     dragonBIndex = numWildDragon;
     //use -1 to error check if needed since variable could be 0. 
     
     if(userGoesfirst == true)
     {
         
         indexofAttackA = (fightAttackMenu(dragonAIndex) -1);
         // Since the user choose is 1 -4 and the index for attack names and strength are 0 - 3 need to minus 1. 
         attackStrengthA = trainersDragon_pointer->getAttackStrength(indexofAttackA);
         cout << "Strenght of this attack is: " << attackStrengthA << endl; 
         damageToB =  WildDragon_pointer->getHp() - attackStrengthA;
        
         if(damageToB <= 0)
         {
               damageToB = 0;
               WildDragon_pointer->setHp(damageToB);
               cout << "You are victorious!" << endl;
                cout << "You have acquired a new dragon named: " << endl;
                WildDragon_pointer->printDragonName();
                cout << endl;
                TrainersDragonArr[numDragons] = WildDragonArr[numWildDragon];
               numPoints++;
              
         }
         else
         {
             cout << "You have dealt " << attackStrengthA << " amount of damage to the wild dragon.  The wild dragon has " << damageToB <<" HP left." << endl;
         
             WildDragon_pointer->setHp(damageToB);
             cout << "wild dragon" << endl;
             WildDragon_pointer->printDragonName();
             cout << endl;
                randomAttackNum = rand() % (4);
                // Mod by 4 will give number 0 -3 which is the index of the attack name and attack strength arrays. 
                cout << "Wild dragon is about to attack with," << endl; 
                WildDragon_pointer->getAttackName(randomAttackNum);
                attackStrengthB = WildDragon_pointer->getAttackStrength(randomAttackNum);
                cout << "Strength of this attack is: " << attackStrengthB << endl; 
                damageToA =  trainersDragon_pointer->getHp() - attackStrengthB;
                if(damageToA <0)
                {
                    damageToA = 0;
                    cout << "O no your Dragon is at 0 HP!" << endl;
                }
               else
                {
                     cout << "You have been hit!" << endl;
                     cout << "Wild dragon has dealt " << attackStrengthB << " amount of damage to your dragon.  Your dragon has " << damageToA <<" HP left." << endl;
                }
               trainersDragon_pointer->setHp(damageToA);
         }  
     }
     else
     {
             randomAttackNum = rand() % (4);
            // Mod by 4 will give number 0 -3 which is the index of the attack name and attack strenght arrays. 
            cout << "Wild dragon is about to attack with," << endl; 
            WildDragon_pointer->getAttackName(randomAttackNum);
            attackStrengthB = WildDragon_pointer->getAttackStrength(randomAttackNum);
            cout << "Strength of this attack is: " << attackStrengthB << endl; 
            damageToA =  trainersDragon_pointer->getHp() - attackStrengthB;
            if(damageToA <0)
            {
                damageToA = 0;
                trainersDragon_pointer->setHp(damageToA);
                checkHpAndDragonsUsedInBattle(dragonAIndex);
                cout << "You have been hit!" << endl;
            }
           else
            {
                 cout << "You have been hit!" << endl;
                 cout << "Wild dragon has dealt " << attackStrengthB << " amount of damage to your dragon.  Your dragon has " << damageToA <<" HP left." << endl;
            
                 trainersDragon_pointer->setHp(damageToA);
                 indexofAttackA = (fightAttackMenu(dragonAIndex) -1);
                 // Since the user choose is 1 -4 and the index for attack names and strength are 0 - 3 need to minus 1. 
                 attackStrengthA = trainersDragon_pointer->getAttackStrength(indexofAttackA);
                 cout << "Strenght of this attack is: " << attackStrengthA << endl; 
                 damageToB =  WildDragon_pointer->getHp() - attackStrengthA;
                
                 if(damageToB <0)
                 {
                     damageToB = 0; 
                     cout << "You are victorious!" << endl;
                        cout << "You have acquired a new dragon named: " << endl;
                        WildDragon_pointer->printDragonName();
                        cout << endl;
                        TrainersDragonArr[numDragons] = WildDragonArr[numWildDragon];
                        numPoints++;
                        
                 }
                 else
                 {
                     cout << "You have dealt " << attackStrengthA << " amount of damage to the wild dragon.  The wild dragon has " << damageToB <<" HP left." << endl;
                 }
             }
             
    }
}
bool DragonGame::whoGoesFirst(int indexOfDragonSelected)
{
   
         if(TrainersDragonArr[indexOfDragonSelected].getHp() < WildDragonArr[numWildDragon].getHp() || TrainersDragonArr[indexOfDragonSelected].getHp() == WildDragonArr[numWildDragon].getHp())
         {

             return true;
         }
         else
         {
            return false; 
         }
      
}
bool DragonGame::checkIfDragonHasHpZero(int index)
{
   int indexOfDragonSelected = index; 
   if (TrainersDragonArr[indexOfDragonSelected].getHp() > 0)
   {
       cout << "Excellent choice!" << endl; 
       return true;
   }
   cout << "This dragon needs to be healed" << endl; 
   cout << "Please try again." << endl; 
   return false;
}
bool DragonGame::canTrainerFightWildDragon()
{
    for(int i = 0; i < numDragons; i++)
    {
       if(TrainersDragonArr[i].getHp() > 0)
       {
           return true;
       }
        
                    
    }
    cout << "All your dragons are at zero HP!" << endl; 
    cout << "No fighting for you . . . time to heal your dragons!" << endl;
    return false; 
     
}
void DragonGame::fightMenu()
{
 int attackStrength = - 1; 
 int indexofAttack = - 1; 
 int indexOfDragonSelected = -1; 
 int choice = 0;
 int numOfRounds = 0; 
 //Only max of three can be used. 
 numDragonsUsedInBattle = 0;
 bool userGoesfirst = false; 
 bool battleOver = false;
 do
     {
            cout << "Select a numerical option:" << endl;
            cout << "======Fight Menu=====" << endl;
            cout << "1. Select or Switch out a dragon." << endl;
            cout << "2. Keep current dragon in battle." << endl; 
            cout << "3. To see the HP of your dragon in battle." << endl;
            cout << "4. To see the HP of the opposing dragon in the battle." << endl;
            cin >> choice;
            switch(choice)
            {
               case 1:
                    cout << "Which dragon would you like to go into battle with?" << endl;
                    cout << "Number of trainers dragons " << numDragons << endl; 
                    indexOfDragonSelected = selectDragon() - 1;
                    
                    if(indexOfDragonSelected >= numDragons || indexOfDragonSelected < 0)
                    {
                        cout << "That dragon doesn't exist, please try again." << endl;
                        break;
                    }
                    else if(checkIfDragonHasHpZero(indexOfDragonSelected)) 
                    {
                        if(numOfRounds == 0)
                        {
                            userGoesfirst = whoGoesFirst(indexOfDragonSelected);
                            //This sets the order of the battle. Who goes first each round. 
                        }
                         numDragonsUsedInBattle++;
                         Dragon* trainersDragon_pointer = &TrainersDragonArr[indexOfDragonSelected];
                         Dragon* WildDragon_pointer = &WildDragonArr[numWildDragon];
                         fightWildDragon(trainersDragon_pointer, WildDragon_pointer, indexOfDragonSelected ,userGoesfirst);
                         numOfRounds++;
                         battleOver = checkHpAndDragonsUsedInBattle(indexOfDragonSelected);
                         //check hp of dragons and numdragonsusedInBattle(can only use three dragons in one battle).  
                       
                         break;
                    }
                    
               case 2:
                       if(numOfRounds > 0 && checkIfDragonHasHpZero(indexOfDragonSelected))
                       //This means they do not have a dragon selected since in case one would numOfRounds++. 
                       {
                            Dragon* trainersDragon_pointer = &TrainersDragonArr[indexOfDragonSelected];
                            Dragon* WildDragon_pointer = &WildDragonArr[numWildDragon];
                            //Use a pointer to update the actual instance instead of a copy of the instance. 
                            fightWildDragon(trainersDragon_pointer, WildDragon_pointer, indexOfDragonSelected, userGoesfirst );
                            numOfRounds++;
                            battleOver = checkHpAndDragonsUsedInBattle(indexOfDragonSelected);
                            //This is checking to see Hp of current dragon and number of dragons used 
                            // since can only use 3 dragons.
                            break; 
                       }
                       else
                       {
                           cout << "You need to select a dragon first, please try again." << endl; 
                           break; 
                       }
                       
               case 3:
                    if(indexOfDragonSelected == -1)
                    {
                        cout << "You still need to select a dragon" << endl;
                        break;
                    }
                    else
                    {
                        TrainersDragonArr[indexOfDragonSelected].printHp();
                        break;
                    }
                case 4:
                    WildDragonArr[numWildDragon].printDragonName();; 
                    WildDragonArr[numWildDragon].printHp(); 
                     break;
                case 5:
                     break;
               default:
                    cout << "Invalid option, please try again." << endl;
                    break; 
            }
     
    }
     
     while(choice !=5 && battleOver != true && canTrainerFightWildDragon() == true);
     //This is checking to see if the user selected 5 or they lost or won the battle or
     //Checking hp of all dragons if all dragons are at zero hp then battle is over. 
}

void  DragonGame::analyzePosition()
{
   int row = 0;
   int col = 0;
   char positionOnMap ='f';
   col = user.getPositionX(); 
   row =user.getPositionY(); 
   positionOnMap = mapArr[row][col];
   switch(positionOnMap)
   {
       case 'p':
            cout << "Nothing exciting here. . . keep moving." << endl;
            break;
       case 'd':
            if(numWildDragon == 0 && numDragons ==0)
            {
                cout << "You have encountered a wild dragon!" << endl; 
                cout<< "This one is friendly and decides to join you on your quest!" << endl;
                TrainersDragonArr[0] = WildDragonArr[0];
                numDragons++;
                numWildDragon++;
                cout<< "Congratulations! you have acquired your first dragon." <<endl;
                numPoints++;
                winner();
            }
            else
            {
               cout << "You have encountered a wild dragon! Who is ready to fight!" << endl;
               if (canTrainerFightWildDragon())
               //This is checking to see if the user has a dragon with hp above zero. 
               {
                   fightMenu();
               }
               else
               {
                   cout << "You do not have any dragons at this time can that fight since they all have hp of zero!" << endl;
                   cout << "Time to heal your dragons!" << endl; 
               }
            }
            break;
        case 'e':
            cout << "Today is your lucky day you found an elixir, this can be used to heal your dragons" << endl;
            user.updateNumElixirs();
            numPoints++;
          
            break;
        case 'c':
            cout << "The luck dragon is on your side today!" << endl;
            cout << "You have found a Chest with five elixirs!" << endl;
            for(int i =0; i<5; i++)
            {
                user.updateNumElixirs();
                numPoints++;
            
            }
            break; 
        default:
               cout<< "Invalid option."<<endl;
               break;
       
   }
   
}
void DragonGame::move()
{ 
    int s = 0;
    char d = 'f';
    cout << "How many spaces would you like to move? " << endl;
    cin >> s;
    cout << "Which direction would you like to move select N for north, S for south, W for west, and E for east" << endl;
    cin >> d;
    
    bool success = false;
    
    switch(d)
    {
        case 'N':
        case 'n':
               success = movenorth(s);
               break;
        case 'S':
        case 's':
               success = movesouth(s);
               break;
        case 'W':
        case 'w':
                success = movewest(s);
                break;
        case 'E':
        case 'e':
                success = moveeast(s);
                break;
        default:
               cout<< "Invalid option."<<endl;
               break;
    }   
        
    if (!success) 
    {
        cout << "Move failed. Try again" << endl;
    }
    else 
    {
            analyzePosition();
    }
}
void DragonGame::printUserPosition()
{
    cout << "user col/x position" << user.getPositionX() << endl;
    cout << "user row/y position" << user.getPositionY() << endl; 
}
void DragonGame::healDragon()
{
    
    int elixir = 0; 
    int numElixir = 0;
    int numElixirsUsedToHeal = 0;
    int newElixirTotal = 0; 
    int usersDragon = 0;
    if(numDragons == 0)
    {
        cout << "You currently have no dragons, keep exploring you'll find one soon!" << endl;
    }
    else
    {
        cout << "Which dragon would you like to heal?" << endl;
        usersDragon = selectDragon();
        TrainersDragonArr[usersDragon - 1].printHp();
        cout << "How many elixirs would you like to use to heal your dragon?" << endl; 
        cin >> elixir;
        numElixir = user.getNumElixirs(); 
        if(numElixir < elixir)
        {
            cout << "You do not have " << elixir << " elixirs. You have this many elixirs you currently have: " << numElixir << endl;
        }
        else 
        {
            numElixirsUsedToHeal = TrainersDragonArr[usersDragon -1].healDragon(elixir);
            cout << "You used this many elixirs: " << numElixirsUsedToHeal << endl; 
        }
        newElixirTotal = numElixir - numElixirsUsedToHeal; 
        user.updateElixirs(newElixirTotal); 
        cout << "You have " << user.getNumElixirs() << " left." << endl; 
    }
}
bool DragonGame::winner()
{
    if(numPoints >= 50 )
    {
        cout << "Congratulations! You have won the game!" << endl;
        cout << "You have 50 or more points!" << endl;
        gameMenu(6);
        return true;
    }
    else if(numDragons >=15)
    {
        cout << "Congratulations! You have won the game!" << endl;
        cout << "You have 15 or more Dragons!" << endl;
        gameMenu(6);
        return true;
    }
    else
    {
       return false; 
    }
}
void DragonGame::finalscores()
{
    ofstream out_file; 
    out_file.open("finalscores.txt"); 
    out_file << user.getPlayerName() << " " << numPoints << endl;
    out_file.close(); 
}
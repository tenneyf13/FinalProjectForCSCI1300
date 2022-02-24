#include "DragonGame.h"
#include <fstream>
int main()
{ 
  
  DragonGame game;
  game.createMap("dragonMap.txt");
  game.loadDragons("dragon.txt");
  game.setName();
  // This code initializes the game state:  board, player and wild dragon array. 
  int choice = 0;
 do
 {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Move around the land" << endl;
        // can move north, east, south or west and will enter how many spaces they would like to move.
        cout << "2. Heal a Dragon" << endl;
        //This will call the heal fcn which is of type dragon
        cout << "3. View Dragons" << endl;
        //This will print their dragons and stats. 
        cout << "4. View points so far" << endl;
        //This will print how many points they have.
        cout << "5. How many elixirs do I have?" << endl;
        //This will display number of elixirs.
        cout << "6. Quit and display my stats." <<endl;
        cin >> choice;
        game.gameMenu(choice); 
       
    }
    while(choice != 6 && game.winner() == false);
    //Want the loop to stop when user hits 6 or game.winner is true since that means they won the game. 
   
    
    return 0;
  
}
 
 //https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected

// https://www.geeksforgeeks.org/data-structures/


 

  
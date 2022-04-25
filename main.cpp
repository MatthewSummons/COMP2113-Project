#include <iostream>

using namespace std;

#include "Title_Screen.hpp"
#include "Save_Load.hpp"

#define inventory_length 8

int main() {
  
  int game_mode = 0;    // 1 :=  New Game, 2 := Continue
  bool saved = false;   // Store if a save file exists
  
  // Update game mode by determining if a save exists or not
  Title_Screen(game_mode, saved);

  // Update the stage and inventory by loading save and creating a new one in none exists
  string stage = "";
  string *inventory = new string[inventory_length];
  Start_Save_Load(game_mode, stage, inventory);

  cout << "The stage is " << stage << endl;
  
  cout << "'ere comes the inventory: " << endl;
  for (int i = 0; i < 8; i++) {
    cout << inventory[i] << endl;
  }

}
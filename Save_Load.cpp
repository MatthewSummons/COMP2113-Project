#include "Save_Load.hpp"

#include <string>     // For C++ Strings
#include <fstream>    // For reading & writing to save files
#include <iostream>   // For printing error messages

#define inventory_length 8

// Store the Staus of the Game
struct Game_State {
  std::string stage;
  std::string *inventory = new std::string [inventory_length];
};

std::string stages [] = {
  "Introduction", 
  "Monster 1",
  "Monster 2"
  "Monster 3",
  "Monster 4",
  "Final Battle "
};

void Start_Save_Load(const int game_mode, std::string &stage, std::string* inventory) {

  Game_State Crystal_Flower;

  // Create a new save
  if (game_mode == 1) {
    Crystal_Flower.stage = "Introduction";

    for (int i = 0; i < inventory_length; i++) {
      Crystal_Flower.inventory[i] = " \n";
    }
    update_save(Crystal_Flower);
  }

  // Load from the save file
  else {
    std::cout << "Loading ... !" << std::endl;
    load_save(Crystal_Flower);
  }

  // Update the stage & inventory after loading from the save file
  stage = Crystal_Flower.stage;
  // Copy inventory items to send to main()
  for (int i = 0; i < inventory_length; i++) {
    inventory[i] = Crystal_Flower.inventory[i];
  }
}

// Given a game state, write to the save file
void update_save(struct Game_State game_status) {
  
  std::cout << "Saving file. Do no Quit." << std::endl;

  std::ofstream save_file;
  save_file.open(".Save/save.save");

  save_file << "Save Exists" << std::endl;

  save_file << game_status.stage << std::endl;

  for (int i = 0; i < inventory_length; i++) {
    save_file << game_status.inventory[i] << std::endl;
  }
  
  if (save_file.fail()) {
    std::cout << "Error opening save file" << std::endl;
    exit(1);
  }

  save_file.close();

  std::cout << "File Saved" << std::endl;
}

// Read from a save file & store it in game_status
void load_save(struct Game_State &game_status) {
  // Open the save file
  std::ifstream save_file;
  save_file.open(".Save/save.save");

  if (save_file.fail()) {
    std::cout << "Error loading from save file" << std::endl;
  }
  
  // Read from the save file
  std::string save_state;
  std::getline(save_file, save_state);

  std::getline(save_file, game_status.stage);
  
  for (int i = 0; i < inventory_length; i++) {
    std::getline(save_file, game_status.inventory[i]);
  }

  save_file.close();
}
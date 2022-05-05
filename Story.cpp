#include <unistd.h> // For implementing ...
#include <chrono>   // a .. delay ..
#include <thread>   // when printing stuff

#include <iostream>   // For prinitng stuff
#include <string>     // For C++ strings

using namespace std;

#include "Story.hpp"
#include "Save_Load.hpp"    // For Saving Files
#include "Minigames.hpp"    // For Minigames
#include "End_Screen.hpp"   // For End Screen

// Originally in SaveLoad.cpp
std::string stages_alias[] = {
  "Introduction",
  "Monster 1",
  "Monster 2",
  "Monster 3",
  "Monster 4",
  "Final Battle"
};

// ! write func to update inventory (Add/ Remove)
struct Choice {
  // Choice Presented to the Player
  string line;
  // End Screen line if incorrect choice made
  string end_screen;

  // Constructor for Struct
  Choice(std::string line, std::string end_screen = "You made the wrong choice") {
    this -> line = line;
    this -> end_screen = end_screen;
  }

  // The function which offers the choice to the player
  void Decide(int delay = 35, bool isEndLine = true) {
    print(this -> line, delay, isEndLine);
    std::string response;
    std::cin >> response;

    if (response == "Y" || response == "y")
      return;
    
    // Show End Screen for selecting the wrong choice
    End_Screen(this -> end_screen);
    
  }
};

typedef struct Choice Choice;


void print(string str, int delay, bool isEndLine) {
  int len = str.length();
  for (int i = 0; i < len; i++) {
    cout << str[i] << flush;
    this_thread::sleep_for(chrono::milliseconds(delay));
  }

  this_thread::sleep_for(chrono::milliseconds(delay + 100));

  if (isEndLine) {
    cout << endl;
  }
}


// Select stage based on load from save file; If new game, play from Introduction
void Play_Stage(string &stage, string *inventory) {
  if (stage == "Introduction")
    Introduction(inventory);
  else if (stage == "Monster 1")
    Monster_1(inventory);
  else if (stage == "Monster 2")
    Monster_2(inventory);
  else if (stage == "Monster 3")
    Monster_3(inventory);
  else if (stage == "Monster 4")
    Monster_4(inventory);
  else if (stage == "Final Battle") {
    Final_Battle(inventory);
    print("Thanks for playing!");
    return;
  }
  
  else {
    cout << "Save File corrupted" << endl;
    exit(1);
  }

  // Ask to save each time
  Ask_Save(stage, inventory);

  // Ask if the player would like to continue playing
  print("Would you like to continue playing? [Y/n]");
  string response;
  cin >> response;

  // Quit out of game
  if ((response == "n") || (response == "Y")) {
    print("Thanks for playing! Come back around again!", 50);
    exit(1);
  }
}

// Ask to save before continuing chpater, save if player wants to
void Ask_Save(const string stage, string *inventory) {
  // Lower the text
  for (int i = 0; i < 3; i++) {
    cout << endl;
  } 

  print("Would you like to save before continuing? [Y/n]");
  
  string response;
  cin >> response;

  // Save if the players want to save
  if (response == "Y" || response == "y") {
    Save(stage, inventory);
  }
}

// After completing a stage, move to the next stage
void Update_Stage(string &stage) {
  // 5 Stages
  string next_stage = "Corrupted";
  for (int i = 0; i < 5; i++) {
    if (stage == stages_alias[i])
      next_stage = stages_alias[i + 1];
  }
  stage = next_stage;
}

void Introduction(string *inventory) {
  system("clear");

  // Protag gains a sword


  print("Introduction");

  Choice choice = Choice("Continue [Y/n]", "Fuck you!");

  choice.Decide();


  // R"()" for raw strings.
   
  //  minigame_1();
  // print()
}

void Monster_1 (string *inventory) {
  system("clear");
  
  print("MONSTER 1");
  print("Bota", 100, false);
  print(" Issayeva", 10);
}

void Monster_2 (string *inventory) {
  system("clear");

  cout << "MONSTER 2" << endl;
}

void Monster_3 (string *inventory) {
  system("clear");

  cout << "MONSTER 3" << endl;
}

void Monster_4 (string *inventory) {
  system("clear");

  cout << "MONSTER 4" << endl;
}

void Final_Battle(string *inventory) {
  system("clear");

  cout << "FINALE" << endl;
}



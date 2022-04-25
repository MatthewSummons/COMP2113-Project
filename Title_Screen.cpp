#include <unistd.h>     // For implementing ...
#include <chrono>       // a .. delay ..
#include <thread>       // when printing stuff

#include <iostream>     // For cout, cin
#include <string>       // For C++ Strings
#include <fstream>      // For reading and writing to save files
#include <iomanip>      // For setw in centering in text

using namespace std;

#define CENTRE 78
#define TERMINAL_HEIGHT 15

#include "Title_Screen.h"

void Title_Screen(int &game_mode) {
  bool saved = isSaved();
  
  print_title_screen(saved);
  
  game_mode = ask_game_mode(saved);
}

// Print a string character by character with a mixed-delay
void delayed_print(std::string str, bool isEndline=true) {
  int len = str.length();
  for (int i = 0; i < len; i++) {
    cout << str[i] << flush;
    // Add the delay, alternating it to make it look more natural
    if (i % 2 == 0)
      std::this_thread::sleep_for(std::chrono::milliseconds(35));
    else
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  
  // Hold at the end of the string for emphasis
  std::this_thread::sleep_for(std::chrono::milliseconds(350));
  
  if (isEndline)
    cout << endl;
}

// Prints the game title, and game mode options for the user to select from. Detects if a save file exists
//  and prints the continue option only if it exists.
void print_title_screen(bool save_status) {
  
  system("clear");

  // Centre Text Vertically
  for (int i = 0; i < TERMINAL_HEIGHT; i++) {
    cout << endl;
  }
  
  // The Game Title
  string Title = R"(
   _____                           _______  _  _    _       
  / ____|                         |__   __|(_)| |  | |      
 | |  __   __ _  _ __ ___    ___     | |    _ | |_ | |  ___ 
 | | |_ | / _` || '_ ` _ \  / _ \    | |   | || __|| | / _ \
 | |__| || (_| || | | | | ||  __/    | |   | || |_ | ||  __/
  \_____| \__,_||_| |_| |_| \___|    |_|   |_| \__||_| \___|                                                         
  )";

  cout << Title << endl;

  // Game mode options below title
  string N = "1. New Game", Q = "2. Quit";

  // Check save from save file and print the continue option if save file exists
  bool isContinue = save_status;

  // Print the Game Mode options
  int offset = N.length();

  cout << setw(CENTRE - offset) << "";
  delayed_print(N);
  // cout << N << endl;

  if (isContinue) {
    string C = "2. Continue";
    cout << setw(CENTRE - offset) << "";
    delayed_print(C);

    // Update the Q string
    Q = "3. Quit";
  }

  cout << setw(CENTRE - offset) << "";
  delayed_print(Q);
  // cout << Q << endl;
  
}

// Opens the save file and checks if a save exists or not
// Returns true if "Save Exists", false if "No Save" & otherwise rewrites the save file
bool isSaved() {
  ifstream save_file;
  save_file.open(".Save/save.sv");

  if (save_file.fail()) {
    delayed_print("Error loading from file");
    exit(1);
  }

  string save_status, No_Save = "No Save";
  getline(save_file, save_status);    // First line of Save file contins save status

  if (save_status == No_Save)
    return false;
  else if (save_status == "Save Exists")
    return true;
  // If corrupted save file then rewrite so the player can start anew
  else {
    cout << setw(CENTRE - 5);  // "Save file is corrupted!" has length 23
    delayed_print("Save file is corrupted!");
    save_file.close();  // Close previously opened file
    
    // Open new file to rewrite it
    ofstream save_file_E;
    save_file_E.open(".Save/save.sv");
    save_file_E << No_Save << endl;
    save_file_E.close();
    exit(1);
  }
}

int ask_game_mode(bool isSaved) {
  int game_mode = -1;
  
  delayed_print("Please select an option from above: ", false);
  int user_option;
  cin >> user_option;
  
  // Quit will be 3
  if (isSaved) {
    if(user_option == 3) {
      delayed_print("Come back next time!");
      system("clear");
      exit(1);
    }
  }
  // Quit will be 2
  else {
    if (user_option == 2) {
      delayed_print("Come back next time!");
      system("clear");
      exit(1);
    }
  }

  return user_option;
} 
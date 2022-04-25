#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define CENTRE 78
#define TERMINAL_HEIGHT 15

#include "Title_Screen.h"

void print_title_screen() {
  
  system("clear");

  // Centre Text Vertically
  for (int i = 0; i < TERMINAL_HEIGHT; i++) {
    cout << endl;
  }
  
  string Title = R"(
   _____                           _______  _  _    _       
  / ____|                         |__   __|(_)| |  | |      
 | |  __   __ _  _ __ ___    ___     | |    _ | |_ | |  ___ 
 | | |_ | / _` || '_ ` _ \  / _ \    | |   | || __|| | / _ \
 | |__| || (_| || | | | | ||  __/    | |   | || |_ | ||  __/
  \_____| \__,_||_| |_| |_| \___|    |_|   |_| \__||_| \___|                                                         
  )";

  cout << Title << endl;

  string N = "1. New Game";
  
  int offset = N.length();
  
  cout << setw(CENTRE - offset) << "";
  cout << N << endl;

  // Check save from save file and print the continue option if save file exists
  bool isContinue = isSaved();
  if (isContinue) {
    string C = "2. Continue";
    cout << setw(CENTRE - offset) << "";
    cout << C << endl;
  }

  string Q = "3. Quit";
  cout << setw(CENTRE - offset) << "";
  cout << Q << endl;
  
}

// Opens the save file and checks if a save exists or not
// Returns true if "Save Exists", false if "No Save" & otherwise rewrites the save file
bool isSaved() {
  ifstream save_file;
  save_file.open(".Save/save.sv");

  if (save_file.fail()) {
    cout << "Error loading from save";
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
    cout << "Save file is corrupted!" << endl;
    save_file.close();  // Close previously opened file
    
    // Open new file to rewrite it
    ofstream save_file_E;
    save_file_E.open(".Save/save.sv");
    save_file_E << No_Save << endl;
    save_file_E.close();
    exit(1);
  }
}


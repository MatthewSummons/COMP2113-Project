#include <unistd.h> // For implementing ...
#include <chrono>   // a .. delay ..
#include <thread>   // when printing stuff

#include <iostream>   // For prinitng stuff
#include <string>     // For C++ strings

using namespace std;

#include "Story.hpp"
#include "End_Screen.hpp"

struct Choice {
  string line;
  string end_screen;
};


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


void Play_Stage(string &stage) {
  if (stage == "Introduction")
    Introduction();
  // else if (stage == "Monster 1")
}

void Introduction() {
  system("clear");

  print("It was a tragic sight.", 100);
  print("An innocent 7 year old was mourning the passing of her father.");
  print("The girl, Hera, had lost her mother at birth & now the only thing that motivated her to live too had been snatched from her hands.");

  // print()

}


// void Monsters () {
//   ;
// }

// void Final_Battle() {
//   ;
// }



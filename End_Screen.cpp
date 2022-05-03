#include <iostream>
#include <string>
#include <iomanip>

#include "Story.hpp"    // For print()

#define CENTRE 78
#define TERMINAL_HEIGHT 15

using namespace std;

void End_Screen (string end_line) {
  string End_Title = R"(
                                        ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  
                                        ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
                                        ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒
                                        ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  
                                        ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒
                                        ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░
                                          ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░
                                        ░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ 
                                              ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     
                                                                                            ░                   
  )";

  
  system("clear");

  // Centre Text Vertically
  for (int i = 0; i < TERMINAL_HEIGHT; i++) {
    cout << endl;
  }

  cout << End_Title << endl;

  // // Centre Text Vertically
  // for (int i = 0; i < TERMINAL_HEIGHT; i++) {
  //   cout << endl;
  // }

  // Print the end line centred under the End Screen
  int offset = end_line.length() / 2;
  cout << setw(78 - offset) << "";
  print(end_line, 100);
}
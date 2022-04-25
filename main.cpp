// #include <unistd.h>
// #include <chrono>
// #include <thread>
// #include <string>

#include <iostream>
#include <string>

using namespace std;

// #include "Helper Functions/Help.h"
#include "Title_Screen.h"

int main()
{
  int game_mode = -1;
  bool saved = false;
  
  Title_Screen(game_mode, saved);

  cout << game_mode << endl;

  // std::string text = "Hello World!";
  
  // for (int i = 0; i < text.length(); i++)
  // {
  //   if (i == text.length()-1)
  //   {
  //     std::cout << text[i] << std::flush;
  //     // Adds the delay
  //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  //     std::cout << std::endl;
  //     // Clears the screen
  //     system("clear");
  //   }
  //   else
  //   {
  //     std::cout << text[i] << std::flush;
  //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
  //   }
  // }
  return 0;
}
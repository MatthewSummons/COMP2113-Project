#include "Helper Functions/Help.h"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string>

int main()
{
  // Title_Screen();

  std::string text = "Hello World!";
  
  for (int i = 0; i < text.length(); i++)
  {
    if (i == text.length()-1)
    {
      std::cout << text[i] << std::flush;
      // Adds the delay
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << std::endl;
      // Clears the screen
      system("clear");
    }
    else
    {
      std::cout << text[i] << std::flush;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
  return 0;
}
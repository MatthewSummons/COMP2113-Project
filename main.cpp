#include "Helper Functions/Help.h"

int main()
{
  setSeed();
  std::cout << RNG(1, 100) << std::endl;

  int arr[4] = {0};
  for (int i{0}; i < 10000; i++)
  {
    std::string item = openTreaure("L", "M", "H", "X");
    if (item == "L")
      arr[0]++;
    else if (item == "M")
      arr[1]++;
    else if (item == "H")
      arr[2]++;
    else
      arr[3]++;
    
  }


  for (int i{0}; i < 4; i++)
  {
    std::cout << arr[i] << std::endl;
  }

  return 0;
}
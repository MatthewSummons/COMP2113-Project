#include <iostream>
#include "Helper Functions/RNG.h"

int main()
{
  setSeed();
  std::cout << RNG(1, 100) << std::endl;

  return 0;
}
#include "RNG.h"

#include <cstdlib>  //For srand() &  rand()
#include <ctime>    // For time()

// Set the seed for the RNG
void setSeed()
{
  srand(time(NULL));
}

// Generates a random number in [low, high]
int RNG(int low, int high)
{
  // Return a random number between low and high inclusive
  return (rand() % high) + low;
}

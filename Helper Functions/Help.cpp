#include "Help.h"
// Included for Editor Suggestions
#include <iostream>
#include <string>

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


// Function which chooses between 4 items of different rarity depending on the biases
// that have been initialized in the function
std::string openTreaure(std::string lowItem, std::string medItem,
  std::string highItem, std::string legendItem)
{
  // Define the upper bounds for which the item of that rarity can be found
  // For example low level items can be found if "luck" is less than 30
  const int lowLuck {40}, medLuck {75}, highLuck {95}, legendLuck {100};
  // With the setup above, there is a 40% chance to get a low level item,
  // a 35% chance to get a medium item, 20% chance for a high & 5% for a legendary

  // Determine the player's "luck" when they open the chest
  int luck {RNG(1, 100)};

  std::cout << "Luck = " << luck << std::endl;
  // Simple control flow to match luck with item
  if (luck < lowLuck)
    return lowItem;
  
  else if (luck < medLuck)
    return medItem;
  
  else if (luck < highLuck)
    return highItem;
  
  else
    return legendItem;
}

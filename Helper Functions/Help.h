#ifndef RNG_H
#define RNG_H

#include <iostream> // For standard I/O
#include <string>   // For the string class
#include <cstdlib>  // For srand() &  rand()
#include <ctime>    // For time()

// Function to set the seed for the game
void setSeed();
// Function to generate a number in a sepcified range
int RNG(int, int);
// Function to return a randomly selected string from input strings
std::string openTreaure(std::string, std::string, std::string, std::string);

#endif

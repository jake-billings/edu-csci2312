/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file for Util functions
 */

//Include stdexcept since we create and throw an exception
// if we get bad values
#include <stdexcept>

//Include random for rand() and srand()
#include <random>

//Use the standard namespace because this isn't production code
// and I don't wanna type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_UTIL_H
#define EDU_CSCI2312_UTIL_H


/**
 * randSeed()
 *
 * function
 *
 * utility function to seed the random number generator
 *
 * called as the first line in main()
 */
void randSeed();


/**
 * randInt()
 *
 * function
 *
 * utility function to make genrating random integers easier
 *
 * min <= value <= max
 *
 * @param min the minimum value an int should be able to take on
 * @param max the max value an int should be able to take on
 * @return a random integer in the inclusive range [min, max]
 */
unsigned int randInt(unsigned int min, unsigned int max);

#endif //EDU_CSCI2312_UTIL_H

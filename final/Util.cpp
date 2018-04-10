/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for Util functions
 */

//Include util header so that we can implement it
#include "Util.h"


/**
 * randSeed()
 *
 * function
 *
 * utility function to seed the random number generator
 *
 * called as the first line in main()
 */
void randSeed() {
    srand(time(NULL));
}


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
unsigned int randInt(unsigned int min, unsigned int max) {
    //Throw error if they gave us parameters that don't make sense
    if (max <= min) {
        throw invalid_argument("in call to randInt(), max must be > min");
    }

    //Perform calculation and return
    return min + rand() % (max - min);
}
/**
 * Name: Jake Billings
 * Date: 02/01/2018
 * Class: CSCI 2312
 * Description:
 *
 * Problem
 * =======
 * Build two grids which are each X width and Y long where X and Y are
 *  user inputs.
 *
 * Randomly select 1/3 of the grid cells to be 1's and 2/3 to be 0's.
 *
 * Compare the two to create a third grid in which 1's exist in only squares
 *  where both of the original grids contained a one.
 *
 * Special Things about my Solution
 * ================================
 *  1. I store three 2D vectors of bool objects because I saw only two states in the problem.
 *     I don't use ints because it's a waste of memory.
 *
 * Test Strategy
 * =============
 * Execute the following tests by hand:
 *
 *  1. Enter 2x2 grid size => grids should be 2x2
 *                         => all cells in gridThree should be the AND of gridOne and gridTwo
 *                         => There should be exactly 1 1 in grids 1 and 2
 *  2. Enter 5x5 grid size => grids should be 5x5
 *                         => all cells in gridThree should be the AND of gridOne and gridTwo
 *                         => There should be exactly 8 1's in grids 1 and 2
 *  3. Enter 5x3 grid size => grids should be 5x3
 *                         => all cells in gridThree should be the AND of gridOne and gridTwo
 *                         => There should be exactly 5 1's in grids 1 and 2
 *
 * Status: Runs on OSX using CLion and on csegrid using g++
 */



//---------Dependency Imports---------
//Include cout
#include <iostream>
//Include time()
#include <time.h>
//include Grid class
#include "Grid.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;


//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Seed the random number generator
    srand(time(NULL));

    //Initialize the desired grid width and height variables
    unsigned int width;
    unsigned int height;

    //Read the width and height via cin
    cout << "How wide should each grid be?" << endl;
    cout << "> ";
    cin >> width;
    cout << "How tall should each grid be?" << endl;
    cout << "> ";
    cin >> height;

    //Add an extra newline for aestetics
    cout << endl;

    //Declare the first two grids; the first two will contain 1/3 1's and 2/3 0's
    // assigned randomly
    Grid gridOne(width, height);
    Grid gridTwo(width, height);

    //Fill grids one and two with 1/3rd ones
    gridOne.fillOneThirdOfGridWithTrue();
    gridTwo.fillOneThirdOfGridWithTrue();

    //Use an overloaded * to combine grids one and two
    // as described in the homework
    Grid gridThree = gridOne * gridTwo;

    //Print all three grids
    cout << "Grid 1" << endl;
    cout << gridOne;
    cout << endl;
    cout << "Grid 2" << endl;
    cout << gridTwo;
    cout << endl;
    cout << "Grid 3" << endl;
    cout << gridThree;
    cout << endl;

    //Exit normal
    return 0;
}
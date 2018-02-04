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
//Include vector
#include <vector>
//Include rand()
#include <random>
//Include time()
#include <time.h>

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

    //Store the desired grid width and height
    const unsigned int width = 5;
    const unsigned int height = 5;

    //Declare the first two grids; the first two will contain 1/3 1's and 2/3 0's
    // assigned randomly
    vector<vector<bool> > gridOne;
    vector<vector<bool> > gridTwo;

    //Declare the third grid, which will contain 1's where both gridOne and gridTwo had 1's
    // and 0's everywhere else
    vector<vector<bool>> gridThree;


    //Generate two empty 2d matrices by appending zeros to
    // arrays then appending vectors of zeros to big vectors
    for (unsigned int i = 0; i < width; i++) {
        vector<bool> rowOne;
        vector<bool> rowTwo;
        for (unsigned int j = 0; j < height; j++) {
            rowOne.push_back(false);
            rowTwo.push_back(false);
        }
        gridOne.push_back(rowOne);
        gridTwo.push_back(rowTwo);
    }

    //Calculate the number of true values we wish to randomly insert
    // into each grid.
    //Since the problem specifies that 1/3rd of each grid must be 1's,
    // we wish to insert one third of the number of elements we can insert,
    // which is the grid size, which is the width times the height.
    //This will function as a floor operation since it uses long/int
    // arithmetic
    const unsigned long desiredInsertCount = gridOne.size() * gridOne[0].size() / 3;

    //While we havn't inserted enough 1 values, insert a 1 value at
    // a random spot in the matrix. Don't insert it if it's
    // already a 1 (that doesn't help at all)
    unsigned int gridOneInsertCount = 0;
    while (gridOneInsertCount < desiredInsertCount) {
        unsigned long x = rand() % gridOne.size();
        unsigned long y = rand() % gridOne[0].size();

        //Don't insert if it's already 1
        if (!gridOne[x][y]) {
            gridOneInsertCount++;
            gridOne[x][y] = true;
        }
    }

    //Repeat the process for grid two
    unsigned int gridTwoInsertCount = 0;
    while (gridTwoInsertCount < desiredInsertCount) {
        unsigned long x = rand() % gridOne.size();
        unsigned long y = rand() % gridOne[0].size();

        //Don't insert if it's already 1
        if (!gridTwo[x][y]) {
            gridTwoInsertCount++;
            gridTwo[x][y] = true;
        }
    }

    //Generate gridThree by iterating over each grid position
    // and inserting a true in gridThree if there's a 1
    // in both gridOne and gridTwo
    for (unsigned int i = 0; i < width; i++) {
        vector<bool> row;
        for (unsigned int j = 0; j < height; j++) {
            row.push_back(gridOne[i][j] == gridTwo[i][j]);
        }
        gridThree.push_back(row);
    }

    cout << "Grid 1" << endl;
    for (unsigned int i = 0; i < gridOne.size(); i++) {
        for (unsigned int j = 0; j < gridOne.size(); j++) {
            cout << gridOne[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    cout << "Grid 2" << endl;
    for (unsigned int i = 0; i < gridTwo.size(); i++) {
        for (unsigned int j = 0; j < gridTwo.size(); j++) {
            cout << gridTwo[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    cout << "Grid 3" << endl;
    for (unsigned int i = 0; i < gridThree.size(); i++) {
        for (unsigned int j = 0; j < gridThree.size(); j++) {
            cout << gridThree[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
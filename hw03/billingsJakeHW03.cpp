/**
 * Name: Jake Billings
 * Date: 02/01/2018
 * Class: CSCI 2312
 * Description:
 *
 * Problem
 * =======
 * Create a class called WaterVehicle that has the following member variables to represent the ship as described in Assignment 1:
 * length of ship (in number of grid spaces)
 * starting grid location
 * horizontal or vertical orientation on grid
 * sunk (Boolean indicating whether the ship has been sunk or not)
 *
 * You will also need to create a reasonable complement of member functions (constructors, accessor, and mutator functions)
 * to create the ships, to set the location of the ship, get the location of the ship, determine if the ship was hit,
 * and determine if the ship is sunk.
 *
 * Then create a Carrier, a Battleship, a Cruiser, a Submarine, and a Destroyer which are all of type WaterVehicle and
 * have the following lengths:
 *
 * Ship Type    Number of Grid Squares
 * Carrier      5
 * Battleship   4
 * Cruiser      3
 * Submarine    3
 * Destroyer    2
 *
 * Test Strategy
 * =============
 * E2E + Integratrion testing in test()
 *  - To test this application, I enter a series of inputs from a text file. These inputs are designed to trigger
 *     multiple types of invalid entries such as ship overlaps and grid excursions. At the end, I check that the
 *     grid is printed correctly in the correct state.
 *
 *    Then, I fire shots to sink the carrier and check that it registers as sunk.
 *
 *    This runs every time the program starts.
 *
 * Status: Runs on OSX using CLion and on csegrid using g++
 */



//---------Dependency Imports---------
//Include cout
#include <iostream>
#include <fstream>
#include <sstream>
//Include vector
#include <vector>
//Include rand()
#include <random>
//Include time()
#include <time.h>
//Include Enums
#include "Enums.h"
//Include WaterVehicle
#include "WaterVehicle.h"
#include "Grid.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;


//---------Poor Man's Testing Suite----------
/**
 * describe()
 *
 * Used to make the style look similar to mocha javascript tests;
 *  All this function really does is print a string followed by "..."
 *
 * @param expectString A string describing what a test is expecting
 */
void describe(const string expectString) {
    cout << expectString << "...";
}

/**
 * assertInt()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertInt(int expected, int got) {
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    cout << endl;

    return expected != got;
}

/**
 * assertString()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertString(string expected, string got) {
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed." << endl << "Expected: \"" << expected << "\"" << endl;
        cout << "Got:      \"" << got << "\"";
    }
    cout << endl;

    return expected != got;
}

//-----------E2E Test Function------------
/**
 * void test()
 *
 * end to end testing for this project
 */
void test() {
    //Print welcome message
    cout << "========E2E Testing========" << endl;

    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    describe("grid: should sucessfully build and print grid");

    const unsigned int width = 5;
    const unsigned int height = width;

    ifstream in;
    in.open("e2einput.txt");
    ofstream outputNull;
    outputNull.open("/dev/null");

    stringstream outputBuf;
    stringstream desiredBuf;

    Grid grid(5, 5);
    grid.interativelyReadFrom(in, outputNull);

    outputBuf << grid;

    desiredBuf << "   | A | B | C | D | E | \n";
    desiredBuf << " 1 | C | C | C | C | C |\n";
    desiredBuf << " 2 | B | B | B | B |   |\n";
    desiredBuf << " 3 |   |   |   |   |Cr |\n";
    desiredBuf << " 4 |   | D | D |   |Cr |\n";
    desiredBuf << " 5 |Sub|Sub|Sub|   |Cr |\n";

    string desired = desiredBuf.str();
    string output = outputBuf.str();

    failCount += assertString(desired, output);

    describe("grid: should not start with isSunk flag to true on the carrier");
    failCount += assertInt(false, grid.getShips()[0].isSunk());

    describe("grid: should not set isSunk flag to true on the carrier after one shot");
    grid.fireShot(Shot(0, 0));
    failCount += assertInt(false, grid.getShips()[0].isSunk());

    describe("grid: should appropriately respond to shots");
    grid.fireShot(Shot(4, 4));
    grid.fireShot(Shot(0, 4));
    grid.fireShot(Shot(0, 3));
    grid.fireShot(Shot(0, 2));
    grid.fireShot(Shot(0, 1));

    stringstream outputBuf2;
    stringstream desiredBuf2;

    outputBuf2 << grid;

    desiredBuf2 << "   | A | B | C | D | E | \n";
    desiredBuf2 << " 1 | X | X | X | X | X |\n";
    desiredBuf2 << " 2 | B | B | B | B |   |\n";
    desiredBuf2 << " 3 |   |   |   |   |Cr |\n";
    desiredBuf2 << " 4 |   | D | D |   |Cr |\n";
    desiredBuf2 << " 5 |Sub|Sub|Sub|   | X |\n";


    string desired2 = desiredBuf2.str();
    string output2 = outputBuf2.str();

    failCount += assertString(desired2, output2);

    describe("grid: should have set the isSunk flag to true on the carrier");
    failCount += assertInt(true, grid.getShips()[0].isSunk());

    int curLen = grid.getShots().size();
    describe("grid: should fire fifteen random shots");
    grid.fireFifteenRandomShots();
    failCount += assertInt(curLen + 15, grid.getShots().size());


    describe("WaterVehicle: should output properly while using overloaded << operator");
    stringstream outputBuf3;
    stringstream desiredBuf3;

    for (unsigned int i = 0; i < grid.getShips().size(); i++) {
        outputBuf3 << grid.getShips()[i] << endl;
    }

    desiredBuf3 << "carrier\t5\t(0, 0)\tsunk" << endl;
    desiredBuf3 << "battleship\t4\t(0, 1)\tnot sunk" << endl;
    desiredBuf3 << "cruiser\t3\t(4, 2)\tsunk" << endl;
    desiredBuf3 << "submarine\t3\t(0, 4)\tnot sunk" << endl;
    desiredBuf3 << "destroyer\t2\t(1, 3)\tnot sunk" << endl;

    string desired3 = desiredBuf3.str();
    string output3 = outputBuf3.str();

    failCount += assertString(desired3, output3);

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End E2E Testing======" << endl;
}

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    test();

    const unsigned int width = 5;
    const unsigned int height = width;

    Grid grid(5, 5);
    grid.interativelyReadFrom(cin, cout);

    cout << grid;

    cout << "Now firing fifteen random shots...";
    grid.fireFifteenRandomShots();
    cout << endl;

    cout << grid;

    for (unsigned int i = 0; i < grid.getShips().size(); i++) {
        cout << grid.getShips()[i] << endl;
    }
    return 0;
}
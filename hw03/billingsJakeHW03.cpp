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
 *	sunk (Boolean indicating whether the ship has been sunk or not)
 *
 * You will also need to create a reasonable complement of member functions (constructors, accessor, and mutator functions)
 * to create the ships, to set the location of the ship, get the location of the ship, determine if the ship was hit,
 * and determine if the ship is sunk.
 *
 * Then create a Carrier, a Battleship, a Cruiser, a Submarine, and a Destroyer which are all of type WaterVehicle and have the following lengths:
 *
 * Ship Type	Number of Grid Squares
 * Carrier      5
 * Battleship   4
 * Cruiser      3
 * Submarine    3
 * Destroyer    2
 *
 *
 * Special Things about my Solution
 * ================================
 *
 *
 * Test Strategy
 * =============
 *
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

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;


//-----------Helper Function------------
//DECLARE printGrid(ship[])
// Parameter: ship[], which is an array of ships representing a board
// Return value: void
// that exist in the "grid" we are printing
void printGrid(ostream &out, vector<WaterVehicle> grid, unsigned int width, unsigned int height) {
    //print blank (in upper left)
    out << "   | ";
    //for i in [0, width)
    for (unsigned int i = 0; i < width; i++) {
        //print convert number to letter i+1 //label the columns
        // such that A=1 etc
        char a = 65 + i;
        out << a;
        out << " | ";
    }
    out << endl;


    for (unsigned int i = 0; i < height; i++) {
        //print j+1 // label the rows
        out << " ";
        out << i + 1;
        out << " |";
        for (unsigned int j = 0; j < width; j++) {
            bool printedShip = false;
            if (grid.size() > 0) {
                for (unsigned int k = 0; k < grid.size(); k++) {
                    //if ship.existsAt(i, j)
                    if (grid[k].existsAt(i, j)) {
                        // print letter for ship.SHIP_TYPE
                        out << grid[k].getLetter();
                        printedShip = true;
                    }
                }
            }
            if (!printedShip) {
                out << "   ";
            }
            out << "|";
        }
        out << endl;
    }
}


//DECLARE createGrid()
// Parameters: input stream (input stream is required since we're going to mock it for testing; it would be in for a
//  real game)
// Return value: ship[2][5] - an array of ship arrays each ship[5] represents a fleet grid
//  *The return value might actually be vectors because .push_back() would be useful
//
vector<vector<WaterVehicle>> createGrid(istream &in, ostream &out, unsigned int width, unsigned int height) {

    //declare a vector of ship vectors to store all boards for the game
    //For each player [0,1]
    vector<vector<WaterVehicle>> grid;
    vector<WaterVehicle> humanGrid;

    //declare a ship vector for current player
    //For each SHIP_TYPE in SHIP_TYPES (5 ship types)
    for (unsigned int i = 0; i < SHIP_TYPE_COUNT; i++) {
        SHIP_TYPE shipType = ALL_SHIP_TYPES[i];

        //if the player is a HUMAN
        //print board (the ship vector for current player)
        printGrid(out, humanGrid, width, height);

        //print message that says we're plaing a ship of type SHIP_TYPE
        //print a message that says we want the upper left hand corner
        // todo this doesn't quite work
        out << "Where would you like to place your " << getNameForShipType(shipType) << "?" << endl;

        //input := getline() from in
        //if the input isn't in the form A1, print error message and accept input again
        //convert the input to (x, y) coordinates where x is the number that corresponds with the letter and y is the number-1
        //E.g. D2 -> x=3, y=1 (since we're zero indexed)
        out << "col> ";
        char colChar;
        in >> colChar;
        int col = colChar - 65; //todo vlaidate
        out << "row> ";
        int row;
        in >> row;
        row--;

        //if the x, y is outside the grid, print message and try again
        if (col > width || row > height || col < 0 || row < 0) {
            out << "Sorry. That's outside of the grid. Please try again." << endl;
            i--;
        } else {

            //calculate the two possible lower right corners of the ship
            //  This are at x+length, y (horizontal) and x, y+length (vertical)
            out << "The lower right of corner of your ship could be at ";
            out << "(" << (col + getLengthForShipType(shipType)) << ", " << row << ") or (" << col << ", "
                << (row + getLengthForShipType(shipType)) << ")";
            out << endl;


            //ask the user which option they want
            out << "Would you like your ship to be horizontal? (Y/n)" << endl;
            out << "> ";
            char inputHorizontal;
            in >> inputHorizontal;

            SHIP_ORIENTATION orientation;
            if (inputHorizontal == 'Y') {
                orientation = SHIP_ORIENTATION::HORIZONTAL;
            } else {
                orientation = SHIP_ORIENTATION::VERTICAL;
            }

            //if the selected option implies a lower right corner that is outside the grid, print message
            //and try again
            bool placementIsInGrid =
                    (orientation == SHIP_ORIENTATION::HORIZONTAL) ?
                    (col + getLengthForShipType(shipType) <= width) :
                    (row + getLengthForShipType(shipType) <= height);

            //init a ship object
            WaterVehicle ship(col, row, orientation, shipType);

            bool overlapsWithAnotherShip = false;
            //for otherShip in ship vector for current player
            for (unsigned int k = 0; k < humanGrid.size(); k++) {
                //if ship.overlapsWith(otherShip)
                if (ship.overlapsWith(humanGrid[k])) {
                    overlapsWithAnotherShip = true;
                }
            }

            if (placementIsInGrid && !overlapsWithAnotherShip) {
                //if valid,
                //push the object into the vector for the current player
                humanGrid.push_back(ship);
            } else {
                //if not,
                //print an error message and try again
                out << "Sorry, you cannot place a ship there. Please try again." << endl;
                i--;
            }
        }
    }

    //push the ship vector for the player into the multivector that stores data for the game
    grid.push_back(humanGrid);

    //if the player is a machine
    //query the smart (or random) algorithm to place the ship...
    //for example,
    //generate x in range [0, width-SHIP_TYPE.length]
    //generate y in range [0, height-SHIP_TYPE.length]
    //flip coin (generate random bool) to determine orientation

    //return the ship multivector that stores boards for the whole game
    return grid;
}


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
        cout << "Failed." << endl << "Expected: \"" << expected << "\""<< endl;
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

    vector<vector<WaterVehicle>> grid = createGrid(in, outputNull, width, height);
    printGrid(outputBuf, grid[0], width, height);

    desiredBuf << "   | A | B | C | D | E | \n";
    desiredBuf << " 1 | C | C | C | C | C |\n";
    desiredBuf << " 2 | B | B | B | B |   |\n";
    desiredBuf << " 3 |   |   |   |   |Cr |\n";
    desiredBuf << " 4 |   | D | D |   |Cr |\n";
    desiredBuf << " 5 |Sub|Sub|Sub|   |Cr |\n";

    string desired = desiredBuf.str();
    string output = outputBuf.str();

    failCount += assertString(desired, output);

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

    vector<vector<WaterVehicle>> grid = createGrid(cin, cout, width, height);
    printGrid(cout, grid[0], width, height);

    return 0;
}
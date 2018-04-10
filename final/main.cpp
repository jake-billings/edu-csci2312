/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description:
 *
 * ==============
 * = Battleship =
 * ==============
 *
 * Problem
 * =======
 * "For many of us old school gamers, we started out playing good old fashioned board games.  Many of us learned strategy
 * from games like Risk and Battleship.  For your project, you will be developing a simple battleship type game to test
 * your knowledge of the concepts we have learned in Object Oriented Programming.
 *
 * The purpose of this project is to have you design of a fairly complicated project using concepts we have learned and
 * then implement the solution using some of the code that we wrote in the previous projects along with new code, and
 * then test your game." - CSCI 2312 Final Project.docx
 *
 * See "CSCI 2312 Final Project.docx" for complete problem statement and requirement set.
 *
 * Create a Carrier, a Battleship, a Cruiser, a Submarine, and a Destroyer which are all of type WaterVehicle and
 * have the following lengths:
 *
 * Ship Type    Number of Grid Squares
 * Carrier      5
 * Battleship   4
 * Cruiser      3
 * Submarine    3
 * Destroyer    2
 *
 *
 * Overview
 * ========
 * The Game class contains two players. The Player class has references to both its own grid and to the other player's
 *  grid. The grids are represented as sparse arrays using the vector data structure. Player is an abstract class.
 *  There exists both a Computer and a Human implementation of the class. Game handles turn and winning logic. Thus,
 *  it is trivial to pit two CPUs against each other or to pit two players against each other.
 *
 *  See Design Document.docx for additional engineering design documentation.
 *  See HW03 for early progress towards this final project (final code is all in this folder)
 *  See HW04 for early design for this final project (final documentation is all in this folder (final))
 *
 *
 * Extra Credit
 * ============
 * I implemented the portion of the extra credit piece that requires an entire ship to be hit in order to be considered
 *  sunk. When a shot is fired into the grid, the grid checks if it sunk any ships. If it does, it marks said ship as
 *  sunk. Thus, the logic is found primarily in Grid::fireShot(). The boolean is then read by other logic to determine
 *  if the ship has been sunk. For instance, the Player::hasLost() method checks all of the ships in the player's grid.
 *
 *
 * Test Strategy
 * =============
 * Integratrion testing in test()
 *  - To test this application, I created a series of unit/intergration tests in test()
 *    calls to describe() state what each test does
 *    multiple mock input csv files are used to validate inputs from the csv file
 *
 *
 * Status: Runs on OSX using CLion and on csegrid using g++
 */

//---------Dependency Imports---------
//Include cout to print stuff to console
#include <iostream>
//Include fstream to test reading from files
#include <fstream>
//Include sstream to test output stream responses in test()
#include <sstream>
//---Project Headers---
//Include all project headers since we use and test them
#include "Enums.h"
#include "WaterVehicle.h"
#include "Grid.h"
#include "Util.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Game.h"

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
    //Abstract grid width and height as constants
    // we don't use these for every grid
    // sometimes we intentionally manipulate grid size
    // for testing
    // however this should be the assumed
    // size when actually playing
    const unsigned int WIDTH = 10;
    const unsigned int HEIGHT = WIDTH;


    //Print welcome message
    cout << "========Testing========" << endl;

    //Keep track of how many unit tests we fail
    unsigned int failCount = 0;

    //Open an input stream to the main "ship_placement.csv" file
    // this file should be properly formatted for game play
    // as per the project requirements
    // the one I use was provided with the project
    ifstream in;
    in.open("ship_placement.csv");

    //---Test Util---
    describe("Util: randInt(): should throw err if max is less than min");
    bool err = false;
    try {
        randInt(500, 1);
    } catch (invalid_argument e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("Util: randInt(): should generate numbers in proper range");
    err = false;
    for (unsigned int i = 0; i < 100000; i++) {
        unsigned int j = randInt(10, 100);
        if (j < 10 || j > 100) {
            err = true;
            break;
        }
    }
    failCount += assertInt(false, err);

    //---Test WaterVehicle---
    describe("WaterVehicle: operator<<: should throw exception reading the header row of the ship_placement.csv file");
    err = false;
    try {
        WaterVehicle v;
        in >> v;
    } catch (invalid_argument e) {
        err = true;
    }
    failCount += assertInt(true, err);

    WaterVehicle v;
    string dummy;

    //Reset the file and jump to the next line in order
    // to test only reading lines from files
    in.clear();
    in.seekg(0, ios::beg);
    getline(in, dummy);

    //read row 1 (depends on specific values actually being in the file)
    in >> v;
    describe("WaterVehicle: operator>>: should read shipType CARRIER from first row of the ship_placement.csv file");
    failCount += assertInt(SHIP_TYPE::CARRIER, v.getShipType());
    describe("WaterVehicle: operator>>: should read col A from first row of the ship_placement.csv file");
    failCount += assertInt(0, v.getX());
    describe("WaterVehicle: operator>>: should read row 1 from first row of the ship_placement.csv file");
    failCount += assertInt(0, v.getY());
    describe("WaterVehicle: operator>>: should read orientation H from first row of the ship_placement.csv file");
    failCount += assertInt(SHIP_ORIENTATION::HORIZONTAL, v.getShipOrientation());

    //read row 2 (depends on specific values actually being in the file)
    WaterVehicle v2;
    in >> v2;
    describe("WaterVehicle: operator>>: should read shipType CARRIER from second row of the ship_placement.csv file");
    failCount += assertInt(SHIP_TYPE::BATTLESHIP, v2.getShipType());
    describe("WaterVehicle: operator>>: should read col B from second row of the ship_placement.csv file");
    failCount += assertInt(1, v2.getX());
    describe("WaterVehicle: operator>>: should read row 5 from second row of the ship_placement.csv file");
    failCount += assertInt(4, v2.getY());
    describe("WaterVehicle: operator>>: should read orientation H from second row of the ship_placement.csv file");
    failCount += assertInt(SHIP_ORIENTATION::HORIZONTAL, v2.getShipOrientation());

    //Reset because we reuse this input stream later
    in.clear();
    in.seekg(0, ios::beg);

    //---Test Grid---
    describe("Grid: operator>>: should throw error reading grid from csv file without header");
    ifstream inNoHeader;
    inNoHeader.open("ship_placement_no_header.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inNoHeader >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inNoHeader.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should throw error reading grid from csv file with duplicate ships");
    ifstream inDuplicateShips;
    inDuplicateShips.open("ship_placement_duplicate_ships.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inDuplicateShips >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inDuplicateShips.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should throw error reading grid from csv file with only four ships");
    ifstream inFour;
    inFour.open("ship_placement_four_ships.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inFour >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inFour.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should throw error reading grid from csv file with only overlapping ships");
    ifstream inOverlapping;
    inOverlapping.open("ship_placement_overlapping_ships.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inOverlapping >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inOverlapping.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should throw error reading grid from csv file with ships outside the grid");
    ifstream inOutsideGrid;
    inOverlapping.open("ship_placement_outside_grid_ships.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inOutsideGrid >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inOutsideGrid.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should throw error reading grid from csv file with six ships in the grid");
    ifstream inSix;
    inSix.open("ship_placement_six_ships.csv");
    err = false;
    try {
        Grid g(WIDTH, HEIGHT);
        inSix >> g;
    } catch (invalid_argument e) {
        err = true;
    }
    inSix.close();
    failCount += assertInt(true, err);

    describe("Grid: operator>>: should read grid from csv file without throwing error");
    Grid grid(WIDTH, HEIGHT);
    err = false;
    try {
        in >> grid;
    } catch (invalid_argument e) {
        err = true;
    }
    failCount += assertInt(false, err);

    //---Test ComputerPlayer---
    describe("ComputerPlayer: placeShips(): should throw error trying to place ships into a grid they won't fit in");
    Grid cpuGrid(4, 4);
    Grid otherGrid(4, 4);
    ComputerPlayer cpu(&cpuGrid, &otherGrid);
    err = false;
    try {
        cpu.placeShips();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("ComputerPlayer: placeShips(): should place ships in a big grid just fine");
    Grid cpuGrid2(10, 10);
    Grid otherGrid2(4, 4);
    ComputerPlayer cpu2(&cpuGrid2, &otherGrid2);
    err = false;
    try {
        cpu2.placeShips();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("ComputerPlayer: fireShot(): should fire nine shots successfully into 3x3 grid");
    Grid cpuGrid3(3, 3);
    Grid otherGrid3(3, 3);
    ComputerPlayer cpu3(&cpuGrid3, &otherGrid3);
    err = false;
    try {
        for (unsigned int i = 0; i < 9; i++) {
            cpu3.fireShot();
        }
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("ComputerPlayer: fireShot(): 9 shots should now be in grid shot array");
    failCount += assertInt(9, otherGrid3.getShots().size());

    describe("ComputerPlayer: fireShot(): should fail to fire a tenth shot into 3x3 grid");
    err = false;
    try {
        cpu3.fireShot();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    //---Test Game---
    describe("Game: should play a CPU v CPU game without throwing an exception");

    Grid aGrid(WIDTH, HEIGHT);
    Grid bGrid(WIDTH, HEIGHT);

    //Create players from those grids
    ComputerPlayer a(&aGrid, &bGrid);
    ComputerPlayer b(&bGrid, &aGrid);

    a.placeShips();
    b.placeShips();

    Game game(&a, &b);

    while (!game.hasLoser()) {
        game.executeRound();
    }

    stringstream outputBuf;
    game.getWinner()->print(outputBuf);

    failCount += assertString("Computer Player\n", outputBuf.str());


    //---Test HumanPlayer---
    describe("HumanPlayer: placeShips(): should place ships in grid by reading from input file");
    Grid grid5(10, 10);
    Grid otherGrid5(4, 4);
    HumanPlayer human(&grid5, &otherGrid5, &cout, &cin);
    err = false;
    try {
        human.placeShips();
    } catch (runtime_error e) {
        err = true;
    } catch (invalid_argument e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("HumanPlayer: operator<<: should output as human player");
    stringstream outputBuf2;
    human.print(outputBuf2);
    failCount += assertString("Human Player\n", outputBuf2.str());

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Testing======" << endl;
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
    //First thing, seed the random number generator using Util function
    randSeed();

    //Second, call the test() function so that we know everything works
    test();

    //Abstract grid width and height as constants
    // we don't use these for every grid
    // sometimes we intentionally manipulate grid size
    // for testing
    // however this should be the assumed
    // size when actually playing
    const unsigned int WIDTH = 10;
    const unsigned int HEIGHT = WIDTH;

    //Create grids
    Grid playerGrid(WIDTH, HEIGHT);
    Grid computerGrid(WIDTH, HEIGHT);

    //Create players from those grids
    ComputerPlayer computer(&computerGrid, &playerGrid);
    HumanPlayer player(&playerGrid, &computerGrid, &cout, &cin);

    //Populate player grid from file
    try {
        player.placeShips();
    } catch (invalid_argument e) {
        cout << "Error reading your ship_placement.csv file. See below for details." << endl;
        cerr << e.what() << endl;
    }

    //Populate computer grid randomly
    computer.placeShips();

    //Create a game object to manage placing ships into the grid
    Game game(&player, &computer);

    //While nobody has lost, continue playing
    // somebody will win eventually
    // if a runtime_error is thrown, it means the user has quit
    // so, we dump the grids to the console and quit
    try {
        while (!game.hasLoser()) {
            game.executeRound();
        }

        //Print which player won
        cout << "The winner is: ";
        game.getWinner()->print(cout);
    } catch (runtime_error e) {
        cout << "The user has opted to quit. Here's the grid state:" << endl;

        cout << "====================Your grid====================" << endl;
        cout << *game.getA()->getGrid() << endl;
        cout << "=================================================" << endl;
        cout << "===============Your Opponent's Grid===============" << endl;
        cout << *game.getB()->getGrid() << endl;
        cout << "==================================================" << endl;
    }


    //Return 0 since we successfully made it to the end of a game
    return 0;
}

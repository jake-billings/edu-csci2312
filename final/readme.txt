*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     :  CSC 2312
*  Due Date  :  Apr. 9, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************


 ==============
 = Battleship =
 ==============

 Problem
 =======
 "For many of us old school gamers, we started out playing good old fashioned board games.  Many of us learned strategy
 from games like Risk and Battleship.  For your project, you will be developing a simple battleship type game to test
 your knowledge of the concepts we have learned in Object Oriented Programming.

 The purpose of this project is to have you design of a fairly complicated project using concepts we have learned and
 then implement the solution using some of the code that we wrote in the previous projects along with new code, and
 then test your game." - CSCI 2312 Final Project.docx

 See "CSCI 2312 Final Project.docx" for complete problem statement and requirement set.

 Create a Carrier, a Battleship, a Cruiser, a Submarine, and a Destroyer which are all of type WaterVehicle and
 have the following lengths:

 Ship Type    Number of Grid Squares
 Carrier      5
 Battleship   4
 Cruiser      3
 Submarine    3
 Destroyer    2


 Overview
 ========
 The Game class contains two players. The Player class has references to both its own grid and to the other player's
  grid. The grids are represented as sparse arrays using the vector data structure. Player is an abstract class.
  There exists both a Computer and a Human implementation of the class. Game handles turn and winning logic. Thus,
  it is trivial to pit two CPUs against each other or to pit two players against each other.

  See Design Document.docx for additional engineering design documentation.
  See HW03 for early progress towards this final project (final code is all in this folder)
  See HW04 for early design for this final project (final documentation is all in this folder (final))


 Extra Credit
 ============
 I implemented the portion of the extra credit piece that requires an entire ship to be hit in order to be considered
  sunk. When a shot is fired into the grid, the grid checks if it sunk any ships. If it does, it marks said ship as
  sunk. Thus, the logic is found primarily in Grid::fireShot(). The boolean is then read by other logic to determine
  if the ship has been sunk. For instance, the Player::hasLost() method checks all of the ships in the player's grid.


 Test Strategy
 =============
 Integratrion testing in test()
  - To test this application, I created a series of unit/intergration tests in test()
    calls to describe() state what each test does
    multiple mock input csv files are used to validate inputs from the csv file


 Status: Runs on OSX using CLion and on csegrid using g++

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
    test() - runs automated E2E and integration testing using a few helper test functions
    main() - runs test() then provides an interactive demo

Name: ComputerPlayer.h
    declaration file containing ComputerPlayer class
    represents a player that is a computer
    plays with random strategy

Name: ComputerPlayer.cpp
    implementation file containing ComputerPlayer class
    represents a player that is a computer
    plays with random strategy

Name: Enums.h
    declaration file containing SHIP_TYPE and SHIP_ORIENTATION enums

Name: Enums.cpp
    implementation file containing helper functions to get names and lengths from enum types

Name: Game.h
    declaration file containing Game class
    represents a game between two players and the logic of ending when someone wins

Name: Game.cpp
    declaration file containing Game class
    represents a game between two players and the logic of ending when someone wins

Name: Grid.h
    declaration file for the Grid class, which represents a grid of ships

Name: Grid.cpp
    implementation file containing all the functions from Grid

Name: HumanPlayer.h
    declaration file containing HumanPlayer class
    represents a player that is a human
    prompts a human user for input on what moves to make via input streams

Name: HumanPlayer.cpp
    implementation file containing HumanPlayer class
    represents a player that is a human
    prompts a human user for input on what moves to make via input streams

Name: Player.h
    declaration file containing Player class
    abstract class represents a player that is a human or a computer
    HumanPlayer and ComputerPlayer implement this abstract class with different strategies

Name: Player.cpp
    implementation file containing Player class
    abstract class represents a player that is a human or a computer
    HumanPlayer and ComputerPlayer implement this abstract class with different strategies

Name: Shot.h
    declaration file for Shot class, which represents a shot into the grid with X, Y coordinates

Name: Shot.cpp
    implementation file for Shot class, which represents a shot into the grid with X, Y coordinates

Name: Util.h
    declaration file for utility functions that make it easier to use rand() from <random>

Name: Shot.cpp
    implementation file for utility functions that make it easier to use rand() from <random>

Name: WaterVehicle.h
    declaration file for WaterVehicle class, which represents a ship in the grid

Name: WaterVehicle.h
    implementation file for WaterVehicle class, which represents a ship in the grid

Name: ship_placement.csv
    file provided with assignment that contains the placement of ships in the grid

Name: ship_placement_duplicate_ships.csv
    test csv file that should cause an error reading ships; ships have been duplicated
    see test() in main

Name: ship_placement_four_ships.csv
    test csv file that should cause an error reading ships; there are only four ships (there should be five)
    see test() in main

Name: ship_placement_no_header.csv
    test csv file that should cause an error reading ships; there is no csv header
    see test() in main

Name: ship_placement_outside_grid_ships.csv
    test csv file that should cause an error reading ships; there are ships outside of the grid
    see test() in main

Name: ship_placement_outside_overlapping_ships.csv
    test csv file that should cause an error reading ships; there are overlapping ships
    see test() in main

Name: ship_placement_six_ships.csv
    test csv file that should cause an error reading ships; there are six ships (there should be five)
    see test() in main

Name: makefile
    c++ makefile that build the project on csegrid

Name: CSCI 2312 Final Project.docx
    microsoft word
    the original project file documenting all requirements

Name: Design Document Template.docx
    microsoft word
    the original template file for project documentation

Name: Design Document.docx
    microsoft word
    additional documentation regarding class types and project architecture

   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.


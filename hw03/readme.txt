*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     :  CSC 2312
*  Due Date  :  Feb. 3, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

 Problem
 =======
 Create a class called WaterVehicle that has the following member variables to represent the ship as described in Assignment 1:
 length of ship (in number of grid spaces)
 starting grid location
 horizontal or vertical orientation on grid
 sunk (Boolean indicating whether the ship has been sunk or not)

 You will also need to create a reasonable complement of member functions (constructors, accessor, and mutator functions)
 to create the ships, to set the location of the ship, get the location of the ship, determine if the ship was hit,
 and determine if the ship is sunk.

 Then create a Carrier, a Battleship, a Cruiser, a Submarine, and a Destroyer which are all of type WaterVehicle and
 have the following lengths:

 Ship Type    Number of Grid Squares
 Carrier      5
 Battleship   4
 Cruiser      3
 Submarine    3
 Destroyer    2
 
 Test Strategy
 =============
 E2E + Integratrion testing in test()
  - To test this application, I enter a series of inputs from a text file. These inputs are designed to trigger
     multiple types of invalid entries such as ship overlaps and grid excursions. At the end, I check that the
     grid is printed correctly in the correct state.
     
    Then, I fire shots to sink the carrier and check that it registers as sunk.
    
    This runs every time the program starts.

 Status: Runs on OSX using CLion and on csegrid using g++

*******************************************************
*  Source files
*******************************************************

Name:  billingsJakeHW03.cpp
    test() - runs automated E2E and integration testing using a few helper test functions
    main() - runs test() then provides an interactive demo

Name: Enums.h
    declaration file containing SHIP_TYPE and SHIP_ORIENTATION enums

Name: Enums.cpp
    implementation file containing helper functions to get names and lengths from enum types

Name: Grid.h
    declaration file for the Grid class, which represents a grid of ships

Name: Grid.cpp
    implementation file containing all the functions from Grid

Name: Shot.h
    declaration file for Shot class, which represents a shot into the grid with X, Y coordinates

Name: Shot.cpp
    implementation file for Shot class, which represents a shot into the grid with X, Y coordinates

Name: WaterVehicle.h
    declaration file for WaterVehicle class, which represents a ship in the grid

Name: WaterVehicle.h
    implementation file for WaterVehicle class, which represents a ship in the grid

   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.


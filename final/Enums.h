/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file containing enums and utility functions that convert SHIP_TYPE to length ints and name strings
 */
#include <string>

//Use the standard namespace because this isn't production code
// and I don't wanna type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_ENUMS_H
#define EDU_CSCI2312_ENUMS_H

//SHIP_TYPE
// Declare an enumeration called SHIP_TYPE with the following values:
// Carrier (length=5)
// Battleship (length=4)
// Cruiser (length=3)
// Submarine (length=3)
// Destroyer (length=2)
enum SHIP_TYPE {
    CARRIER=1,
    BATTLESHIP=2,
    CRUISER=3,
    SUBMARINE=4,
    DESTROYER=5
};

//DECLARE ALL_SHIP_TYPES
// array of all ship types for easy iteration
const SHIP_TYPE ALL_SHIP_TYPES[] = {CARRIER, BATTLESHIP, CRUISER, SUBMARINE, DESTROYER};
//DECLARE ALL_SHIP_TYPES
// an int count of ship types for easy iteration
const unsigned int SHIP_TYPE_COUNT = 5;

//SHIP_ORIENTATION
// Declare an enumeration called SHIP_TYPE with the following values:
// Horizontal
// Vertical
enum SHIP_ORIENTATION {
    HORIZONTAL=1,
    VERTICAL=2
};

//DECLARE ALL_SHIP_TYPES
// an int count of ship orientations for easy iteration
const SHIP_ORIENTATION ALL_SHIP_ORIENTATIONS[] = {HORIZONTAL, VERTICAL};

//DECLARE SHIP_ORIENTATION_COUNT
// array of all ship orientations for easy iteration
const unsigned int SHIP_ORIENTATION_COUNT = 2;

//DECLARE length for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: unsigned integer representing the length of a ship
unsigned int getLengthForShipType(SHIP_TYPE shipType);

//DECLARE name for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: string representing the name of a ship
string getNameForShipType(SHIP_TYPE shipType);

#endif
#include <string>

using namespace std;

#ifndef EDU_CSCI2312_ENUMS_H
#define EDU_CSCI2312_ENUMS_H

//SHIP_TYPE
// todo get rid of this cause by the reqirements, we have to store the
// int length not the SHIP_TYPE :(
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

const SHIP_TYPE ALL_SHIP_TYPES[] = {CARRIER, BATTLESHIP, CRUISER, SUBMARINE, DESTROYER};
const unsigned int SHIP_TYPE_COUNT = 5;

//SHIP_ORIENTATION
// Declare an enumeration called SHIP_TYPE with the following values:
// Horizontal
// Vertical
enum SHIP_ORIENTATION {
    HORIZONTAL=1,
    VERTICAL=2
};


//DECLARE length for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: unsinged integer representing the length of a ship
unsigned int getLengthForShipType(SHIP_TYPE shipType);

//DECLARE name for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: string representing the name of a ship
string getNameForShipType(SHIP_TYPE shipType);

#endif
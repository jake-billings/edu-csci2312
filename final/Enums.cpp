/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file containing utility functions that convert SHIP_TYPE to length ints and name strings
 */
#include "Enums.h"

//DECLARE length for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: unsinged integer representing the length of a ship
unsigned int getLengthForShipType(SHIP_TYPE shipType) {
    switch (shipType) {
        case CARRIER:
            return 5;
        case BATTLESHIP:
            return 4;
        case CRUISER:
            return 3;
        case SUBMARINE:
            return 3;
        case DESTROYER:
            return 2;
        default:
            return 0;
    }
}

//DECLARE name for SHIP_TYPE
// Parameters: shipType SHIP_TYPE
// Return value: string representing the name of a ship
string getNameForShipType(SHIP_TYPE shipType) {
    switch (shipType) {
        case CARRIER:
            return "carrier";
        case BATTLESHIP:
            return "battleship";
        case CRUISER:
            return "cruiser";
        case SUBMARINE:
            return "submarine";
        case DESTROYER:
            return "destroyer";
        default:
            return "unknown";
    }
}
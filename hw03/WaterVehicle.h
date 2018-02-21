//
// Created by Jake Billings on 2/3/18.
//

#ifndef EDU_CSCI2312_WATERVEHICLE_H
#define EDU_CSCI2312_WATERVEHICLE_H

//Include string since we need it for getLetter()
#include <string>
#include "Enums.h"

//Use the standard namespace
using namespace std;

//-----------Data Structures/Classes----------

/**
 * WaterVehicle
 *
 * Represents a ship in the battleship project as an element in a sparse array instead of a grid
 */
//SHIP
// Declare a data structure called Ship with the following properties:
// int x - the x value of the leftmost corner of the ship
// int y - the y value of the uppermost corner of the ship
// SHIP_TYPE shipType - the type (and therefore length) of the ship
// SHIP_ORIENTATION - the orientation of the ship (which determines where its lower right corner is)
//
// help from: https://www.geeksforgeeks.org/find-two-rectangles-overlap/
// DECLARE ship.overlapsWith()
// Parameters: the other ship to check if this ship overlaps with
// Return value: boolean representing whether or not this ship overlaps with the other
//  a boolean function that checks if this instance of ship overlaps with another
/*If one rectangle is on left side of other
  if (this.upperLeftX > other.lowerRightX || this.lowerRightX > other.upperLeftX ) return false
 If one rectangle is above other
  if (this.upperLeftY < other.lowerRightY || this.lowerRightY < other.upperLeftY ) return false
 return true*/
class WaterVehicle {
private:
    /**
     * x
     *
     * the x coordinate of the upper lefthand corner of the ship
     */
    unsigned int x;

    /**
     * y
     *
     * the y coordinate of the upper lefthand corner of the ship
     */
    unsigned int y;

    /**
     * shipOrientation
     *
     * the orientation of the ship (horizontal or vertical)
     */
    SHIP_ORIENTATION shipOrientation;

    /**
     * shipType
     *
     * the type of the ship (horizontal or vertical)
     */
    SHIP_TYPE shipType;

    /**
     * sunk
     *
     * a boolean representing whether or not a ship has been sunk
     *  by an enemy torpedo
     */
    bool sunk = false;

public:
    WaterVehicle(unsigned int x, unsigned int y, SHIP_ORIENTATION shipOrientation, SHIP_TYPE shipType);

    // DECLARE ship.existsAt()
    // Parameters: i, j representing x y coordinate to check against the ship's location
    // Return value: boolean representing whether or not the ship exists at that point
    /* bool existsAt(int i, int j)
      a boolean function that checks if a ship exists at a grid space
      if ship is HORIZONTAL
        return true if y matches j and i >= x and i< x+length
      else if ship is VERTICAL
        return true if x matches i and j >= y and j< y+length*/
        //Getters and setters
    bool existsAt(unsigned int i, unsigned int j);

    bool overlapsWith(WaterVehicle other);

    /**
     * getLetter()
     *
     * @returns an apporpriate string to represent the ship in the grid
     */
    string getLetter();

    friend ostream& operator<<(ostream &out, WaterVehicle vehicle);

    //Getters and Setters
    unsigned int getLength() const;
    unsigned int getX() const;
    void setX(unsigned int x);
    unsigned int getY() const;
    void setY(unsigned int y);
    SHIP_ORIENTATION getShipOrientation() const;
    SHIP_TYPE getShipType() const;
    void setShipType(SHIP_TYPE shipType);
    void setShipOrientation(SHIP_ORIENTATION shipOrientation);
    bool isSunk() const;
    void setSunk(bool isSunk);
};


#endif //EDU_CSCI2312_WATERVEHICLE_H

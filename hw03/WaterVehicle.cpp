//
// Created by Jake Billings on 2/3/18.
//

#include "Enums.h"
#include "WaterVehicle.h"

// DECLARE ship.existsAt()
// Parameters: i, j representing x y coordinate to check against the ship's location
// Return value: boolean representing whether or not the ship exists at that point
/* bool existsAt(int i, int j)
  a boolean function that checks if a ship exists at a grid space
  if ship is HORIZONTAL
    return true if y matches j and i >= x and i< x+length
  else if ship is VERTICAL
    return true if x matches i and j >= y and j< y+length*/
bool WaterVehicle::existsAt(unsigned int row, unsigned int col) {
    if (this->getShipOrientation() == SHIP_ORIENTATION::HORIZONTAL) {
        return (this->getY() == row)
               && col >= (this->getX())
               && col < (this->getX() + this->getLength());
    }
    return this->getX() == col && row >= this->getY() && row < (this->getY() + this->getLength());
}

// DECLARE ship.overlapsWith()
// Parameters: the other ship to check if this ship overlaps with
// Return value: boolean representing whether or not this ship overlaps with the other
//  a boolean function that checks if this instance of ship overlaps with another
/*If one rectangle is on left side of other
  if (this.upperLeftX > other.lowerRightX || this.lowerRightX > other.upperLeftX ) return false
 If one rectangle is above other
  if (this.upperLeftY < other.lowerRightY || this.lowerRightY < other.upperLeftY ) return false
 return true*/
bool WaterVehicle::overlapsWith(WaterVehicle other) {
    if (this->getX() > other.getX()+(other.getShipOrientation()==SHIP_ORIENTATION::HORIZONTAL?other.getLength():0)) {
        return false;
    }
    if (this->getX()+(this->getShipOrientation()==SHIP_ORIENTATION::HORIZONTAL?this->getLength():0) < other.getX()){
        return false;
    }
    if (this->getY() > (other.getY()+(other.getShipOrientation()==SHIP_ORIENTATION::VERTICAL?other.getLength():0))) {
        return false;
    }
    if ((this->getY()+(this->getShipOrientation()==SHIP_ORIENTATION::VERTICAL?this->getLength():0)) < other.getY()) {
        return false;
    }
    return true;
}

/**
 * getLetter()
 *
 * @return an apporpriate string to represent the ship in the grid
 */
string WaterVehicle::getLetter() {
    switch (this->shipType) {
        case CARRIER:
            return " C ";
        case BATTLESHIP:
            return " B ";
        case CRUISER:
            return "Cr ";
        case SUBMARINE:
            return "Sub";
        case DESTROYER:
            return " D ";
        default:
            return "UNKNOWN";
    }
}

//Getters and Setters
unsigned int WaterVehicle::getLength() const {
    return getLengthForShipType(this->getShipType());
}

unsigned int WaterVehicle::getX() const {
    return x;
}

void WaterVehicle::setX(unsigned int x) {
    WaterVehicle::x = x;
}

unsigned int WaterVehicle::getY() const {
    return y;
}

void WaterVehicle::setY(unsigned int y) {
    WaterVehicle::y = y;
}

SHIP_ORIENTATION WaterVehicle::getShipOrientation() const {
    return shipOrientation;
}

void WaterVehicle::setShipOrientation(SHIP_ORIENTATION shipOrientation) {
    WaterVehicle::shipOrientation = shipOrientation;
}

bool WaterVehicle::isIsSunk() const {
    return isSunk;
}

void WaterVehicle::setIsSunk(bool isSunk) {
    WaterVehicle::isSunk = isSunk;
}

SHIP_TYPE WaterVehicle::getShipType() const {
    return shipType;
}

void WaterVehicle::setShipType(SHIP_TYPE shipType) {
    WaterVehicle::shipType = shipType;
}

WaterVehicle::WaterVehicle(unsigned int x, unsigned int y, SHIP_ORIENTATION shipOrientation, SHIP_TYPE shipType) : x(x), y(y), shipOrientation(shipOrientation), shipType(shipType),
                                          isSunk(false) {}

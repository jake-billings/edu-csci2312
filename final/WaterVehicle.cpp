/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for WaterVehicle class
 */

#include "WaterVehicle.h"

/**
 * WaterVehicle
 *
 * constructor
 *
 * creates a basic ship to insert into the grid
 *
 * @param x
 * @param y
 * @param shipOrientation
 * @param shipType
 */
WaterVehicle::WaterVehicle(unsigned int x, unsigned int y, SHIP_ORIENTATION shipOrientation, SHIP_TYPE shipType)
        : x(x), y(y), shipOrientation(shipOrientation), shipType(shipType), sunk(false) {}


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
    if (this->getX() >
        other.getX() + (other.getShipOrientation() == SHIP_ORIENTATION::HORIZONTAL ? other.getLength() : 0)) {
        return false;
    }
    if (this->getX() + (this->getShipOrientation() == SHIP_ORIENTATION::HORIZONTAL ? this->getLength() : 0) <
        other.getX()) {
        return false;
    }
    if (this->getY() >
        (other.getY() + (other.getShipOrientation() == SHIP_ORIENTATION::VERTICAL ? other.getLength() : 0))) {
        return false;
    }
    if ((this->getY() + (this->getShipOrientation() == SHIP_ORIENTATION::VERTICAL ? this->getLength() : 0)) <
        other.getY()) {
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


/**
 * operator<<
 *
 * operator
 *
 * prints a ship and it's sink status to an output stream such as cout
 *
 * @param out output stream (such as cout)
 * @param vehicle water vehicle to print
 * @return out
 */
ostream &operator<<(ostream &out, WaterVehicle vehicle) {
    out << getNameForShipType(vehicle.getShipType()) << "\t";
    out << vehicle.getLength() << "\t";
    out << "(" << vehicle.getX() << ", " << vehicle.getY() << ")" << "\t";
    if (!vehicle.isSunk()) {
        out << "not ";
    }
    out << "sunk";
    return out;
}


/**
 * operator>>
 *
 * operator
 *
 * reads a ship IN CSV FORMAT as if from the provided CSV format
 *  example: Carrier,A1,H
 *  see operator>> for GRID
 *
 * throws invalid_argument if the ship is malformed in any way
 *
 * @param in
 * @param vehicle
 * @return
 */
istream &operator>>(istream &in, WaterVehicle &vehicle) {
    //TypeOfShip,Location,HorizOrVer

    //Declare strings to read raw file contents
    string shipTypeString;
    string location;
    char shipOrientation;

    getline(in, shipTypeString, ',');
    getline(in, location, ',');
    in >> shipOrientation;

    while ((in.peek() == '\n') || (in.peek() == '\r')) {
        in.ignore();
    }

    if (shipTypeString == "Carrier") {
        vehicle.setShipType(SHIP_TYPE::CARRIER);
    } else if (shipTypeString == "Battleship") {
        vehicle.setShipType(SHIP_TYPE::BATTLESHIP);
    } else if (shipTypeString == "Cruiser") {
        vehicle.setShipType(SHIP_TYPE::CRUISER);
    } else if (shipTypeString == "Submarine") {
        vehicle.setShipType(SHIP_TYPE::SUBMARINE);
    } else if (shipTypeString == "Destroyer") {
        vehicle.setShipType(SHIP_TYPE::DESTROYER);
    } else {
        throw invalid_argument("invalid shipType '" + shipTypeString +
                               "' while reading ship from input stream; see Enums.h for valid ship types");
    }

    if (location.size() != 2) {
        throw invalid_argument(
                "invalid ship location; must be one char and one number representing location: " + location);
    }
    //Subtract by 65 to convert from ASCII then subtract by 1 to convert from 1-indexed to 0 indexed
    int col = location[0] - 65;
    //Subtract by 48 to convert from ASCII then subtract by 1 to convert from 1-indexed to 0 indexed
    int row = location[1] - 49;

    if ((col < 0) || (row < 0)) {
        throw invalid_argument(
                "invalid ship location; grid coords must be positive ints: " + to_string(row) + ", " + to_string(col) +
                "; " + location);
    }

    if (shipOrientation == 'H') {
        vehicle.setShipOrientation(SHIP_ORIENTATION::HORIZONTAL);
    } else if (shipOrientation == 'V') {
        vehicle.setShipOrientation(SHIP_ORIENTATION::VERTICAL);
    } else {
        throw invalid_argument("invalid ship orientation: must be H or V: " + shipOrientation);
    }

    vehicle.setX((unsigned int) col);
    vehicle.setY((unsigned int) row);

    return in;
}


//----Getters and Setters----
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
bool WaterVehicle::isSunk() const {
    return sunk;
}
void WaterVehicle::setSunk(bool sunk) {
    WaterVehicle::sunk = sunk;
}
SHIP_TYPE WaterVehicle::getShipType() const {
    return shipType;
}
void WaterVehicle::setShipType(SHIP_TYPE shipType) {
    WaterVehicle::shipType = shipType;
}
WaterVehicle::WaterVehicle() {}

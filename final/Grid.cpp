/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for grid class
 */

//Include the header file se we can implement it
#include "Grid.h"

/**
 * Grid
 *
 * constructor
 *
 * @param width the width of this grid (usually 10)
 * @param height the height of this grid (usually 10)
 */
Grid::Grid(unsigned int width, unsigned int height) : width(width), height(height) {}


//DECLARE printGrid(ship[])
// Parameter: ship[], which is an array of ships representing a board
// Return value: void
// that exist in the "grid" we are printing
ostream &operator<<(ostream &out, Grid grid) {
    //print blank (in upper left)
    if (grid.getHeight() >= 10) cout << " ";
    out << "   | ";
    //for i in [0, this->width)
    for (unsigned int i = 0; i < grid.width; i++) {
        //print convert number to letter i+1 //label the columns
        // such that A=1 etc
        char a = 65 + i;
        out << a;
        out << " | ";
    }
    out << endl;


    for (unsigned int i = 0; i < grid.height; i++) {
        //print j+1 // label the rows
        out << " ";
        if (i + 1 <= 9) out << " ";
        out << i + 1;
        out << " |";
        for (unsigned int j = 0; j < grid.width; j++) {
            bool printedShip = false;
            for (unsigned int k = 0; k < grid.shots.size(); k++) {
                if (grid.shots[k].existsAt(i, j)) {
                    bool wasHit = false;
                    for (unsigned int l = 0; l < grid.ships.size(); l++) {
                        if (grid.ships[l].existsAt(i, j)) {
                            wasHit = true;
                            break;
                        }
                    }

                    if (wasHit) {
                        out << " O ";
                    } else {
                        out << " X ";
                    }

                    printedShip = true;
                    break;
                }
            }
            if (!printedShip && (grid.ships.size() > 0)) {
                for (unsigned int k = 0; k < grid.ships.size(); k++) {
                    //if ship.existsAt(i, j)
                    if (grid.ships[k].existsAt(i, j)) {
                        // print letter for ship.SHIP_TYPE
                        out << grid.ships[k].getLetter();
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

    return out;
}

//DECLARE printForOpponent()
// prints only the hits/misses in the grid to out
// used by human player to show the oposing player's ships
void Grid::printForOpponent(ostream &out) {
    //print blank (in upper left)
    if (this->getHeight() >= 10) cout << " ";
    out << "   | ";
    //for i in [0, this->width)
    for (unsigned int i = 0; i < this->width; i++) {
        //print convert number to letter i+1 //label the columns
        // such that A=1 etc
        char a = 65 + i;
        out << a;
        out << " | ";
    }
    out << endl;


    for (unsigned int i = 0; i < this->height; i++) {
        //print j+1 // label the rows
        out << " ";
        if (i + 1 <= 9) out << " ";
        out << i + 1;
        out << " |";
        for (unsigned int j = 0; j < this->width; j++) {
            bool printedShip = false;
            for (unsigned int k = 0; k < this->shots.size(); k++) {
                if (this->shots[k].existsAt(i, j)) {
                    bool wasHit = false;
                    for (unsigned int l = 0; l < this->ships.size(); l++) {
                        if (this->ships[l].existsAt(i, j)) {
                            wasHit = true;
                            break;
                        }
                    }

                    if (wasHit) {
                        out << " O ";
                    } else {
                        out << " X ";
                    }

                    printedShip = true;
                    break;
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

//DECLARE fireShot()
// EXTRA CREDIT
// Paramter s: the shot to fire into this grid
// it is assumed that this is a valid move to make
// it is the responsibility of the player to make
// sure he/she doesn't place a shot that's already been fired
//
// Sets the "sunk" flag on a ship IF every space the ship
// occupies has been sunk
void Grid::fireShot(Shot s) {
    this->shots.push_back(s);

    for (unsigned int i = 0; i < this->ships.size(); i++) {
        bool foundNotShotSpot = false;
        for (unsigned int j = 0; j < this->ships[i].getLength(); j++) {
            unsigned int row = this->ships[i].getY();
            unsigned int col = this->ships[i].getX();
            if (this->ships[i].getShipOrientation() == SHIP_ORIENTATION::HORIZONTAL) {
                col += j;
            } else {
                row += j;
            }

            bool foundShot = false;
            for (unsigned int k = 0; k < this->shots.size(); k++) {
                if (this->shots[k].existsAt(row, col)) {
                    foundShot = true;
                    break;
                }
            }

            if (!foundShot) {
                foundNotShotSpot = true;
                break;
            }
        }
        if (!foundNotShotSpot) {
            this->ships[i].setSunk(true);
        }
    }
}

/**
 * fireFifteenRandomShots()
 *
 * fires fifteen random shots into the grid by appending the objects to a vector
 */
void Grid::fireFifteenRandomShots() {
    for (unsigned int i = 0; i < 15; i++) {
        this->fireShot(Shot(rand() % width, rand() % height));
    }
}

/**
 * canInsert()
 *
 * returns true if a ship is within grid bounds and does not overlap with other ships
 *
 * @param ship
 * @return
 */
bool Grid::canInsert(WaterVehicle ship) {
    //can't insert if outside grid
    //if the x, y is outside the grid, print message and try again
    if ((ship.getX() > this->width) || (ship.getY() > height)) {
        return false;
    }

    //if the selected option implies a lower right corner that is outside the grid, print message
    //and try again
    //can't insert if outside grid
    if ((ship.getShipOrientation() == SHIP_ORIENTATION::HORIZONTAL) ?
        ((ship.getX() + getLengthForShipType(ship.getShipType())) > this->width) :
        ((ship.getY() + getLengthForShipType(ship.getShipType())) > this->height)) {
        return false;
    }

    //for otherShip in ship vector for current player
    for (unsigned int k = 0; k < this->ships.size(); k++) {
        //if ship.overlapsWith(otherShip)
        if (ship.overlapsWith(this->ships[k])) {
            return false; //Can't insert if overlapping
        }

        if (ship.getShipType() == ships[k].getShipType()) {
            return false; //Can't insert if the ship has already been added
        }
    }

    return true;
}


//DECLARE insert()
//
//calls push_back() on the ship vector with ship
//
// adds a ship to this grid (it is the responsibility of the player to ensure it's a valid location)
//
// paramters: ship - the WaterVehicle object to insert into this grid's ship vector
void Grid::insert(WaterVehicle ship) {
    this->ships.push_back(ship);
}


/**
 * operator>>
 *
 * reads the entire grid from an input stream
 *  that points to a csv file with a format similar to the following:
 *
 *  TypeOfShip,Location,HorizOrVer
 *  Carrier,A1,H
 *
 * @param in an input stream
 * @param grid a grid to read into
 * @return in stream
 */
istream &operator>>(istream &in, Grid &grid) {
    string headers;
    getline(in, headers);

    if (headers.substr(0, 30) != "TypeOfShip,Location,HorizOrVer") {
        throw invalid_argument("invalid input stream while reading grid; headers are not right: " + headers);
    }

    unsigned int i = 0;
    while (!in.eof()) {
        WaterVehicle s;
        in >> s;
        if (!grid.canInsert(s)) {
            throw invalid_argument("invalid input stream while reading grid; ship can't be placed in grid: " +
                                   getNameForShipType(s.getShipType()));
        }
        grid.insert(s);
        //Break out if the stream has more than 5 ships; we don't care
        if (i++ > 5) break;
    }

    if (grid.getShips().size() != 5) {
        throw invalid_argument("invalid input stream while reading grid; stream must have exactly 5 ships: " +
                               to_string(grid.getShips().size()));
    }
}

//---Getters and Setters---
vector<WaterVehicle> Grid::getShips() const {
    return this->ships;
}
vector<Shot> Grid::getShots() {
    return this->shots;
}
unsigned int Grid::getWidth() const {
    return width;
}
unsigned int Grid::getHeight() const {
    return height;
}

//
// Created by Jake Billings on 2/21/18.
//

#include "Grid.h"
#include<iostream>

Grid::Grid(unsigned int width, unsigned int height) : width(width), height(height) {}

//DECLARE createGrid()
// Parameters: input stream (input stream is required since we're going to mock it for testing; it would be in for a
//  real game)
// Return value: ship[2][5] - an array of ship arrays each ship[5] represents a fleet grid
//  *The return value might actually be vectors because .push_back() would be useful
//
void Grid::interativelyReadFrom(istream &in, ostream &out) {

    //declare a vector of ship vectors to store all boards for the game
    //For each player [0,1]

    //declare a ship vector for current player
    //For each SHIP_TYPE in SHIP_TYPES (5 ship types)
    for (unsigned int i = 0; i < SHIP_TYPE_COUNT; i++) {
        SHIP_TYPE shipType = ALL_SHIP_TYPES[i];

        //if the player is a HUMAN
        //print board (the ship vector for current player)
        out << *this;

        //print message that says we're plaing a ship of type SHIP_TYPE
        //print a message that says we want the upper left hand corner
        // todo this doesn't quite work
        out << "Where would you like to place your " << getNameForShipType(shipType) << "?" << endl;

        //input := getline() from in
        //if the input isn't in the form A1, print error message and accept input again
        //convert the input to (x, y) coordinates where x is the number that corresponds with the letter and y is the number-1
        //E.g. D2 -> x=3, y=1 (since we're zero indexed)
        out << "col> ";
        char colChar;
        in >> colChar;
        int col = colChar - 65; //todo vlaidate
        out << "row> ";
        int row;
        in >> row;
        row--;

        //if the x, y is outside the grid, print message and try again
        if (col > this->width || row > height || col < 0 || row < 0) {
            out << "Sorry. That's outside of the grid. Please try again." << endl;
            i--;
        } else {

            //calculate the two possible lower right corners of the ship
            //  This are at x+length, y (horizontal) and x, y+length (vertical)
            out << "The lower right of corner of your ship could be at ";
            out << "(" << (col + getLengthForShipType(shipType)) << ", " << row << ") or (" << col << ", "
                << (row + getLengthForShipType(shipType)) << ")";
            out << endl;


            //ask the user which option they want
            out << "Would you like your ship to be horizontal? (Y/n)" << endl;
            out << "> ";
            char inputHorizontal;
            in >> inputHorizontal;

            SHIP_ORIENTATION orientation;
            if (inputHorizontal == 'Y') {
                orientation = SHIP_ORIENTATION::HORIZONTAL;
            } else {
                orientation = SHIP_ORIENTATION::VERTICAL;
            }

            //if the selected option implies a lower right corner that is outside the grid, print message
            //and try again
            bool placementIsInGrid =
                    (orientation == SHIP_ORIENTATION::HORIZONTAL) ?
                    (col + getLengthForShipType(shipType) <= this->width) :
                    (row + getLengthForShipType(shipType) <= height);

            //init a ship object
            WaterVehicle ship(col, row, orientation, shipType);

            bool overlapsWithAnotherShip = false;
            //for otherShip in ship vector for current player
            for (unsigned int k = 0; k < this->ships.size(); k++) {
                //if ship.overlapsWith(otherShip)
                if (ship.overlapsWith(this->ships[k])) {
                    overlapsWithAnotherShip = true;
                }
            }

            if (placementIsInGrid && !overlapsWithAnotherShip) {
                //if valid,
                //push the object into the vector for the current player
                this->ships.push_back(ship);
            } else {
                //if not,
                //print an error message and try again
                out << "Sorry, you cannot place a ship there. Please try again." << endl;
                i--;
            }
        }
    }

    //if the player is a machine
    //query the smart (or random) algorithm to place the ship...
    //for example,
    //generate x in range [0, this->width-SHIP_TYPE.length]
    //generate y in range [0, height-SHIP_TYPE.length]
    //flip coin (generate random bool) to determine orientation

    //return the ship multivector that stores boards for the whole game
}

//DECLARE printGrid(ship[])
// Parameter: ship[], which is an array of ships representing a board
// Return value: void
// that exist in the "grid" we are printing
ostream &operator<<(ostream &out, Grid grid) {
    //print blank (in upper left)
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
        out << i + 1;
        out << " |";
        for (unsigned int j = 0; j < grid.width; j++) {
            bool printedShip = false;
            for (unsigned int k = 0; k < grid.shots.size(); k++) {
                if (grid.shots[k].existsAt(i, j)) {
                    out << " X ";
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

void Grid::fireShot(Shot s) {
    this->shots.push_back(s);


    for (unsigned int i = 0; i < this->ships.size(); i++) {
        bool foundNotShotSpot = false;
        for (unsigned int j = 0; j < this->ships[i].getLength(); j++) {
            unsigned int row = this->ships[i].getY();
            unsigned int col = this->ships[i].getX();
            if (this->ships[i].getShipOrientation()==SHIP_ORIENTATION::HORIZONTAL) {
                col += j;
            } else {
                row += j;
            }

            bool foundShot = false;
            for (unsigned int k = 0; k < this->shots.size(); k++) {
                if (this->shots[k].existsAt(row,col)) {
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

vector<WaterVehicle> Grid::getShips() {
    return this->ships;
}

vector<Shot> Grid::getShots() {
    return this->shots;
}

void Grid::fireFifteenRandomShots() {
    for (unsigned int i = 0; i < 15; i++) {
        this->fireShot(Shot(rand() % width, rand() % height));
    }
}
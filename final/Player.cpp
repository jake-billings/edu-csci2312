/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for HumanPlayer class
 */

//Include the player header so that we can implement it
#include "Player.h"

/**
 * hasFiredShotAt()
 *
 * method
 *
 * returns true if this player has already fired a shot at the location
 *  (row, col) in the opposing grid
 *
 * queries the shots vector of the other grid
 *
 * used to ensure we don't waste shots
 *
 * see fireShot() in ComputerPlayer and HumanPlayer
 *
 * @param row the row of the candidate shot
 * @param col the col of the candidate shot
 * @return true if this player has already fired a shot at (row, col)
 */
bool Player::hasFiredShotAt(unsigned int row, unsigned int col) {
    for (unsigned int i = 0; i < this->opposingGrid->getShots().size(); i++) {
        if ((this->opposingGrid->getShots()[i].getRow() == row) && (this->opposingGrid->getShots()[i].getCol() == col)) return true;
    }

    return false;
}


/**
 * tryInsert()
 *
 * method
 *
 * checks if Ship s can be inserted into our grid
 *
 * if it can be, we insert it and return true
 * if not, we return false
 *
 * the validity of a placement is determined by grid
 *  containment and ship overlap in Grid::canInsert()
 *
 * @param s the ship to place
 * @return true if the ship was placed
 */
bool Player::tryInsert(WaterVehicle s) {
    if (this->grid->canInsert(s)) {
        grid->insert(s);
        return true;
    }
    return false;
}


/**
 * hasLost()
 *
 * method
 *
 * returns true if all ships are marked as sunk
 * ships are marked as sunk in fireShot() in grid
 *  when a shot covers the last location on a ship
 *
 * See WaterVehicle::isSunk()
 * See Grid::fireShot()
 *
 * @return true if this player has had all of its ships sunk
 */
bool Player::hasLost() const {
    vector<WaterVehicle> ships = this->getGrid()->getShips();
    for (unsigned int i = 0; i < ships.size(); i++) {
        if (!ships[i].isSunk()) return false;
    }
    return true;
}


//----Getters----
//Setters are not included because it does not
// make sense to mutate the state of the properties
// of this object after creation
const Grid *Player::getGrid() const {
    return grid;
}
Grid *Player::getOpposingGrid() const {
    return opposingGrid;
}

/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for ComputerPlayer class
 */
#include "ComputerPlayer.h"


/**
 * ComputerPlayer()
 *
 * constructor
 *
 * @param grid
 * @param opposingGrid
 */
ComputerPlayer::ComputerPlayer(Grid *grid, Grid *opposingGrid) {
    this->grid = grid;
    this->opposingGrid = opposingGrid;
}


/**
 * placeShips()
 *
 * method
 *
 * uses an advanced machine-learning VR blockchain algorithm to place the computer player's ships in its
 *  grid before the game starts
 *
 * "machine-learning VR blockchain algorithm" is a joke.
 *
 * this function does not guarantee its own success
 *
 * it places each shp type sequentially in a random location on the grid. if that spot is not valid, it generates
 *  a new random ship of the same type and tries again
 *
 * after 10,000 tries on one ship type, it assumes the grid is full and gives up; this throws an exception
 *
 * in my testing, this has worked fine (see unit testing in test())
 */
void ComputerPlayer::placeShips() {
    //Get the grid width and height, so we know the bounds to generate numbers in
    unsigned int width = this->getGrid()->getWidth();
    unsigned int height = this->getGrid()->getHeight();

    //Iterate to place each ship type in the grid sequentially
    for (unsigned int shipTypeIndex = 0; shipTypeIndex < SHIP_TYPE_COUNT; shipTypeIndex++) {
        //Try up to 10,000 times to insert the ship into the grid at a random location and orientation
        bool insertedShip = false;
        for (unsigned int i = 0; i < 10000; i++) {
            WaterVehicle s(
                    randInt(0, width),
                    randInt(0, height),
                    ALL_SHIP_ORIENTATIONS[randInt(1, SHIP_ORIENTATION_COUNT)],
                    ALL_SHIP_TYPES[shipTypeIndex]
            );

            //tryInsert() returns true if the ship is successfully inserted, so it's valid break critera
            if (this->tryInsert(s)) {
                insertedShip = true;
                break;
            }
        }
        //If it
        // fails after 10,000 times, assume the grid is full, give up, and throw an exception
        if (!insertedShip) {
            throw runtime_error(
                    "ComputerPlayer: failed to insert ship into grid; maybe the grid is too small to hold the ship");
        }
    }

}


/**
 * fireShot()
 *
 * method
 *
 * uses an advanced machine-learning VR blockchain algorithm to place target, track, and destroy the other player's
 *  ships
 *
 * "machine-learning VR blockchain algorithm" is a joke.
 *
 * this method tries up to 10,000 times to place a shot in the opposing player's grid
 *  after 10,000 tries, we assume the other grid is full throw an exception
 *
 * (firing the shot fails if a shot has already been fired in the same place)
 *
 * see unit testing in test()
 */
void ComputerPlayer::fireShot() {
    unsigned int width = this->getGrid()->getWidth();
    unsigned int height = this->getGrid()->getHeight();

    //try 10,000 random shots
    for (unsigned int i = 0; i < 10000; i++) {
        unsigned int row = randInt(0, width);
        unsigned int col = randInt(0, height);

        if (!this->hasFiredShotAt(row, col)) {
            Shot s(row, col);
            this->opposingGrid->fireShot(s);
            return;
        }
    }

    //we tried 10,000 times to fire a shot we haven't fired before. we probably filled up the other grid
    throw runtime_error("ComputerPlayer: failed to fire shot into grid; could the grid be full?");
}


/**
 * print()
 *
 * method
 *
 * virtual function implementation
 *
 * prints "Computer Player" to the output
 *
 * @param out
 */
void ComputerPlayer::print(ostream &out) const {
    out << "Computer Player" << endl;
}
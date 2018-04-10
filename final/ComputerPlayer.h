/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file for ComputerPlayer class
 */

//Include ostream to implement the print() function
#include <ostream>

//Include Player to extend it
#include "Player.h"

//Include Util.h for random number generation
#include "Util.h"

//Use the standard namespace because this isn't production code
// and I don't wanna type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_COMPUTERPLAYER_H
#define EDU_CSCI2312_COMPUTERPLAYER_H


/**
 * ComputerPlayer
 *
 * class
 *
 * subclass of Player
 *
 * implementation of the player class that executes all moves using random numbers
 *  ships are placed randomly
 *  shots are fired randomly
 *
 * See Grid
 * See Game
 * See Player
 * See HumanPlayer
 */
class ComputerPlayer : public Player {
public:
    /**
     * ComputerPlayer()
     *
     * constructor
     *
     * @param grid
     * @param opposingGrid
     */
    ComputerPlayer(Grid *grid, Grid *opposingGrid);

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
    void placeShips() override;

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
    void fireShot() override;

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
    void print(ostream &out) const override;
};


#endif //EDU_CSCI2312_COMPUTERPLAYER_H

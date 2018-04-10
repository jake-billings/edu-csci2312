/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file for HumanPlayer class
 */

//Include io stream since we work with input and output streams
#include <iostream>
//Include file streams so that we can read from the csv file to populate ships
#include <fstream>
//Include stdexcept since we throw exceptions sometimes
#include <stdexcept>
//Include Player.h so that we can extend it
#include "Player.h"

//Use the standard namespace because this isn't production code
// and I don't wanna type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_HUMANPLAYER_H
#define EDU_CSCI2312_HUMANPLAYER_H


/**
 * HumanPlayer
 *
 * class
 *
 * subclass of player
 *
 * represents and manangers the interactions with human beings via
 *  io streams so that game logic (in Game.h/cpp) doesn't need to know
 *  if it's talking to a human or to a machine
 *
 * instantiates with stream pointers in/out so that cin/cout can be replaced
 *  with other streams for testing/validation
 *
 * See Grid
 * See Game
 * See Player
 * See ComputerPlayer
 */
class HumanPlayer : public Player {
private:
    /**
     * out
     *
     * ostream pointer
     *
     * represents the output stream to use when we want
     *  to tell the human this object represents what we're doing
     */
    ostream *out;

    /**
     * in
     *
     * istream pointer
     *
     * represents the output stream to use when we want
     *  to ask the human  what we're doing
     */
    istream *in;
public:
    /**
     * HumanPlayer()
     *
     * constructor
     *
     * @param grid pointer to the grid for THIS player
     * @param opposingGrid pointer to the grid for the OTHER player (our enemy)
     * @param out output stream (cout) to use to communicate with the player we represent
     * @param in input stream (cin) to use to communicate with the player we represent
    */
    HumanPlayer(Grid *grid, Grid *opposingGrid, ostream *out, istream *in);


    /**
     * placeShips()
     *
     * method
     *
     * place the ships
     *
     * reads ships from csv file and places them in our grid
     *
     * this method would use user input to populate the grid;
     *  however, project requirements state that user ships are to be
     *  read from a CSV file, so we load the ships from "ship_placement.csv"
     *
     * throws illegal_argument if there is any error in "ship_placement.csv"
     * if called twice, this method will throw an error
     */
    void placeShips();


    /**
     * fireShot()
     *
     * method
     *
     * fires a shot into the other player's grid by accepting user input
     *  from the input streams we're connected to
     *
     * prints the known grid state so that the user can make decisions
     */
    void fireShot();


    /**
     * print()
     *
     * method
     *
     * virtual function implementation
     *
     * prints "Human Player" to the output
     *
     * @param out
     */
    void print(ostream &out) const;
};


#endif //EDU_CSCI2312_HUMANPLAYER_H

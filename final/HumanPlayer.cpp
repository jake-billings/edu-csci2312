/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for HumanPlayer class
 */
#include "HumanPlayer.h"


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
HumanPlayer::HumanPlayer(Grid *grid, Grid *opposingGrid, ostream *out, istream *in) {
    this->in = in;
    this->out = out;
    this->grid = grid;
    this->opposingGrid = opposingGrid;
}


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
void HumanPlayer::placeShips() {
    ifstream fin;
    fin.open("ship_placement.csv");
    fin >> *this->grid;
}


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
void HumanPlayer::fireShot() {
    //Print grid state
    *this->out << "====================Your grid====================" << endl;
    *this->out << *this->getGrid() << endl;
    *this->out << "=================================================" << endl;
    *this->out << "===============Your Opponent's Grid===============" << endl;
    this->getOpposingGrid()->printForOpponent(*this->out);
    *this->out << "==================================================" << endl;

    //Give the opportunity to quit
    *this-> out << "Would you like to quit or continue? (Enter 'q' to quit; enter 'y' to continue)" << endl;
    *this->out << "inp> ";
    char inp;
    *this->in >> inp;

    //If the user chose to quit, throw an exception
    if (inp == 'q') {
        throw runtime_error("user has opted to quit");
    }

    //Ask for coordinates to shoot at
    *this->out << "Please enter coordinates on your opponent's grid to fire a shot." << endl;

    //While the shot isn't valid, recollect its
    // location
    Shot *s = nullptr;
    bool shotValid = false;
    while (!shotValid) {
        *this->out << "col> ";
        char colChar;
        *this->in >> colChar;
        int col = colChar - 65;
        *this->out << "row> ";
        int row;
        *this->in >> row;
        row--;

        shotValid = (col <= this->getOpposingGrid()->getWidth()) && (row <= this->getOpposingGrid()->getHeight()) && (col >= 0) && (row >= 0);
        if (!shotValid) {
            *this->out << "Sorry, that shot is out of bounds. Please try again." << endl;
        } else {
            s = new Shot(row, col);
        }
    }

    //Fire into the opposing grid
    this->getOpposingGrid()->fireShot(*s);
    delete s;
}


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
void HumanPlayer::print(ostream &out) const {
    out << "Human Player" << endl;
}

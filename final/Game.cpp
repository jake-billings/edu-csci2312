/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: implementation file for Game class
 */

//Include Game header so we can implement it
#include "Game.h"


/**
 * Game()
 *
 * constructor
 *
 * assigns a and b
 *
 * @param a player 1
 * @param b player 2
 */
Game::Game(Player *a, Player *b) : a(a), b(b) {}


/**
 * getWinner()
 *
 * returns the winning player from this game if the game is complete
 *
 * throws a runtime_error if a player hasn't won yet
 *
 * use hasLoser() to check before calling this function
 *
 * @return the winner of this game
 */
const Player *Game::getWinner() const {
    if (!this->hasLoser()) throw runtime_error("cannot provide winner if game is still in play");
    if (this->a->hasLost()) {
        return b;
    }
    return b;
}


/**
 * hasLoser()
 *
 * returns true if either player has lost the game
 *
 * this can be used as a proxy for "isComplete" since the game is only done
 *  when we have a winner and a loser. the existance of a loser implies both
 *  the completion of the game and the existance of a winner
 *
 * see getWinner()
 *
 * @return true if the game is over
 */
bool Game::hasLoser() const {
    return this->a->hasLost() || this->b->hasLost();
}


/**
 * executeRound()
 *
 * method
 *
 * throws an error if the game is already over
 *
 * call hasLoser() to check if the game is over before calling this method
 *
 * calls player a to fire a shot
 *  if player a wins, we return
 *  if not, we execute player 2's turn
 */
void Game::executeRound() {
    if (this->hasLoser()) throw runtime_error("cannot execute round if game is already over");

    this->a->fireShot();

    if (this->hasLoser()) return;

    this->b->fireShot();
}


//---Getters---
// Setters are intentionally excluded so as not to mutate
// the state of the players
// it doesn't make any sense to change players after starting
// a game
const Player *Game::getA() const {
    return a;
}
const Player *Game::getB() const {
    return b;
}
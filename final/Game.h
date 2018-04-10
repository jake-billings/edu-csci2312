/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file for Game class
 */

//Include Player since we use two players
#include "Player.h"

#ifndef EDU_CSCI2312_GAME_H
#define EDU_CSCI2312_GAME_H

/**
 * Game
 *
 * class
 *
 * represents one game/round between two players
 *  can use any combination of human players and machine players
 *  since Player is abstract
 *
 * contains logic to get the winner and to check if the game is over
 *
 * See player
 */
class Game {
private:
    /**
     * a
     *
     * Player pointer
     *
     * the first player to take a turn
     *
     * returned by getWinner() if a wins
     * we call fireShot when it's a's turn
     * however, a must place ships in its grid before starting the game
     */
    Player *a;


    /**
     * b
     *
     * Player pointer
     *
     * the first player to take a turn
     *
     * returned by getWinner() if a wins
     * we call fireShot when it's b's turn
     * however, b must place ships in its grid before starting the game
     */
    Player *b;

public:
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
    Game(Player *a, Player *b);


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
    const Player *getWinner() const;


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
    bool hasLoser() const;


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
    void executeRound();


    //---Getters---
    // Setters are intentionally excluded so as not to mutate
    // the state of the players
    // it doesn't make any sense to change players after starting
    // a game
    const Player *getA() const;
    const Player *getB() const;
};


#endif //EDU_CSCI2312_GAME_H

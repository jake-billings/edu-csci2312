/**
 * Name: Jake Billings
 * Date: 02/01/2018
 * Class: CSCI 2312
 * Description: implementation file for shot class
 */

#include "Shot.h"

/**
 * basic constructor for shot fired into grid
 *
 * @param row the row of the shot
 * @param col the col of the shot
 */
Shot::Shot(unsigned int row, unsigned int col) : row(row), col(col) {}
}

/**
 * existsAt()
 *
 * returns true if row and col match the row and col of this shot
 *  (similar to existsAt() for Ship)
 *
 * @param row row to check
 * @param col col to check
 * @return true if row and col match the row and col of this shot
 */
bool Shot::existsAt(unsigned int row, unsigned int col) const {
    return this->getRow() == row && this->getCol() == col;
}

//getters and setters
unsigned int Shot::getRow() const {
    return row;
}

unsigned int Shot::getCol() const {
    return col;
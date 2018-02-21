//
// Created by Jake Billings on 2/21/18.
//

#include "Shot.h"


Shot::Shot(unsigned int row, unsigned int col) : row(row), col(col) {}

unsigned int Shot::getRow() const {
    return row;
}

unsigned int Shot::getCol() const {
    return col;
}

bool Shot::existsAt(unsigned int row, unsigned int col) const {
    return this->getRow() == row && this->getCol() == col;
}
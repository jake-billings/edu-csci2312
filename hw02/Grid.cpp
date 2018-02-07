/**
 * Name: Jake Billings
 * Date: 02/07/2018
 * Class: CSCI 2312
 * Description: implementation file for Grid class (see desc in main HW file)
 */

#include "Grid.h"


/**
 * Grid()
 *
 * constructor
 *
 * instantiates the vector grid that the grid class relies on
 *
 * @param width the width to make the vector grid
 * @param height the height to make the grid
 */
Grid::Grid(unsigned int width, unsigned int height) {
//Generate two empty 2d matrices by appending zeros to
// arrays then appending vectors of zeros to big vectors
    for (unsigned int i = 0; i < width; i++) {
        vector<bool> row;
        for (unsigned int j = 0; j < height; j++) {
            row.push_back(false);
        }
        this->grid.push_back(row);
    }
}

/**
 * getOneThirdOfGridSize()
 *
 * Returns the floor of the width times the height diveded by three
 *
 * This is the count of 1/3rd of the cells in the grid
 *
 * @return
 */
unsigned int Grid::getOneThirdOfGridSize() {
    //Calculate the number of true values we wish to randomly insert
    // into each this->grid.
    //Since the problem specifies that 1/3rd of each this->grid must be 1's,
    // we wish to insert one third of the number of elements we can insert,
    // which is the this->grid size, which is the this->width times the height.
    //This will function as a floor operation since it uses long/int
    // arithmetic
    return this->grid.size() * this->grid[0].size() / 3;
}

/**
 * fillOneThirdOfGridWithTrue()
 *
 * fill precisely one third of the grid with 1's
 *
 * depends on the grid starting with only 0's
 */
void Grid::fillOneThirdOfGridWithTrue() {
    //While we havn't inserted enough 1 values, insert a 1 value at
    // a random spot in the matrix. Don't insert it if it's
    // already a 1 (that doesn't help at all)
    unsigned int gridInsertCount = 0;
    while (gridInsertCount < this->getOneThirdOfGridSize()) {
        unsigned long x = rand() % this->grid.size();
        unsigned long y = rand() % this->grid[0].size();

        //Don't insert if it's already 1
        if (!this->grid[x][y]) {
            gridInsertCount++;
            this->grid[x][y] = true;
        }
    }
}

/**
 * operator<<
 *
 * prints a grid to a stream; usually cout
 *
 * @param out
 * @param grid
 * @return
 */
ostream& operator<<(ostream &out, Grid &grid) {
    for (unsigned int i = 0; i < grid.grid.size(); i++) {
        for (unsigned int j = 0; j < grid.grid[0].size(); j++) {
            out << grid.grid[i][j] << ' ';
        }
        out << endl;
    }

    return out;
}

/**
 * operator+
 *
 * define addition as the combination of two grids as defined in the homework problem;
 *  a + b results in a grid where ones exist only where 1's existed in both a and b
 *
 * @param gridOne
 * @param gridTwo
 * @return
 */
Grid operator*(Grid gridOne, Grid gridTwo) {
    //Declare the third grid, which will contain 1's where both gridOne and gridTwo had 1's
    // and 0's everywhere else
    Grid gridThree(gridOne.grid.size(), gridOne.grid[0].size());
    //Generate gridThree by iterating over each grid position
    // and inserting a true in gridThree if there's a 1
    // in both gridOne and gridTwo
    for (unsigned int i = 0; i < gridThree.grid.size(); i++) {
        for (unsigned int j = 0; j < gridThree.grid[0].size(); j++) {
            gridThree.grid[i][j] = gridOne.grid[i][j] && (gridOne.grid[i][j] == gridTwo.grid[i][j]);
        }
    }

    return gridThree;
}
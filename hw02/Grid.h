/**
 * Name: Jake Billings
 * Date: 02/07/2018
 * Class: CSCI 2312
 * Description: declaration file for Grid class (see desc in main HW file)
 */

#ifndef EDU_CSCI2312_GRID_H
#define EDU_CSCI2312_GRID_H

//Include streams
#include <iostream>
//Include vector
#include <vector>
//Include rand()
#include <random>

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;

class Grid {
private:
    /**
     * grid
     *
     * 2D vector in which to store our data
     */
    vector<vector<bool> > grid;

public:
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
    Grid(unsigned int width, unsigned int height);

    /**
     * getOneThirdOfGridSize()
     *
     * Returns the floor of the width times the height diveded by three
     *
     * This is the count of 1/3rd of the cells in the grid
     *
     * @return
     */
    unsigned int getOneThirdOfGridSize();

    /**
     * fillOneThirdOfGridWithTrue()
     *
     * fill precisely one third of the grid with 1's
     *
     * depends on the grid starting with only 0's
     */
    void fillOneThirdOfGridWithTrue();

    /**
     * operator<<
     *
     * prints a grid to a stream; usually cout
     *
     * @param out
     * @param grid
     * @return
     */
    friend ostream &operator<<(ostream &out, Grid &grid);

    /**
     * operator*
     *
     * define multiplication as the combination of two grids as defined in the homework problem;
     *  a + b results in a grid where ones exist only where 1's existed in both a and b
     *
     * @param gridOne
     * @param gridTwo
     * @return
     */
    friend Grid operator*(Grid gridOne, Grid gridTwo);
};


#endif //EDU_CSCI2312_GRID_H

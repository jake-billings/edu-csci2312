/**
 * Name: Jake Billings
 * Date: 02/01/2018
 * Class: CSCI 2312
 * Description: declaration file containing the Grid class
 */

#ifndef EDU_CSCI2312_GRID_H
#define EDU_CSCI2312_GRID_H

#include <vector>
#include "WaterVehicle.h"
#include "Shot.h"

/**
 * Grid
 *
 * class
 *
 * A grid is a sparse-array-like object containing ships (type: WaterVehicle) for a game of battleship
 *
 * Ship objects are stored in a vector and contain coordinate, type, and length information allowing for
 *  member functions to recreate what it would look like to store a 2D array full of ship fields.
 */
class Grid {
private:
    /**
     * ships
     *
     * WaterVehicle[]
     *
     * all of the ships that have been placed on the grid
     */
    vector<WaterVehicle> ships;

    /**
     * shots
     *
     * Shot[]
     *
     * all of the shots that have been fired into the grid
     */
    vector<Shot> shots;

    /**
     * width
     *
     * int
     *
     * the width of the grid
     */
    unsigned int width;

    /**
     * height
     *
     * int
     *
     * the height of the grid
     */
    unsigned int height;
public:
    /**
     * create an empty grid with a fixed width and height
     *
     * @param width
     * @param height
     */
    Grid(unsigned int width, unsigned int height);

    /**
     * interativelyReadFrom()
     *
     * execute an interactive process on the streams in/out to construct a grid from user or e2e testing input
     *
     * @param in  LIKE cin
     * @param out  LIKE cout
     */
    void interativelyReadFrom(istream &in, ostream &out);

    /**
     * fireShot()
     *
     * appends a Shot object to the shots array
     *
     * @param s
     */
    void fireShot(Shot s);

    /**
     * fireFifteenRandomShots()
     *
     * fires fifteen random shots into the grid by appending the objects to a vector
     */
    void fireFifteenRandomShots();

    /**
     * getShips()
     *
     * returns the ships vector so we can get its size later
     *
     * @return  the ships vector
     */
    vector<WaterVehicle> getShips();

    /**
     * getShots()
     *
     * returns the shots vector so we can get its size later
     *
     * @return the shots vector
     */
    vector<Shot> getShots();


    /**
     * operator<<
     *
     * prints the entire grid to an output stream
     *
     * @param out an output stream like cout
     * @param grid a grid to print
     * @return out stream
     */
    friend ostream& operator<< (ostream &out, Grid grid);
};


#endif //EDU_CSCI2312_GRID_H

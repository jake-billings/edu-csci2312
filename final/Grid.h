/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file containing the Grid class
 */

#ifndef EDU_CSCI2312_GRID_H
#define EDU_CSCI2312_GRID_H

//Include iostream because we have stream operators to define
#include <iostream>
//Include vector because this data structure is a 2D vector
#include <vector>
//Include stdexcept because we throw errors sometimes
#include <stdexcept>
//Include WaterVehicle since the grid contains ships
#include "WaterVehicle.h"
//Include Shot since the grid contains shots
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
     * canInsert()
     *
     * returns true if a ship is within grid bounds and does not overlap with other ships
     *
     * @param ship
     * @return
     */
    bool canInsert(WaterVehicle ship);

    void insert(WaterVehicle ship);

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
    vector<WaterVehicle> getShips() const;

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
    friend ostream &operator<<(ostream &out, Grid grid);

    void printForOpponent(ostream &out);

    /**
     * operator>>
     *
     * reads the entire grid from an input stream
     *  that points to a csv file with a format similar to the following:
     *
     *  TypeOfShip,Location,HorizOrVer
     *  Carrier,A1,H
     *
     * @param in an input stream
     * @param grid a grid to read into
     * @return in stream
     */
    friend istream &operator>>(istream &in, Grid &grid);

    //---Getters and Setters---
    unsigned int getWidth() const;
    unsigned int getHeight() const;
};


#endif //EDU_CSCI2312_GRID_H

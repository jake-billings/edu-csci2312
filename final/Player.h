/**
 * Name: Jake Billings
 * Date: 04/09/2018
 * Class: CSCI 2312
 * Description: declaration file for HumanPlayer class
 */

//Include Shot since we process shot objects
#include "Shot.h"
//Include WaterVehicle since we process ship objects
#include "WaterVehicle.h"
//Include Enums since we process ship objects
#include "Enums.h"
//Include Grid since we work with grids
#include "Grid.h"

#ifndef EDU_CSCI2312_PLAYER_H
#define EDU_CSCI2312_PLAYER_H

class Player {
protected:
    Grid *grid;
    Grid *opposingGrid;

public:
    virtual void placeShips() = 0;
    virtual void fireShot() = 0;
    virtual void print(ostream &out) const = 0;

    bool hasLost() const;

    bool tryInsert(WaterVehicle s);

    bool hasFiredShotAt(unsigned int x, unsigned int y);

    const Grid *getGrid() const;

    Grid *getOpposingGrid() const;
};


#endif //EDU_CSCI2312_PLAYER_H

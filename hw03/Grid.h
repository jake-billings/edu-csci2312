//
// Created by Jake Billings on 2/21/18.
//

#ifndef EDU_CSCI2312_GRID_H
#define EDU_CSCI2312_GRID_H

#include <vector>
#include "WaterVehicle.h"
#include "Shot.h"

class Grid {
private:
    vector<WaterVehicle> ships;
    vector<Shot> shots;
    unsigned int width;
    unsigned int height;
public:
    Grid(unsigned int width, unsigned int height);

    void interativelyReadFrom(istream &in, ostream &out);
    void fireShot(Shot s);
    void fireFifteenRandomShots();

    vector<WaterVehicle> getShips();
    vector<Shot> getShots();


    friend ostream& operator<< (ostream &out, Grid grid);
};


#endif //EDU_CSCI2312_GRID_H

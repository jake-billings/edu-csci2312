//
// Created by Jake Billings on 2/21/18.
//

#ifndef EDU_CSCI2312_SHOT_H
#define EDU_CSCI2312_SHOT_H


class Shot {
public:
    Shot(unsigned int row, unsigned int col);

private:
    unsigned int row;
    unsigned int col;
public:
    unsigned int getRow() const;
    unsigned int getCol() const;
    bool existsAt(unsigned int row, unsigned int col) const;
};


#endif //EDU_CSCI2312_SHOT_H

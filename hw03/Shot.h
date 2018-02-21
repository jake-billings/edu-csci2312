/**
 * Name: Jake Billings
 * Date: 02/01/2018
 * Class: CSCI 2312
 * Description: declaration file containing the Shot class
 */


#ifndef EDU_CSCI2312_SHOT_H
#define EDU_CSCI2312_SHOT_H

/**
 * Shot
 *
 * represents a shot into the grid with X, Y coordinates
 */
class Shot {
public:
    /**
     * basic constructor for shot fired into grid
     *
     * @param row the row of the shot
     * @param col the col of the shot
     */
    Shot(unsigned int row, unsigned int col);

private:
    unsigned int row;
    unsigned int col;
public:
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
    bool existsAt(unsigned int row, unsigned int col) const;

    //getters and setters
    unsigned int getRow() const;
    unsigned int getCol() const;
};


#endif //EDU_CSCI2312_SHOT_H

/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Horse
 */

#include "Animal.h"
#include <iostream>
#include <stdexcept>

#ifndef EDU_CSCI2312_HORSE_H
#define EDU_CSCI2312_HORSE_H

/**
 * Horse
 *
 * class
 *
 * stores data from a file with the format
 *  Seabiscuit,brown,golden,12,7
 */
class Horse : public Animal {
private:
    /**
     * maneColor
     *
     * string
     *
     * the horse's mane color as a string
     */
    string maneColor;

    /**
     * age
     *
     * unsigned int
     *
     * the number of years for which this horse object has been alive
     */
    unsigned int age;

    /**
     * height
     *
     * unsigned int
     *
     * the height of this horse object in US feet (ft)
     */
    unsigned int height;
public:
    /**
     * print()
     *
     * method
     *
     * prints this object to cout as per homework requirements
     */
    void print() const;

    /**
     * read()
     *
     * reads this object from the stream is
     * throws exceptions if is is not properly formatted
     *
     * @param is input stream to read from
     */
    void read(istream &is);

    /**
     * subtractFromHeight()
     *
     * subtracts "amount" from this->height and returns the new height
     *
     * @param amount the amount to subtract by
     * @return the new height
     */
    unsigned int subtractFromHeight(unsigned int amount);

    //----Getters and Setters----
    const string &getManeColor() const;

    void setManeColor(const string &maneColor);

    unsigned int getAge() const;

    void setAge(unsigned int age);

    unsigned int getHeight() const;

    void setHeight(unsigned int height);
};


#endif //EDU_CSCI2312_HORSE_H

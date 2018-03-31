/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Fish
 */

#include "Animal.h"

#include <string>
#include <iostream>
#include <stdexcept>

//Use the standard namespace because this isn't production code, and I don't
// want to type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_FISH_H
#define EDU_CSCI2312_FISH_H

/**
 * Fish
 *
 * class
 *
 * stores data from a file with the format
 *  Nemo,orange,FALSE,coral reef,FALSE
 */
class Fish : public Animal {
private:
    /**
     * habitat
     *
     * string
     *
     * the string habitat that this fish lives in
     */
    string habitat;

    /**
     * freshwater
     *
     * bool
     *
     * a boolean representing if this fish lives in fresh water
     *  if the boolean is false, it presumably lives in salt water
     */
    bool freshwater;

    /**
     * predator
     *
     * bool
     *
     * true if this fish is a predator; false if it is not
     */
    bool predator;
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

    //----Getters and Setters----
    const string &getHabitat() const;

    void setHabitat(const string &habitat);

    bool isFreshwater() const;

    void setFreshwater(bool freshwater);

    bool isPredator() const;

    void setPredator(bool predator);
};


#endif //EDU_CSCI2312_FISH_H

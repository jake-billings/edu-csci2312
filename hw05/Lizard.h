/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Lizard
 */

#include "Animal.h"
#include <iostream>
#include <stdexcept>

//Use the standard namespace because this isn't production code, and I don't
// want to type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_LIZARD_H
#define EDU_CSCI2312_LIZARD_H

/**
 * Lizard
 *
 * class
 *
 * stores data from a file with the format
 *  Joey,red,fish tank,FALSE,12
 */
class Lizard : public Animal {
private:
    /**
     * habitat
     *
     * string
     *
     * the lizard's habitat as a string
     */
    string habitat;

    /**
     * lizardProtected
     *
     * bool
     *
     * true if this lizard is a protected species; false if not
     */
    bool lizardProtected;

    /**
     * weight
     *
     * unsigned int
     *
     * the weight of this lizard in US pounds (lbs)
     */
    unsigned int weight;
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

    bool isProtected() const;

    void setProtected(bool lizardProtected);

    unsigned int getWeight() const;

    void setWeight(unsigned int weight);
};


#endif //EDU_CSCI2312_LIZARD_H

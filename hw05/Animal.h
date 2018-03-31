/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Animal
 */

#include <string>
#include <ostream>

//Use the standard namespace because this isn't production code, and I don't
// want to type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_ANIMAL_H
#define EDU_CSCI2312_ANIMAL_H

/**
 * Animal
 *
 * class
 *
 * contains all properties that all animals have
 * contains all
 */
class Animal {
private:
    /**
     * name
     *
     * string
     *
     * the name of this animal object
     */
    string name;

    /**
     * color
     *
     * string
     *
     * the color of this animal object
     *  I'd use a uint_32 if I had more time and this was production. 32 bit color should be enough
     *  Maybe an enum if it needed to be user friendly
     */
    string color;

public:
    /**
     * print()
     *
     * virtual function
     *
     * overridden by subclasses to print the animal-specific details
     */
    virtual void print() const = 0;

    /**
     * read()
     *
     * virtual function
     *
     * reads the data for this object from a file input stream
     */
    virtual void read(istream &is) = 0;

    /**
     * operator>>
     *
     * input stream operator
     *
     * reads this animal object using the read() function
     *
     * @param is input stream
     * @param a animal to read
     * @return is input stream
     */
    friend istream &operator>>(istream &is, Animal &a);

    //----Getters and Setters----
    const string &getName() const;

    void setName(const string &name);

    const string &getColor() const;

    void setColor(const string &color);
};


#endif //EDU_CSCI2312_ANIMAL_H

/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Dog
 */

#include "Animal.h"
#include <string>
#include <ostream>
#include <iostream>
#include <stdexcept>

//Use the standard namespace because this isn't production code, and I don't
// want to type "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_DOG_H
#define EDU_CSCI2312_DOG_H

/**
 * Dog
 *
 * class
 *
 * stores data from a file with the format
 *  Buddy,Labrador Retreiver,7,Black,87
 */
class Dog : public Animal {
private:
    /**
     * breed
     *
     * string
     *
     * the dog's breed as a string
     */
    string breed;

    /**
     * age
     *
     * unsigned int
     *
     * the number of years for which this dog object has been alive
     */
    unsigned int age;

    /**
     * weight
     *
     * unsigned int
     *
     * the weight of this dog in US pounds (lbs)
     */
    unsigned int weight;
public:
    /**
     * subtractFromWeight()
     *
     * subtracts "amount" from this->weight and returns the new weight
     *
     * @param amount the amount to subtract by
     * @return the new weight
     */
    unsigned int subtractFromWeight(unsigned int amount);

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
    const string &getBreed() const;

    void setBreed(const string &breed);

    unsigned int getAge() const;

    void setAge(unsigned int age);

    unsigned int getWeight() const;

    void setWeight(unsigned int weight);
};


#endif //EDU_CSCI2312_DOG_H

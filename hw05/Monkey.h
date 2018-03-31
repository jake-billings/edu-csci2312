/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: declaration file for class Monkey
 */

#include "Animal.h"
#include <iostream>
#include <stdexcept>

#ifndef EDU_CSCI2312_MONKEY_H
#define EDU_CSCI2312_MONKEY_H

/**
 * Monkey
 *
 * class
 *
 * stores data from a file with the format
 *  Foo,brown,3,TRUE,Malaysia,FALSE
 */
class Monkey : public Animal {
private:
    /**
     * age
     *
     * unsigned int
     *
     * the number of years for which this monkey object has been alive
     */
    unsigned int age;

    /**
     * wild
     *
     * bool
     *
     * true if this monkey is wild; false if it's not
     */
    bool wild;

    /**
     * home
     *
     * string
     *
     * string respresentation of this Monkey's home
     */
    string home;

    /**
     * endangered
     *
     * bool
     *
     * true if this monkey is endangered; false if it's not
     */
    bool endangered;
public:

    friend istream &operator>>(istream &is, Monkey &monkey);

    /**
     * changeEndangered()
     *
     * flips the state of the endangered boolean and returns the new value
     *
     * @return the new value of endangered
     */
    bool changeEndangered();

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
    unsigned int getAge() const;

    void setAge(unsigned int age);

    bool isWild() const;

    void setWild(bool wild);

    const string &getHome() const;

    void setHome(const string &home);

    bool isEndangered() const;

    void setEndangered(bool endangered);
};


#endif //EDU_CSCI2312_MONKEY_H

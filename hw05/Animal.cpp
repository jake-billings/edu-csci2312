/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Animal
 */

#include "Animal.h"

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
istream &operator>>(istream &is, Animal &a) {
    a.read(is);
    return is;
}

//----Getters and Setters----
const string &Animal::getName() const {
    return name;
}

void Animal::setName(const string &name) {
    Animal::name = name;
}

const string &Animal::getColor() const {
    return color;
}

void Animal::setColor(const string &color) {
    Animal::color = color;
}

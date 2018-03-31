/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Horse
 */

#include "Horse.h"

/**
 * read()
 *
 * reads from is to populate the fields of this object
 *
 * @param is input stream pointing to a valid data stream
 */
void Horse::read(istream &is) {
    string name;
    string color;
    string maneColor;
    string age;
    string height;

    getline(is, name, ',');
    getline(is, color, ',');
    getline(is, maneColor, ',');
    getline(is, age, ',');
    getline(is, height, ',');

    this->setName(name);
    this->setColor(color);
    this->setManeColor(maneColor);
    this->setAge(stoi(age));
    this->setHeight(stoi(height));
}

/**
 * print()
 *
 * overriden virtual function from animal
 *
 * prints this animal to cout
 */
void Horse::print() const {
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Mane Color: " << this->getManeColor() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Height: " << this->getHeight() << endl;
}

/**
 * subtractFromHeight()
 *
 * subtracts "amount" from this->height and returns the new height
 *
 * @param amount the amount to subtract by
 * @return the new height
 */
unsigned int Horse::subtractFromHeight(unsigned int amount) {
    int newHeight = this->getHeight() - amount;
    if (newHeight < 0) throw runtime_error("Cannot set horse to negative height");
    this->setHeight(newHeight);
    return newHeight;
}

//----Getters and Setters----
const string &Horse::getManeColor() const {
    return maneColor;
}

void Horse::setManeColor(const string &maneColor) {
    Horse::maneColor = maneColor;
}

unsigned int Horse::getAge() const {
    return age;
}

void Horse::setAge(unsigned int age) {
    Horse::age = age;
}

unsigned int Horse::getHeight() const {
    return height;
}

void Horse::setHeight(unsigned int height) {
    Horse::height = height;
}

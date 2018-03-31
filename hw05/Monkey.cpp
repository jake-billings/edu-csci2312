/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Monkey
 */

#include "Monkey.h"

/**
 * print()
 *
 * overriden virtual function from animal
 *
 * prints this animal to cout
 */
void Monkey::print() const {
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Wild: " << (this->isWild() ? "Yes" : "No") << endl;
    cout << "Home: " << this->getHome() << endl;
    cout << "Endangered: " << (this->isEndangered() ? "Yes" : "No") << endl;
}

/**
 * operator>>
 *
 * input stream operator
 *
 * calls monkey.read() to read a monkey from a stream
 *
 * @param is input stream
 * @param monkey empty monkey object
 * @return is input stream
 */
istream &operator>>(istream &is, Monkey &monkey) {
    monkey.read(is);
    return is;
}

/**
 * read()
 *
 * reads from is to populate the fields of this monkey object
 *
 * @param is input stream pointing to a valid data stream
 */
void Monkey::read(istream &is) {
    string name;
    string color;
    string age;
    string wild;
    string home;
    string endangered;


    getline(is, name, ',');
    getline(is, color, ',');
    getline(is, age, ',');
    getline(is, wild, ',');
    getline(is, home, ',');
    getline(is, endangered, ',');

    this->setName(name);
    this->setColor(color);
    this->setAge(stoi(age));
    this->setHome(home);

    if (wild == "FALSE") {
        this->setWild(false);
    } else if (wild == "TRUE") {
        this->setWild(true);
    } else {
        throw runtime_error("invalid boolean for field wild while parsing monkey");
    }

    if (endangered == "FALSE") {
        this->setEndangered(false);
    } else if (endangered == "TRUE") {
        this->setEndangered(true);
    } else {
        throw runtime_error("invalid boolean for field wild while parsing monkey");
    }
}

/**
 * changeEndangered()
 *
 * flips the state of this->endangered (as required by homework)
 *
 * @return the new value of this->endangered
 */
bool Monkey::changeEndangered() {
    this->endangered = !this->isEndangered();
    return this->isEndangered();
}

//----Getters and Setters----
unsigned int Monkey::getAge() const {
    return age;
}

void Monkey::setAge(unsigned int age) {
    Monkey::age = age;
}

bool Monkey::isWild() const {
    return wild;
}

void Monkey::setWild(bool wild) {
    Monkey::wild = wild;
}

const string &Monkey::getHome() const {
    return home;
}

void Monkey::setHome(const string &home) {
    Monkey::home = home;
}

bool Monkey::isEndangered() const {
    return endangered;
}

void Monkey::setEndangered(bool endangered) {
    Monkey::endangered = endangered;
}

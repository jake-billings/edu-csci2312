/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Fish
 */

#include "Fish.h"

/**
 * read()
 *
 * reads from is to populate the fields of this object
 *
 * @param is input stream pointing to a valid data stream
 */
void Fish::read(istream &is) {
    string name;
    string color;
    string freshwater;
    string habitat;
    string predator;

    getline(is, name, ',');
    getline(is, color, ',');
    getline(is, freshwater, ',');
    getline(is, habitat, ',');
    getline(is, predator, ',');

    this->setName(name);
    this->setColor(color);
    this->setHabitat(habitat);

    if (freshwater == "FALSE") {
        this->setFreshwater(false);
    } else if (freshwater == "TRUE") {
        this->setFreshwater(true);
    } else {
        throw runtime_error("invalid boolean for field freshwater while parsing fish");
    }

    if (predator == "FALSE") {
        this->setPredator(false);
    } else if (predator == "TRUE") {
        this->setPredator(true);
    } else {
        throw runtime_error("invalid boolean for field predator while parsing fish");
    }
}

/**
 * print()
 *
 * overriden virtual function from animal
 *
 * prints this animal to cout
 */
void Fish::print() const {
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Freshwater: " << (this->isFreshwater()?"Yes":"No") << endl;
    cout << "Habitat: " << this->getHabitat() << endl;
    cout << "Predator: " << (this->isPredator()?"Yes":"No") << endl;
}

//----Getters and Setters----
const string &Fish::getHabitat() const {
    return habitat;
}

void Fish::setHabitat(const string &habitat) {
    Fish::habitat = habitat;
}

bool Fish::isFreshwater() const {
    return freshwater;
}

void Fish::setFreshwater(bool freshwater) {
    Fish::freshwater = freshwater;
}

bool Fish::isPredator() const {
    return predator;
}

void Fish::setPredator(bool predator) {
    Fish::predator = predator;
}

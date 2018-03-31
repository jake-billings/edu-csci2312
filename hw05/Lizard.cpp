/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Lizard
 */
#include "Lizard.h"

/**
 * print()
 *
 * overriden virtual function from animal
 *
 * prints this animal to cout
 */
void Lizard::print() const {
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Habitat: " << this->getHabitat() << endl;
    cout << "Protected: " << (this->isProtected() ? "Yes" : "No") << endl;
    cout << "Weight: " << this->getWeight() << endl;
}

/**
 * read()
 *
 * reads from is to populate the fields of this object
 *
 * @param is input stream pointing to a valid data stream
 */
void Lizard::read(istream &is) {
    string name;
    string color;
    string habitat;
    string lizardProtected;
    string weight;

    getline(is, name, ',');
    getline(is, color, ',');
    getline(is, habitat, ',');
    getline(is, lizardProtected, ',');
    getline(is, weight, ',');

    this->setName(name);
    this->setColor(color);
    this->setHabitat(habitat);
    this->setWeight(stoi(weight));

    if (lizardProtected == "FALSE") {
        this->setProtected(false);
    } else if (lizardProtected == "TRUE") {
        this->setProtected(true);
    } else {
        throw runtime_error("invalid boolean for field protected while parsing lizard");
    }
}

//----Getters and Setters----
const string &Lizard::getHabitat() const {
    return habitat;
}

void Lizard::setHabitat(const string &habitat) {
    Lizard::habitat = habitat;
}

bool Lizard::isProtected() const {
    return lizardProtected;
}

void Lizard::setProtected(bool lizardProtected) {
    Lizard::lizardProtected = lizardProtected;
}

unsigned int Lizard::getWeight() const {
    return weight;
}

void Lizard::setWeight(unsigned int weight) {
    Lizard::weight = weight;
}

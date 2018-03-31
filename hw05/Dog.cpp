/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description: implementation file for class Dog
 */

#include "Dog.h"

/**
 * read()
 *
 * reads from is to populate the fields of this object
 *
 * @param is input stream pointing to a valid data stream
 */
void Dog::read(istream &is) {
    string name;
    string breed;
    string age;
    string color;
    string weight;

    getline(is, name, ',');
    getline(is, breed, ',');
    getline(is, age, ',');
    getline(is, color, ',');
    getline(is, weight, ',');

    this->setName(name);
    this->setBreed(breed);
    this->setAge(stoi(age));
    this->setColor(color);
    this->setWeight(stoi(weight));
}

/**
 * subtractFromWeight()
 *
 * subtracts "amount" from this->weight and returns the new weight
 *
 * @param amount the amount to subtract by
 * @return the new weight
 */
unsigned int Dog::subtractFromWeight(unsigned int amount) {
    int newWeight = this->getWeight() - amount;
    if (newWeight < 0) throw runtime_error("Cannot set dog to negative weight");
    this->setWeight(newWeight);
    return newWeight;
}

/**
 * print()
 *
 * overriden virtual function from animal
 *
 * prints this animal to cout
 */
void Dog::print() const {
    cout << "Name: " << this->getName() << endl;
    cout << "Breed: " << this->getBreed() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Weight: " << this->getWeight() << endl;
}

//----Getters and Setters----
const string &Dog::getBreed() const {
    return breed;
}

void Dog::setBreed(const string &breed) {
    Dog::breed = breed;
}

unsigned int Dog::getAge() const {
    return age;
}

void Dog::setAge(unsigned int age) {
    Dog::age = age;
}

unsigned int Dog::getWeight() const {
    return weight;
}

void Dog::setWeight(unsigned int weight) {
    Dog::weight = weight;
}
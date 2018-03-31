/**
 * Name: Jake Billings
 * Date: 03/30/2018
 * Class: CSCI 2312
 * Description:
 *
 * Problem
 * =======
 * This assignment will have you read information in from various files, perform exception handling when reading those
 * files, and create a base class and derived classes with virtual functions to read the various files, perform some
 * computations on the inputs as described below, and print the file details.
 *
 * For this assignment, create a base class called Animal.  It should have as member variables any variables that are
 * contained across all animals in this assignment along with any associated mutator and accessor member functions.
 * You will create a derived class for each of the following: dog, fish, horse, monkey and lizard.  The member functions
 * to read and output the object’s information will be virtual functions.  Each derived class must contain the
 * additional member variables and member functions needed to include all fields in each input file. Each input file
 * will contain data about one object; you will not be required to read in information about multiple objects from
 * one file.
 *
 * My Solution
 * ===========
 * I implement virtual print() and read() functions. Then, I override the normal stream operators to use these virtual
 *  functions. If at any point, the stream fails to read a required value or an invalid value is presented,
 *  then the read() function throws an exception. The main() function catches this exception and displays
 *  an error.
 * I throw exceptions if function attempt to set weights/heights into the negatives on the Dog/Horse objects.
 *
 *
 * Test Strategy
 * =============
 *  See test()
 *
 *  I run unit tests that ensure that the stream operator (which uses the virtual read() function) properly reads data
 *   from the example data files.
 *  I also created garbage/corrupted/fuzzy test files and read those. I have unit tests that verify that exceptions
 *   are thrown when this occurs.
 *  I also have a demo that prints the results of the the mandatory calculations, and I check the results manually.
 *
 * Status: Runs on OSX using CLion and on csegrid using g++
 */



//---------Dependency Imports---------
//Include cout
#include <iostream>
#include <fstream>
#include <stdexcept>

//Include Project Files
#include "Dog.h"
#include "Fish.h"
#include "Horse.h"
#include "Lizard.h"
#include "Monkey.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;


//---------Poor Man's Testing Suite----------
/**
 * describe()
 *
 * Used to make the style look similar to mocha javascript tests;
 *  All this function really does is print a string followed by "..."
 *
 * @param expectString A string describing what a test is expecting
 */
void describe(const string expectString) {
    cout << expectString << "...";
}

/**
 * assertInt()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertInt(int expected, int got) {
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    cout << endl;

    return expected != got;
}

/**
 * assertString()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertString(string expected, string got) {
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed." << endl << "Expected: \"" << expected << "\"" << endl;
        cout << "Got:      \"" << got << "\"";
    }
    cout << endl;

    return expected != got;
}

//-----------Unit Test Function------------
/**
 * void test()
 *
 * unit testing for this project
 */
void test() {
    //Print welcome message
    cout << "========Unit Testing========" << endl;

    unsigned int failCount = 0;

    //---Read a Properly-Formatted Dog File and Verify It---
    Dog d;
    ifstream dStream;
    dStream.open("Dog.csv");
    dStream >> d;
    dStream.close();

    describe("should read property dog.name from properly formatted file");
    failCount += assertString("Buddy", d.getName());
    describe("should read property dog.breed from properly formatted file");
    failCount += assertString("Labrador Retreiver", d.getBreed());
    describe("should read property dog.age from properly formatted file");
    failCount += assertInt(7, d.getAge());
    describe("should read property dog.color from properly formatted file");
    failCount += assertString("Black", d.getColor());
    describe("should read property dog.weight from properly formatted file");
    failCount += assertInt(87, d.getWeight());

    //Verify that subtracting into the negative realm results in an error
    describe("should throw an error if subtracting a dog's weight into the negatives");
    bool dThrewError = false;
    try {
        d.subtractFromWeight(1000);
    } catch (runtime_error e) {
        dThrewError = true;
    }
    failCount += assertInt(true, dThrewError);

    //---Read a Properly-Formatted Fish File and Verify It---
    Fish f;
    ifstream fStream;
    fStream.open("Fish.csv");
    fStream >> f;
    fStream.close();

    describe("should read property fish.name from properly formatted file");
    failCount += assertString("Nemo", f.getName());
    describe("should read property fish.color from properly formatted file");
    failCount += assertString("orange", f.getColor());
    describe("should read property fish.freshwater from properly formatted file");
    failCount += assertInt(false, f.isFreshwater());
    describe("should read property fish.habitat from properly formatted file");
    failCount += assertString("coral reef", f.getHabitat());
    describe("should read property fish.predator from properly formatted file");
    failCount += assertInt(false, f.isPredator());

    //---Read a Properly-Formatted Horse File and Verify It---
    Horse h;
    ifstream hStream;
    hStream.open("Horse.csv");
    hStream >> h;
    hStream.close();

    describe("should read property horse.name from properly formatted file");
    failCount += assertString("Seabiscuit", h.getName());
    describe("should read property horse.color from properly formatted file");
    failCount += assertString("brown", h.getColor());
    describe("should read property horse.maneColor from properly formatted file");
    failCount += assertString("golden", h.getManeColor());
    describe("should read property horse.age from properly formatted file");
    failCount += assertInt(12, h.getAge());
    describe("should read property horse.height from properly formatted file");
    failCount += assertInt(7, h.getHeight());

    //Verify that subtracting into the negative realm results in an error
    describe("should throw an error if subtracting a horse's height into the negatives");
    bool hThrewError = false;
    try {
        h.subtractFromHeight(1000);
    } catch (runtime_error e) {
        hThrewError = true;
    }
    failCount += assertInt(true, hThrewError);

    //---Read a Properly-Formatted Lizard File and Verify It---
    Lizard l;
    ifstream lStream;
    lStream.open("Lizard.csv");
    lStream >> l;
    lStream.close();

    describe("should read property lizard.name from properly formatted file");
    failCount += assertString("Joey", l.getName());
    describe("should read property lizard.color from properly formatted file");
    failCount += assertString("red", l.getColor());
    describe("should read property lizard.habitat from properly formatted file");
    failCount += assertString("fish tank", l.getHabitat());
    describe("should read property lizard.protected from properly formatted file");
    failCount += assertInt(false, l.isProtected());
    describe("should read property lizard.weight from properly formatted file");
    failCount += assertInt(12, l.getWeight());

    //---Read a Properly-Formatted Monkey File and Verify It---
    Monkey m;
    ifstream mStream;
    mStream.open("Monkey.csv");
    mStream >> m;
    mStream.close();

    describe("should read property monkey.name from properly formatted file");
    failCount += assertString("Foo", m.getName());
    describe("should read property monkey.color from properly formatted file");
    failCount += assertString("brown", m.getColor());
    describe("should read property monkey.age from properly formatted file");
    failCount += assertInt(3, m.getAge());
    describe("should read property monkey.wild from properly formatted file");
    failCount += assertInt(true, m.isWild());
    describe("should read property monkey.home from properly formatted file");
    failCount += assertString("Malaysia", m.getHome());
    describe("should read property monkey.endangered from properly formatted file");
    failCount += assertInt(false, m.isEndangered());

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a horse from a dog file");
    ifstream dogStream;
    bool err = false;
    dogStream.open("Dog.csv");
    try {
        Horse testHorse;
        dogStream >> testHorse;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    dogStream.close();
    failCount += assertInt(true, err);

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a fish from a corrupted fish file");
    ifstream nastyFishStream;
    err = false;
    nastyFishStream.open("Fish_nasty.csv");
    try {
        Fish testFish;
        nastyFishStream >> testFish;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    nastyFishStream.close();
    failCount += assertInt(true, err);

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a horse from a corrupted horse file");
    ifstream nastyHorseStream; //ikea food
    err = false;
    nastyFishStream.open("Horse_nasty.csv");
    try {
        Horse testHorse;
        nastyFishStream >> testHorse;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    nastyHorseStream.close();
    failCount += assertInt(true, err);

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a horse from a nasty file");
    ifstream nastyStream; //ikea food
    err = false;
    nastyStream.open("nasty.csv");
    try {
        Horse testHorse;
        nastyStream >> testHorse;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    nastyStream.close();
    failCount += assertInt(true, err);

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a horse from a very nasty (fuzzer) file");
    ifstream fuzzerStream; //ikea food
    err = false;
    fuzzerStream.open("fuzzy.csv");
    try {
        Horse testHorse;
        fuzzerStream >> testHorse;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    fuzzerStream.close();
    failCount += assertInt(true, err);

    //---Read an Improperly-Formatted File and Verify It Throws an error---
    describe("should throw an exception reading a horse from a non-existent file");
    ifstream emptyStream; //ikea food
    err = false;
    emptyStream.open("");
    try {
        Horse testHorse;
        emptyStream >> testHorse;
    } catch (invalid_argument e) {
        err = true;
    } catch (runtime_error e) {
        err = true;
    }
    emptyStream.close();
    failCount += assertInt(true, err);


    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Testing======" << endl;
}

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Run Unit tests
    test();

    //---Demo the application---

    //Print welcome message
    cout << "===========Demo===========" << endl;

    //Declare variables to hold the classes we have to read
    Dog d;
    Fish f;
    Horse h;
    Lizard l;
    Monkey m;

    //Try to read all the objects from their respective files
    try {
        ifstream dStream;
        dStream.open("Dog.csv");
        dStream >> d;
        dStream.close();
        ifstream fStream;
        fStream.open("Fish.csv");
        fStream >> f;
        fStream.close();
        ifstream hStream;
        hStream.open("Horse.csv");
        hStream >> h;
        hStream.close();
        ifstream lStream;
        lStream.open("Lizard.csv");
        lStream >> l;
        lStream.close();
        ifstream mStream;
        mStream.open("Monkey.csv");
        mStream >> m;
        mStream.close();
    } catch (invalid_argument e) {
        cout << "Sorry. There was an error loading from that file. Check this message for details: " << endl;
        cout << e.what() << endl;
        cout << "Your file is not properly formatted. Make sure all integers are actually integers." << endl;
    } catch (runtime_error e) {
        cout << "Sorry. There was an error loading from that file. Check this message for details: " << endl;
        cout << e.what() << endl;
        cout << "Your file is not properly formatted. Make sure all booleans are actually integers." << endl;
    }

    //Complete the calculations required by the assignment
    try {
        d.subtractFromWeight(10);
    } catch (runtime_error e) {
        cout << "Oops. There was an issue subtracting from weight. See this message for more details:" << endl;
        cout << e.what() << endl;
    }
    try {
        h.subtractFromHeight(10);
    } catch (runtime_error e) {
        cout << "Oops. There was an issue subtracting from weight. See this message for more details:" << endl;
        cout << e.what() << endl;
    }

    //This isn't going to throw an error
    m.changeEndangered();

    d.print();
    cout << endl;
    f.print();
    cout << endl;
    h.print();
    cout << endl;
    l.print();
    cout << endl;
    m.print();

    //Print exit message
    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}
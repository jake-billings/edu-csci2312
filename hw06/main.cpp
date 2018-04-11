/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 *
 * Task:
 *
 * Outline
 * =======
 *  - describe(), assertInt() - Simple Test Suite Functions
 *  - test() Unit Testing
 *  - main(), which includes a call to test() and demo
 *
 * Status: compiles and runs on csegrid
 */

//---------Dependency Imports---------
//Include standard libraries we are allowed to use
#include <iostream>
//Include sstream for testing the output of the << operator
#include <sstream>

//Include the assignment headers
#include "LinkedList.hpp"

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
        cout << "Failed. Expected \"" << expected << "\"; Got \"" << got << "\".";
    }
    cout << endl;

    return expected != got;
}

/**
 * int test()
 *
 * Tests the functionality of the union operators; logs errors to the console if they exist
 */
void test() {
    //Print welcome message
    cout << "========Unit Tests========" << endl;

    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //push_front
    describe("push_front: should successfully store char at pos zero with length 0");
    LinkedList<char> v;
    v.push_front('f');
    failCount += assertInt('f', v.first());
    describe("push_front: should successfully store char at pos zero with length 1");
    v.push_front('d');
    failCount += assertInt('d', v.first());
    describe("push_front: should successfully store char at pos zero with length 2");
    v.push_front('s');
    failCount += assertInt('s', v.first());
    describe("push_front: should successfully store char at pos zero with length 3");
    v.push_front('a');
    failCount += assertInt('a', v.first());
    describe("push_front: list should contain \"asdf\"");
    string line;
    ostringstream os(line);
    os << v;
    failCount += assertString("asdf", os.str());

    //push_back
    describe("push_back: should successfully store char at back of linked list");
    v.push_back('t');
    failCount += assertInt(v.last(), 't');
    describe("push_back: list should now contain \"asdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdft", os.str());
    describe("push_back: should successfully store char at back of linked list");
    v.push_back('y');
    failCount += assertInt(v.last(), 'y');
    describe("push_back: list should now contain \"asdfty\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdfty", os.str());

    //pop_back
    describe("pop_back: should successfully delete char at back of linked list");
    v.pop_back();
    failCount += assertInt('t', v.last());
    describe("pop_back: list should now contain \"asdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdft", os.str());

    //pop_front
    describe("pop_front: should successfully delete char at front of linked list");
    v.pop_front();
    failCount += assertInt('s', v.first());
    describe("pop_front: list should now contain \"sdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("sdft", os.str());

    //test for small arrays
    LinkedList<char> a;
    describe("pop_back: should throw error if the list is empty");
    bool err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("pop_back: should not throw error if the list is one item");
    a.push_front('a');
    err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("pop_back: should be empty after removing last item");
    failCount += assertInt(true, a.isEmpty());

    describe("pop_back: should throw an error if the list has been emptied");
    err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    LinkedList<char> c;
    describe("pop_front: should throw an error if the list is empty");
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("pop_front: should not throw an error if there is an item in the list");
    c.push_front('a');
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("pop_front: should throw an error if the list has been emptied");
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);


    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;
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

    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}
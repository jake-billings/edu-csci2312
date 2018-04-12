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
//Include fstream for reading binary data from students.dat
#include <fstream>

//Include the assignment headers
#include "Student.h"
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

    //-----Test LinkedList-----

    //push_front
    describe("LinkedList: push_front: should successfully store char at pos zero with length 0");
    LinkedList<char> v;
    v.push_front('f');
    failCount += assertInt('f', v.first());
    describe("LinkedList: push_front: should successfully store char at pos zero with length 1");
    v.push_front('d');
    failCount += assertInt('d', v.first());
    describe("LinkedList: push_front: should successfully store char at pos zero with length 2");
    v.push_front('s');
    failCount += assertInt('s', v.first());
    describe("LinkedList: push_front: should successfully store char at pos zero with length 3");
    v.push_front('a');
    failCount += assertInt('a', v.first());
    describe("LinkedList: push_front: list should contain \"asdf\"");
    string line;
    ostringstream os(line);
    os << v;
    failCount += assertString("asdf", os.str());

    //push_back
    describe("LinkedList: push_back: should successfully store char at back of linked list");
    v.push_back('t');
    failCount += assertInt(v.last(), 't');
    describe("LinkedList: push_back: list should now contain \"asdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdft", os.str());
    describe("LinkedList: push_back: should successfully store char at back of linked list");
    v.push_back('y');
    failCount += assertInt(v.last(), 'y');
    describe("LinkedList: push_back: list should now contain \"asdfty\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdfty", os.str());

    //pop_back
    describe("LinkedList: pop_back: should successfully delete char at back of linked list");
    v.pop_back();
    failCount += assertInt('t', v.last());
    describe("LinkedList: pop_back: list should now contain \"asdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("asdft", os.str());

    //pop_front
    describe("LinkedList: pop_front: should successfully delete char at front of linked list");
    v.pop_front();
    failCount += assertInt('s', v.first());
    describe("LinkedList: pop_front: list should now contain \"sdft\"");
    line.clear();
    os = ostringstream(line);
    os << v;
    failCount += assertString("sdft", os.str());

    //test for small arrays
    LinkedList<char> a;
    describe("LinkedList: pop_back: should throw error if the list is empty");
    bool err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("LinkedList: pop_back: should not throw error if the list is one item");
    a.push_front('a');
    err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("LinkedList: pop_back: should be empty after removing last item");
    failCount += assertInt(true, a.isEmpty());

    describe("LinkedList: pop_back: should throw an error if the list has been emptied");
    err = false;
    try {
        a.pop_back();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    LinkedList<char> c;
    describe("LinkedList: pop_front: should throw an error if the list is empty");
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("LinkedList: pop_front: should not throw an error if there is an item in the list");
    c.push_front('a');
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("LinkedList: pop_front: should throw an error if the list has been emptied");
    err = false;
    try {
        c.pop_front();
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("LinkedList: clear: should make a full LinkedList empty");
    LinkedList<char> d;
    d.push_front('a');
    d.push_front('b');
    d.push_front('c');
    d.push_front('d');
    d.push_front('e');
    d.clear();
    failCount += assertInt(true, d.isEmpty());

    describe("LinkedList: clear: should still be emtpy if called on an empty LinkedList");
    d.clear();
    failCount += assertInt(true, d.isEmpty());

    describe("LinkedList: clear: should still be able to add elements after");
    d.push_front('z');
    failCount += assertInt('z', d.first());

    describe("LinkedList: operator=: should assign one list to another");
    LinkedList<char> e;
    e.push_front('f');
    e.push_front('g');
    e.push_front('i');
    LinkedList<char> f;
    f.push_front('h');
    f.push_front('k');
    f.push_front('j');
    f.push_front('z');
    f.push_front('y');
    e = f;
    failCount += assertInt('y', e.first());

    describe("LinkedList: operator=: lefthand element should still be able to receive elements");
    e.push_front('q');
    failCount += assertInt('q', e.first());

    describe("LinkedList: operator=: lefthand element should still be able to clear()");
    e.clear();
    failCount += assertInt(true, e.isEmpty());

    describe("LinkedList: operator=: righthand element should still be able to receive elements");
    f.push_front('r');
    failCount += assertInt('r', f.first());

    describe("LinkedList: operator=: righthand element should still be able to clear()");
    f.clear();
    failCount += assertInt(true, f.isEmpty());

    describe("LinkedList: operator>>: should output elements in sequence");
    LinkedList<char> jake;
    jake.push_front('k');
    jake.push_front('a');
    jake.push_front('j');
    jake.push_back('e');
    line.clear();
    os = ostringstream(line);
    os << jake;
    failCount += assertString("jake", os.str());

    describe("LinkedList: printList(): should output elements in sequence");
    LinkedList<char> jake2;
    jake2.push_front('k');
    jake2.push_front('a');
    jake2.push_front('j');
    jake2.push_back('e');
    line.clear();
    os = ostringstream(line);
    jake2.printList(os);
    failCount += assertString("jake", os.str());


    //-----Test Student Struct/IO-----
    describe("student: operator>>: should successfully read first student from students.dat");
    err = false;
    Student s;
    ifstream in;
    try {
        in.open("students.dat", ios::in | ios::binary);
        in >> s;
    } catch (exception e) {
        cerr << e.what();
        err = true;
    }
    failCount += assertInt(false, err);

    describe("student: operator>>: should read the first student's name as 'Ashly'");
    failCount += assertString("Ashly", s.name);
    describe("student: operator>>: should read the first student's id as 111");
    failCount += assertInt(111, s.id);

    describe("student: operator>>: should read two more students from the file");
    unsigned int count = 0;
    while (in >> s) {
        count++;
    }
    failCount += assertInt(2, count);

    in.close();

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

    //---Exact Tests from Document---
    //Create a pointer to a list and assign it to a new pointer
    LinkedList<int> *a = new LinkedList<int>;

    //Demonstrate all functions with multiple ints and use cout statements and the printList to
    // describe each of the functions.
    cout << "Empty LinkedList: " << *a << endl;

    a->push_front(2);
    a->push_front(3);

    cout << "Two element LinkedList: " << *a << endl;

    a->push_back(4);
    a->push_back(5);

    cout << "Four element LinkedList: " << *a << endl;

    a->pop_back();

    cout << "pop_back(): " << *a << endl;

    a->pop_front();

    cout << "pop_front(): " << *a << endl;

    //Create a pointer to a second list and construct it with the first list
    LinkedList<int> b(*a);

    //Print out the second list to show that your copy constructor worked.
    cout << "copied List: " << b << endl;

    //Create a pointer to a third list, then use = to assign it to the first list
    LinkedList<int> *c = new LinkedList<int>;
    *c = *a; // use * to use the overloaded operator instead of pointer assignment

    //Print out the third list to show that your assignment operator worked.
    cout << "assigned list: " << *c << endl;

    //Demonstrate exception handling of pop_front.
    try {
        while (true) {
            a->pop_front();
        }
    } catch (runtime_error e) {
        cout << "you can't remove elements forever without getting an exception" << endl;
    }

    //Delete both pointers
    delete a;
    delete c;

    //Declare a list of type Students
    LinkedList<Student> *students = new LinkedList<Student>;

    //Read in Students from provided binary file students.dat.
    ifstream in;
    in.open("students.dat", ios::in | ios::binary);
    Student s;

    //Use push_front to create a linked list of students. Note: if you don’t get 3 records read in from students.dat,
    // you could try writing some binary students before reading them in…then comment that out once you get the students.dat to read in properly.
    while (in >> s) {
        students->push_back(s);
    }

    //Print students list to show it worked
    while (!students->isEmpty()) {
        cout << students->first() << endl;
        students->pop_front();
    }

    cout << "=========End Demo=========" << endl;

    delete students;

    //Exit with a 0 status code
    return 0;
}
/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2312
 * Description: declaration file for Student struct/input operator
 */


//Include iostream so we can define an operator
#include<iostream>

//Use the standard namespace since this isn't production code, and I don't wanna type
// "std::" all the time
using namespace std;

#ifndef EDU_CSCI2312_STUDENT_H
#define EDU_CSCI2312_STUDENT_H

/**
 * Student
 *
 * struct
 *
 * represents the exact binary structure of a student in the file "students.dat"
 *
 * you cannot edit this at all, or everything will break
 *
 * we use delicate binary IO in the project (it's a requirement)
 */
struct Student {
    friend ostream &operator<<(ostream &os, const Student &student);

    /**
     * name
     *
     * C-string (20-length char array)
     *
     * name 20-byte C-String-style name of this student
     */
    char name[20];

    /**
     * id
     *
     * int
     *
     * the student's 4-byte id
     */
    int id;
};

/**
 * operator>>
 *
 * reads a student from "students.dat" using direct binary file IO
 *
 * @param is binary input stream to read from
 * @param a student object to read to
 * @return is the binary input stream
 */
istream &operator>>(istream &is, Student &a);

/**
 * operator<<
 *
 * writes a student to cout using ascii output
 *
 * @param os the cout-like ascii output stream to write to
 * @param student the student struct to write
 * @return os the cout-like ascii output stream
 */
ostream &operator<<(ostream &os, const Student &student);

#endif //EDU_CSCI2312_STUDENT_H

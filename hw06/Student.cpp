/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2312
 * Description: implemenation file for Student input operator
 */


//Include the header file so we can implement it
#include "Student.h"


/**
 * operator>>
 *
 * reads a student from "students.dat" using direct binary file IO
 *
 * @param is binary input stream to read from
 * @param a student object to read to
 * @return is the binary input stream
 */
istream &operator>>(istream &is, Student &a) {
    is.read((char *) &a, sizeof(Student));
    return is;
}


/**
 * operator<<
 *
 * writes a student to cout using ascii output
 *
 * @param os the cout-like ascii output stream to write to
 * @param student the student struct to write
 * @return os the cout-like ascii output stream
 */
ostream &operator<<(ostream &os, const Student &student) {
    os << "name: " << student.name << " id: " << student.id;
    return os;
}
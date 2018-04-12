*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     :  CSC 2312
*  Due Date  :  Apr. 11, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Problem
=======
"For this assignment, you will use pointers with dynamic memory, templates, binary files and exception handling to
  build a multi-purpose, generic, Single Linked List. Anytime you are using dynamic memory, you should have a Copy
  Constructor, overloaded Assignment Operator, and a Destructor. Though this will be similar in functionality to the
  C++ Standard Template Library (STL) forward_list, you will create your own using pointers (instead of forward_list,
  list or vector)." - Assignment Docx

  Implement a generic (templated LinkedList) as well as binary file IO for a student struct


Test Strategy
=============
 See test()

 I run unit tests for every function. I run a few tests to ensure that edge cases don't break existing functionality.
 Each test checks the result of an operation. I ensure to test that methods that should throw exceptions do.

Status: Runs on OSX using CLion and on csegrid using g++

*******************************************************
*  Source files
*******************************************************

Name:  billingsJakeHW06.cpp
    test() - runs automated unit and integration testing using a few helper test functions
    main() - runs test() then provides a demo

Name: LinkedList.hpp
    declaration file for LinkedList class
    a LinkedList represents an ordered list using pointers
    since this implementation uses templates, the implentation must be in the header file
    the assignment specifies that the header should have the extension "hpp"

Name: Node.hpp
    declaration file for Node class
    a LinkedList contains multiple nodes in a path structure
    the node class "wraps" data in the LinkedList class adding a pointer to the next node
    since this implementation uses templates, the implentation must be in the header file
    the assignment specifies that the header should have the extension "hpp"

Name: Student.h
    declaration file for Student struct and stream operators

Name: Student.cpp
    implementation file for Student stream operators

Name: students.dat
    binary data file provided by the assignment
    contains three students in binary format

   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.


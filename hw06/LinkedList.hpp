/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2312
 * Description: declaration file for template class LinkedList
 */

//Include iostream to implement the << operator
#include <iostream>
//Include stdexcept because we throw errors sometimes
#include <stdexcept>
//Include node class because we need it
#include "Node.hpp"

#ifndef EDU_CSCI2312_LINKEDLIST_H
#define EDU_CSCI2312_LINKEDLIST_H

/**
 * LinkedList
 *
 * class
 *
 * Represents an ordered list that can be accessed and modified at the ends.
 *
 * LinkedList data structures provide efficent access to the front of the list and ineffcient access to the end. Each
 *  element is inserted into heap memory and a chain of pointers from one element to the next creates the ordered list.
 *
 * The following class is my implementation of a linked list data structure for CSCI2312 Object Oriented Programming
 *  at University of Colorado Denver.
 *
 * This implementation has the following functions implemented:
 *  - Copy Constructor
 *  - Overloaded Assignment Operator
 *  - clear
 *  - destructor
 *  - push_front
 *  - push_back
 *  - pop_front
 *  - pop_back
 *  - printlist (assignment-specific function to print the whole list)
 *  - isEmpty
 *
 * deallocates memory on node deletion and in destructor
 * copy constructor makes a deep copy of the list and using the default copy constructor for elements
 *
 * elements are "wrapped" in "nodes"
 *
 * elements are the objects in the ordered lists; nodes add pointers from one to the next to the data structure
 *
 * https://en.wikipedia.org/wiki/Linked_list
 *
 * @tparam T the type of class that this LinkedList will hold (e.g. char, Student)
 */
template<class T> class LinkedList {
private:
    /**
     * head
     *
     * Node<T> pointer
     *
     * this is a pointer to the first node of the linked list
     */
    Node<T> *head;
public:
    /**
     * LinkedList
     *
     * constructor
     *
     * default empty
     *
     * O(1)
     *
     * instantiates an empty linked list
     */
    LinkedList() {
        //Set head pointer to null this is important
        // as head isn't null if you don't set it to null
        this->head = nullptr;
    }

    /**
     * ~LinkedList
     *
     * destructor
     *
     * O(n)
     *
     * deallocates all memory used on the heap by this linked list
     *  by iterating each element
     */
    ~LinkedList() {
        Node<T> *cur = this->head;
        Node<T> *next = nullptr;
        while (cur != nullptr) {
            next = cur->getNext();
            delete cur;
            cur = next;
        }
    }

    /**
     * LinkedList()
     *
     * constructor
     *
     * copy constructor override
     *
     * called implicitly when passing by value (e.g. in stream operators)
     *
     * O(n)
     *
     * copies the LinkedList original into this new LinkedList by iterating over each element
     *  creating a new Node object and copying the data
     *
     * @param original the original linked list to copy
     */
    LinkedList(const LinkedList<T> &original) {
        //Set head pointer to null in the same way the empty/default constructor does; this is important
        // as head isn't null if you don't set it to null
        this->head = nullptr;

        //Loop over each element of the old list and copy it
        Node<T> *cur = original.head;
        while (cur != nullptr) {
            this->push_back(cur->getData());
            cur = cur->getNext();
        }
    }

    /**
     * push_front()
     *
     * method
     *
     * O(1)
     *
     * adds an element to the front of this linked list by wrapping it in a new node object, placing it on the heap,
     *  and updating the head pointer
     *
     * @param  value the value to place into the LinkedList (type T from template)
     */
    void push_front(T value) {
        //Allocate a new node on the heap that points to the old head node
        Node<T> *n = new Node<T>(value, this->head);

        //Set head to point at the new node on the heap
        this->head = n;
    }

    /**
     * push_back()
     *
     * method
     *
     * O(n)
     *
     * adds an element to the back of this LinkedList by iterating through all the elements, then creating a new node,
     *  placing it on the heap, then setting the next pointer of the last node
     *
     * NOTE: this function has a higher algorithmic complexity than push_front()
     *
     * @param value the value to place into the LinkedList (type T from template)
     */
    void push_back(T value) {
        //If the list is already empty, use the simpler algorithm from push_front to insert the
        // value then return
        if (this->head == nullptr) {
            return this->push_front(value);
        }

        //Now, we can assume the head pointer is a node (not nullptr).
        // We iterate until we find the last node
        Node<T> *cur = this->head;
        while (cur->getNext() != nullptr) {
            cur = cur->getNext();
        }

        //Allocate a new node on the heap that points to nullptr (since it's the last element of the list)
        Node<T> *n = new Node<T>(value, nullptr);

        //Update the ptr of the node that used to be the last node to point at the new node
        cur->setNext(n);
    }

    /**
     * pop_front()
     *
     * method
     *
     * O(1)
     *
     * removes an element from the list be deallocating the memory from the first node and updating the head pointer
     *
     * throws an error if the list is empty
     */
    void pop_front() {
        //Throw an error if the list is empty because we can't remove an element that doesn't exist
        if (this->head == nullptr) {
            throw std::runtime_error("cannot remove first element of an empty LinkedList");
        }

        //Get a pointer the the current element in the first position
        Node<T> *n = this->head;

        //Move head pointer to point at the second element
        this->head = this->head->getNext();

        //Delete the node that used to be the head
        delete n;
    }

    /**
     * pop_back()
     *
     * method
     *
     * O(n)
     *
     * NOTE: this function has a higher algorithmic complexity than pop_front()
     *
     * removes an element from the end of the LinkedList by iterating though each element, deallocating the last element
     *  then updating the new last element's pointer
     *
     * throws an error if the list is empty
     */
    void pop_back() {
        //Throw an error if the list is empty because we can't remove an element that doesn't exist
        if (this->head == nullptr) {
            throw std::runtime_error("cannot remove last element of an empty LinkedList");
        }

        //Iterate until we get to the last node; keep track of the current node and the next
        // because we will need to update the pointer of the previous node
        Node<T> *cur = this->head;
        Node<T> *next = cur->getNext();
        while (next != nullptr && (next->getNext()) != nullptr) {
            cur = next;
            next = cur->getNext();
        }

        //If there isn't a "next" element, we are removing the first element. In this case, there is only one element
        // and we must delete it at the head.
        // otherwise, current is the second-to-last node, which needs it's pointer set to null, and next is the last
        // element, which must be freed
        if (next == nullptr) {
            delete cur;
            this->head = nullptr;
        } else {
            cur->setNext(nullptr);
            delete next;
        }
    }

    /**
     * first()
     *
     * method
     *
     * O(1)
     *
     * returns the first element of this LinkedList by reading  from the head node
     *
     * throws an error if the list is empty
     *
     * @return the first element of this LinkedList (type T from template)
     */
    T first() {
        //throw an error if the list is empty; we can't return an element that isn't there
        if (this->head == nullptr) {
            throw std::runtime_error("cannot get last element of an empty LinkedList");
        }

        //otherwise, return the data from the head node
        return this->head->getData();
    }

    /**
     * last()
     *
     * method
     *
     * O(n)
     *
     * returns the last element of this LinkedList by iterating through each element and returning when the next
     *  pointer is null
     *
     * NOTE: this function has a higher algorithmic complexity than front()
     *
     * throws an error if the list is empty
     *
     * @return the last element of this LinkedList
     */
    T last() {
        //throw an error if the list is empty; we can't return an element that isn't there
        if (this->head == nullptr) {
            throw std::runtime_error("cannot get last element of an empty LinkedList");
        }

        //iterate over each node to find the last one
        Node<T> *cur = this->head;
        while (cur->getNext() != nullptr) {
            cur = cur->getNext();
        }

        //return the data from the last node
        return cur->getData();
    }

    /**
     * isEmpty()
     *
     * method
     *
     * returns true if this list is empty
     * this list is empty if the head pointer is null, so we return the result of this check
     *
     * @return true if this list is empty
     */
    bool isEmpty() {
        return this->head == nullptr;
    }

    /**
     * operator<<
     *
     * sequentially writes the contents of this LinkedList to the output stream out
     *
     * designed for a LinkedList of type char; this will properly write the contents to cout like a string
     *
     * example use:
     *
     * LinkedList<char> list;
     * list.push_back('a');
     * list.push_back('b');
     * list.push_back('c');
     * cout << list << endl; //prints "abc\n"
     *
     * @param out the output stream to write to
     * @param list the LinkedList to output
     * @return ostream out
     */
    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> list) {
        Node<T> *cur = list.head;

        while (cur != nullptr) {
            out << *cur;
            cur = cur->getNext();
        }

        return out;
    }
};

#endif
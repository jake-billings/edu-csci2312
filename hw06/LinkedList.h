#include <iostream>
#include "Node.h"

using namespace std;


/**
 * LinkedList
 *
 * class
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
 * https://en.wikipedia.org/wiki/Linked_list
 */
template<class T>
class LinkedList {
private:
    Node<T> *head;
public:
    LinkedList() {
        this->head = nullptr;
    }

    ~LinkedList() {
        Node<T> *cur = this->head;
        Node<T> *next = nullptr;
        while (cur != nullptr) {
            next = cur->getNext();
            delete cur;
            cur = next;
        }
    }

    LinkedList(const LinkedList<T> &original) {
        this->head = nullptr;
        Node<T> *cur = original.head;
        while (cur != nullptr) {
            this->push_back(cur->getData());
            cur = cur->getNext();
        }
    }

    void push_front(T value) {
        Node<T> *n = new Node<T>(value, this->head);
        this->head = n;
    }

    void push_back(T value) {
        if (this->head == nullptr) {
            return this->push_front(value);
        }

        Node<T> *cur = this->head;
        while (cur->getNext() != nullptr) {
            cur = cur->getNext();
        }

        Node<T> *n = new Node<T>(value, nullptr);

        cur->setNext(n);
    }

    void pop_front() {
        if (this->head == nullptr) {
            throw runtime_error("cannot remove first element of an empty LinkedList");
        }

        Node<T> *n = this->head;
        this->head = this->head->getNext();
        delete n;
    }

    void pop_back() {
        if (this->head == nullptr) {
            throw runtime_error("cannot remove last element of an empty LinkedList");
        }

        Node<T> *cur = this->head;
        Node<T> *next = cur->getNext();
        while (next != nullptr && (next->getNext()) != nullptr) {
            cur = next;
            next = cur->getNext();
        }

        if (next == nullptr) {
            this->head = nullptr;
        } else {
            cur->setNext(nullptr);
            delete next;
        }
    }

    T first() {
        return this->head->getData();
    }

    T last() {
        if (this->head == nullptr) {
            throw runtime_error("cannot get last element of an empty LinkedList");
        }

        Node<T> *cur = this->head;
        while (cur->getNext() != nullptr) {
            cur = cur->getNext();
        }

        return cur->getData();
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    friend ostream &operator<<(ostream &out, LinkedList<T> list) {
        Node<T> *cur = list.head;

        while (cur != nullptr) {
            out << *cur;
            cur = cur->getNext();
        }

        return out;
    }
};

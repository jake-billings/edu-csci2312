//
// Created by Jake Billings on 4/11/18.
//

#ifndef EDU_CSCI2312_NODE_H
#define EDU_CSCI2312_NODE_H

#include <iostream>

template <class T>
class Node {
private:
        T data;
        Node *next;
public:
    Node(T data, Node *next) : data(data), next(next) {}

    T getData() const {
        return data;
    }

    Node *getNext() const {
        return this->next;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << node.data;
        return os;
    }
};


#endif //EDU_CSCI2312_NODE_H

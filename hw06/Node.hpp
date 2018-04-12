/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2312
 * Description: declaration file for template class Node
 */

#ifndef EDU_CSCI2312_NODE_H
#define EDU_CSCI2312_NODE_H

//Include ostream so that we can implement the << operator
#include <ostream>

/**
 * Node
 *
 * class
 *
 * mutable - LinkedList can and does change the pointer value of nodes
 *
 * wraps the data type T and adds a pointer from this node to another node
 *
 * the purpose of this data structure is for use within the LinkedList class
 *
 * @tparam T the type of class that this node will hold
 */
template<typename T>
class Node {
private:
    /**
     * data
     *
     * T
     *
     * the actual data that this node holds
     */
    T data;

    /**
     * next
     *
     * Node<T> pointer
     *
     * a pointer to the next node in the linked list
     *  this will be nullptr if this is the last node in the list
     */
    Node *next;
public:
    /**
     * Node
     *
     * constructor
     *
     * @param data the data this node should hold
     * @param next the next pointer of this node
     */
    Node(T data, Node *next) : data(data), next(next) {}

    /**
     * getData()
     *
     * returns the data held by this Node
     *
     * @return the data represented by this node
     */
    T getData() const {
        return data;
    }

    /**
     * getNext()
     *
     * returns the pointer to the next node in the LinkedList
     *  nullptr if this is the last element in the list
     *
     * @return pointer to the next node in the LinkedList
     */
    Node *getNext() const {
        return this->next;
    }

    /**
     * setNext()
     *
     * modifies the pointer to the next node in the LinkedList
     *
     * used in LinkedList::push_back() and LinkedList::pop_back() to update pointer values of the last element
     *
     * @param next the new next ptr (nullptr if this node is to become the last in the list)
     */
    void setNext(Node *next) {
        this->next = next;
    }

    /**
     * operator<<
     *
     * passes the operator on to the data element of this node
     *
     * "os << node.data"
     *
     * @param os the output stream to output to
     * @param node the node to output (we will output its data)
     * @return os the output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << node.data;
        return os;
    }
};


#endif //EDU_CSCI2312_NODE_H

#include "LinkedList.h"

/**
 * LinkedList()
 *
 * constructor
 *
 * instantiates a default linked list with a single "termination" element
 */
LinkedList::LinkedList() {
    this->n.data = '\0';
    this->n.nextPtr = nullptr;
}

/**
 * ~LinkedList()
 *
 * destructor
 *
 * free all of the memory from all of the nodes we created
 */
LinkedList::~LinkedList() {
    //If there's no next element, we're not using heap memory, so don't bother freeing it
    if (n.nextPtr != nullptr) {
        //Loop through each pointer and free it
        Node *targetPtr = this->n.nextPtr;
        while (targetPtr->nextPtr != nullptr) {
            Node* nextPtr = targetPtr->nextPtr;
            free(targetPtr);
            targetPtr = nextPtr;
        }
        n.nextPtr = nullptr;
    }
}

/**
 * insertAtFront()
 *
 * O(1)
 *
 * add a value to the beginning of the linked list
 *
 * @param value value to add
 * @return true if operation was successful
 */
bool LinkedList::insertAtFront(char value) {
    //copy the old first node from local instance memory to the heap
    Node *heapPtr = (Node *) malloc(sizeof(Node));
    memcpy(heapPtr, &this->n, sizeof(Node));

    //instantiate a new node in local scope memory
    Node newNode;
    newNode.data = value;
    newNode.nextPtr = heapPtr;

    //store the new node to local instance memory
    this->n = newNode;

    return true;
}

/**
 * insertBeforePosition()
 *
 * O(n)
 *
 * insert a value at a specific location in the linked list
 *
 * @param value value to add
 * @param index index to add at
 * @return true if operation was successful
 */
bool LinkedList::insertBeforePosition(char value, int index) {
    //If value is negative, throw error
    if (index < 0) return false;
    //If value is at front, call the front function
    if (index == 0) return this->insertAtFront(value);

    //Follow each pointer until we reach the proper index
    Node *prevPtr = nullptr;
    Node *targetPtr = &n;
    for (unsigned int i = 0; i < index; i++) {
        //If we hit nullptr, they gave us an index that is outside the list
        // return false
        if (targetPtr->nextPtr == nullptr) {
            return false;
        }
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    //Instantiate a node on the heap
    // point it's nextPtr to the next element
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = value;
    n->nextPtr = targetPtr;

    //Point the previous element at the new element
    prevPtr->nextPtr = n;

    //return true
    return true;
}

/**
 * insertAtBack()
 *
 * O(n)
 *
 * inserts an element on the end of the list
 *
 * @param value value to insert
 * @return true if successful
 */
bool LinkedList::insertAtBack(char value) {
    //iterate to find the last node
    Node *targetPtr = &(this->n);
    while (targetPtr->nextPtr != nullptr) {
        targetPtr = targetPtr->nextPtr;
    }

    //instatiate a new node on the heap
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = value;
    n->nextPtr = nullptr;

    //point the last node in the list to the new node on the heap
    targetPtr->nextPtr = n;

    //return true
    return true;
}

/**
 * deleteAtFront()
 *
 * O(1)
 *
 * deletes at the front of the list
 *
 * @return true if successful
 */
bool LinkedList::deleteAtFront() {
    //if we're on the "termination element," don't bother deleting
    if (this->n.data == '\0') return false;

    //move the next pointer to the current element
    this->n = *this->n.nextPtr;

    //return true
    return true;
}

/**
 * deletePosition()
 *
 * O(n)
 *
 * delete at any position in the list
 *
 * @param index index to delete at
 * @return true if successful
 */
bool LinkedList::deletePosition(int index) {
    //if we're on the "termination element," don't bother deleting
    if (this->n.data == '\0') return false;

    //if index is invalid, return false
    if (index < 0) return false;

    //if index is 0, call deleteAtFront()
    if (index == 0) return this->deleteAtFront();

    //iterate through pointers until we get
    // to the index we want
    Node *prevPtr = nullptr;
    Node *targetPtr = &n;
    for (unsigned int i = 0; i < index; i++) {
        //return false if we exceed the index
        // (they gave us an index that's out of range)
        if (targetPtr->nextPtr == nullptr) {
            return false;
        }
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    //set the previous nextPtr to our next ptr then free our memory
    prevPtr->nextPtr = targetPtr->nextPtr;
    free(targetPtr);

    //return true
    return true;
}

/**
 * deleteAtBack()
 *
 * O(n)
 *
 * delete an element from the end of the list
 *
 * @return true if successful
 */
bool LinkedList::deleteAtBack() {
    //if we're on the "termination element," don't bother deleting
    if (this->n.data == '\0') return false;

    //iterate through elements until we get to the end
    Node *prevPtr = nullptr;
    Node *targetPtr = &(this->n);
    while (targetPtr->nextPtr != nullptr) {
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    //if there's actually an element, free the memory and
    // shift the array
    if (prevPtr != nullptr) {
        prevPtr->nextPtr = nullptr;
        free(targetPtr);

        return true;
    }

    //return false; there was no element
    return false;
}

/**
 * operator<<
 *
 * O(n)
 *
 * prints a linked list to a stream
 *
 * @param out stream to print to
 * @param list list to print
 * @return out
 */
ostream &operator<<(ostream &out, LinkedList *list) {
    //print the first element
    out << list->n.data;

    //iterate through the pointer chain
    Node *nextPtr = list->n.nextPtr;
    while (nextPtr != nullptr) {
        //ignore the "termination element"
        if (nextPtr->data != '\0') out << nextPtr->data;
        nextPtr = nextPtr->nextPtr;
    }

    //return the output stream
    return out;
}

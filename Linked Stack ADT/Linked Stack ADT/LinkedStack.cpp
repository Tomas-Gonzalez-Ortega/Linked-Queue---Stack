/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #8 lab08 The Linked Stack ADT
 * Description: A generic linked structured Stack ADT named LinkedStack implementation with the following functionalities:
 1. A constructor, LinkedStack(), to create an empty stack.
 2. A destructor, ~LinkedStack(), to free the stack memory.
 3. A function to push a new element into the stack: void push(T newElement).
 4. A function to pop and return the element at the top of the stack: T pop(); this function throws a runtime-error exception, or simply prints an error message in case the stack is empty.
 5. A function to retrieve the element at the top of the stack: T getTop(); this function throws a runtime-error exception (if you know how), or simply prints an error message in case the stack is empty.
 6. A function to check if the stack is empty: bool isEmpty().
 * @version Copyright © 2017-11-23 All rights reserved. Langara College
 */
#include "LinkedStack.h"
#include <iostream>

// no-arg node constructor to create a node
template<typename T>
LinkedStack<T>::LinkedStack() {
    top = nullptr;
    size = 0;
}

// Stack destructor
template<typename T>
LinkedStack<T>::~LinkedStack() {
    delete this->top;
}

/**
 Inserts a new element in the stack
 @param newElement the actual element we want to push inside the stack
 */
template<typename T>
void LinkedStack<T>::push(T newElement) {
    Node<T>* newNode = new Node<T>(newElement);
    newNode->next = top;
    top = newNode;
    size++;
}

/**
 Deletes an element from the stack - throws a run time error if the stack is empty
 @return the stack without the element removed
 */
template<typename T>
T LinkedStack<T>::pop() throw (runtime_error) {
    if (this->top->element == NULL)
        throw runtime_error("No elements in the stack");
    else {
        Node<T>* topNode = this->top->next;
        T currentNode = topNode->element;
        this->top->next = this->top->next->next;
        delete []topNode;
        size--;
        return currentNode;
    }
}

/**
 Gets the element present at top - throws a run time error if the stack is empty
 @return the actual element sit at top of the stack
 */
template<typename T>
const T LinkedStack<T>::getTop() throw (runtime_error) {
    if (this->top->next == NULL)
        throw runtime_error("No elements in the stack");
    else
        return this->top->next->element;
}

/**
 Checks if the stack is empty
 @return true if the stack is empty
 @return false if at least 1 element is contained
 */
template<typename T>
bool const LinkedStack<T>::isEmpty() {
    return (this->top == nullptr);
}

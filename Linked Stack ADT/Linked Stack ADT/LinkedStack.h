/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #8 lab08 The Linked Stack ADT
 * Description: A generic linked structured Stack ADT header file named LinkedStack. With the following functionalities:
 1. A constructor, LinkedStack(), to create an empty stack.
 2. A destructor, ~LinkedStack(), to free the stack memory.
 3. A function to push a new element into the stack: void push(T newElement).
 4. A function to pop and return the element at the top of the stack: T pop(); this function throws a runtime-error exception, or simply prints an error message in case the stack is empty.
 5. A function to retrieve the element at the top of the stack: T getTop(); this function throws a runtime-error exception, or simply prints an error message in case the stack is empty.
 6. A function to check if the stack is empty: bool isEmpty().
 * @version Copyright © 2017-11-23 All rights reserved. Langara College
 */

#ifndef LinkedStack_h
#define LinkedStack_h
#include <stdexcept>
using namespace std;

template<typename T>
class Node {
    
public:
    
    T element;
    Node<T> next;
    
    // no-arg node constructor to create a node
    Node() {
        next = nullptr;
    }
    
    /**
     argumented generic node constructor to create a node with a specific element
     @param element the actual element we want to pass to the next node
     */
    Node(T element) {
        this->element = element;
        next = nullptr;
    }
};

template<typename T>
class LinkedStack {
    
private:
    
    Node<T>* top;
    int size;
    
public:
    // No-arg constructor to create an empty Stack
    LinkedStack();
    
    // Stack destructor
    ~LinkedStack();
    
    /**
     Inserts a new element in the stack
     @param newElement the actual element we want to push inside the stack
     */
    void push(T newElement);
    
    /**
     Deletes an element from the stack - throws a run time error if the stack is empty
     @return the stack without the element removed
     */
    T pop() throw (runtime_error);
    
    /**
     Gets the element present at top - throws a run time error if the stack is empty
     @return the actual element sit at top of the stack
     */
    const T getTop() throw (runtime_error);
    
    /**
     Checks if the stack is empty
     @return true if the stack is empty
     @return false if at least 1 element is contained
     */
    bool const isEmpty();
};

#endif /* LinkedStack_h */

/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #8 lab08 The Linked Queue ADT
 * Description: A generic linked structured Queue ADT implementation for the LinkedQueue header file withh the following functionalities:
 1. A constructor, LinkedQueue(), to create an empty queue.
 2. A destructor, ~LinkedQueue(), to free the queue memory.
 3. A function to insert a new element at the end of the queue:void insert(T newElement).
 4. A function to delete and return the element at the front of the queue: T remove(); this function throws a runtime-error exception.
 5.A function to check if the queue is empty: bool isEmpty().
 * @version Copyright © 2017-11-23 All rights reserved. Langara College
 */

#include "LinkedQueue.h"
#include <iostream>

// No-arg constructor to create an empty Linked Queue
template<typename T>
LinkedQueue<T>::LinkedQueue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

// Queue destructor
template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
    delete front;
}

/**
 Inserts a new element in the head element of the Linked Queue
 @param newElement the actual element we want to enqueue
 */
template<typename T>
void LinkedQueue<T>::insert(T newElement) {
    if (rear == size - 1)
        cout << "Out of bounds index error" << endl;
    else
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else
            rear = rear + 1;
    T element[rear] = newElement;
}

/**
 Removes the tail element in the queue - throws a run time error if the queue is empty
 @return the queue without the element removed
 */
template<typename T>
T LinkedQueue<T>::remove() throw (runtime_error) {
    if (isEmpty())
        throw runtime_error("No elements in the stack");
    T it = front->next->element;  // Store dequeued value
    Node<T> *tempNode = front->next; // Hold dequeued link
    front->next = tempNode->next;       // Advance front
    if (rear == tempNode) rear = front; // Dequeue last element
        delete tempNode;                    // Delete
    size --;
    return it;                       // Return element value
}

/**
 Checks if the Linked Queue is empty
 @return true if the Linked Queue is empty
 @return false if at least 1 element is contained
 */
template<typename T>
bool const LinkedQueue<T>::isEmpty() {
    return (size != 0);
}

/**
 Clears the Linked Queue and deletes each link node
 */
template<typename T>
void LinkedQueue<T>::clear() {
    while(front->next != NULL) {
        rear = front;
        delete rear;
    }
    rear = front;
    size = 0;
}

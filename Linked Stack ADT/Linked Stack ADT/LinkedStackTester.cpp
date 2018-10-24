/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #8 lab08 The Linked Stack ADT
 * Description: A generic linked structured Stack ADT main testing the following functionalities:
 1. A constructor, LinkedStack(), to create an empty stack.
 2. A destructor, ~LinkedStack(), to free the stack memory.
 3. A function to push a new element into the stack: void push(T newElement).
 4. A function to pop and return the element at the top of the stack: T pop(); this function throws a runtime-error exception, or simply prints an error message in case the stack is empty.
 5. A function to retrieve the element at the top of the stack: T getTop(); this function throws a runtime-error exception (if you know how), or simply prints an error message in case the stack is empty.
 6. A function to check if the stack is empty: bool isEmpty().
 * @version Copyright © 2017-11-23 All rights reserved. Langara College
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedStack.h"
using namespace std;

int main() {
    // Create a linked int stack
    LinkedStack<int> intLinkedStack;
    for (int i = 0; i < 10; i++)
        intLinkedStack.push(i);
    while (!intLinkedStack.isEmpty())
        cout << intLinkedStack.pop() << " ";
    cout << endl;
    
    // Create a linked string stack
    LinkedStack<string> stringLinkedStack;
    stringLinkedStack.push("Naoko");
    stringLinkedStack.push("Karina");
    stringLinkedStack.push("Tarra");
    while (!stringLinkedStack.isEmpty())
        cout << stringLinkedStack.pop() << " ";
    cout << endl;
    return 0;
}

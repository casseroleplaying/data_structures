#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node<T>* next;
};

template <class T>
class Stack {
private:
    node<T>* top;
public:
    Stack();
    Stack(const Stack<T>& source);
    Stack& operator=(const Stack& source);
    ~Stack();

    void push(T item);
    void pop();
    void display();
    void deleteStack();

    T& peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

class fullStack {};                     // Exception class

// Stack() - default constructor
// Postcondition: Initializes stack pointer to NULL
template <class T>
Stack<T>::Stack() { top = NULL; }

// Stack() - copy constructor
// Postcondition: Produce a deep copy instance of source stack on declaration
template <class T>
Stack<T>::Stack(const Stack<T>& source)
{
    Stack<T> tempStack;
    node<T>* sourcePtr = source.top;

    while (sourcePtr != NULL) {         // copy stack in reverse to temp stack
        tempStack.push(sourcePtr->data);
        sourcePtr = sourcePtr->next;
    }

    while (!tempStack.isEmpty()) {      // now copy in original order to this
        push(tempStack.peek());
        tempStack.pop();
    }
}

// = overloads the assignment operator
// returns a reference to a deep copy of source object
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& source)
{
    if (!isEmpty())
        deleteStack();

    Stack<T> tempStack;
    node<T>* sourcePtr = source.top;

    while (sourcePtr != NULL) {         // copy stack in reverse to temp stack
        tempStack.push(sourcePtr->data);
        sourcePtr = sourcePtr->next;
    }

    while (!tempStack.isEmpty()) {      // now copy in original order to this
        push(tempStack.peek());
        tempStack.pop();
    }
    return *this;
}

// ~Stack() - destructor
// Postcondition: destroys stack conetnts and frees all dynamically allocated memory
//      sets stack pointer to NULL
template <class T>
Stack<T>::~Stack() { deleteStack(); }

// push() - pushes an item onto the stack
// Postcondition: item has been placed on top of stack and stack pointer has been 
//      moved up to item
template <class T>
void Stack<T>::push(T item)
{
    try {
        node<T>* temp = new node<T>;        // create a new node
        temp->next = top;                   // point new node to the top
        top = temp;                         // move the top
        top->data = item;                   // get the data
    }
    catch (bad_alloc bad) {
        throw fullStack();
    }
}

// pop() - removes item from top of the stack
// Postcondition: element at top of stack has been removed,
//      dynamically allocated memoryt is freed and the stack pointer
//      has been moved to the next item down
template <class T>
void Stack<T>::pop()
{
    node<T>* temp = top;                // create temporary pointer
    if (top != NULL)
        top = top->next;                // move the top down
    delete temp;                        // free the popped node
    temp = NULL;                        // set the temp pointer to NULL
}

// peek() - returns a copy of the data in the item at the top of the stack
template <class T>
T& Stack<T>::peek() const { return top->data; }

// display() - displays the stack contents from top to bottom
template <class T>
void Stack<T>::display()
{
    node<T>* temp = top;                // traverse the stack using a temp pointer
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// deleteStack() - pops all elements off the stack
template <class T>
void Stack<T>::deleteStack()
{
    while (top != NULL)
        pop();
}

// isEmpty() - returns true if stack is empty, false otherwise
template <class T>
bool Stack<T>::isEmpty() const { return top == NULL; }

// isFull() - returns true if stack is full (cannot dynamically allocate more nodes), false otherwise
template <class T>
bool Stack<T>::isFull() const
{
    try {
        node<T>* temp = new node<T>;
    }
    catch (bad_alloc bad) {
        return 1;
    }
    return 0;
}

#endif
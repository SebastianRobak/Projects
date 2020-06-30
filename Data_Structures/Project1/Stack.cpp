#include "Stack.h"

// Constructor to create stack
template <class X>
myStack<X>::myStack(int size)
{
    table_array = new X[size];
    top = -1;
    max_size = size;
}
template myStack<int>::myStack(int size);
template myStack<double>::myStack(int size);

// Function to add element to the stack
template <class X>
void myStack<X>::push(X x)
{
    if (size() == max_size)
    {
        cout << "FullStackException\n";
    }
    else table_array[++top] = x;
}
template void myStack<int>::push(int x);
template void myStack<double>::push(double x);

// Function to remove element from the stack
template <class X>
void myStack<X>::pop()
{
    if (Empty())
    {
        cout << "Stos jest pusty wiec nie mozna usunac elementu\n";
    }
    else top--;
}
template void myStack<int>::pop();
template void myStack<double>::pop();

// Function to display top element
template <class X>
void myStack<X>::show_top()
{
    if (!Empty())
        cout << "Element na szczycie stosu to: " << table_array[top] << endl;
    else
    {
        cout << "Stos jest pusty\n";
    }
}
template void myStack<int>::show_top();
template void myStack<double>::show_top();

// Function to return current size of the stack
template <class X>
int myStack<X>::size()
{
    return top + 1;
}
template int myStack<int>::size();
template int myStack<double>::size();

// Function returns bool if stack is empty
template <class X>
bool myStack<X>::Empty()
{
    return top == -1;
}
template bool myStack<int>::Empty();
template bool myStack<double>::Empty();
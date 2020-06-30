#pragma once
#include <iostream>
using namespace std;

// Queue's size
#define SIZE 10

template <class X>
class myQueue
{
    X* table_array;
    int max_size;   
    int front;       
    int back;        
    int current_size; 

public:
    myQueue(int size = SIZE);     
    ~myQueue() {
        delete[] table_array;
    };

    void dequeue();
    void enqueue(X);
    void front_elem(); 
    int size();
    bool Empty();
};



// Constructor to create queue
template <class X>
myQueue<X>::myQueue(int size)
{
    table_array = new X[size];
    max_size = size;
    front = 0;
    back = -1;
    current_size = 0;
}

// Function to remove element from queue
template <class X>
void myQueue<X>::dequeue()
{
    if (Empty())
    {
        cout << "Nie mozna usunac bo kolejka jest pusta\n";
    }
    else {
        front = (front + 1) % max_size;
        current_size--;
    }
}

// Function to add element to the queue
template <class X>
void myQueue<X>::enqueue(X item)
{
    if (size() == max_size)
    {
        cout << "FullQueueException\n";
    }
    else {
        back = (back + 1) % max_size;
        table_array[back] = item;
        current_size++;
    }
}

// Function that returns front element from the queue
template <class X>
void myQueue<X>::front_elem()
{
    if (Empty())
    {
        cout << "Kolejka jest pusta\n";
    }
    else cout << "Element na poczatku kolejki to: " << table_array[front] << endl;
}

// Function that returns the size of the queue
template <class X>
int myQueue<X>::size()
{
    return current_size;
}

// Function that checks if queue is empty
template <class X>
bool myQueue<X>::Empty()
{
    return size() == 0;
}

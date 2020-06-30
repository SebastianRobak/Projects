#pragma once
#include <iostream>
using namespace std;

// Stack's size
#define SIZE 2
template <class X>
class myStack
{private:
    X *table_array;
    int top;
    int max_size;

public:
    myStack(int size = SIZE);
    ~myStack() {
        delete[] table_array;
    }

    void push(X);
    void pop();
    void show_top();
    int size();
    bool Empty();
};



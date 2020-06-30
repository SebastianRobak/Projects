#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Heap's size
#define HEAP_SIZE 15
#define HEAP_MAX_NUMB 10
#define HEAP_MIN_NUMB 0

template <class X>
class Heap
{
private:
    X* table_array;
    int max_size;
    int last;

public:
    Heap(int size = HEAP_SIZE);
    ~Heap() {
        delete[] table_array;
    }

    X parent(int n);
    X left(int n);
    X right(int n);
    void build(int n);
    void restore();
    void push(X n);
    void pop();
    int size();
    void display();
    bool Empty();
    bool Full();
};

// Constructor to create  heap
template <class X>
Heap<X>::Heap(int size)
{
    table_array = new X[size + 1];
    max_size = size;
    last = 0;
}

template <class X>
X Heap<X>::parent(int n)
{
    return (n / 2);
}

template <class X>
X Heap<X>::left(int n)
{
    return (2 * n);
}

template <class X>
X Heap<X>::right(int n)
{
    return (2 * n + 1);
}

template <class X>
void Heap<X>::build(int n)
{
    if (last == 0) {
        if (n > max_size)
        {
            cout << "Podano zbyt wiele elementow, przekroczono rozmiar tablicy wiec nie wszystkie elementy zostaly uzyte\n";
            n = max_size;
        }
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 1; i <= n; ++i)
        {
            X x =  HEAP_MIN_NUMB + ((X)rand() / RAND_MAX)*(HEAP_MAX_NUMB-HEAP_MIN_NUMB);
            table_array[i] = x;
            ++last;
        }
        restore();
    }
    else {
        cout << "Kopiec juz istnieje i jest nastepujacy\n";
        display();
    }
}

template <class X>
void Heap<X>::push(X n)
{
    if (!Full()) table_array[++last] = n;
    else cout << "Kopiec pelny nie mozna dodac elementu\n";
    restore();
}

template <class X>
void Heap<X>::pop()
{
    if (last == 1) cout << "Jest tylko jeden element, nie mozna wykonac operacji\n";
    else if (!Empty()) table_array[1] = table_array[last--];
    else  cout << "Kopiec pusty nie mozna usunac\n";
    restore();
}

template <class X>
void Heap<X>::restore()
{

}

template <class X>
int Heap<X>::size()
{
    int a = last;
    int levels = 0;
    while (a > 0)
    {
        a /= 2;
        ++levels;
    }
    //cout << "Wysokosc kopca to: " << levels << endl;
    return levels;
}

template <class X>
void Heap<X>::display()
{
    if (!Empty()) {
        int bin = 1, j = 1;

        for (int it = 1; j <= last; it++)
        {
            cout << table_array[j++] << " ";

            if (it == bin)
            {
                bin = bin * 2;
                it = 0;
                cout << endl;
            }

        }
    }
    else cout << "Kopiec jest pusty nie mozna wyswietlic\n";
}

template <class X>
bool Heap<X>::Empty()
{
    return last == 0;
}

template <class X>
bool Heap<X>::Full()
{
    return last == max_size;
}
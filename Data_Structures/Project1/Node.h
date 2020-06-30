#pragma once
#include <iostream>
using namespace std;

//Class to keep number and pointer to next node
template <class X>
class Node
{
public:
	X data;		// data(number)
	Node* next; 	// pointer to the next node

};


#pragma once
#include <iostream>
using namespace std;

//Class to keep number and pointer to next and previous node
template <class X>
class DoubleNode
{
public:
	X data;		//ata(number)
	DoubleNode* next; 	// pointer to the next node
	DoubleNode* last;		// pointer to the previous node
};


#pragma once
#include <iostream>
#include "DoubleNode.h"
using namespace std;

template <class X>
class DoublyList
{
private:
	DoubleNode<X>* head;
	DoubleNode<X>* tail;
public:
	DoublyList();
	bool Empty();

	void display();
	void display_first();
	void display_last();

	void push_front(X value);
	void push_back(X value);
	void push_after_key(X key, X value);

	void pop_front();
	void pop_back();
	void pop_key(X key);


};

// Constructor to create singlylinkedlist
template <class X>
DoublyList<X>::DoublyList()
{
	head = NULL;
	tail = NULL;
}
// Function to display the whole list
template <class X>
void DoublyList<X>::display()
{
	if (!Empty()) {
		cout << "\nElementy:\n";
		DoubleNode<X>* temp = new DoubleNode<X>;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
// Function to display the first element of the list
template <class X>
void DoublyList<X>::display_first()
{
	if (!Empty()) cout << "Pierwszy element na liscie to: " << head->data << endl;
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
// Function to display the last element of the list
template <class X>
void DoublyList<X>::display_last()
{
	if (!Empty()) cout << "Ostatni element na liscie to: " << tail->data << endl;
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
//Function to add element to the front of the list
template <class X>
void DoublyList<X>::push_front(X value)
{
	DoubleNode<X>* new_node = new DoubleNode<X>;
	DoubleNode<X>* next = new DoubleNode<X>;
	new_node->data = value;
	new_node->next = head;
	new_node->last = NULL;
	if (head != NULL) head->last = new_node;
	else tail = new_node;
	head = new_node;
}
//Function to add element to the back of the list
template <class X>
void DoublyList<X>::push_back(X value)
{
	DoubleNode<X>* new_node = new DoubleNode<X>;
	DoubleNode<X>* prev = new DoubleNode<X>;
	prev = head;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		new_node->last = NULL;
		head = new_node;
		tail = new_node;
		return;
	}
	tail->next = new_node;
	new_node->last = tail;
	tail = new_node;
	return;
}
//Function to add element after the key in the list
template <class X>
void DoublyList<X>::push_after_key(X key, X value)
{
	if (!Empty()) {
		if (tail->data == key) push_back(value);
		else {
			DoubleNode<X>* temp = new DoubleNode<X>;
			DoubleNode<X>* new_node = new DoubleNode<X>;
			temp = head;
			bool found = false;
			new_node->data = value;
			while (temp != NULL)
			{
				if (temp->data == key)
				{
					new_node->next = temp->next;
					temp->next = new_node;
					new_node->last = temp;
					if (new_node->next != NULL) new_node->next->last = new_node;
					found = true;
					break;
				}
				temp = temp->next;

			}
			if (!found) cout << "Nie znaleziono klucza\n";
		}
	}
	else cout << "Nie mozna wstawic po kluczu bo lista jest pusta\n";
}
//Function to remove element from the front of the list
template <class X>
void DoublyList<X>::pop_front()
{
	if (!Empty()) {
		if (head == tail) tail = NULL;
		DoubleNode<X>* temp = new DoubleNode<X>;
		temp = head;
		head = head->next;
		if (head != NULL) head->last = NULL;
		delete temp;
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function to remove element from the back of the list
template <class X>
void DoublyList<X>::pop_back()
{
	if (!Empty()) {
		if (head == tail) head = NULL;
		DoubleNode<X>* temp = new DoubleNode<X>;
		temp = tail;
		tail = tail->last;
		if (tail != NULL) tail->next = NULL;
		delete temp;
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function to remove key from the list
template <class X>
void DoublyList<X>::pop_key(X key)
{
	if (!Empty()) {
		if (head->data == key) pop_front();
		else if (tail->data == key) pop_back();
		else {
			DoubleNode<X>* current = new DoubleNode<X>;
			DoubleNode<X>* previous = new DoubleNode<X>;
			DoubleNode<X>* temp = new DoubleNode<X>;
			bool found = false;
			current = head;
			while (current->next != NULL)
			{
				current = current->next;
				if (current->data == key)
				{
					temp = current;
					current->last->next = current->next;
					current->next->last = current->last;
					delete temp;
					found = true;
					break;
				}
			}
			if (!found) cout << "Nie znaleziono klucza\n";
		}
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function that checks if list is empty
template <class X>
bool DoublyList<X>::Empty()
{
	return head == NULL;
}

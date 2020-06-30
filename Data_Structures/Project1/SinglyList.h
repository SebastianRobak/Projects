#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class X>
class SinglyList
{
private:
	Node<X>* head;
public:
	SinglyList();
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
SinglyList<X>::SinglyList()
{
	head = NULL;
}
// Function to display the whole list
template <class X>
void SinglyList<X>::display()
{
	if (!Empty()) {
		Node<X>* temp = new Node<X>;
		temp = head;
		cout << "\nElementy:\n";
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
// Function to display the first element of the list
template <class X>
void SinglyList<X>::display_first()
{
	if (!Empty()) cout << "Pierwszy element na liscie to: " << head->data << endl;
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
// Function to display the last element of the list
template <class X>
void SinglyList<X>::display_last()
{
	if (!Empty()) {
		Node<X>* temp = new Node<X>;
		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		cout << "Ostatni element na liscie to: " << temp->data << endl;
	}
	else cout << "Nie mozna wyswietlic, bo lista jest pusta\n";
}
//Function to add element to the front of the list
template <class X>
void SinglyList<X>::push_front(X value)
{
	Node<X>* temp = new Node<X>;
	temp->data = value;
	temp->next = head;
	head = temp;
}
//Function to add element to the back of the list
template <class X>
void SinglyList<X>::push_back(X value)
{
	if (!Empty()) {
		Node<X>* temp = new Node<X>;
		Node<X>* new_node = new Node<X>;
		new_node->data = value;
		new_node->next = NULL;
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
	else {
		Node<X>* temp = new Node<X>;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
}
//Function to add element after the key in the list
template <class X>
void SinglyList<X>::push_after_key(X key, X value)
{
	if (!Empty()) {
		Node<X>* temp = new Node<X>;
		Node<X>* new_node = new Node<X>;
		temp = head;
		bool found = false;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				new_node->data = value;
				new_node->next = temp->next;
				temp->next = new_node;
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (!found) cout << "Nie znaleziono klucza\n";
	}
	else cout << "Lista jest pusta nie mozna szukac klucza\n";
}
//Function to remove element from the front of the list
template <class X>
void SinglyList<X>::pop_front()
{
	if (!Empty()) {
		Node<X>* temp = new Node<X>;
		temp = head;
		head = head->next;
		delete temp;
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function to remove element from the back of the list
template <class X>
void SinglyList<X>::pop_back()
{
	if (!Empty()) {
		Node<X>* current = new Node<X>;
		Node<X>* previous = new Node<X>;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		delete current;
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function to remove key from the list
template <class X>
void SinglyList<X>::pop_key(X key)
{
	if (!Empty()) {
		Node<X>* current = new Node<X>;
		Node<X>* previous = new Node<X>;
		Node<X>* temp = new Node<X>;
		bool found = false;
		current = head;
		if (current->data == key) {
			previous = head;
			head = head->next;
			found = true;
			delete previous;
		}
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
			if (current->data == key)
			{
				temp = current;
				previous->next = current->next;
				delete temp;
				found = true;
				break;
			}
		}
		if (!found) cout << "Nie znaleziono klucza\n";
	}
	else cout << "Nie mozna usunac, bo lista jest pusta\n";
}
//Function that checks if list is empty
template <class X>
bool SinglyList<X>::Empty()
{
	return head == NULL;
}


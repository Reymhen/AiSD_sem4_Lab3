#pragma once
#include <iostream>
using namespace std;
class Route
{
private:

	class Node {
	public:
		string from;
		string to;
		int price;
		int indexLine = -1;
		int indexColumn = -1;
		Node* next; // pointer to the next element
	};
	Node* head; // pointer to the begin of List
	Node* tail; // pointer to the end of List
public:
	
	Route(string from, string to, int price, int indexLine, int indexColumn)
	{
		Node* temp = new Node; // Create temporary node
		temp->from = from;
		temp->to = to;
		temp->price = price;
		temp->indexLine = indexLine;
		temp->indexColumn = indexColumn;
		temp->next = tail;
		head = temp;
		tail = temp;
	}

	Route()
	{
		Node* temp = new Node; // Create temporary node
		temp->from = "";
		temp->to = "";
		temp->price = -1;
		temp->indexLine = -1;
		temp->indexColumn = -1;
		head = tail = NULL;
		temp->next = NULL;
	}

	Node* at(size_t index) {
		if (index < get_size()) // If index is in List range
		{
			Node* temp = head; // Create temporary node
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp;
		}
		else {
			throw out_of_range("The position of the element is out of range List index\n"); // Error message
		}
	}

	// getting list of route size
	int get_size() {
		int list_size = 0;
		Node* temp = head;
		while (temp != NULL) {
			list_size++;
			temp = temp->next;
		}
		return list_size;
	}
	Node* get_head() {
		return head;
	}

	// checking if the list of route is empty
	bool isEmpty() {
		return head == NULL;
	}

	// removing all list of route items
	void clearList() {
		Node* temp = head; // Create temporary node
		while (head != NULL) {
			temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;
	}
	// adding to the end of the list
	void push_back(string from, string to, int price) {
		Node* temp = new Node;
		if (isEmpty() == 1) { // If List is empty  
			temp->from = from;
			temp->to = to;
			temp->price = price;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else { // If List isn't empty
			temp->from = from;
			temp->to = to;
			temp->price = price;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}

	}

	// deleting the first element deleting an element
	void pop_front() {

		if (isEmpty() == 0) // If List isn't empty
		{
			Node* temp = head; // Create temporary node
			head = head->next;
			delete temp;
			if (head == NULL) tail = head;
		}
		else {
			throw invalid_argument("List is empty. First element cannot be deleted"); // Error message 
		}
	}
	// removing the last item
	void pop_back() {
		if (isEmpty() == 0) // If List isn't empty
		{
			Node* temp = head; // Create temporary node
			if (head->next == NULL) {
				pop_front();
			}
			else {
				while (temp->next != NULL) {
					tail = temp;
					temp = temp->next;
				}
				tail->next = NULL;
				delete temp;
			}
		}
		else {
			throw invalid_argument("List is empty. Last element cannot be deleted"); // Error message 
		}
	}

	// deleting an element 
	void remove(Node* delet) {

		bool flag = false;
		size_t cout = 0;
		if (delet == head)
		{
			return pop_front();
		}
		else if (delet == tail)
		{
			return pop_back();
		}
		else {
			Node* temp = head; // Create temporary node
			for (Node* i = head; i != delet; i = i->next) {
				temp = temp->next;
				cout++;
			}
			Node* remove = temp;
			temp = head;
			for (int i = 0; i < cout - 1; i++) {
				temp = temp->next;
			}
			temp->next = remove->next;
			delete remove;


		}
		if (flag = false) {
			throw out_of_range("The position of the element is out of range List index\n"); // Error message
		}
	}

	Node* findIndex(int indexLine, int indexColumn) {
		if (isEmpty()) {
			throw invalid_argument("Listroute  is empty.\n"); // Error message 
		}
		else {
			Node* temp = head;
			bool flag = false;
			while (temp != NULL) {
				if (temp->indexLine == indexLine && temp->indexColumn == indexColumn) {
					return temp;
					flag = true;
				}
				temp = temp->next;
			}
			if (flag == false) return NULL; // Error message
		}
	}

	void printRoute() {
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->from << " " << temp->to << " " << temp->price << " " << temp->indexLine << " " << temp->indexColumn << " " << endl;
			temp = temp->next;
		}
	}

};
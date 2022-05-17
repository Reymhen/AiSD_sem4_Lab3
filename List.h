#pragma once
#include <iostream>
#include <stdexcept> 
using namespace std;

template <typename is_typename>

class List {

private:

	class Node {
	public:
		is_typename date; // date of element
		Node* next; // pointer to the next element
	};
	Node* head; // pointer to the begin of List
	Node* tail; // pointer to the end of List

public:
	// Constructor with date
	List(is_typename date) {

		Node* temp = new Node; // Create temporary node
		temp->date = date;
		temp->next = tail;
		head = temp;
		tail = temp;
	}

	// Constructor without date
	List() {
		head = tail = NULL;
		Node* temp = new Node; // Create temporary node
		temp->next = NULL;
		/*temp->date = NULL;*/
	}

	//// Destructor
	//~List() {
	//	clearList();
	//}
	 // getting an element by index
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

	// getting list size
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
	// checking if the list is empty
	bool isEmpty() {
		return head == NULL;
	}

	// removing all list items
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
	void push_back(is_typename date) {
		Node* temp = new Node;
		if (isEmpty() == 1) { // If List is empty  
			temp->date = date;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else { // If List isn't empty
			temp->date = date;
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
		if(flag = false) {
			throw out_of_range("The position of the element is out of range List index"); // Error message
		}
	}

	void printList() {
		Node* temp = head;
		while (/*head */temp!= NULL)
		{
			cout << temp->date << " ";
			temp = temp->next;
			/*pop_front();*/
		}
	}
	
	void calculateSizeMatrix() {
			Node* temp = head;
			Node* temp2;
			Node* buff;
			for (int i = 0; i < get_size(); i++) {
				temp2 = temp->next;
				 for (int j = i + 1; j < get_size(); j++) {
					if (temp->date == temp2->date) {
						buff = temp2->next;
						remove(temp2);
						temp2 = buff;
						j--;
					}
					else
						temp2 = temp2->next;
				 }
				temp = temp->next;
			}		    
	}
};

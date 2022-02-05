/*
	Print a Reversed Linked List
	
	Given a linked list, we do not have to change the content of the list, 
	but we have to access each node in such a way that the linked list 
	is printed in a reversed manner.

	input linklist : 1->2->3->4->5
	output : 5, 4, 3, 2, 1

	So first thing is to build the linklist
	and than after this , define one method
	who can print the linkedlist in reverse order
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct Node {
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
};

struct SingleLinkList {
	Node* head;
	Node* tail;

	SingleLinkList() : head(nullptr), tail(nullptr) {}
	Node* Create(int data) {
		Node* p = new Node();
		p->data = data;
		p->next = nullptr;
		return p;
	}
	void addNode(int data) {
		if (head == nullptr) {
			// your linklist is empty right now
			head = tail = Create(data);
		}
		else {
			Node* newNode = Create(data);
			tail->next = newNode;
			tail = newNode;
		}
	}
	void Build(int array[], int size) {
		for (int i = 0; i < size; ++i) {
			addNode(array[i]);
		}
	}
	void Print() {
		Node* start = head;
		cout << "Link List chain --> ";
		while (start) {
			cout << start->data << " ";
			start = start->next;
		}
		cout << endl;
	}

	// For iterative mehtod
	void reverse_iter()
	{
		// What I want to achieve here, to reverse the linked list
		// [1]->[2]->[3]->[4]->[5]
		Node* start = head;
		Node* prev = nullptr; // to hold the previous node pointer

		// let's iterate the chain below
		while (start) {
				Node* temp = start;
				start = start->next;
				temp->next = prev;
				prev = temp;
		}

		head = prev;
	}

	void reverse() {
		Node* prev = nullptr;
		reverse(head, prev);
		head = prev;
	}

private:
	// For recursive method
	void reverse(Node* start, Node* &prev)
	{
		if (start)
		{
			Node* temp = start;
			start = start->next;
			temp->next = prev;
			prev = temp;
			reverse(start, prev);
		}
	}

};

//Driver Function
int main()
{
	SingleLinkList sl;
	int arr[] = { 1,2,3,4,5 };
	sl.Build(arr, 5);
	sl.Print();
	cout << "After Reversing ..." << endl;
	sl.reverse();
	sl.Print();

	return 0;
}

#endif // FORREF

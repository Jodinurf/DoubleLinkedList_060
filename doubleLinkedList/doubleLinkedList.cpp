#include <iostream>
#include <string>
using namespace std;

class Node {
public :
	int noMhs;
	string name;
	Node* next;
	Node* previous;
};

class DoubleLinkedList {
private :
	Node* START = NULL;
public:

	void addNode();
	bool search(int rollNo, Node** previous, Node* current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();

};

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim;		//step 2
	newNode->name = nm;			//step 2
}
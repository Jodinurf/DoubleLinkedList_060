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
	bool search(int rollNo, Node** previous, Node**current);
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

	/*insert a node in the beginning of a doubly - Linked lists*/
	if (START == NULL || nim <= START->noMhs) {		//check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number no allowed" << endl;
			return;
		}
		newNode->next = START;		//Step 3
		if (START != NULL)
			START->previous = newNode;	//step 4
		newNode->previous = NULL;		//step 5
		START = newNode;				//step 6
		return;
	}

	/*inserting aNode between two nodes in the List*/
	Node* current = START;		//1.a
	Node* previous = NULL;		//1.b
	while (current->next != NULL && current->next->noMhs < nim)	//step 1.c
	{
		previous = current;			//1.d
		current = current->next;	//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs)
	{
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = current->next;		//step.4
	newNode->previous = current;		//step.5
	if (current->next != NULL)
		current->next->previous = newNode;	//step.6
	current->next = newNode;
}


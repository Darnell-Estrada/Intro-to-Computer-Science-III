// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Simple List
// This program implements a simple linked list.

#include <iostream>
#include <string>
using namespace std;

class List {
	private:
		struct Node {
			char val;
			Node *next;
		};
		Node *head;

	public:
		List();
		~List();
		void clear();
		void add(char);
		void print() const;
};

List::List() {
	head = NULL;
}

List::~List() {
	clear();
}

void List::add(char v) {
	Node *newNode = new Node,
		*currNode = NULL;
	newNode->val = v;
	newNode->next = NULL;
	if (!head) {
		head = newNode;
	}
	else {
		currNode = head;
		while (currNode->next) {
			currNode = currNode->next;
		}
		currNode->next = newNode;
	}
}

void List::clear() {
	Node *currNode = head;
	if (!head) {
		return;
	}
	else {
		while (head) {
			currNode = head;
			head = head->next;
			delete currNode;
		}
		head = NULL;
	}
}

void List::print() const {
	Node *currNode = head;
	cout << "HEAD -> ";
	while (currNode) {
		cout << currNode->val << " -> ";
		currNode = currNode->next;
	}
	cout << "NULL\n";
}

void menu();

int main() {
	string ch,
		val;
	List obj;
	do {
		cout << "[ACMP]: ";
		getline(cin, ch);
		switch (ch[0]) {
			case 'A': case 'a': {
				cout << "Enter a value to add: ";
				getline(cin, val);
				obj.add(val[0]);
				break;
			}
			case 'C': case 'c': {
				obj.clear();
				cout << "The list is cleared.\n";
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				obj.print();
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			default: {
				cout << "You entered an invalid character.\n";
				break;
			}
		}
	} while (true);
	cin.ignore();
	cin.get();
	return 0;
};

void menu() {
	cout << "A: Add\n"
		<< "C: Clear\n"
		<< "M: Menu\n"
		<< "P: Print\n"
		<< "Q: Quit\n";
}
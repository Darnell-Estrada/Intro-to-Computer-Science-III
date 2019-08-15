// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC17
// This program implements a linked list.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void menu();

class CharList {
	private:
		struct Node {
			char value;
			Node *next;
		};
		Node *head;
	public:
		CharList();
		~CharList();
		bool write();
		bool read();
		void insert(char);
		void remove(char);
		void destroy();
		bool search(char) const;
		int size() const;
		void print() const;
		void reverse() const;
		void reverse(Node*) const;
};

CharList::CharList() {
	head = NULL;
}

CharList::~CharList() {
	destroy();
}

bool CharList::write() {
	ofstream file;
	Node *currPtr = head;
	file.open("list.dat", ios::out);
	while (currPtr) {
		file << currPtr->value;
		currPtr = currPtr->next;
	}
	if (file) {
		file.close();
		return true;
	}
	else {
		return false;
	}
}

bool CharList::read() {
	destroy();
	char c = ' ';
	ifstream file;
	file.open("list.dat", ios::in);
	if (file) {
		while (file >> c) {
			insert(c);
		}
		file.close();
		return true;
	}
	else {
		return false;
	}
}

void CharList::insert(char v) {
	Node *newPtr = new Node,
		*currPtr = NULL,
		*prevPtr = NULL;
	newPtr->value = v;
	if (!head) {
		head = newPtr;
		newPtr->next = NULL;
	}
	else {
		currPtr = head;
		while (currPtr && currPtr->value < v) {
			prevPtr = currPtr;
			currPtr = currPtr->next;
		}
		if (!prevPtr) {
			head = newPtr;
			newPtr->next = currPtr;
		}
		else {
			prevPtr->next = newPtr;
			newPtr->next = currPtr;
		}
	}
}

void CharList::remove(char v) {
	Node *currPtr = NULL,
		*prevPtr = NULL;
	if (!head) {
		return;
	}
	else if (head->value == v) {
		currPtr = head->next;
		delete head;
		head = currPtr;
	}
	else {
		currPtr = head;
		while (currPtr && currPtr->value != v) {
			prevPtr = currPtr;
			currPtr = currPtr->next;
		}
		if (currPtr) {
			prevPtr->next = currPtr->next;
			delete currPtr;
		}
	}
}

void CharList::destroy() {
	Node *currPtr = head;
	if (!head) {
		return;
	}
	else {
		while (head) {
			currPtr = head;
			head = head->next;
			delete currPtr;
		}
		head = NULL;
	}
}

bool CharList::search(char v) const {
	Node *currPtr = head;
	while (currPtr) {
		if (currPtr->value == v) {
			return true;
		}
		currPtr = currPtr->next;
	}
	return false;
}

int CharList::size() const {
	int numNodes = 0;
	Node *currPtr = head;
	while (currPtr) {
		numNodes++;
		currPtr = currPtr->next;
	}
	return numNodes;
}

void CharList::print() const {
	Node *currPtr = head;
	cout << "HEAD -> ";
	while (currPtr) {
		cout << currPtr->value << " -> ";
		currPtr = currPtr->next;
	}
	cout << "NULL\n";
}

void CharList::reverse() const {
	cout << "HEAD -> ";
	reverse(head);
	cout << "NULL\n";
}

void CharList::reverse(Node* n) const {
	if (n) {
		reverse(n->next);
		cout << n->value << " -> ";
	}
}

int main() {
	string letter,
		value;
	CharList list;
	do {
		cout << "[CDGILMPQRSW]: ";
		getline(cin, letter);
		switch (letter[0]) {
			case 'C': case 'c': {
				list.destroy();
				cout << "The list is cleared.\n";
				break;
			}
			case 'D': case 'd': {
				cout << "Enter a character to remove: ";
				getline(cin, value);
				list.remove(value[0]);
				break;
			}
			case 'G': case 'g': {
				if (list.read()) {
					cout << "The list was successfully constructed.\n";
				}
				else if (!list.read()) {
					cout << "The list failed to be constructed.\n";
				}
				break;
			}
			case 'I': case 'i': {
				cout << "Enter a character to insert: ";
				getline(cin, value);
				list.insert(value[0]);
				break;
			}
			case 'L': case 'l': {
				cout << "Length: " << list.size() << endl;
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				list.print();
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			case 'R': case 'r': {
				list.reverse();
				break;
			}
			case 'S': case 's': {
				cout << "Enter a character to search for: ";
				getline(cin, value);
				if (list.search(value[0])) {
					cout << value[0] << " is found in the linked list.\n";
				}
				else if (!list.search(value[0])) {
					cout << value[0] << " is not found in the linked list.\n";
				}
				break;
			}
			case 'W': case 'w': {
				if (list.write()) {
					cout << "The file was successfully written.\n";
				}
				else if (!list.write()) {
					cout << "The file was failed to be written.\n";
				}
				break;
			}
			default: {
				cout << "You entered an invalid character. Please refer to the menu.\n";
				break;
			}
		}
	} while (true);
	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "C: Clear\n"
		<< "D: Delete\n"
		<< "G: Get\n"
		<< "I: Insert\n"
		<< "L: Length\n"
		<< "M: Menu\n"
		<< "P: Print\n"
		<< "Q: Quit\n"
		<< "R: Reverse\n"
		<< "S: Search\n"
		<< "W: Write\n";
}
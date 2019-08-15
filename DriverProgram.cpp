// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// DriverProgram.cpp
// This program implements a binary tree.

#include "BTree.h"

void menu();

int main() {
	string pick = " ",
		arg = " ";
	BTree<char> tree;
	do {
		cout << "[CIMPQRS]: ";
		getline(cin, pick);
		switch (pick[0]) {
			case 'C': case 'c': {
				cout << "Number of nodes in the binary tree: "
					<< tree.count() << endl;
				break;
			}
			case 'I': case 'i': {
				cout << "Enter a value to insert to the binary tree: ";
				getline(cin, arg);
				tree.insert(arg[0]);
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				if (!tree.count())
					cout << "The binary tree is empty.";
				else {
					tree.preprint();
					cout << endl;
				}
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			case 'R': case 'r': {
				cout << "Enter a value to remove from the binary tree: ";
				getline(cin, arg);
				tree.remove(arg[0]);
				break;
			}
			case 'S': case 's': {
				cout << "Enter a value to search from the binary tree: ";
				getline(cin, arg);
				if (tree.search(arg[0])) {
					cout << arg[0] << " was found in the binary tree.\n";
				}
				else {
					cout << arg[0] << " was NOT found in the binary tree.\n";
				}
				break;
			}
			default: {
				cout << "You entered an invalid menu choice.\n";
				break;
			}
		}
	} while (true);
	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "C: Count\n"
		<< "I: Insert\n"
		<< "M: Menu\n"
		<< "P: Preprint\n"
		<< "Q: Quit\n"
		<< "R: Remove\n"
		<< "S: Search\n";
}
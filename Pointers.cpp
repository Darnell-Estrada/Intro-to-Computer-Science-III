// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Pointers
// This program implements pointers.

#include <iostream>
using namespace std;

int main() {
	int value = 24,
		*pointer = NULL;
	pointer = &value;
	cout << "The variable's value is " << value << "."
		<< "\nThe variable's address is " << pointer << "."
		<< "\n\nAgain, the variable's value is " << *pointer
		<< " and the variable's address is " << &value << ".\n";
	cin.ignore();
	cin.get();
	return 0;
}
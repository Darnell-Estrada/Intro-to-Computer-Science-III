// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC19
// This program implements recursion.

#include <iostream>
#include <string>
using namespace std;

int sigma(int);
void reverse(string);

int main() {
	string userString = " ";
	cout << "Function 1: I will enter a positive integer into"
		<< " my function and it\nwill return its sum from"
		<< " the integer 1 to the integer I had entered."
		<< "\n\nI entered 5.\nSum of numbers for 5: "
		<< sigma(5)
		<< "\n\nFunction 2: Enter a string and I will display it backwards."
		<< "\nEnter string: ";
	getline(cin, userString);
	cout << "\nForward: " << userString << "\nReverse:";
	reverse(userString);
	cin.ignore();
	cin.get();
	return 0;
}

int sigma(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + sigma(n - 1);
	}
}

void reverse(string s) {
	static int num;
	int length = s.length();
	if (num < length) {
		num++;
		reverse(s);
	}
	cout << s[num--];
}
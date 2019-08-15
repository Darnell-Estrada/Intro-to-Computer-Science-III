// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC18
// This program implements a dynamic stack.

#include <iostream>
#include <string>
using namespace std;

template <class T>
class DynStack {
	private:
		struct Node {
			Node *next;
			T value;
		};
		Node *top;
	public:
		DynStack();
		DynStack(const DynStack&);
		~DynStack();
		bool isEmpty();
		void push(T);
		DynStack& operator=(const DynStack&);
		T pop(T&);
};

template <class T>
DynStack<T>::DynStack() {
	top = NULL;
}

template <class T>
DynStack<T>::DynStack(const DynStack& obj) {
	*this = obj;
}

template <class T>
DynStack<T>::~DynStack() {
	Node *currNode = NULL,
		*nextNode = NULL;
	currNode = top;
	while (currNode) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

template <class T>
bool DynStack<T>::isEmpty() {
	if (!top) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void DynStack<T>::push(T v) {
	Node *newNode = new Node;
	newNode->value = v;
	if (isEmpty()) {
		top = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

template <class T>
DynStack<T>& DynStack<T>::operator=(const DynStack& right) {
	Node *newNode = NULL,
		*currNode = NULL,
		*nextNode = NULL,
		*origNode = NULL,
		*travNode = NULL;
	currNode = top;
	while (currNode) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	origNode = right.top;
	while (origNode) {
		newNode = new Node;
		newNode->value = origNode->value;
		newNode->next = NULL;
		if (!top) {
			top = newNode;
		}
		else {
			travNode = top;
			while (travNode->next) {
				travNode = travNode->next;
			}
			travNode->next = newNode;
		}
		origNode = origNode->next;
	}
	return *this;
}

template <class T>
T DynStack<T>::pop(T& v) {
	Node *tempNode = NULL;
	if (isEmpty()) {
		throw "The stack is empty!\n";
	}
	else {
		v = top->value;
		tempNode = top->next;
		delete top;
		top = tempNode;
	}
	return v;
}

int main() {
	char catchPop = ' ';
	int stringSize = 0,
		index = 0;
	string userString;
	DynStack<char> stack1;
	cout << "Enter string: ";
	getline(cin, userString);
	while (userString[index]) {
		stack1.push(userString[index]);
		index++;
		stringSize++;
	}
	DynStack<char> stack2(stack1);
	DynStack<char> stack3;
	stack3 = stack2;
	try {
		cout << "The first object reversing the string: ";
		for (index = 0; index < stringSize; index++) {
			cout << stack1.pop(catchPop);
		}
		cout << "\nThe second object reversing the string: ";
		for (index = 0; index < stringSize; index++) {
			cout << stack2.pop(catchPop);
		}
		cout << "\nThe third object reversing the string: ";
		for (index = 0; index < stringSize; index++) {
			cout << stack3.pop(catchPop);
		}
		cout << "\nAttempting to pop a node from its empty stack: ";
		stack3.pop(catchPop);
	}
	catch (char *error) {
		cout << error;
	}
	cin.ignore();
	cin.get();
	return 0;
}
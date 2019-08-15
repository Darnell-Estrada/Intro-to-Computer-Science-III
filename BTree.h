// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// BTree.h
// This program implements a binary tree.

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class BTree {
	private:
		struct Node {
			Node *left;
			Node *right;
			T value;
		};
		Node *root;
		void destroyTree(Node*);
		void destroy(Node*&);
		void insert(Node*&, T);
		void find(Node*&, T);
		bool search(Node*, T) const;
		int count(Node*) const;
		void preprint(Node*) const;
	public:
		BTree();
		~BTree();
		void insert(T val);
		void remove(T val);
		bool search(T val) const;
		int count() const;
		void preprint() const;
};

template <class T>
void BTree<T>::destroyTree(Node* nodePtr) {
	if (!nodePtr) {
		return;
	}
	destroyTree(nodePtr->left);
	destroyTree(nodePtr->right);
	delete nodePtr;
}

template <class T>
void BTree<T>::destroy(Node*& nodePtr) {
	Node *tempPtr = NULL;
	if (!nodePtr->left && !nodePtr->right) {
		delete nodePtr;
		nodePtr = NULL;
	}
	else if (!nodePtr->left) {
		tempPtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempPtr;
	}
	else if (!nodePtr->right) {
		tempPtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempPtr;
	}
	else {
		tempPtr = nodePtr->right;
		while (tempPtr->left) {
			tempPtr = tempPtr->left;
		}
		tempPtr->left = nodePtr->left;
		tempPtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempPtr;
	}
}

template <class T>
void BTree<T>::insert(Node*& nodePtr, T val) {
	Node *newPtr = NULL;
	if (!nodePtr) {
		newPtr = new Node;
		nodePtr = newPtr;
		newPtr->left = newPtr->right = NULL;
		newPtr->value = val;
	}
	else if (val < nodePtr->value) {
		insert(nodePtr->left, val);
	}
	else {
		insert(nodePtr->right, val);
	}
}

template <class T>
void BTree<T>::find(Node*& nodePtr, T val) {
	if (!nodePtr) {
		return;
	}
	else if (nodePtr->value == val) {
		destroy(nodePtr);
	}
	else if (val < nodePtr->value) {
		find(nodePtr->left, val);
	}
	else {
		find(nodePtr->right, val);
	}
}

template <class T>
bool BTree<T>::search(Node* nodePtr, T val) const {
	if (!nodePtr) {
		return false;
	}
	else if (nodePtr->value == val) {
		return true;
	}
	else if (val < nodePtr->value) {
		return search(nodePtr->left, val);
	}
	else {
		return search(nodePtr->right, val);
	}
}

template <class T>
int BTree<T>::count(Node* nodePtr) const {
	static int num;
	if (!nodePtr) {
		return 0;
	}
	else {
		return (count(nodePtr->left) + count(nodePtr->right) + 1);
	}
}

template <class T>
void BTree<T>::preprint(Node* nodePtr) const {
	if (!nodePtr) {
		return;
	}
	else {
		cout << nodePtr->value << " ";
		preprint(nodePtr->left);
		preprint(nodePtr->right);
	}
}

template <class T>
BTree<T>::BTree() {
	root = NULL;
}

template <class T>
BTree<T>::~BTree() {
	destroyTree(root);
}

template <class T>
void BTree<T>::insert(T val) {
	insert(root, val);
}

template <class T>
void BTree<T>::remove(T val) {
	find(root, val);
}

template <class T>
bool BTree<T>::search(T val) const {
	return search(root, val);
}

template <class T>
int BTree<T>::count() const {
	return count(root);
}

template <class T>
void BTree<T>::preprint() const {
	preprint(root);
}

#endif BTREE_H
// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Rectangle.cpp

#include "Rectangle.h"

Rectangle::Rectangle() {
	width = 0;
	length = 0;
}

Rectangle::~Rectangle() {
}

void Rectangle::setWidth(double wid) {
	if (wid >= 0) {
		width = wid;
	}
	else {
		cout << "\nYou entered an invalid character!\n";
	}
}

void Rectangle::setLength(double leng) {
	if (leng >= 0) {
		length = leng;
	}
	else {
		cout << "\nYou entered an invalid character!";
	}
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getLength() const {
	return length;
}

double Rectangle::getArea() const {
	return length * width;
}
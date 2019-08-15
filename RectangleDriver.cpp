// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// RectangleDriver.cpp
// This program combines smart pointers with classes.

#include "Rectangle.h"

int main() {
	double num = 0.0,
		totalArea = 0.0;
	Rectangle *bedroom = NULL,
		*bathroom = NULL,
		*kitchen = NULL;
	bedroom = new Rectangle;
	bathroom = new Rectangle;
	kitchen = new Rectangle;
	cout << "This program calculates the area of three rooms."
		"\nEnter bedroom width: ";
	cin >> num;
	bedroom->setWidth(num);
	cout << "Enter bedroom length: ";
	cin >> num;
	bedroom->setLength(num);
	cout << "Enter bathroom width: ";
	cin >> num;
	bathroom->setWidth(num);
	cout << "Enter bathroom length: ";
	cin >> num;
	bathroom->setLength(num);
	cout << "Enter kitchen width: ";
	cin >> num;
	kitchen->setWidth(num);
	cout << "Enter kitchen length: ";
	cin >> num;
	kitchen->setLength(num);
	cout << "\nData for three rooms"
		<< "\nBedroom width: " << bedroom->getWidth()
		<< "\nBedroom length: " << bedroom->getLength()
		<< "\nBathroom width: " << bathroom->getWidth()
		<< "\nBathroom length: " << bathroom->getLength()
		<< "\nKitchen width: " << kitchen->getWidth()
		<< "\nKitchen length: " << kitchen->getLength();
	totalArea = bedroom->getArea() + bathroom->getArea() + kitchen->getArea();
	cout << "\nArea for all three rooms: " << totalArea << endl;
	delete bedroom;
	delete bathroom;
	delete kitchen;
	bedroom = NULL;
	bathroom = NULL;
	kitchen = NULL;
	cin.ignore();
	cin.get();
	return 0;
}
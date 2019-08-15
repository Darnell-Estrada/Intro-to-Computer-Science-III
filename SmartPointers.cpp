// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Smart Pointers
// This program uses smart pointers.

#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
	private:
		double width,
			length;
	public:
		void setWidth(double);
		void setLength(double);
		double getWidth() const;
		double getLength() const;
		double getArea() const;
};

void Rectangle::setWidth(double wid) {
	width = wid;
}

void Rectangle::setLength(double leng) {
	length = leng;
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getLength() const {
	return length;
}

double Rectangle::getArea() const {
	return width * length;
}

int main() {
	double userWidth = 0.0,
		userLength = 0.0,
		totalArea = 0.0;
	unique_ptr<Rectangle> bedroom(new Rectangle);
	unique_ptr<Rectangle> bathroom(new Rectangle);
	unique_ptr<Rectangle> kitchen(new Rectangle);
	cout << "This program calculates the area of three rooms."
		"\nEnter bedroom width: ";
	cin >> userWidth;
	cout << "Enter bedroom length: ";
	cin >> userLength;
	bedroom->setWidth(userWidth);
	bedroom->setLength(userLength);
	cout << "Enter bathroom width: ";
	cin >> userWidth;
	cout << "Enter bathroom length: ";
	cin >> userLength;
	bathroom->setWidth(userWidth);
	bathroom->setLength(userLength);
	cout << "Enter kitchen width: ";
	cin >> userWidth;
	cout << "Enter kitchen length: ";
	cin >> userLength;
	kitchen->setLength(userLength);
	kitchen->setWidth(userWidth);
	cout << "\nData for three rooms"
		<< "\nBedroom width: " << bedroom->getWidth()
		<< "\nBedroom length: " << bedroom->getLength()
		<< "\nBathroom width: " << bathroom->getWidth()
		<< "\nBathroom length: " << bathroom->getLength()
		<< "\nKitchen width: " << kitchen->getWidth()
		<< "\nKitchen length: " << kitchen->getLength();
	totalArea = bedroom->getArea() + bathroom->getArea() + kitchen->getArea();
	cout << "\nArea for all three rooms: " << totalArea << endl;
	cin.ignore();
	cin.get();
	return 0;
}
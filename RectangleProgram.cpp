// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Rectangle Program
// This is rectangle program.

#include <iostream>
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
	return length * width;
}

int main() {
	double userLength = 0.0,
		userWidth = 0.0;
	Rectangle box;
	cout << "This program calculates the area of a rectangle.\n"
		<< "Enter length: ";
	cin >> userLength;
	cout << "Enter width: ";
	cin >> userWidth;
	box.setLength(userLength);
	box.setWidth(userWidth);
	cout << "\nResults\nLength: " << box.getLength()
		<< "\nWidth: " << box.getWidth()
		<< "\nArea: " << box.getArea() << endl;
	cin.ignore();
	cin.get();
	return 0;
}
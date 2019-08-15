// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
	private:
		double width,
			length;
	public:
		Rectangle();
		~Rectangle();
		void setWidth(double);
		void setLength(double);
		double getWidth() const;
		double getLength() const;
		double Rectangle::getArea() const;
};

#endif RECTANGLE_H
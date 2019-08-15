// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC14
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iomanip>
#include <iostream>
using namespace std;

class Circle {
	private:
		const double PI = 3.14159265358979323846;
		double radius;
	public:
		Circle();
		Circle(double);
		Circle(const Circle&);
		void setRadius(double);
		double getRadius() const;
		double getArea() const;
		double getDiameter() const;
		double getCircumference() const;
		Circle& operator=(const Circle&);
		Circle operator+(const Circle&);
		Circle operator++();
		Circle operator++(int);
		bool operator<(const Circle&);
		bool operator==(const Circle&);
		friend ostream& operator<<(ostream& o, const Circle& c) {
			o << c.radius;
			return o;
		}
		friend istream& operator>>(istream& i, Circle& c) {
			i >> c.radius;
			return i;
		}
};

Circle::Circle() {
	radius = 0.0;
}

Circle::Circle(double r) {
	radius = r;
}

Circle::Circle(const Circle& c) {
	radius = c.radius;
}

void Circle::setRadius(double r) {
	radius = r;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getArea() const {
	return PI * pow(radius, 2);
}

double Circle::getDiameter() const {
	return radius * 2;
}

double Circle::getCircumference() const {
	return 2 * PI * radius;
}

Circle& Circle::operator=(const Circle& rhs) {
	radius = rhs.radius;
	return *this;
}

Circle Circle::operator+(const Circle& rhs) {
	return radius + rhs.radius;
}

Circle Circle::operator++() {
	radius = 0.1 + radius;
	return *this;
}

Circle Circle::operator++(int) {
	Circle temp(radius);
	radius = radius + 0.1;
	return temp;
}

bool Circle::operator<(const Circle& rhs) {
	bool accordance;
	if (radius < rhs.radius) {
		accordance = true;
	}
	else {
		accordance = false;
	}
	return accordance;
}

bool Circle::operator==(const Circle& rhs) {
	bool accordance;
	if (radius == rhs.radius) {
		accordance = true;
	}
	else {
		accordance = false;
	}
	return accordance;
}

#endif CIRCLE_H
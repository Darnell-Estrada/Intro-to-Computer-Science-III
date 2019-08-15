// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC14
// Circle.cpp
// This program uses a class to
// store a circle's attributes.

#include "Circle.h"

int main() {
	Circle c;
	cout << "Default Constructor's Radius: " << c.getRadius();
	Circle d(5.0);
	cout << "\nOverloaded Contructor's Radius: " << d.getRadius();
	Circle e(d);
	cout << "\nCopy Constructor's Radius: " << e.getRadius();
	c.setRadius(6.0);
	cout << "\nMutator Function's Radius: " << c.getRadius()
		<< "\nAccessor Function's Radius: " << c.getRadius()
		<< "\nAccessor Function's Area: " << c.getArea()
		<< "\nAccessor Function's Diameter: " << c.getDiameter()
		<< "\nAccessor Function's Circumference: " << c.getCircumference();
	c = e;
	cout << "\n\n(LHS = RHS): " << c.getRadius();
	Circle f(9.0),
		g(12.0);
	cout << "\n(LHS < RHS)?: "
		<< (f < g);
	Circle h(15.0),
		j(15.0);
	cout << "\n(LHS == RHS)?: "
		<< (h == j);
	Circle m(18.0),
		n(19.0),
		k;
	k = m + n;
	cout << "\n(LHS + RHS): "
		<< k.getRadius();
	Circle p(21.0);
	cout << "\n\nThe ++ operator (prefix) increments the radius' value by 0.1."
		<< "\nRadius (Before): " << fixed << showpoint << setprecision(1)
		<< p.getRadius();
	++p;
	cout << "\nRadius (After): " << fixed << showpoint << setprecision(1)
		<< p.getRadius();
	Circle q(23.9);
	cout << "\n\nThe ++ operator (postfix) increments the radius' value by 0.1."
		<< "\nRadius (Before): " << fixed << showpoint << setprecision(1)
		<< q.getRadius();
	q++;
	cout << "\nRadius (After): " << fixed << showpoint << setprecision(1)
		<< q.getRadius() << "\n\nOverloaded String Operators"
		<< " Demonstration";
	Circle r;
	cout << "\nEnter a radius: ";
	cin >> r;
	cin.get();
	cout << "The radius entered was "
		<< r << ".\n";
	cin.ignore();
	cin.get();
	return 0;
}
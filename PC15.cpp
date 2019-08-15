// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC15
// This program uses derived Monster classes.

#include <iostream>
#include <string>
using namespace std;

class Monster {
	private:
		int hitPoints;
		string name;
	public:
		Monster();
		Monster(int, string);
		void setName(string);
		void setHitPoints(int);
		int getHitPoints() const;
		string getName() const;
		virtual void Monster::printData() const {
			cout << "Name: " << name
				<< "\nHit Points: " << hitPoints;
		}
};

class Orc:public Monster {
	private:
		double dps;
	public:
		Orc();
		Orc(double);
		Orc(double, string);
		void setDPS(double);
		double getDPS() const;
		virtual void printData() const {
			cout << "Name: " << getName()
				<< "\nDPS: " << dps;
		}
};

class Eagle:public Monster {
	private:
		int flightSpeed;
	public:
		Eagle();
		Eagle(int);
		Eagle(int, string);
		void setFlightSpeed(int);
		int getFlightSpeed() const;
		virtual void printData() const {
			cout << "Name: " << getName()
				<< "\nFlight Speed: " << flightSpeed;
		}
};

Monster::Monster() {
	hitPoints = 0;
	name = " ";
}

Monster::Monster(int h, string n) {
	hitPoints = h;
	name = n;
}

void Monster::setName(string n) {
	name = n;
}

void Monster::setHitPoints(int h) {
	hitPoints = h;
}

int Monster::getHitPoints() const {
	return hitPoints;
}

string Monster::getName() const {
	return name;
}

Orc::Orc() {
	dps = 0.0;
}

Orc::Orc(double d) {
	dps = d;
}

Orc::Orc(double d, string n) {
	dps = d;
	Monster::setName(n);
}

void Orc::setDPS(double d) {
	dps = d;
}

double Orc::getDPS() const {
	return dps;
}

Eagle::Eagle() {
	flightSpeed = 0;
}

Eagle::Eagle(int f) {
	flightSpeed = f;
}

Eagle::Eagle(int f, string n) {
	flightSpeed = f;
	Monster::setName(n);
}

void Eagle::setFlightSpeed(int f) {
	flightSpeed = f;
}

int Eagle::getFlightSpeed() const {
	return flightSpeed;
}

int main() {
	const int SIZE = 3;
	int index = 0;
	Monster *beast[SIZE] = {new Monster(98, "Balrog"),
							new Orc(13.2, "Gothmog"),
							new Eagle(92, "Gwaihir")};
	for (index = 0; index < SIZE; index++) {
		beast[index]->printData();
		cout << endl;
	}
	for (index = 0; index < SIZE; index++) {
		delete beast[index];
	}
	cin.ignore();
	cin.get();
	return 0;
}
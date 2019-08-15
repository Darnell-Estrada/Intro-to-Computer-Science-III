// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC13
// This program records test scores.

#include <iomanip>
#include <iostream>
using namespace std;

class Tests {
	private:
		int numScores;
		float *testScores;
	public:
		Tests(int);
		void setTestScores(int, float);
		float getTestScores(int) const;
		float getHighestScore(int) const;
		float getLowestScore(int) const;
		float getAverageScore(int) const;
		~Tests();
};

Tests::Tests(int t) {
	int index = 0;
	numScores = t;
	testScores = new float[t];
	for (index = 0; index < numScores; index++) {
		testScores[index] = 0.0;
	}
}

void Tests::setTestScores(int i, float s) {
	testScores[i] = s;
}

float Tests::getTestScores(int i) const {
	return testScores[i];
}

float Tests::getHighestScore(int t) const {
	float high = testScores[0];
	int index = 0;
	for (index = 1; index < t; index++) {
		if (testScores[index] > high) {
			high = testScores[index];
		}
	}
	return high;
}

float Tests::getLowestScore(int t) const {
	float low = testScores[0];
	int index = 0;
	for (index = 1; index < t; index++) {
		if (testScores[index] < low) {
			low = testScores[index];
		}
	}
	return low;
}

float Tests::getAverageScore(int t) const {
	float sum = 0.0;
	int index = 0;
	for (index = 0; index < t; index++) {
		sum += testScores[index];
	}
	return (sum / t);
}

Tests::~Tests() {
	delete[] testScores;
	testScores = NULL;
}

int main() {
	float userScore = 0.0;
	int userNumber = 0,
		index = 0;
	cout << "Enter the number of test scores: ";
	cin >> userNumber;
	Tests exam(userNumber);
	for (index = 0; index < userNumber; index++) {
		cout << "Enter test score #" << index + 1 << " : ";
		cin >> userScore;
		exam.setTestScores(index, userScore);
	}
	cin.get();
	cout << "\nData for Test Scores"
		<< "\n--------------------"
		<< "\nTest" << setw(17) << "Score\n";
	for (index = 0; index < userNumber; index++) {
		cout << setw(4) << index + 1 << setw(16)
			<< fixed << showpoint << setprecision(1)
			<< exam.getTestScores(index) << endl;
	}
	cout << "\nHighest score: "
		<< fixed << showpoint << setprecision(1)
		<< exam.getHighestScore(userNumber)
		<< "\nLowest Score: "
		<< fixed << showpoint << setprecision(1)
		<< exam.getLowestScore(userNumber)
		<< "\nAverage Score: "
		<< fixed << showpoint << setprecision(1)
		<< exam.getAverageScore(userNumber) << endl;
	cin.ignore();
	cin.get();
	return 0;
}
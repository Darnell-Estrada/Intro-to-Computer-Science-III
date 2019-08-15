// DARNELL JAMES V. ESTRADA
// CS 2370 SEC 01
// PC16
// This program uses class templates.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <class M>
class Model {
	private:
		const int SIZE = 2;
		fstream file;
		string filename;
		M *list;
	public:
		Model(string);
		void write(M);
		M read(int);
		~Model();
		class fileError {};
		class indexError {};
};

template <class M>
Model<M>::Model(string fn) {
	filename = fn;
	list = new M[SIZE];
}

template <class M>
Model<M>::~Model() {
	delete[] list;
	list = NULL;
}

template <class M>
void Model<M>::write(M value) {
	file.open(filename, ios::app);
	if (file) {
		file << value << endl;
		file.close();
	}
	else {
		throw fileError();
	}
}

template <class M>
M Model<M>::read(int index) {
	int count = 0;
	if (index < 0 || index > 1) {
		throw indexError();
	}
	file.open(filename);
	if (file) {
		for (count = 0; count < SIZE; count++) {
			file >> list[count];
		}
		file.close();
		if (index > 0 || index < 1) {
			for (count = 0; count < SIZE; count++) {
				if (count == index) {
					return list[count];
				}
			}
		}
	}
	else {
		throw fileError();
	}
	return NULL;
}

template <class L>
L larger(L first, L second) {
	if (first > second) {
		return first;
	}
	else {
		return second;
	}
}

int main() {
	Model<int> object1("data1.txt");
	Model<string> object2("data2.txt");
	try {
		object1.write(larger(50, 35));
		object1.write(larger(95, 45));
		cout << "I wrote the integers 50 and 35 to a Model object."
			<< "\nI will now return the largest of the two integers.\n"
			<< object1.read(0);
		cout << "\n\nI wrote the integers 95 and 40 to the same Model object."
			<< "\nI will now return the largest of the two integers.\n"
			<< object1.read(1);
		object2.write(larger("Hello", "World"));
		object2.write(larger("Bernie", "Sanders"));
		cout << "\n\nI wrote the strings \"Hello\" and \"World\""
			<< " to another Model object."
			<< "\nI will now return the largest of the two strings.\n"
			<< object2.read(0);
		cout << "\n\nI wrote the strings \"Bernie\" and \"Sanders\""
			<< " to the same Model object."
			<< "\nI will now return the largest of the two strings.\n"
			<< object2.read(1);
		cout << "\n\nI will now try to enter an invalid index"
			<< " into the first Model object.";
		cout << object1.read(22);
	}
	catch (Model<fstream>::fileError) {
		cout << "\nError: A problem occurred opening the file\n";
	}
	catch (Model<int>::indexError) {
		cout << "\nError: An invalid index was entered\n";
	}
	cin.ignore();
	cin.get();
	return 0;
}
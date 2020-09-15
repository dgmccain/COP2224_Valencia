#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	int count = 0;
	int fileSize;;
	string *fileContents;
	ifstream inFile;
	ofstream outFile;

	inFile.open("my_input.txt");

	outFile.open("my_output.dat");

	cout << "Enter file size: ";
	cin >> fileSize;
	fileContents = new string[fileSize]; //each new string for each int value of fileSize will
										 //be assigned to an element in the *array* fileContents...

	//find out how to insert pre-determined data from a txt file to the dat file at the start of program and
	//see if there is any way to save data from txt or dat file(s) into a variable, array, etc. within the program...
	//^^^ doing those 2 things should help with displaying the data through cout ^^^...

	do
	{
		cout << "Enter a number: ";
		cin >> a;
		cout << "Enter another number: ";
		cin >> b;

		inFile >> a >> b;
		c = a + b;

		outFile << c << endl;
		count++;
	} while (count < fileSize);

	//cout << outFile;

	inFile.close();
	outFile.close();

	system("pause");
}
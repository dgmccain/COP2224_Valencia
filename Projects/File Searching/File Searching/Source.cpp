#include <iostream>
#include <iomanip> //can be used for formatting in later program modding
#include <string>
#include <fstream> //included for opening, reading, writing, and closing file
using namespace std;

bool reimburseChecker(char character)
{
	switch (character)
	{
	case 'C':
	case 'D':
	case 'H':
		return true;
	default:
		return false;
	}
}

int main()
{
	ifstream inFile;  //included for writing to file
	ofstream outFile; //included for reading file

	const int SIZE = 11;
	string codes[SIZE];
	string items[SIZE];
	double prices[SIZE];
	char character;
	bool status;

	inFile.open("pharmdat.txt");  //opens txt file for input - writing
	outFile.open("pharmdat.out"); //opens out file for output - reading

	cout << "Creating file with pharmacy data info...\n"; //message displayed when program is run

	outFile << "Pharmacy Data...\n";
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> codes[i] >> items[i] >> prices[i];
	}

	// OUTPUTS...
	for (int i = 0; i < SIZE; i++)
	{
		character = codes[i][0]; // 0 is the first character of string array[i]...
		outFile << codes[i] << " " << items[i] << " ";
		status = reimburseChecker(character); // SEARCH FILE...
		if (status == true)
		{
			outFile << "Qualified Expense "; // reimbursement output...
		}
		outFile << std::fixed << std::setprecision(2) << prices[i] << " \n";
	}

	inFile.close();  //closes txt file
	outFile.close(); //closes out file

	system("pause");
	return 0;
}
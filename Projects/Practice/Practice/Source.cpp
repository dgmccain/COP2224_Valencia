#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void Display_Menu()
{
	cout << endl;
	cout << "|****************|    |****************|" << endl;
	cout << "|*START - (from)*|    |*  END - (to)  *|" << endl;
	cout << "|****************|    |****************|" << endl;
	cout << "|1. Eagle Way    |    |1. Eagle Way    |" << endl;
	cout << "|2. I-234        |    |2. I-234        |" << endl;
	cout << "|3. Daltry Lane  |    |3. Daltry Lane  |" << endl;
	cout << "|4. Park Street  |    |4. Park Street  |" << endl;
	cout << "|****************|    |****************|" << endl;
	cout << endl;
}

void Display_Rates()
{
	const int NUM_ROWS = 5;
	const int NUM_COLS = 5;
	string rates[NUM_ROWS][NUM_COLS] = { 
		{ "            ", "Eagle Way   ", "I-234       ", "Daltry Lane ", "Park Street " },
		{ "Eagle Way   ", "$0.00       ", "$1.33       ", "$1.56       ", "$2.28       " },
		{ "I-234       ", "$1.33       ", "$0.00       ", "$0.58       ", "$1.33       " },
		{ "Daltry Lane ", "$1.56       ", "$0.58       ", "$0.00       ", "$0.95       " },
		{ "Park Street ", "$2.28       ", "$1.33       ", "$0.95       ", "$0.00       " } };

	cout << endl << "These are the current toll rates..." << endl << endl;
	for (int rows = 0; rows < NUM_ROWS; rows++)
	{
		for (int cols = 0; cols < NUM_COLS; cols++)
		{
			cout << rates[rows][cols] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void Calc_Cost(int start, int end)
{
	const int NUM_ROWS = 4;
	const int NUM_COLS = 4;
	double costs[NUM_ROWS][NUM_COLS] = {
		{ 0.00, 1.33, 1.56, 2.28 },
		{ 1.33, 0.00, 0.58, 1.33 },
		{ 1.56, 0.58, 0.00, 0.95 },
		{ 2.28, 1.33, 0.95, 0.00 } };
	//I do not know how to call a multi-dimensional array from main()...

	cout << "Travel will cost $" << costs[start-1][end-1] << endl << endl;

}

void main()
{
	int start;
	int end;
	char contKey;

	do {
		Display_Menu();
		Display_Rates();
		cout << "Enter the number which corresponds to your start location: ";
		cin >> start;

		while (start < 0 || start > 4)
		{
			cout << "Invalid input." << endl;
			cout << "Enter the number which corresponds to your start location: ";
			cin >> start;
		}

		cout << "Enter the number which corresponds to your end location: ";
		cin >> end;

		while (end < 0 || end > 4)
		{
			cout << "Invalid input." << endl;
			cout << "Enter the number which corresponds to your end location: ";
			cin >> end;
		}

		Calc_Cost(start, end);

		cout << "Would you like to enter another route?" << endl;
		cout << "Enter 'C' to continue or anything else to quit: ";
		cin >> contKey;
		system("cls");

	} while (contKey == 'c' || contKey == 'C');

	cout << "Have a nice drive!" << endl;
	Sleep(1000);

	system("pause");
}
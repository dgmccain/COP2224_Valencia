#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

int getNum(char checker[], char x)
{
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (x == checker[i]) //checks if input is digit...
		{
			return x;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		throw - 1; //throw to catch in main...
	}
}

void main() {
	char x;
	char checker[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //digit checker...
	int count = 10; //seconds of wait time when incorrect input is entered...
	string quitEntry; //string ensures multiple characters can be
					  //entered without repeating the wait timer...

	do
	{
		cout << "Enter a number: ";
		try
		{
			cin >> x;
			cin.clear();
			cin.ignore();
			x = getNum(checker, x);
		}
		catch (int) //I could have required user to input integer then end the program
					//but instead included a quit phrase and timer for every invalid entry...
		{
			system("cls");
			while (count > 0)
			{
				cout << "Error: not a valid number. Please try again in " <<
					count << " seconds..." << endl;
				Sleep(1000); //added wait time for when invalid entry is entered...
				count--;
				system("cls");
				x = 0;
			}
			count = 10;
			cin.clear();
			cin.ignore();
		}

		system("cls"); //clear screen to start quit option...
		cout << "Enter 'quit' to quit: ";
		cin >> quitEntry;
		system("cls");
	} while (quitEntry != "quit");

	system("pause");
}
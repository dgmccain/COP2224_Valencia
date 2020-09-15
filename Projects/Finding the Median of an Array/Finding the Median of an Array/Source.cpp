#include <iostream>
#include <exception>
using namespace std;

void median(int numArray[], const int SIZE)
{
	double result;
	bool isSorted = true;
	int j;
	bool isZero = true;

	for (int i = 0; i < SIZE; i++)
	{
		if (numArray[i] > 0)
		{
			isZero = false;
		}
	}
	if (isZero || SIZE <= 0)
	{
		//throw numeric exception value of -1...
		throw -1;
	}
	else
	{
		for (int i = 0; i < (SIZE - 1); i++)
		{
			if (numArray[i] > numArray[i + 1])
			{
				isSorted = false;
				//throw numeric exception value of -2...
				throw - 2;
			}
		}
		if (isSorted)
		{
			//calculate median...
			if (SIZE % 2 == 0)
			{
				//calculate even number median...
				int a = numArray[SIZE / 2];
				int b = numArray[(SIZE / 2) - 1];
				result = (a + b) / (double)2;
			}
			else
			{
				//calculate odd number median...
				result = numArray[SIZE / 2];
			}
		}
		cout << endl;
	}

	cout << "The median is " << result << endl << endl;
}

void main() {
	const int SIZE = 10; //adjustable...
	int numArray[SIZE];

	try
	{
		//POPULATE ARRAY...
		cout << "Enter " << SIZE << " numbers from lowest to highest: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cin >> numArray[i];
		}
		//find median for array...
		median(numArray, SIZE);
	}
	catch (int a)
	{
		if (a == -1)
		{
			cout << "Error: No elements in array.\n";
		}
		else if (a == -2)
		{
			cout << "Error: Array not in sorted order.\n";
		}
	}

	system("pause");
}
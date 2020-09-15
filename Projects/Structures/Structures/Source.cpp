#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct inventory_item
{
	int num;
	string name;
	int quantity;
	double price;
	double totalCost;
};

void main()
{
	const int SIZE = 3;
	inventory_item array[SIZE];
	int numCounter = 1;

	for (int i = 0; i < SIZE; i++)
	{
		array[i].num = numCounter;
		cout << "Product #" << array[i].num << endl;
		cout << "Enter product name: ";
		cin >> array[i].name;
		cout << "Enter product quantity: ";
		cin >> array[i].quantity;
		cout << "Enter product price: $";
		cin >> array[i].price;
		array[i].totalCost = array[i].quantity * array[i].price;
		cout << endl << "Product info..." << endl;
		cout << "Product #" << array[i].num << endl;
		cout << "Product name: " << array[i].name << endl;
		cout << "Quantity: " << array[i].quantity << endl;
		cout << "Price per item: $" << fixed;
		cout << setprecision(2) << array[i].price << endl;
		cout << "Total cost : $" << fixed;
		cout << setprecision(2) << array[i].totalCost << endl << endl;
		numCounter++;
	}

	system("pause");
}
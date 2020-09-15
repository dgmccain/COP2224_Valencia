#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct restaurant
{
	string name;
	string cuisine;
	string price;
	double rating;
};

void searchListCuisine(const int SIZE, restaurant array[]);
void searchListRatings(const int SIZE, restaurant array[]);

void main()
{
	const int SIZE = 10;
	restaurant array[SIZE];
	char answer;
	char quitKey;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter restaurant Name: ";
		std::getline(std::cin, array[i].name);
		cout << "Enter restaurant Cuisine: ";
		std::getline(std::cin, array[i].cuisine);
		cout << "Enter restaurant Price Range: ";
		cin >> array[i].price;
		cout << "Enter restaurant rating: ";
		cin >> array[i].rating;
		while (array[i].rating < 1 || array[i].rating > 5)
		{
			cout << "You have to enter a rating from 1-5." << endl;
			cout << "Enter restaurant rating: ";
			cin >> array[i].rating;
		}
		cin.ignore();

		cout << endl << "restaurant info..." << endl;
		cout << "Name: " << array[i].name << endl;
		cout << "Cuisine: " << array[i].cuisine << endl;
		cout << "Price Range: " << array[i].price << endl;
		cout << "Rating: " << array[i].rating << endl << endl;
	}

	do
	{
		cout << "How would you like to search for restaurants?" << endl;
		cout << "Type 'C' for cuisine or 'R' for ratings: ";
		cin >> answer;
		cout << endl;

		if (answer == 'c' || answer == 'C')
		{
			searchListCuisine(SIZE, array);
		}
		else if (answer == 'r' || answer == 'R')
		{
			searchListRatings(SIZE, array);
		}
		cout << "Would you like to continue? 'Y' for yes, 'N' for no. >> ";
		cin >> quitKey;
		system("cls");
	} while (quitKey == 'y' || quitKey == 'Y');

	system("pause");
}

void searchListCuisine(const int SIZE, restaurant array[])
{
	string searchCuisine;

	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i].cuisine << endl;
	}
	cout << endl << "Which type of cuisine are you looking for? >> ";
	cin.ignore();
	std::getline(std::cin, searchCuisine);
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (searchCuisine == array[i].cuisine)
		{
			cout << array[i].name << endl;
			cout << array[i].cuisine << endl;
			cout << array[i].price << endl;
			cout << array[i].rating << endl << endl;
		}
	}
}

void searchListRatings(const int SIZE, restaurant array[])
{
	double searchRatings;

	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i].rating << endl;
	}

	cout << endl << "Which particular rating are you looking for? >> ";
	cin >> searchRatings;
	while (searchRatings < 0 || searchRatings > 5)
	{
		cout << "You have to enter a rating from 1-5." << endl;
		cout << "Enter restaurant rating: ";
		cin >> searchRatings;
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (searchRatings == array[i].rating)
		{
			cout << array[i].name << endl;
			cout << array[i].cuisine << endl;
			cout << array[i].price << endl;
			cout << array[i].rating << endl << endl;
		}
	}
}
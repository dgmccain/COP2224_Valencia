#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int CAPACITY = 100; //change CAPACITY to affect array size...

class MovieInfo
{
public:
	string title;
	string genre;
	int movieTime;
	double price;

	void sortMoviesByTitle()
	{
		cout << "Title: " << title << ".  Genre: " << genre << ".  Time: ";
		cout << movieTime << " minutes.  Price: $" << price << "." << endl;
	}

	void sortMoviesByGenre()
	{
		cout << "Genre: " << genre << ".  Title: " << title << ".  Time: ";
		cout << movieTime << " minutes.  Price: $" << price << "." << endl;
	}

	void sortMoviesByPrice()
	{
		cout << "Price: $" << price << ".  Title: " << title << ".  Genre: ";
		cout << genre << ".  Time: " << movieTime << " minutes." << endl;
	}

	void searchMovieTitles()
	{

	}
};
class CustomerInfo
{
public:
	string name;
	string movieTitle;
	double moviePrice;
	int quantity;
	double totalCost;

	void sortCustomersByName()
	{
		//it might be better to just perform cout << "Name of customer: " << name; because
		//of the amount of information on the screen when the program is run...
		//either way, it is easily modifiable so I'll keep the extra info for now...

		cout << "Name of customer: " << name << ".  Movie purchased: " << movieTitle;
		cout << ".  Price per ticket: $" << moviePrice << ".  Quantity purchased: ";
		cout << quantity << " tickets.  Total Cost: $" << totalCost << "." << endl;
	}

	void sortCustomersByTitle()
	{
		cout << "Movie purchased: " << movieTitle << ".  Name of customer: " << name;
		cout << ".  Price per ticket: $" << moviePrice << ".  Quantity purchased: ";
		cout << quantity << " tickets.  Total Cost: $" << totalCost << "." << endl;
	}

	void sortCustomersByCost()
	{
		cout << "Total cost: $" << totalCost << ".  Name of customer: " << name << ".  Movie";
		cout << " purchased: " << movieTitle << ".  Price per ticket: $" << moviePrice << ".  ";
		cout << "Quantity purchased: " << quantity << ".  Total cost: $" << totalCost << "." << endl;
	}
};

bool getCode()
{
	string securityCode = "270448"; //adjustable code...
	string userCode;

	cout << "Please enter your 6-digit access code: ";
	cin >> userCode;
	if (userCode == securityCode)
	{
		cout << endl << "Code accepted" << endl << endl;
		return true;
	}
	else
	{
		cout << endl << "Invalid code" << endl << endl;
		return false;
	}
};

int getMoviePreference()
{
	int choice;

	do
	{
		cout << "=======================================" << endl;
		cout << "|How would you like to sort the list? |" << endl;
		cout << "=======================================" << endl;
		cout << "|Type 1 to prioritize by title        |" << endl;
		cout << "|Type 2 to prioritize by genre        |" << endl;
		cout << "|Type 3 to prioritize by price        |" << endl;
		cout << "=======================================" << endl;
		cin >> choice;

		if (choice < 1 || choice > 3)
		{
			cout << endl << "INVALID INPUT" << endl << endl;
		}
	} while (choice < 1 || choice > 3);

	return choice;
}

int getCustomerPreference()
{
	int choice;

	do
	{
		cout << "===================================================" << endl;
		cout << "|How would you like to sort the purchase history? |" << endl;
		cout << "===================================================" << endl;
		cout << "|Type 1 to prioritize by customer name            |" << endl;
		cout << "|Type 2 to prioritize by movie title              |" << endl;
		cout << "|Type 3 to prioritize by total cost               |" << endl;
		cout << "===================================================" << endl;
		cin >> choice;

		if (choice < 1 || choice > 3)
		{
			cout << endl << "INVALID INPUT" << endl << endl;
		}
	} while (choice < 1 || choice > 3);

	return choice;
}

int displayMenu()
{
	int choice;

	cout << "====================================" << endl;
	cout << "|What would you like to do?        |" << endl;
	cout << "====================================" << endl;
	cout << "|1 to view the movie list          |" << endl;
	cout << "|2 to buy a movie ticket           |" << endl;
	cout << "|3 to add a movie to the list      |" << endl;
	cout << "|4 to delete a movie from the list |" << endl;
	cout << "|5 to view purchase history        |" << endl;
	cout << "|6 to delete a customer's purchase |" << endl;
	cout << "|7 to quit the program             |" << endl;
	cout << "====================================" << endl;
	cin >> choice;

	return choice;
}

void main() //a lot of functions are in main() which can be performed as their own functions
			//outside the main, however, I am not very familiar with how to implement two-
			//dimensional dynamic arrays outside of the main()...
{
	int choice;
	bool isValid = false;
	MovieInfo **movieList;
	CustomerInfo **customerList;
	int movieCount = 0;
	int customerCount = 0;
	int preferance;
	string removeMovie;
	string removeCustomer;
	string confirmation;
	bool equivalent = false;
	char contKey;

	movieList = new MovieInfo*[CAPACITY]; //establish two-dimensional dynamic array for movies...
	for (int i = 0; i < CAPACITY; i++)
	{
		movieList[i] = new MovieInfo[4];
	}

	customerList = new CustomerInfo*[CAPACITY]; //establish two-dimensional dynamic array for customers...
	for (int i = 0; i < CAPACITY; i++)
	{
		customerList[i] = new CustomerInfo[5];
	}

	//create first movie entry - possible to implement with file...
	movieList[0]->title = "Shazam"; //movieList[0] could have also been written as movieList[movieCount] because
	movieList[0]->genre = "Action"; //movieCount is initialized to 0 already...
	movieList[0]->movieTime = 132;
	movieList[0]->price = 8.11;

	//more movies can be added like this...
	movieCount++; //sets movieCount to 1, so movieLists[1]->title could be written as movieLists[movieCount]->title...
	movieList[1]->title = "Avengers: Infinity War";
	movieList[1]->genre = "Action"; //same situation as movieLists[1]->title...
	movieList[1]->movieTime = 182;
	movieList[1]->price = 11.49;

	//create first customer entry - same possibilities as moveList above...
	customerList[customerCount]->name = "David McCain"; //could also be customerList[0]->name...
	customerList[customerCount]->movieTitle = "Shazam"; //could also be movieList[movieCount]->title...
	customerList[customerCount]->moviePrice = movieList[movieCount]->price;
	customerList[customerCount]->quantity = 6;
	customerList[customerCount]->totalCost = (movieList[movieCount]->price) * customerList[customerCount]->quantity;

	//more customer data can be pre-determined in the same way as long as customerCount++; is before the new info...

	do
	{
		choice = displayMenu();

		switch (choice)
		{
		case 1:
			cout << endl << "You chose to view the list of movies" << endl << endl;
			preferance = getMoviePreference();
			if (preferance == 1)
			{
				cout << endl;
				for (int i = 0; i <= movieCount; i++)
				{
					movieList[i]->sortMoviesByTitle();
				}
			}
			else if (preferance == 2)
			{
				cout << endl;
				for (int i = 0; i <= movieCount; i++)
				{
					movieList[i]->sortMoviesByGenre();
				}
			}
			else if (preferance == 3)
			{
				cout << endl;
				for (int i = 0; i <= movieCount; i++)
				{
					movieList[i]->sortMoviesByPrice();
				}
			}
			cout << endl;
			break;
		case 2:
			cout << endl << "You chose to buy a movie ticket" << endl;
			//function goes here...
			customerCount++;
			cout << "Enter your name: ";
			cin.ignore();
			getline(cin, customerList[customerCount]->name);
			cout << "Enter what movie you would like to see: ";
			getline(cin, customerList[customerCount]->movieTitle);
			for (int i = 0; i <= movieCount; i++)
			{
				if (customerList[customerCount]->movieTitle == movieList[i]->title)
				{
					equivalent = true;
					i = movieCount;
				}
			}
			if (equivalent)
			{
				customerList[customerCount]->moviePrice = movieList[movieCount]->price;
				cout << "The price per ticket for " << customerList[customerCount]->movieTitle << " is $";
				cout << customerList[customerCount]->moviePrice << "." << endl;
				cout << "Enter how many tickets you want to purchase: ";
				cin >> customerList[customerCount]->quantity;
				cout << "That brings the total cost to $";
				customerList[customerCount]->totalCost = (customerList[customerCount]->quantity *
					customerList[customerCount]->moviePrice); //calculate total cost...
				cout << customerList[customerCount]->totalCost << "." << endl; //display total cost...
				cout << endl << "Enter 'accept' to confirm your purchase or 'cancel' to cancel your order: ";
				cin >> confirmation;
				while (confirmation != "accept" && confirmation != "cancel")
				{
					cout << endl << "You have to confirm or deny your purchase...";
					cout << endl << "Enter 'accept' to confirm your purchase or 'cancel' to cancel your order: ";
					cin >> confirmation;
					system("cls");
				}
				if (confirmation == "accept")
				{
					cout << "Your order has been placed. Have a great day!" << endl;
				}
				else
				{
					cout << "You have cancelled your order. Come again soon!" << endl;
					//delete [] customerList[customerCount]; brough about errors, but
					//I found that I can remove a customerCount from the array instead...
					customerCount--; //delete customer...
				}
			}
			else
			{
				cout << "That movie is not available. Going back to main menu now..." << endl;
				customerCount--; //delete customer...
			}
			equivalent = false;
			cout << endl;
			break;
		case 3:
			cout << endl << "You chose to add a movie to the list" << endl;
			isValid = getCode();
			if (isValid)
			{
				movieCount++;
				cout << "Enter the title: ";
				cin.ignore();
				getline(cin, movieList[movieCount]->title);
				cout << "Enter the genre: ";
				getline(cin, movieList[movieCount]->genre);
				cout << "Enter the movie's length in minutes: ";
				cin >> movieList[movieCount]->movieTime;
				cout << "Enter the price of the movie: $";
				cin >> movieList[movieCount]->price;
			}
			cout << endl;
			break;
		case 4:
			cout << endl << "You chose to delete a movie from the list" << endl;
			isValid = getCode();
			if (isValid)
			{
				cout << "Enter the name of the movie you want to remove: ";
				cin.ignore();
				getline(cin, removeMovie);

				for (int i = 0; i <= movieCount; i++)
				{
					if (removeMovie == movieList[i]->title)
					{
						while (i < movieCount)
						{
							movieList[i] = movieList[i + 1];
							i++;
						}
					}
				}
				movieCount--;
			}
			cout << endl;
			break;
		case 5:
			cout << endl << "You chose to view purchase history" << endl;
			isValid = getCode();
			if (isValid)
			{
				preferance = getCustomerPreference();
				if (preferance == 1)
				{
					cout << endl;
					for (int i = 0; i <= customerCount; i++)
					{
						customerList[i]->sortCustomersByName();
					}
				}
				else if (preferance == 2)
				{
					cout << endl;
					for (int i = 0; i <= customerCount; i++)
					{
						customerList[i]->sortCustomersByTitle();
					}
				}
				else if (preferance == 3)
				{
					cout << endl;
					for (int i = 0; i <= customerCount; i++)
					{
						customerList[i]->sortCustomersByCost();
					}
				}
				cout << endl;
			}
			break;
		case 6:
			cout << endl << "You chose to delete a customer's purchase" << endl;
			isValid = getCode();
			if (isValid)
			{
				cout << "You need to know the customer's name before deleting their";
				cout << " purchase history. You can view the list of customers from the";
				cout << " main menu at any time. Would you like to continue? Y/N: ";
				cin >> contKey;
				if (contKey == 'y' || contKey == 'Y')
				{
					cout << "Enter the customer's name: ";
					cin.ignore();
					getline(cin, removeCustomer);

					for (int i = 0; i <= customerCount; i++)
					{
						if (removeCustomer == customerList[i]->name)
						{
							while (i < customerCount)
							{
								customerList[i] = customerList[i + 1];
								i++;
							}
							customerCount--;
						}
					}
					cout << endl;
				}
			}
			cout << endl;
			break;
		case 7:
			cout << endl << "You quit the program" << endl << endl;
			break;
		default:
			cout << endl << "INVALID INPUT" << endl;
			cout << "program closing..." << endl << endl;
			choice = 7;
			break;
		}
		system("pause");
		system("cls");

	} while (choice != 7);

	system("pause");
}
#include <iostream>
#include <iomanip> //can be used for formatting in later program modding
#include <string>
#include <fstream> //included for opening, reading, writing, and closing file
using namespace std;

class MovieInfo //inventroy needs to be able to be sorted and updated...
{
public:
	string title;
	string genre;
	int movieLength;
	double ticketPrice;
};

/*
class Customer //customer info also needs to be stored in a file like MovieInfo...
{
public:
string name;
string movieTitle;
double price;
int ticketQuantity;
};
*/

void getNewMovieInfo(int movieListCount, ifstream &inFile) //originally was MovieInfo type instead of void...
{
	MovieInfo *m;
	m = new MovieInfo[movieListCount];
	//consider changing MovieInfo *m to individual tempVals to use for getting cin from user, and to cout to file...

	cin.ignore();
	cout << "Enter movie data..." << endl;
	cout << "Title: ";
	getline(cin, m->title); //find out why it's not m.theater, instead it's m->theater...
							/*
							*use something like this to replace user input spaces in title with underscores for readability...*
							for (int i = 0; i < m->title.length; i++)
							{
							if (m->title[i] == ' ')
							{
							m->title[i] = '_';
							}
							cout << m->title;
							}
							*/
	cout << "Genre: ";
	getline(cin, m->genre);
	cout << "Length of movie in minutes: ";
	cin >> m->movieLength;
	cout << "Price: $";
	cin >> m->ticketPrice;

	//inFile << m->title << m->genre << m->movieLength << m->ticketPrice;

	//inFile needs to get data from object m...
	//return *m;
	//delete m; //NEED TO DO BUT HAVING ERRORS!!!...

	//use same concept of dealing with *m to read files for case 1 scenario and potentially case 5 as well...
}

/*
void viewFileData()
{

}
*/

int displayMenu(int &movieListCounter, ifstream &inFile) //use & to change counter in main...
{
	int choice;
	//int code = 2639; //secret code needed to enter movie data...
	//int userCode; //userCode needs to be the same as the security code...
	string tempTitle;
	string tempGenre;
	int tempMovieLength;
	double tempTicketPrice;
	//tempVals get set to last text file input after first run, so on the next run it tries to read line 5...

	cout << "============================" << endl;
	cout << "|What would you like to do?|" << endl;
	cout << "============================" << endl;
	cout << "|1 to view movies list     |" << endl;
	cout << "|2 to add a movie to list  |" << endl;
	cout << "|3 to buy a movie ticket   |" << endl;
	cout << "|4 to quit the program     |" << endl;
	cout << "============================" << endl;
	cin >> choice;
	//add a fifth choice to view customer purchase history with required passcode...
	//also add search feature for choice 1 *will most likely use sort() function*...
	//possibly create a sortByPreference variable that gets an integer value from the user and then
	//goes to another funtion *like sortByTitle() or sortByGenre()* based upon the user input value...

	switch (choice)
	{
	case 1:
		cout << endl << "You chose to view the list of movies" << endl << endl;
		//include funtion which contains another switch case for getting the user's sorting preference...
		for (int i = 0; i < movieListCounter; i++)
		{
			inFile >> tempTitle >> tempGenre >> tempMovieLength >> tempTicketPrice; //find out how to enter spaces for title...
			cout << tempTitle << " " << tempGenre << " " << tempMovieLength << " " << tempTicketPrice << endl;
		}
		cout << endl;
		break;
	case 2:
		//cout << "enter the passcode to enter the new movie data: ";
		//cin >> userCode;
		//if (userCode == code)
		//{
		cout << endl << "You chose to add a movie to the list" << endl << endl;
		getNewMovieInfo(movieListCounter, inFile);
		movieListCounter++;
		//movieListCounter++;
		//}
		//else
		//{
		//    cout << "That is not the code..." << endl;
		//}
		cout << endl;
		break;
	case 3:
		cout << endl << "You chose to buy a movie ticket" << endl << endl;
		break;
	case 4:
		cout << endl << "You quit the program" << endl << endl;
		break;
	default:
		cout << endl << "INVALID INPUT" << endl;
		cout << "program closing..." << endl << endl;
		choice = 4;
		break;
	}

	return choice;
};

void main()
{
	int menuChoice;
	int movieListCounter = 8;
	//int buyerListCounter = 1;
	ifstream inFile;  //included for writing to file

					  //Note on passing pointers to other functions:
					  //Using the & symbol is pass by reference, whereas only using * is pass by value.
					  //Ex. pointerParameters(int* &p, double *q){};
					  //This means that when using &, both *p and p values can be changed.
					  //However, *q can only have its *q value changed - not the q value.

					  /*
					  *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
					  *FIND OUT HOW TO WRITE TO FILE for switch case 2...
					  *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
					  */



	inFile.open("movies.txt");  //opens txt file for input - writing

	do
	{
		menuChoice = displayMenu(movieListCounter, inFile);
		inFile.close();
		inFile.open("movies.txt"); //close and re-open file so that the list in main reads from line 1 each time...
	} while (menuChoice != 4);

	//delete k; //DO NOT FORGET THIS...
	inFile.close();  //closes txt file

	system("pause");
}
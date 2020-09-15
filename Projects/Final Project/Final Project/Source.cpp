#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//related to movies.txt (and now movies.dat as well)...
class MovieInfo //inventroy needs to be able to be sorted and updated...
{
public:
	string title;
	string genre;
	int movieLength;
	double ticketPrice;
};

//related to buyers.txt...
class Customer //customer info also needs to be stored in a file like MovieInfo...
{
public:
	string name;
	string movieTitle; //get from list of movies...
	double price; //get from list of movies...
	int ticketQuantity;
};

void getNewMovieInfo(int movieListCount, ifstream &inFile, ofstream & outFile) //originally was MovieInfo type instead of void...
{
	MovieInfo *m;
	m = new MovieInfo[movieListCount];
	//consider changing MovieInfo *m to individual tempVals to use for getting cin from user, and to cout to file...

	cin.ignore();
	cout << "Enter movie data..." << endl;
	cout << "Title: ";
	getline(cin, m->title); //find out why it's not m.theater, instead it's m->theater...

	/*either implement a getline() function for the title within the txt file, or use
	something like this to replace user input spaces in title with underscores for readability...

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

	outFile << m->title << m->genre << m->movieLength << m->ticketPrice; //why doesn't this save to movies.dat?...
	//find out how to cout << outFile,
	//and how to outFile << inFile...

	//inFile needs to get data from object m...
	//possibly change type to MovieInfo to return *m...
	delete[] m;

	//use the same concept of dealing with *m to read files for case 1 scenario of getting txt info and
	//storing it in an object for use within the program...
}

/*
void viewFileData() //this could be implemented for switch case 1 in displayMenu...
{

}
*/

int displayMenu(int &movieListCounter, ifstream &inFile, ofstream &outFile) //use & to change counter in main...
{
	int choice;
	//temporary variables for use in switch case 1...
	string tempTitle;
	string tempGenre;
	int tempMovieLength;
	double tempTicketPrice;

	cout << "============================" << endl;
	cout << "|What would you like to do?|" << endl;
	cout << "============================" << endl;
	cout << "|1 to view movies list     |" << endl;
	cout << "|2 to add a movie to list  |" << endl;
	cout << "|3 to buy a movie ticket   |" << endl;
	cout << "|4 to quit the program     |" << endl;
	cout << "============================" << endl;
	cin >> choice;
	//add a fifth choice to view customer purchase history...
	//add a sixth choice to add/delete customer purchases...
	//add the option to delete a movie from the list with option 2...
	//also add search feature for choice 1 *will most likely use sort() function*...
	//create a sortByPreference variable that gets an integer value from the user and then
	//goes to another funtion *like sortByTitle() or sortByGenre()* based upon the user input value...

	switch (choice)
	{
	case 1:
		cout << endl << "You chose to view the list of movies" << endl << endl;
		//include funtion which contains another switch case for getting the user's sorting preference...
		//until i can sort by preference, this displays all current movie info in movies.txt...
		for (int i = 0; i < movieListCounter; i++)
		{
			inFile >>  tempTitle >> tempGenre >> tempMovieLength >> tempTicketPrice; //find out how to enter spaces for title...
			cout << tempTitle << " " << tempGenre << " " << tempMovieLength << " " << tempTicketPrice << endl;
		}
		cout << endl;
		break;
	case 2:
		cout << endl << "You chose to add a movie to the list" << endl << endl;
		getNewMovieInfo(movieListCounter, inFile, outFile);
		movieListCounter++;
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
	int movieListCounter = 8; //if movies are added/deleted in the text file, this number needs to change too...
	//int buyerListCounter = 1;
	ifstream inFile;
	ofstream outFile;

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



	inFile.open("movies.txt");  //opens txt file for input - writing...
	outFile.open("movies.dat"); //opens dat file for output - reading...

	do
	{
		menuChoice = displayMenu(movieListCounter, inFile, outFile);
		inFile.close();
		outFile.close();
		inFile.open("movies.txt"); //close and re-open files so that the list in main reads from line 1 each time...
		outFile.open("movies.dat");
	} while (menuChoice != 4);

	inFile.close();
	outFile.close();

	system("pause");
}
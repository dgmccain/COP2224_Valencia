using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

class artwork
{
private:
	int artworkID = 0;
	int ownerID = 0;
	string artist = "_";
	string title = "_";
	int minBid = 0;
	int currHighBid = 0;
	int bidderID = 0;

public:
	void auction()
	{
		cout << "Who is the artist? >> ";
		cin.ignore();
		getline(cin, artist);
		cout << "What is the title? >> ";
		getline(cin, title);
		cout << "Enter the 4-digit artwork ID: ";
		cin >> artworkID;
		while (artworkID < 1000 || artworkID > 9999)
		{
			cout << "The code has to be between 1000 and 9999..." << endl;
			cout << "Enter the 4-digit artwork ID: ";
			cin >> artworkID;
		}
		cout << "Enter your 4-digit ID code: ";
		cin >> ownerID;
		while (ownerID < 1000 || ownerID > 9999)
		{
			cout << "The code has to be between 1000 and 9999..." << endl;
			cout << "Enter the 4-digit owner ID: ";
			cin >> ownerID;
		}
		cout << "What do you want the minimum bid to be? >> $";
		cin >> minBid;
	}
	bool make_bid(int potentialID, int bid) //parameters: bid & bidderID...
	{
		if (bid >= minBid && bid > currHighBid)
		{
			currHighBid = bid;
			bidderID = potentialID; //check...
			return true; //check...
		}
		else
		{
			return false; //check...
		}
	}
	void show(int numEntries)
	{
		cout << "Bidding Info..." << endl;
		cout << "Artist: " << artist << endl;
		cout << "Title: " << title << endl;
		cout << "Owner ID: " << ownerID << endl;
		cout << "Artwork ID: " << artworkID << endl;
		cout << "Minimum bid: $" << minBid << endl;
		cout << "Current highest bid: $" << currHighBid << endl;
		cout << "Highest bidder ID: " << bidderID << endl;
		cout << "There are " << numEntries << " more bidding opportunities left " << endl;
		cout << "before the auction is over." << endl << endl;
	}
	void menu()
	{
		cout << endl;
		cout << "==========================================" << endl;
		cout << "|       What would you like to do?       |" << endl;
		cout << "==========================================" << endl;
		cout << "|Type 1 to enter artwork for the auction |" << endl;
		cout << "|Type 2 to bid at the auction            |" << endl;
		cout << "|Type 3 to view current auction info     |" << endl;
		cout << "==========================================" << endl;
		cout << "Choice: ";
		}
};

void main()
{
	artwork bidObj;
	int bid = 0;
	int bidderID;
	bool isValid;
	int numEntries;
	int choice;

	cout << "How many bids are going to be logged? >> ";
	cin >> numEntries;

	do
	{
		bidObj.menu();
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			bidObj.auction();
			break;
		case 2:
			cout << "Enter your 4-digit bidder ID: ";
			cin >> bidderID;
			while (bidderID < 1000 || bidderID > 9999)
			{
				cout << "The code has to be between 1000 and 9999..." << endl;
				cout << "Enter the 4-digit bidder ID: ";
				cin >> bidderID;
			}
			cout << "Enter your bid: $";
			cin >> bid;
			isValid = bidObj.make_bid(bidderID, bid);
			if (isValid)
			{
				cout << "You are now the highest bidder" << endl;
			}
			else
			{
				cout << "You are not the highest bidder" << endl;
			}
			numEntries--;
			break;
		case 3:
			bidObj.show(numEntries);
			break;
		default:
			cout << "INVALID CHOICE" << endl;
			break;
		}
	} while (numEntries > 0);

	system("pause");
}
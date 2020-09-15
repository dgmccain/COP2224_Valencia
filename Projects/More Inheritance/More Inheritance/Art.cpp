using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

class art
{
public:
	string artist = "_";
	string title = "_";
	int id = 0;

	void getArt()
	{
		cout << "Who is the artist? >> ";
		cin.ignore();
		getline(cin, artist);
		cout << "What is the title? >> ";
		getline(cin, title);
		cout << "What is the id number? >> #";
		cin >> id;
	}
	void displayArt()
	{
		cout << "Artwork Info..." << endl;
		cout << "Artist: " << artist << endl;
		cout << "Title: " << title << endl;
		cout << "ID: " << id << endl;
	}
	//Add storeArt function here or after displayPainting, displaySculpture, and displayPottery...
};

class painting :public art
{
private:
	double length;
	double width;
	string type[4] = { "Oil", "Watercolor", "Pastel", "Mixed-media" };
	int answer;
	string mediaType;
public:
	void paintingInfo()
	{
		getArt();
		cout << "What media was used for the artwork?" << endl;
		cout << "1 for oil" << endl << "2 for watercolor" << endl;
		cout << "3 for pastel" << endl << "4 for mixed-media" << endl;
		cout << "Media type: ";
		cin >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "Input not within range" << endl;
			cout << "What media was used for the artwork?" << endl;
			cout << "1 for oil" << endl << "2 for watercolor" << endl;
			cout << "3 for pastel" << endl << "4 for mixed-media" << endl << endl;
			cout << "Media type: ";
			cin >> answer;
		}
		mediaType = type[answer];
		cout << "What is the length of the painting? >> ";
		cin >> length;
		cout << "What is the width of the painting? >> ";
		cin >> width;
		cout << endl;
	}
	void displayPainting()
	{
		displayArt();
		cout << "Media: " << mediaType << endl;
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl << endl;
	}
};

class sculpture : public art
{
private:
	string material[3] = { "Wood", "Metal", "Plastic" };
	int answer;
	string materialType;
public:
	void sculptureInfo()
	{
		getArt();
		cout << "What material was used for the sculpture?" << endl;
		cout << "1 for wood" << endl;
		cout << "2 for metal" << endl;
		cout << "3 for plastic" << endl << endl;
		cout << "Material: ";
		cin >> answer;
		while (answer < 1 || answer > 3)
		{
			cout << "What material was used for the sculpture?" << endl;
			cout << "1 for wood" << endl;
			cout << "2 for metal" << endl;
			cout << "3 for plastic" << endl << endl;
			cout << "Material: ";
			cin >> answer;
		}
		materialType = material[answer];
		cout << endl;
	}
	void displaySculpture()
	{
		displayArt();
		cout << "Material: " << materialType << endl << endl;
	}
};

class pottery :public art
{
private:
	string potteryArray[4] = { "Earthenware", "Stoneware", "Porcelain", "Ceramic" };
	int answer;
	string potteryType;
	double length;
	double width;
	double height;
public:
	void potteryInfo()
	{
		getArt();
		cout << "What type of pottery was used for the artwork?" << endl;
		cout << "1 for earthenware" << endl << "2 for stoneware" << endl;
		cout << "3 for porcelain" << endl << "4 for ceramic" << endl;
		cout << "Pottery type: ";
		cin >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "What type of pottery was used for the artwork?" << endl;
			cout << "1 for earthenware" << endl << "2 for stoneware" << endl;
			cout << "3 for porcelain" << endl << "4 for ceramic" << endl;
			cout << "Pottery type: ";
			cin >> answer;
		}
		potteryType = potteryArray[answer];
		cout << "What is the length of the pottery? >> ";
		cin >> length;
		cout << "What is the width of the pottery? >> ";
		cin >> width;
		cout << "What is the height of the pottery? >> ";
		cin >> height;
		cout << endl;
	}
	void displayPottery()
	{
		displayArt();
		cout << "Pottery type: " << potteryType << endl;
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl << endl;
	}
};

void main()
{
	painting obj1;
	sculpture obj2;
	pottery obj3;
	int answer;
	int numEntries;

	cout << "How many works of art have info to be entered? >> ";
	cin >> numEntries;

	do
	{
		cout << "=======================================" << endl;
		cout << "|What type of artwork are you logging?|" << endl;
		cout << "=======================================" << endl;
		cout << "|Type 1 for painting                  |" << endl;
		cout << "|Type 2 for sculpture                 |" << endl;
		cout << "|Type 3 for pottery                   |" << endl;
		cout << "=======================================" << endl;
		cout << "Art Type: ";
		cin >> answer;

		while (answer < 1 || answer > 3)
		{
			cout << "INPUT NOT WITHIN RANGE" << endl;
			cout << "=======================================" << endl;
			cout << "|What type of artwork are you logging?|" << endl;
			cout << "=======================================" << endl;
			cout << "|Type 1 for painting                  |" << endl;
			cout << "|Type 2 for sculpture                 |" << endl;
			cout << "|Type 3 for pottery                   |" << endl;
			cout << "=======================================" << endl;
			cout << "Art Type: ";
			cin >> answer;
		}

		switch (answer)
		{
		case 1:
			obj1.paintingInfo();
			obj1.displayPainting();
			break;
		case 2:
			obj2.sculptureInfo();
			obj2.displaySculpture();
			break;
		case 3:
			obj3.potteryInfo();
			obj3.displayPottery();
			break;
		default:
			cout << "INVALID INPUT" << endl;
			break;
		}

		numEntries--;
	} while (numEntries > 0);

	system("pause");
}
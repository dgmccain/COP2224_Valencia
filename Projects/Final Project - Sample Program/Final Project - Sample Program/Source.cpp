#include<iostream> 
#include<fstream> 
#include<iomanip> 
#include<cctype> 
using namespace std;

const int DESC_SIZE = 51; // holds inventory description size 
const int DATE_SIZE = 11; // holds date size 

struct InventoryItem	// inventory structure 

{

	char desc[DESC_SIZE];	// description holds 31 charaters 
	int quantity;	// variable to hold quantity 
	double whlCost;	// variable to hold wholesale cost 
	double rtlCost;	// variable to hold retail cost 
	char date[DATE_SIZE];	// variable to hold date 

};

void addRec(fstream &);	// function prototype to add a record 
void viewRec(fstream &);	// function prototype to view a record 
void chgRec(fstream &);	// function prototype to change a record 
int menu();

void main()
{

	long selection;	// variable to hold menu selection 
	long recNum;	// variable to hold the record number of the inventory item 

	fstream inventory("Inventory.dat", ios::in | ios::out | ios::binary);
	InventoryItem record = { " ", 0, 0.0 };

	cout << fixed << showpoint << setprecision(2);
	cout << "Inventory Managment" << endl;


	for (int count = 0; count < 5; count++)	// write the blank records 

	{

		inventory.write(reinterpret_cast<char *>(&record), sizeof(record));

	}

	inventory.close();

	inventory.open("Inventory.dat", ios::out | ios::binary);

	do
	{
		selection = menu();
		switch (selection)
		{
		case 1:	// Add a new record 
		{
			addRec(inventory);
			break;
		}
		case 2:	//View record 
		{
			viewRec(inventory);
			break;
		}
		case 3:	//Change record 
		{
			chgRec(inventory);
			break;
		}
		default:	//Invalid selection 
		{
			cout << "Invalid selection" << endl;
			selection = 4;
			break;
		}
		}

	} while (selection != 4);

	cout << "Hava a nice day." << endl;
	inventory.close();
	system("pause");
}
int menu()
{
	int choice;

	cout << "Please make a selection, 1 through 4." << endl;
	cout << "1. Add a new record" << endl;
	cout << "2. View an exisitng record" << endl;
	cout << "3. Change an exisitng record" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
	cout << "Enter your choice (1-4): ";
	cin >> choice;

	while (choice < 1 || choice > 4)

	{
		cout << "Invaild selection!" << endl;
		cout << "Please enter your choice (1-4) : ";

		cin >> choice;
	}

	cout << endl;
	return choice;

}

void addRec(fstream &file) // function to add new information to inventory 
{
	cout << "Enter the following inventory data:" << endl;

	fstream inventory("Inventory.dat", ios::out | ios::binary);

	InventoryItem record;

	//Enter new data 

	cout << "Description: ";

	cin.ignore();
	cin.getline(record.desc, DESC_SIZE);

	cout << "Quantity: ";
	cin >> record.quantity;

	cout << "Wholesale cost: ";
	cin >> record.whlCost;

	cout << "Retail price: ";
	cin >> record.rtlCost;

	cout << "Date added to inventory (in 00/00/0000 format): ";
	cin >> record.date;

	inventory.write(reinterpret_cast<char *>(&record), sizeof(record)); //FIND OUT WHAT THIS DOES - I believe that
																		//it writes the entered cin info to the file...
	cout << "Record added to file." << endl;

	file.close();

}

void viewRec(fstream &file)	// function to view record 
{

	fstream inventory("Inventory.dat", ios::out | ios::binary);
	InventoryItem record;

	long recNum;

	cout << "Enter the record number of the item to view:";
	cin >> recNum;

	// Move to the record and read it. 

	inventory.seekg(recNum * sizeof(record), ios::beg);                    //FIND OUT WHAT THIS DOES...
	inventory.read(reinterpret_cast<char *>(&record), sizeof(record));     //SAME...

	cout << "Description: " << record.desc << endl;
	cout << "Quantity: " << record.quantity << endl;
	cout << "Wholesale cost: " << record.whlCost << endl;
	cout << "Retail price: " << record.rtlCost << endl;
	cout << "Date (in 00/00/0000 format): " << record.date << endl;

	if (file.fail())
		file.clear();
	file.close();

}

void chgRec(fstream &file)	// function to change a record
{

	fstream inventory("InventoryFile.dat", ios::out | ios::binary);
	InventoryItem record;

	long recNum;

	cout << "Enter the record number of the item you want to edit: ";
	cin >> recNum;	// Move to the record and read it. 

	inventory.seekg(recNum * sizeof(record), ios::beg);
	inventory.read(reinterpret_cast<char *>(&record), sizeof(record));

	cout << "Description: " << record.desc << endl;
	cout << "Quantity: " << record.quantity << endl;
	cout << "Wholesale cost: " << record.whlCost << endl;
	cout << "Retail price: " << record.rtlCost << endl;
	cout << "Date (in 00/00/0000 format): " << record.date << endl;
	cout << endl;

	// Move back to the beginning of this record's position 

	inventory.seekp(recNum * sizeof(record), ios::beg);

	// Write new record over the current record 

	// inventory.write(reinterpret_cast<char *>(&record),sizeof(record)); 

	// Close the file. 

	inventory.close();
}
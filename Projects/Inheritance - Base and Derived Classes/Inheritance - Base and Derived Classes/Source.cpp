using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

class person
{
public:
	string firstName = "_";
	string lastName = "_";
	int age = 0;
};

class student :public person
{
private:
	int courses;
	double gpa;
public:
	void studentInfo()
	{
		cout << "What is your first name? >> ";
		cin >> firstName;
		cout << "What is your last name? >> ";
		cin >> lastName;
		cout << "What is your age? >> ";
		cin >> age;
		cout << "How many courses have you taken? >> ";
		cin >> courses;
		cout << "What is your GPA? >> ";
		cin >> gpa;
		cout << endl;
	}
	void displayStudent()
	{
		cout << "You are student " << firstName << " " << lastName << ", age " << age << ". ";
		cout << "You have taken " << courses << " courses and have a " << gpa << " GPA." << endl << endl;
	}
};

class staff : public person
{
private:
	double hourlyPay;
	double hoursPerWeek;
public:
	void staffInfo()
	{
		cout << "What is your first name? >> ";
		cin >> firstName;
		cout << "What is your last name? >> ";
		cin >> lastName;
		cout << "What is your age? >> ";
		cin >> age;
		cout << "How much do you make per hour? >> $";
		cin >> hourlyPay;
		cout << "How many hours do you work per week? >> ";
		cin >> hoursPerWeek;
		cout << endl;
	}
	void displayStaff()
	{
		cout << "You are staff member " << firstName << " " << lastName << ", age " << age << ". ";
		cout << "You make $" << fixed << setprecision(2) << hourlyPay << " an hour and work ";
		cout << setprecision(0) << hoursPerWeek << " hours a week." << endl << endl;
	}
};

class faculty :public person
{
private:
	double hourlyPay;
	double hoursPerWeek;
public:
	void facultyInfo()
	{
		cout << "What is your first name? >> ";
		cin >> firstName;
		cout << "What is your last name? >> ";
		cin >> lastName;
		cout << "What is your age? >> ";
		cin >> age;
		cout << "How much do you make per hour? >> $";
		cin >> hourlyPay;
		cout << "How many hours do you work per week? >> ";
		cin >> hoursPerWeek;
		cout << endl;
	}
	void displayFaculty()
	{
		cout << "You are faculty member " << firstName << " " << lastName << ", age " << age << ". ";
		cout << "You make $" << fixed << setprecision(2) << hourlyPay << " an hour and work ";
		cout << setprecision(0) << hoursPerWeek << " hours a week." << endl << endl;
	}
};

void main()
{
	student obj1;
	staff obj2;
	faculty obj3;
	int answer;
	int numPeople;

	cout << "How many people are entering info? >> ";
	cin >> numPeople;

	do
	{
		cout << "====================" << endl;
		cout << "|What is your role?|" << endl;
		cout << "====================" << endl;
		cout << "|Type 1 for student|\n|Type 2 for staff  |\n|Type 3 for faculty| " << endl;
		cout << "====================" << endl << "role >> ";
		cin >> answer;

		switch (answer)
		{
		case 1:
			obj1.studentInfo();
			obj1.displayStudent();
			break;
		case 2:
			obj2.staffInfo();
			obj2.displayStaff();
			break;
		case 3:
			obj3.facultyInfo();
			obj3.displayFaculty();
			break;
		default:
			cout << "INVALID INPUT" << endl;
			break;
		}

		numPeople--;
	} while (numPeople > 0);

	system("pause");
}
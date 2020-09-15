#include <iostream>
using namespace std;

int main() {
	double piVal = 3.141592; //Value of pi for calculations
	double radius; //User input value
	double volume; //Calculated later
	double surfaceArea; //Calculated later

	cout << "Enter the value of the radius: ";
	cin >> radius;

	volume = (4.0 / 3.0) * piVal * (radius * radius * radius);
	surfaceArea = 4.0 * piVal * (radius *radius);

	cout << "The volume is " << volume; //Display volume
	cout << "\nThe surface area is " << surfaceArea << "\n"; //Display surface area

	system("pause");
	return 0;
}
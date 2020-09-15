#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//double item;
	//double shippingCost = 10 * item;
	//double total;
	int userNum;
	double itemPrice;
	double array[5] = { 0, 0, 0, 0, 0 };
	double total = 0.0;

	cout << "Enter how many items (up to 5) you want to purchase: ";
	cin >> userNum;

	for (int i = 0; i < userNum; i++) {
		cout << "Enter the price for item #" << i + 1 << ": $";
		cin >> array[i];
	}
	for (int i = 0; i < userNum; i++) {
		total += array[i];
	}

	cout << "The total is $";
	cout << fixed;
	cout << setprecision(2) << total;
	cout << "\n";

	system("pause");
	return 0;
}
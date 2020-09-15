#include <iostream>
using namespace std;

int main() {
	const int SIZE = 6;
	int practiceMatches[SIZE] = { 0, 0, 0, 0, 0, 0 };
	int matchNum[SIZE] = { 1, 2, 3, 4, 5, 6, };
	int total = 0;
	int avg;

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter how many people attended practice match "
			<< matchNum[i] << ": ";
		cin >> practiceMatches[i];
		total = total + practiceMatches[i];
	}
	avg = total / SIZE;
	cout << "\nThe average attendance per match for the season is " <<
		avg << endl << endl;

	system("pause");
	return 0;
}
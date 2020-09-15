#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
	char letter;
	
	cout << "Enter a letter: ";
	cin >> letter;

	while (isdigit(letter))
	{
		cout << "You entered a number. That is not a valid input..." << endl;
		cout << "Enter a letter: ";
		cin >> letter;
	}
	if (!isdigit(letter))
		cout << "You entered the letter " << letter << endl;

	system("pause");
	return 0;
}
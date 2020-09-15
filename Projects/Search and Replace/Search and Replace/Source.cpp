#include <iostream>
#include <string>
using namespace std;

// REPLACE WORD FUNCTION...
void ReplaceWord(const int SIZE, string phrase[], string replaceWord, string newWord)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (phrase[i] == replaceWord)
		{
			phrase[i] = newWord;
		}
		// REPLACE WORD IF FOLLOWED BY PUNCTUATION...
		if (phrase[i] == replaceWord + ',')
		{
			phrase[i] = newWord + ',';
		}
		if (phrase[i] == replaceWord + '.')
		{
			phrase[i] = newWord + '.';
		}
		if (phrase[i] == replaceWord + '!')
		{
			phrase[i] = newWord + '!';
		}
		if (phrase[i] == replaceWord + '?')
		{
			phrase[i] = newWord + '?';
		}
	}
}

int main()
{
	const int SIZE = 10; //size can be changed...
	string phrase[SIZE];
	string replaceWord;
	string newWord;

	// DETERMINE PHRASE...
	cout << "Enter a 10 word phrase: "; //word limit can be changed...
	for (int i = 0; i < SIZE; i++)
	{
		cin >> phrase[i];
	}

	cout << "Word to replace: ";
	cin >> replaceWord;

	cout << "New word: ";
	cin >> newWord;

	// REPLACE WORD...
	ReplaceWord(SIZE, phrase, replaceWord, newWord); //replace word function...

	// OUTPUT RESULT...
	cout << "Result: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << phrase[i] << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}
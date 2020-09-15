#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// REPLACE WORD FUNCTION...
void ReplaceWords(const int SIZE, string phrase[], string replaceWord[], string newWord[])
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (phrase[i] == replaceWord[j])
			{
				phrase[i] = newWord[j];
			}
			// REPLACE WORD IF FOLLOWED BY PUNCTUATION...
			if (phrase[i] == replaceWord[j] + ',')
			{
				phrase[i] = newWord[j] + ',';
			}
			if (phrase[i] == replaceWord[j] + '.')
			{
				phrase[i] = newWord[j] + '.';
			}
			if (phrase[i] == replaceWord[j] + '!')
			{
				phrase[i] = newWord[j] + '!';
			}
			if (phrase[i] == replaceWord[j] + '?')
			{
				phrase[i] = newWord[j] + '?';
			}
		}
	}
}

int main()
{
	ifstream inFile; //included for writing to file...
	ofstream outFile; //included for reading file...

	const int SIZE = 92; //size can be changed and txt file edited...
	string phrase[SIZE];
	string replaceWord[5] = { "apparant", "greatful", "medievel", "seperate", "wierd" };
	string newWord[5] = { "apparent", "grateful", "medieval", "separate", "weird" };

	// MESSAGE DISPLAYED WHEN PROGRAM IS RUN...
	cout << "Creating file with sentences...\n";

	// COPY TXT DATA TO ARRAY...
	inFile.open("sentences.txt"); //opens txt file for input - writing...
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> phrase[i];
	}
	// FINISHED WITH TXT FILE...
	inFile.close(); //closes txt file...

	// OPEN OUT FILE...
	outFile.open("sentences.out"); //opens out file for output - reading...

	// REPLACE WORDS...
	ReplaceWords(SIZE, phrase, replaceWord, newWord);

	// OUTPUT RESULT...
	outFile << "*Result*" << endl << endl; //message displayed at beginning of OUT file...
	for (int i = 0; i < SIZE; i++)
	{
		outFile << phrase[i] << " ";
		if (i % 15 == 0 && i != 0)
		{
			outFile << endl;
		}
	}

	// FINISHED WITH OUT FILE...
	outFile.close(); //closes out file...

	system("pause");
	return 0;
}
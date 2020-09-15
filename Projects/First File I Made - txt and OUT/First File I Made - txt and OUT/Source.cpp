#include <iostream>
#include <iomanip> //can be used for formatting in later program modding
#include <string>
#include <fstream> //included for opening, reading, writing, and closing file
using namespace std;

int main()
{
	ifstream inFile;  //included for writing to file
	ofstream outFile; //included for reading file

					  /*variables should be changed to utilize arrays*/
	char athlete1Letter;
	double athlete1Time1, athlete1Time2, athlete1Time3, athlete1TotalTime;
	char athlete2Letter;
	double athlete2Time1, athlete2Time2, athlete2Time3, athlete2TotalTime;
	char athlete3Letter;
	double athlete3Time1, athlete3Time2, athlete3Time3, athlete3TotalTime;
	char athlete4Letter;
	double athlete4Time1, athlete4Time2, athlete4Time3, athlete4TotalTime;
	double avgTotalTime;

	inFile.open("racedat.txt");  //opens txt file for input - writing
	outFile.open("racedat.out"); //opens out file for output - reading

	cout << "Creating file with race data info...\n"; //message displayed when program is run

	outFile << "Enter athlete identifier followed by the 3 completion times for running, swimming, and biking.\n";
	outFile << "Do this 4 times for each of the 4 athletes with time entered in minutes...\n";
	inFile >> athlete1Letter >> athlete1Time1 >> athlete1Time2 >> athlete1Time3;
	inFile >> athlete2Letter >> athlete2Time1 >> athlete2Time2 >> athlete2Time3;
	inFile >> athlete3Letter >> athlete3Time1 >> athlete3Time2 >> athlete3Time3;
	inFile >> athlete4Letter >> athlete4Time1 >> athlete4Time2 >> athlete4Time3;

	/*calculations can be made cleaner with use of array*/
	athlete1TotalTime = athlete1Time1 + athlete1Time2 + athlete1Time3;
	athlete2TotalTime = athlete2Time1 + athlete2Time2 + athlete2Time3;
	athlete3TotalTime = athlete3Time1 + athlete3Time2 + athlete3Time3;
	athlete4TotalTime = athlete4Time1 + athlete4Time2 + athlete4Time3;
	avgTotalTime = (athlete1TotalTime + athlete2TotalTime + athlete3TotalTime + athlete4TotalTime) / 4;

	/*outputs will also look better with use of array*/
	outFile << athlete1Letter << " " << athlete1Time1 << " " << athlete1Time2 << " " << athlete1Time3 << " ";
	outFile << athlete2Letter << " " << athlete2Time1 << " " << athlete2Time2 << " " << athlete2Time3 << " ";
	outFile << athlete3Letter << " " << athlete3Time1 << " " << athlete3Time2 << " " << athlete3Time3 << " ";
	outFile << athlete4Letter << " " << athlete4Time1 << " " << athlete4Time2 << " " << athlete4Time3 << " \n";

	outFile << "Athlete " << athlete1Letter << " completed the race in a total of " << athlete1TotalTime << " minutes\n";
	outFile << "Athlete " << athlete2Letter << " completed the race in a total of " << athlete2TotalTime << " minutes\n";
	outFile << "Athlete " << athlete3Letter << " completed the race in a total of " << athlete3TotalTime << " minutes\n";
	outFile << "Athlete " << athlete4Letter << " completed the race in a total of " << athlete4TotalTime << " minutes\n";
	outFile << "The average total time for completing the race is " << avgTotalTime << " minutes\n";

	inFile.close();  //closes txt file
	outFile.close(); //closes out file

	system("pause");
	return 0;
}
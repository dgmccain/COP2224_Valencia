#include <iostream>
#include <string>
using namespace std;

int findAvgTestScores(int testScores[], const int SIZE) { //Function 1
	int scoresAvg = 0;
	int scoresTotal = 0;

	for (int i = 0; i < SIZE; i++) {
		scoresTotal += testScores[i];
	}

	scoresAvg = scoresTotal / SIZE;

	return scoresAvg;
}

int findBelowAvgScores(int testScores[], string students[], int avgScore, const int SIZE) { //Function 2
	int result[6] = { 0, 0, 0, 0, 0, 0, };
	int placeHolder = 0;

	for (int i = 0; i < SIZE; i++) {
		if (testScores[i] < avgScore) {
			result[i] = testScores[i];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (result[i] != 0) {
			cout << students[i] << " scored below average at " << testScores[i] << "%" << "\n";
		}
	}

	return placeHolder;
}

int findHighScore(int testScores[], const int SIZE) { //Function 3
	int highScore;
	int tempVal = 0;

	for (int i = 0; i < SIZE; i++) {
		if (tempVal < testScores[i]) {
			tempVal = testScores[i];
		}
	}
	highScore = tempVal;

	return highScore;
}

int findHighScoreStudents(int testScores[], string students[], int highScore, const int SIZE) { //Function 4
	int highScoreStudents = 0;

	for (int i = 0; i < SIZE; i++) {
		if (testScores[i] == highScore) {
			cout << students[i] << " had a high score of " << highScore << "%" << "\n";
		}
	}
	cout << "\n";

	return highScoreStudents;
}

int main() {
	const int SIZE = 6;
	int testScores[SIZE] = { 77, 48, 93, 68, 93, 81 }; //Numbers within array can be changed
	string students[SIZE] = { "Rachel", "Joe", "Ross", "Phoebe", "Chandler", "Monica" }; //Names in array can be changed
	int avgScores;
	int belowAvgScores;
	int highScore;
	string highScoreStudents;

	avgScores = findAvgTestScores(testScores, SIZE); //Function 1
	cout << "The scoring average is " << avgScores << "%" << "\n\n";
	belowAvgScores = findBelowAvgScores(testScores, students, avgScores, SIZE); //Function 2
	highScore = findHighScore(testScores, SIZE); //Function 3
	cout << "\nThe highest score is " << highScore << "%" << "\n\n";
	highScoreStudents = findHighScoreStudents(testScores, students, highScore, SIZE); //Function 4


	system("pause");
	return 0;
}
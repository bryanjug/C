#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Date: 10/8/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Grade Lab
*********************************************************************************************/
/*********************************************************************************************
Analysis

Inputs (data description your app accepts): any number of test scores

Outputs (data description data your program produces and in what formats): the average of the scores put into two decimal places

Constraints (list ALL found in problem statement): the range that the score is limited to is 0 to 100

Formulas (in any): take all the numbers and add them to find the average of the series

*********************************************************************************************/
/*********************************************************************************************
Design (Requires one level of step-wise refinement for all steps)

1.

*********************************************************************************************/
/*********************************************************************************************
Testing
1. Main Function repeats calculation 4 times
2. User Inputs a set of test grades
3. Outputs the 4 averages of the set series

*********************************************************************************************/
//Implementation starts here

#include <stdio.h>
#include <math.h>
#include <ctype.h>

FILE *fp;

int getUserScores();
int calculateSum(int sum);
int calculateScoreAmount(int scoreAmount);
int calculateAverage(int sum, int scoreAmount);

int main(void) {

	fp = fopen("csis.txt", "w");

		getUserScores(4);
		calculateAverage(4);

	fclose(fp);
	return 0;
}

int calculateSum(int sum) {
	int score1, score2, score3, score4;

	return sum = score1 + score2 + score3 + score4;
}

int calculateScoreAmount(int scoreAmount) {
	int score1;
	int score2;
	int score3;
	int score4;

	for (int i = 0; i < scoreAmount; ++i) {
		int newScore1;
		int newScore2;
		int newScore3;
		int newScore4;

		if (score1 > -1) {
			newScore1 = 1;
		}
		else if (score2 > -1) {
			newScore2 = 1;
		}
		else if (score3 > -1) {
			newScore3 = 1;
		}
		else if (score4 > -1) {
			newScore4 = 0;
		}
		else if (score2 == -1) {
			newScore2 = 0;
		}
		else if (score3 == -1) {
			newScore3 = 0;
		}
		else if (score4 == -1) {
			newScore4 = 0;
		}
		else if (score1 == -1) {
			newScore1 = 0;
		}
		return scoreAmount = newScore1 + newScore2 + newScore3 + newScore4;
	}
}

int getUserScores() {
	int score1, score2, score3, score4;

	do {
		printf("Enter the test scores to calculate the average: \n");
		fprintf(fp, "Enter the test scores to calculate the average: \n");
		scanf("%d %d %d %d\n", &score1, &score2, &score3, &score4);

		if (score1, score2, score3, score4 == -1);
			continue;

	} while (score1, score2, score3, score4 >= 0 || score1, score2, score3, score4 <= 100);

	return score1, score2, score3, score4;
}

int calculateAverage(int sum, int scoreAmount) {

	int average = sum / scoreAmount;

	printf("The average of the scores is: %d\n", average);
	fprintf(fp, "The average of the scores is: %d\n", average);

	fclose(fp);

	return 0;
}
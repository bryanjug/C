#define _CRT_SECURE_NO_WARNINGS

/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Student No.: 011333579
Date: 10/2/17
IDE version:
OS version:
Lab Assignment: BMI Lab
*********************************************************************************************/

/*********************************************************************************************

Analysis

Inputs (data description your app accepts): height and weight

Outputs (data description data your program produces and in what formats): BMI level and BMI number

Constraints (list ALL found in problem statement): theres are 4 different weight types: underweight, normal, overweight, and obese

Formulas (in any): (weight * 703) / (height * height)

*********************************************************************************************/

/*********************************************************************************************

Design (Requires one level of step-wise refinement for all steps)

*********************************************************************************************/

/*********************************************************************************************

Testing (Minimum of one test case)

*********************************************************************************************/

//Implementation starts here

#include <stdio.h>
#include <math.h>
#include <ctype.h>

FILE *fp;

float calculateBMI(float weight, float height);
void evaluateBMI();

int main(void) {
	int i;

	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		evaluateBMI();
	}
		fclose(fp);
		return 0;
}

float calculateBMI(float weight, float height) {
	float BMI = ((weight * 703) / (height * height));
	return BMI;
}

void evaluateBMI() {

	float BMI, weight, height;

	printf("Enter your weight in pounds and your height in inches to get your BMI value: ");
	fprintf(fp, "Enter your weight in pounds and your height in inches to get your BMI value: ");

	scanf("%f %f", &weight, &height);

	BMI = calculateBMI(weight, height);

	if (BMI < 18.5) {
		printf("Your BMI is considered Underweight. Your BMI is %f\n", BMI);
		fprintf(fp, "Your BMI is considered Underweight. Your BMI is %f\n", BMI);
	}
	else if (BMI >= 18.5 && BMI <= 25) {
		printf("Your BMI is considered Normal. Your BMI is %f\n", BMI);
		fprintf(fp, "Your BMI is considered normal. Your BMI is %f\n", BMI);
	}
	else if (BMI >= 25 && BMI <= 30) {
		printf("Your BMI is considered Overweight. Your BMI is %f\n", BMI);
		fprintf(fp, "Your BMI is considered overweight. Your BMI is %f\n", BMI);
	}
	else if (BMI >= 30) {
		printf("Your BMI is considered Obese. Your BMI is %f\n", BMI);
		fprintf(fp, "Your BMI is considered obese. Your BMI is %f\n", BMI);
	}
	else
		printf("An Error Occured.");
}
#define _CRT_SECURE_NO_WARNINGS

/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Student No.: 011333579
Date: 10/2/17
IDE version:
OS version:
Lab Assignment: Fibonacci Lab
*********************************************************************************************/

/*********************************************************************************************

Analysis

Inputs (data description your app accepts): first two numbers ( 0, 1 )

Outputs (data description data your program produces and in what formats): first 20 fibonacci numbers

Constraints (list ALL found in problem statement): the series must start adding after ( 0, 1 )

Formulas (in any): take the last two numbers and add them to find the next number in the series

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

FILE * output;

int fibCalculation(int fib);

int main() {
	int firstNumber = 0, c, fib;
	printf("Enter the number of fibonacci numbers in the series: \n");
	scanf("%d", &fib);
	output = fopen("csis.txt", "w");
	fprintf(output, "Enter the number of fibonacci numbers in the series: \n");

	printf("The total of %d numbers from the fibonacci series are: \n", fib);
	fprintf(output, "The total of %d numbers from the fibonacci series are: \n", fib);

	for (c = 1; c <= fib; c++) {
		printf("%d\n", fibCalculation(firstNumber));
		fprintf(output, "%d\n", fibCalculation(firstNumber));
		firstNumber++;
	}
	fclose(output);
	return 0;
}

int fibCalculation(int fib) {
	if (fib == 0)
		return 0;
	else if (fib == 1)
		return 1;
	else
		return(fibCalculation(fib - 1) + fibCalculation(fib - 2));
}
#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Student No.: 011333579
Date: 11/5/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Decode Lab
*********************************************************************************************/

/*********************************************************************************************

Analysis

Inputs (data description your app accepts):

1. A scrambled message is given.

Outputs (data description data your program produces and in what formats):

1. The message becomes unscrambled.

Constraints (list ALL found in problem statement):

1. The unscrambled message's letters define a number assignment.
2. This number assignment is assigned a 3 digit sequence number, in rising order, to go before it.
3. The numbers indicate the potition.
4. The numbers do not need to be in order.

Formulas (in any):

(int[array])left > (int[array])right;

*********************************************************************************************/

/*********************************************************************************************
Design (Requires one level of step-wise refinement for all steps)

1. read the numbers into an array and sort them into rising order
2. Cut each sorted number into two
3. Using the last two digits (modulus operator) as the index to the correct character
4. print the characters in the correct order
5. display to user which order is the encoded/decoded message

*********************************************************************************************/

/*********************************************************************************************

Testing (Minimum of one test case)

1. input
1.1 1954614501173091302716149215121803514014157001251516514182071340714837168422103715333132442122416321141461601420727128041881113711

2. output
2.1 CFL2AP(T9W,H!JEM86ND0BZ7UK1Y3VG4XR)ISOQ5.         ;-

*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 26

FILE *fp;

void displayNumbers(int[], int);
int compareIntArray(const void *, const void *);
void displayEncoded();
void displayDecoded();

int main() {

	fp = fopen("csis.txt", "w");

	int numbers[LENGTH] = { 19546, 14501, 17309, 13027, 16149, 21512, 18035, 14014, 15700, 12515, 16514, 18207, 13407, 14837, 16842, 21037, 15333, 13244, 21224, 16321, 14146, 16014, 20727, 12804, 18811, 13711 };

	displayEncoded();
	displayNumbers(numbers, LENGTH);
	qsort(numbers, LENGTH, sizeof(int), compareIntArray);
	displayDecoded();
	displayNumbers(numbers, LENGTH);

	fclose(fp);
	return 0;
}
	//Cut each sorted number into two using the last 2 digits (modulus operator) as the index to the correct character
void displayNumbers(int buffer[], int size) { //array, size of array
	for (int index = 0; index < size; index++) {
		printf("%d\n", buffer[index]); //sort into ascending order
		fprintf(fp, "%d\n", buffer[index]);
	}
}

int compareIntArray(const void *left, const void *right) { //sets the array to a new address
	if (*(int *)left < *(int *)right)
		return -1;
	return *(int *)left > *(int *)right;
} //char *strrev(char *s1);

void displayEncoded() { //prints the intructions to the code

	printf("Here is the encoded list of results:\n");
	fprintf(fp, "Here is the encoded list of results:\n");
}

void displayDecoded() {
	printf("Here is the decoded list of results:\n");
	fprintf(fp, "Here is the decoded list of results:\n");
} 
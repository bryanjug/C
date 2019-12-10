#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Stefan Einoder, Bryan Jug, Kervens Louis-juste, Christian Morrison
Student No.: 011333579
Date: 11/12/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Statistics Lab
*********************************************************************************************/

/*********************************************************************************************

Analysis
Inputs (data description your app accepts):
1. getty_textstatlab.txt file
2.
3.
Outputs (data description data your program produces and in what formats):
1. Number of lines in text
2. Number of words in text
3. Avg. length of all words in text
4. Histogram of length of words in text
5. Number of characters in text (excluding blanks and punctuation)
6. Table showing frequency of each letter in text
7. Frequency of each vowel in the text as a percentage of the total number of vowels read
Constraints (list ALL found in problem statement):
1. Program named stats.c
2. Get input from getty_textstatlab.txt text file
3. Main() function should appear as the first function
4. Create function prototypes for each function used in our program
5. Send output to stdout and csis.txt
6. Do error checking when opening a file
Formulas (in any):
1.
2.
3.
*********************************************************************************************/
/*********************************************************************************************
Design (Requires one level of step-wise refinement for all steps)
1. Count number of lines in text
1.1 Create char variable 'ch'
1.2 Create loop with int variable 'linecount = 0'
1.2.1 Read file
1.2.2 Each time 'ch' is a new line (\n), increment 'linecount' (++linecount)
1.2.3 Stop when end of file (EOF) is reached
2. Count number of words in text
2.1 Create char variable 'ch'
2.2 Create loop with int variable 'wordcount = 0'
2.2.1 Read file
2.2.2 Each time 'ch' is a space (' '), increment 'wordcount' (++wordcount)
2.2.3 Stop when end of file (EOF) is reached
3. Calculate avg. length of all words in text
3.1
4. Display histogram of length of words in text
4.1
5. Count number of characters in text (excluding blanks and punctuation)
5.1 Create char variable 'ch'
5.2 Create loop with int variable 'charcount = 0'
5.2.1 Read file
5.2.2 Each time 'ch' is NOT a space (' ') and NOT a new line (\n), increment 'charcount' (++charcount)
5.2.3 Stop when end of file (EOF) is reached
6. Display table showing frequency of each letter in text
6.1
7. Count number of vowels in text and output frequency of each vowel as a percentage of total # of vowels
*********************************************************************************************/
/*********************************************************************************************
Testing (Minimum of one test case)
1. Expected input:
getty_textstatlab.txt
2. Expected output (result):
# of lines:  30
# of words:  242
avg length of all words in text: 4.69
histogram:
# of characters: 1134
frequency of each letter:    a-100, b-14, c-31, d-54, e-165, f-25, g-26, h-79, i-69, j-0, k-3, l-41, m-13, n-76, o-91, p-16, q-0, r-81, s-45, t-124, u-20, v-23, w-27, x-0, y-10, z-0
% frequency of each vowel:   a-22%, e-37%, i-16%, 0-20%, u-5%   445
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void numberLines();// Tells you how many lines there are in given file
void numberWords();// Tells you how many words there are in givne file
void wordLength(int[], int); // tells you how many words of each length there are
void averageLength(int[], int); //calculates average length of all words in text to nearest decimal
void histogram(int[], int);  //prints histogram of letters
void frequencyOfCharacters();
void totalCharacters();
void numberVowels();

#define FILE_READ "getty_textstatlab.txt"
#define WORD 12
#define VOWEL 5  // used for matrix that holds the vowels
#define PERCENT 100 //used when calculating percentage
#define ALL 256  // used in matrix that stores all ASCii characters encountered

FILE *fp;
FILE *fpout;

int main(void) {

	static int length[WORD];

	fpout = fopen("csis.txt", "w");
	fp = fopen(FILE_READ, "r");

	numberLines();
	numberWords();
	wordLength(length, WORD);
	averageLength(length, WORD);
	histogram(length, WORD);
	totalCharacters();
	frequencyOfCharacters();
	numberVowels();

	fclose(fp);
	fclose(fpout);
	return 0;
}

void numberLines() {
	int lines = 1;
	char c;

	fp = fopen(FILE_READ, "r");
	while ((c = getc(fp)) != EOF)
	{
		if (c == '\n')
		{
			++lines;
		}

	}
	printf("There are %d lines in this document.\n", lines);
	fprintf(fpout, "There are %d lines in this document.\n", lines);
	fclose(fp);
}

void numberWords() {
	int words = 0;
	char character;
	fp = fopen(FILE_READ, "r");
	while ((character = getc(fp)) != EOF)
	{
		if (ispunct(character) || isspace(character))
		{
			while (ispunct(character) || isspace(character))
			{
				character = getc(fp);
			}
			++words;
		}
	}
	printf("There are %d words in this passage.\n", words);
	fprintf(fpout, "There are %d words in this passage.\n", words);
	fclose(fp);
}

void wordLength(int length[], int max) {

	char character;
	int size = 1;
	fp = fopen(FILE_READ, "r");
	while ((character = getc(fp)) != EOF)
	{
		if (ispunct(character) || isspace(character))
		{
			while (ispunct(character) || isspace(character))
			{
				character = getc(fp);
			}
			length[size]++;
			size = 0;
		}
		++size;
	}
	fclose(fp);
}

void averageLength(int list[], int max) {
	float sum = 0, number = 0;
	float average;
	for (int i = 1; i < WORD; i++)
	{
		sum += list[i];
	}
	for (int i = 1; i < WORD; i++)
	{
		number += (i*list[i]);
	}
	average = number / sum;
	printf("The average length of the words in this text is %.0lf letters\n", average);
	fprintf(fpout, "The average length of the words in this text is %.0lf letters\n", average);
}

void histogram(int list[], int max) {

	for (int i = 1, j = 0; i < WORD; i++)
	{
		printf("%2d: %3d ", i, list[i]);
		while (j < list[i])
		{
			printf("*");
			++j;
		}
		j = 0;
		printf("\n");
	}
}

void frequencyOfCharacters() {

	static int letter[256];

	int ch; //number of characters seen, character or EOF flag from input
	int i;

	FILE *fp = fopen(FILE_READ, "r"); //input file

	while ((ch = getc(fp)) != EOF) {
		if (isupper(ch) || islower(ch)) {
				letter[ch] += 1;
		}
	}

	printf("Here is the frequency of each letter:\n");
	fprintf(fpout, "Here is the frequency of each letter:\n");

	for (i = 'A'; i < 'Z'; ++i) {
		if (letter[i] != 0) {
			printf("%c - %d\n", i, letter[i]);
		}
	}

	for (i = 'a'; i < 'z'; ++i) {
		if (letter[i] != 0) {
			printf("%c - %d\n", i, letter[i]);
		}
	}

	fclose(fp);
}

void totalCharacters() {

	int totalCounter = 0; int ch, i; //number of characters seen, character or EOF flag from input
	static int letter[256];

	FILE *fp = fopen(FILE_READ, "r"); //input file

	while (1) {
		ch = fgetc(fp);

		if (ch == EOF)
			break;
		else if (isupper(ch) || islower(ch)) {
			letter[ch] += 1;
			++totalCounter;
		}
	}
	printf("The total amount of characters is: %d\n", totalCounter);
	fprintf(fpout, "The total amount of characters is: %d\n", totalCounter);

	fclose(fp);
}

void numberVowels()
{
	char vowels[] = { "AEIOU" };   //3 paralel matrices    first holds vowel characters
	static float count[VOWEL];   // holds how many times each vowel occur
	static float percent[VOWEL];  //holds percentage of total for each vowel
	char character;  // hold current scanned character
	float sum = 0;  // used to sum total number of vowels

	if (!(fp = fopen(FILE_READ, "r")))
	{
		printf(".txt file could not be opened.\n");
		exit(1);
	}

	while ((character = getc(fp)) != EOF) //scans each character
	{

		character = toupper(character); //turns all lower case to upper case
		switch (character) // switch  increments vowel count for which ever one occurs. Ignores everything else
		{
		case 'A': count[0]++;
			break;
		case 'E': count[1]++;
			break;
		case 'I': count[2]++;
			break;
		case 'O': count[3]++;
			break;
		case 'U': count[4]++;
			break;
		}
	}

	for (int i = 0; i < VOWEL; i++)// loop sums up all vowel occurance in count array
	{
		sum += count[i];
	}

	printf("There are %.0lf vowels in this passage\n", sum);
	fprintf(fpout, "There are %.0lf vowels in this passage\n", sum);
	for (int i = 0; i < VOWEL; i++)  //loop calculates percent of total for each vowel and populates percent array
	{
		percent[i] = (count[i] / sum)*PERCENT;
	}

	printf("Vowel\t frequency\t Percent of total\n");
	fprintf(fpout, "Vowel\t frequency\t Percent of total\n");

	for (int i = 0; i < VOWEL; i++)
	{
		printf("%c\t", vowels[i]);
		fprintf(fpout, "%c\t", vowels[i]);

		printf("%6.0lf\t\t\t", count[i]);
		fprintf(fpout, "%6.0lf\t\t\t", count[i]);

		printf("%.2lf\n", percent[i]);
		fprintf(fpout, "%.2lf\n", percent[i]);
	}

	fclose(fp);
}
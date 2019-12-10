#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Student No.: 011333579
Date: 12/10/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Database Lab
*********************************************************************************************/

/*********************************************************************************************

Analysis

Inputs (data description your app accepts):

1. calendar date
2. julian date
3. two calendar dates

Outputs (data description data your program produces and in what formats):

1. calendar date
2. julian date
3. days between two calendar dates

Constraints (list ALL found in problem statement):

1. Ask the user which option to take

Formulas (in any):

int isLeapYear(int year) {
return ((!(year % 4) && year % 100) || !(year % 400));
}

*********************************************************************************************/

/*********************************************************************************************
Design (Requires one level of step-wise refinement for all steps)

1. display menu is showing 4 different parts to choose from
2. asks the user for the calender date and the julian date
3. convert each of these values into each other
4. take two different dates and compare the length of days between the two

*********************************************************************************************/

/*********************************************************************************************

Testing (Minimum of one test case)

1. user inputs a calendar date, a julian date, and two new calendar dates
2. finds the conversion of calendar to julian, and julian to calendar dates. The two new calendar dates are compared and given a number of days between each date.

*********************************************************************************************/\

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define SIZE 14 

FILE *fpout;

typedef struct {
	char fname[7];
	char initial[2];
	char lname[10];
	char street[17];
	char city[12];
	char state[3];
	char zip[6];
	int age;
	char sex[2];
	int tenure; //years of employment
	double salary; //weekly salary

}Employee;

int main(void);
void foo(Employee totalEmployees[]);
void firstLastNames(Employee totalEmployees[]);
void highestPaidFemale(Employee totalEmployees[]);
void lowestPaidMale(Employee totalEmployees[]);
void averageSalary(Employee totalEmployees[]);
void nameLowWoman(Employee totalEmployees[]);
void ratioManToMan(Employee totalEmployees[]);
void veteranEmployees(Employee totalEmployees[]);
void raiseLowWages(Employee totalEmployees[]);

int main(void) {
	fpout = fopen("csis.txt", "w");

	printf("Here's an example of a basic structure (payfile.txt):\n");

	Employee totalEmployees[SIZE] = {
		{ "ADA", "A", "AGUSTA", "33 BABBAGE ROAD", "LOVELACE", "GB", "19569", 28, "F", 2, 350.50 },
		{ "ISSAC",   "A", "ASIMOV",    "99 FICTION WAY",   "AMHERST",     "MA", "63948", 58, "M", 6, 423.88 },
		{ "HUMPHRY", "R", "BOGART",    "71 SAM STREET",    "HOLLYWOOD",   "CA", "48482", 56, "M", 5, 366.00 },
		{ "ALBERT",  "G", "EINSTEIN",  "94 ENERGY WAY",    "PRINCETON",   "NJ", "47474", 67, "M", 8, 780.00 },
		{ "EMMYLOU", "L", "HARRIS",    "66 COUNTRY ROAD",  "NASHVILLE",   "TN", "72647", 38, "F", 2, 767.42 },
		{ "JAMES",   "T", "KIRK",      "11 SPACE STREET",  "VULCAN",      "CA", "82828", 46, "M", 1, 235.70 },
		{ "TED",     "L", "KOPPEL",    "55 ABC PLACE",     "WASHINGTON",  "DC", "37376", 48, "M", 9, 909.44 },
		{ "DAVID",   "T", "LETTERMAN", "14 WNBC AVENUE",   "NEW YORK",    "NY", "19338", 47, "M", 5, 445.65 },
		{ "STEVIE",  "R", "NICKS",     "31 MUSIC ROAD",    "CHICAGO",     "IL", "23459", 38, "F", 8, 460.88 },
		{ "MONTY",   "P", "PYTHON",    "76 SILLY STREET",  "LONDON",      "GB", "80939", 44, "M", 2, 320.50 },
		{ "ROGER",   "R", "RABBIT",    "15 LOONEY TOONS",  "HOLLYWOOD",   "CA", "91343", 24, "M", 4, 259.53 },
		{ "SALLY",   "W", "RIDE",      "21 COLUMBIA WAY",  "HOUSTON",     "TX", "91123", 30, "F", 9, 707.80 },
		{ "ROD",     "Q", "SERLING",   "11 TWLIGHT ZONE",  "SAN DIEGO",   "CA", "93939", 56, "M", 1, 440.00 },
		{ "LUKE",    "R", "SKYWALKER", "43 MILKY WAY",     "NEW YORK",    "NY", "12343", 35, "M", 5, 660.00 }
	}; //put payfile.txt into an array of structures similar to the file

	foo(totalEmployees);
	firstLastNames(totalEmployees);
	highestPaidFemale(totalEmployees);
	lowestPaidMale(totalEmployees);
	averageSalary(totalEmployees);
	nameLowWoman(totalEmployees);
	ratioManToMan(totalEmployees);
	veteranEmployees(totalEmployees);
	raiseLowWages(totalEmployees);

	fclose(fpout);
	return 0;
}

void foo(Employee totalEmployees[]) {
	int i;

	for (i = 0; i < SIZE; ++i) {
		printf("%10s %5s %10s %20s %15s %10s %10s %10d %10s %10d %10.2f\n", totalEmployees[i].fname, totalEmployees[i].initial, totalEmployees[i].lname,
			totalEmployees[i].street, totalEmployees[i].city, totalEmployees[i].state, totalEmployees[i].zip, totalEmployees[i].age, totalEmployees[i].sex,
			totalEmployees[i].tenure, totalEmployees[i].salary);
		fprintf(fpout, "%10s %5s %10s %20s %15s %10s %10s %10d %10s %10d %10.2f\n", totalEmployees[i].fname, totalEmployees[i].initial, totalEmployees[i].lname,
			totalEmployees[i].street, totalEmployees[i].city, totalEmployees[i].state, totalEmployees[i].zip, totalEmployees[i].age, totalEmployees[i].sex,
			totalEmployees[i].tenure, totalEmployees[i].salary);
	}
}

void firstLastNames(Employee totalEmployees[]) { //output first and last name of men on the payroll
	printf("Here's the list of all the male employees' first and last names:\n");
	fprintf(fpout, "Here's the list of all the male employees' first and last names:\n");
	int i;
	char Male;
	char myStr[] = "M";
	for (i = 0; i < SIZE; ++i) {
		if (Male = strstr(totalEmployees[i].sex, myStr)) {
			printf("%10s %10s\n", totalEmployees[i].fname, totalEmployees[i].lname);
			fprintf(fpout, "%10s %10s\n", totalEmployees[i].fname, totalEmployees[i].lname);
		}
		else
			continue;
	} 
}

void highestPaidFemale(Employee totalEmployees[]) { //output first/last name of highest paid woman
	printf("The highest paid female of the payroll is:\n");
	fprintf(fpout, "The highest paid female of the payroll is:\n");

	int i;
	char Female;
	char myStr[] = "F";
	double largest = totalEmployees[0].salary;

	for (i = 0; i < SIZE; ++i) {
		if (Female = strstr(totalEmployees[i].sex, myStr)) {
			if (totalEmployees[i].salary > largest) {
				printf("%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
				fprintf(fpout, "%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
			}
		}
		else
			continue;
	}
}

void lowestPaidMale(Employee totalEmployees[]) {
	printf("The lowest paid male of the payroll is:\n");
	fprintf(fpout, "The lowest paid male of the payroll is:\n");
	int i;
	char Male;
	char myStr[] = "M";
	double largest = totalEmployees[0].salary;

	for (i = 0; i < SIZE; ++i) {
		if (Male = strstr(totalEmployees[i].sex, myStr)) {
			if (totalEmployees[i].salary < largest) {
				printf("%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
				fprintf(fpout, "%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
			}
		}
		else
			continue;
	}
}

void averageSalary(Employee totalEmployees[]) { //output average salary
	int i;
	double average;
	double sum = 0;

	printf("The average salary between all the employers of the payroll is: ");
	fprintf(fpout, "The average salary between all the employers of the payroll is: ");

	for (i = 0; i <= SIZE; i++) {
		sum = sum + totalEmployees[i].salary;
	}

	average = sum / SIZE;

	printf("%.2f.\n", average);
	fprintf(fpout, "%.2f.\n", average);
}

void nameLowWoman(Employee totalEmployees[]) { //output first/last name of all women earning less than half the average salary
	int i;
	char Female;
	char myStr[] = "F";
	double largest = totalEmployees[0].salary;

	printf("The women who are earning less than half the average salary are:\n ");
	fprintf(fpout, "The women who are earning less than half the average salary are:\n ");

	for (i = 0; i < SIZE; ++i) {
		if (Female = strstr(totalEmployees[i].sex, myStr)) {
			if (totalEmployees[i].salary < 509) {
				printf("%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
				fprintf(fpout, "%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
			}
		}
		else
			continue;
	}
}

void ratioManToMan(Employee totalEmployees[]) { //output (1000th) of the ratio of men above the average salary to men below the average salary
	int i;
	char Male;
	char myStr[] = "M";
	double largest = totalEmployees[0].salary;
	double lowerCount = 0;
	double upperCount = 0;
	double ratio;

	for (i = 0; i < SIZE; ++i) {
		if (Male = strstr(totalEmployees[i].sex, myStr)) {
			if (totalEmployees[i].salary < 509) {
				lowerCount++;

			}
			else if (totalEmployees[i].salary > 509) {
				upperCount++;

			}
		}
		else
			continue;
	}

	ratio = upperCount / lowerCount;

	printf("The ratio of men above the average salary to men below the average pay salary is 1 : %.3f.\n", ratio);
	fprintf(fpout, "The ratio of men above the average salary to men below the average pay salary is 1 : %.3f.\n", ratio);
}

void veteranEmployees(Employee totalEmployees[]) { //output first/last name of employees who make more than 35k p/year, have been with the company for 5 years, and who are over 30 years old
	int i;
	double salaryYear;
	printf("The first and last names of the employees who make more than 35k per year, have been with the company for 5 years, and who are over 30 years old:\n");
	fprintf(fpout, "The first and last names of the employees who make more than 35k per year, have been with the company for 5 years, and who are over 30 years old:\n");

	for (i = 0; i < SIZE; ++i) {
		salaryYear = (totalEmployees[i].salary * 52);

		if (salaryYear > 35000) {
			if (totalEmployees[i].tenure >= 5) {
				if (totalEmployees[i].age > 30) {
					printf("%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
					fprintf(fpout, "%s %s\n", totalEmployees[i].fname, totalEmployees[i].lname);
				}
			}
		}
	}
}

void raiseLowWages(Employee totalEmployees[]) { //give 10% raise to those who make less than $350 p/week, and output the first/last names of those who received it
	int i;
	double raisedAccPercentage, raisedAccTotal;

	printf("A 10%% raise is given to those who make less than $350 p/week, and their first/last names of those who received it are displayed:\n");
	fprintf(fpout, "A 10%% raise is given to those who make less than $350 p/week, and their first/last names of those who received it are displayed:\n");

	for (i = 0; i < SIZE; ++i) {
		if (totalEmployees[i].salary < 350) {
			raisedAccPercentage = 0.1 * totalEmployees[i].salary;
			raisedAccTotal = raisedAccPercentage + totalEmployees[i].salary;

			printf("%10s %10s %.2f\n", totalEmployees[i].fname, totalEmployees[i].lname, raisedAccTotal);
			fprintf(fpout, "%10s %10s %.2f\n", totalEmployees[i].fname, totalEmployees[i].lname, raisedAccTotal);
		}
	}
}
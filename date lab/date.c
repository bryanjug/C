#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug
Student No.: 011333579
Date: 10/22/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Date Lab
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

*********************************************************************************************/

#include <stdio.h>
#include <math.h>

FILE *output;

int displayMenu();
int getCalendarDate();
int getJulianDate();
int toCalendar(int julianDate, int julianYear, int leapYear);
int toJulian(int calendarDay, int calendarMonth, int calendarYear, int leapYear, int julianDateTotal);
int daysBetweenDates(int julianDate, int calendarYear, int calendarDayTotal, int calendarMonth, int calendarDay, int julianYear, int julianDateTotal);
int isLeapYear(int year);

int main() {

	int endCondition = 0;

	output = fopen("csis.txt", "w");

	displayMenu();
	getCalendarDate();
	getJulianDate();
	int toCalendar(int julianDate, int julianYear, int leapYear);
	int toJulian(int calendarDay, int calendarMonth, int calendarYear, int leapYear, int julianDateTotal);
	int daysBetweenDates(int julianDate, int calendarYear, int calendarDayTotal, int calendarMonth, int calendarDay, int julianYear, int julianDateTotal);
	int isLeapYear(int year);

	fclose(output);
	return 0;
}

int displayMenu() { //displays selection menu and prompts user for selection

	int selection;

	printf("DATE SELECTION MENU\n");
	fprintf(output, "DATE SELECTION MENU\n");

	do {
		printf("1. Convert calendar date into Julian date\n");
		fprintf(output, "1. Convert calendar date into Julian date\n");

		printf("2. Convert Julian date into calendar date\n");
		fprintf(output, "2. Convert Julian date into calendar date\n");

		printf("3. Compute days between two calendar dates\n");
		fprintf(output, "3. Compute days between two calendar dates\n");

		printf("4. Exit program\n");
		fprintf(output, "4. Exit program\n");

		scanf("ENTER SELECTION (1 - 4): %d\n", &selection);

	} while (selection == 4); //runs != 0 to terminate command on exit

	return 0;
}

int getCalendarDate() { //prompts and gets Calendar date from user

	int calendarDay, calendarMonth, calendarYear;

	printf("What is the calendar date you would like to convert to Julian date?\n");
	scanf("%d %d %d\n", &calendarDay, &calendarMonth, &calendarYear);

	return calendarDay, calendarMonth, calendarYear;
}

int getJulianDate() { //prompts and gets Julian date from user

	int julianDate, julianYear;

	printf("What is the Julian date you would like to convert to calendar date?\n");
	scanf("%d %d\n", &julianDate, &julianYear);

	return julianDate, julianYear;
}

int toCalendar(int julianDate, int julianYear, int leapYear) { //converts Julian Date into calendar date

	int calendarDay, calendarMonth, calendarDayTotal;

	calendarDay = julianDate;

	while (1 < julianDate < 366) {
		continue;
	}

	if (julianDate < 31) {
		int calendarDayTotal = calendarDay / 1;
		int calendarMonth = 1;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 31) {
		int calendarDayTotal = calendarDay / 2;
		int calendarMonth = 2;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 59) {
		int calendarDayTotal = calendarDay / 3;
		int calendarMonth = 3;
		return calendarMonth, calendarDayTotal;
	}

	else if ((julianDate > 60) && (julianYear = leapYear)) {
		int calendarDayTotal = calendarDay / 3;
		int calendarMonth = 3;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 90) {
		int calendarDayTotal = calendarDay / 4;
		int calendarMonth = 4;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 120) {
		int calendarDayTotal = calendarDay / 5;
		int calendarMonth = 5;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 151) {
		int calendarDayTotal = calendarDay / 6;
		int calendarMonth = 6;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 181) {
		int calendarDayTotal = calendarDay / 7;
		int calendarMonth = 7;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 212) {
		int calendarDayTotal = calendarDay / 8;
		int calendarMonth = 8;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 243) {
		int calendarDayTotal = calendarDay / 9;
		int calendarMonth = 9;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 273) {
		int calendarDayTotal = calendarDay / 10;
		int calendarMonth = 10;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 304) {
		int calendarDayTotal = calendarDay / 11;
		int calendarMonth = 11;
		return calendarMonth, calendarDayTotal;
	}

	else if (julianDate > 334) {
		int calendarDayTotal = calendarDay / 12;
		int calendarMonth = 12;
		return calendarMonth, calendarDayTotal;
	}

	return 0;
}

int toJulian(int calendarDay, int calendarMonth, int calendarYear, int leapYear, int julianDateTotal) { //converts calendar date into Julian Date

	int calendarMonth2, calendarMonth3, calendarMonth4, calendarMonth5, calendarMonth6, calendarMonth7, calendarMonth8, calendarMonth9, calendarMonth10, calendarMonth11, calendarMonth12;
	int calendarMonth1 = 31;
	int month;

	if (calendarMonth = 1) {
		calendarMonth1 = 0;
		month = calendarMonth1;
		julianDateTotal = (calendarDay + calendarMonth1);
		return julianDateTotal, month;
	}

	else if (calendarMonth = 2) {

		int calendarMonth2 = 28;
		month = calendarMonth2;
		julianDateTotal = (calendarDay + calendarMonth1);
		return calendarMonth2, julianDateTotal, month;
	}

	else if ((calendarMonth = 2) && (calendarYear = leapYear)) {

		int calendarMonth2 = 28;
		month = calendarMonth2;
		julianDateTotal = (calendarDay + calendarMonth1);
		return calendarMonth2, julianDateTotal, month;
	}

	else if (calendarMonth = 3) {

		int calendarMonth3 = (calendarMonth1 + calendarMonth2);
		month = calendarMonth3;
		julianDateTotal = (calendarDay + (calendarMonth3));
		return calendarMonth3, julianDateTotal, month;
	}

	else if (calendarMonth = 4) {
		
		int calendarMonth4 = calendarMonth1 + calendarMonth2 + calendarMonth3;
		month = calendarMonth4;
		julianDateTotal = (calendarDay + (calendarMonth4));
		return calendarMonth4, julianDateTotal, month;
	}

	else if (calendarMonth = 5) {

		int calendarMonth5 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4;
		month = calendarMonth5;
		julianDateTotal = (calendarDay + (calendarMonth5));
		return calendarMonth5, julianDateTotal, month;
	}

	else if (calendarMonth = 6) {

		int calendarMonth6 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5;
		month = calendarMonth6;
		julianDateTotal = (calendarDay + (calendarMonth6));
		return calendarMonth6, julianDateTotal, month;
	}

	else if (calendarMonth = 7) {

		int calendarMonth7 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6;
		month = calendarMonth7;
		julianDateTotal = (calendarDay + (calendarMonth7));
		return calendarMonth7, julianDateTotal, month;
	}

	else if (calendarMonth = 8) {

		int calendarMonth8 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6 + calendarMonth7;
		month = calendarMonth8;
		julianDateTotal = (calendarDay + (calendarMonth8));
		return calendarMonth8, julianDateTotal, month;
	}

	else if (calendarMonth = 9) {

		int calendarMonth9 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6 + calendarMonth7 + calendarMonth8;
		month = calendarMonth9;
		julianDateTotal = (calendarDay + (calendarMonth9));
		return calendarMonth9, julianDateTotal, month;
	}

	else if (calendarMonth = 10) {

		int calendarMonth10 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6 + calendarMonth7 + calendarMonth8 + calendarMonth9;
		month = calendarMonth10;
		julianDateTotal = (calendarDay + (calendarMonth10));
		return calendarMonth10, julianDateTotal, month;
	}

	else if (calendarMonth = 11) {

		int calendarMonth11 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6 + calendarMonth7 + calendarMonth8 + calendarMonth9 + calendarMonth10;
		month = calendarMonth11;
		julianDateTotal = (calendarDay + (calendarMonth11));
		return calendarMonth11, julianDateTotal, month;
	}

	else if (calendarMonth = 12) {

		int calendarMonth12 = calendarMonth1 + calendarMonth2 + calendarMonth3 + calendarMonth4 + calendarMonth5 + calendarMonth6 + calendarMonth7 + calendarMonth8 + calendarMonth9 + calendarMonth10 + calendarMonth11;
		month = calendarMonth12;
		julianDateTotal = (calendarDay + (calendarMonth12));
		return calendarMonth12, julianDateTotal, month;
	}

	return 0;
}

int daysBetweenDates(int julianDate, int calendarYear, int calendarDayTotal, int calendarMonth, int calendarDay, int julianYear, int julianDateTotal) { //calculates the number of days between two calendar dates

	int newDay, newMonth, newYear, day2, month2, year2;

	printf("Enter two dates to find the number of days between them: \n");
	scanf("%d %d %d		%d %d %d", &newDay, &newMonth, &newYear, &day2, &month2, &year2);

	double firstSum = (newDay + (newMonth * 30) + (newYear * 365.26));
	double secondSum = (day2 + (month2 * 30) + (year2 * 365.26));

	int daysTotal = firstSum - secondSum;

	printf("Convert Calendar Date Into Julian Date\n");
	fprintf(output, "Convert Calendar Date Into Julian Date\n");
	printf("%d %d %d	(%d, %d)\n", calendarDay, calendarMonth, julianYear, julianDateTotal, julianYear);
	fprintf(output, "%d %d %d	(%d, %d)\n", calendarDay, calendarMonth, julianYear, julianDateTotal, julianYear);

	printf("Convert Julian Date Into Calendar Date\n");
	fprintf(output, "Convert Julian Date Into Calendar Date\n");
	printf("%d %d		(%d, %d, %d)\n", julianDate, calendarYear, calendarDayTotal, calendarMonth, calendarYear);
	fprintf(output, "%d %d		(%d, %d, %d)\n", julianDate, calendarYear, calendarDayTotal, calendarMonth, calendarYear);

	printf("Compute Number of Days Between Two Calendar Dates\n");
	fprintf(output, "Compute Number of Days Between Two Calendar Dates\n");
	printf("%d %d %d  %d %d %d  (%d)\n", newDay, newMonth, newYear, day2, month2, year2, daysTotal);
	fprintf(output, "%d %d %d  %d %d %d  (%d)\n", newDay, newMonth, newYear, day2, month2, year2, daysTotal);

	return 0;
}

int isLeapYear(int year) {

	int leapYear;

	return leapYear = ((!(year % 4) && year % 100) || !(year % 400));
}
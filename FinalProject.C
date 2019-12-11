Array = continuous and touching block of memory
Block will hold a value, sub[0] = first, sub[1] = second
Last element = array size - 1
Offset = 4 bits over to find the next element
Each is a 4 bit array
Each block is the same size
Array is only passed by reference, not value
What does it cost to, passing an array, when to pass an array, parallel arrays, 2D arrays, memorize sorting, binary search, qsort
Create an array
<data type> <array name> [<size>];
= integrals, floating point types
= good variable name
= size always in [brac kets] with real #s (cannot change)
Char gradeBuffer[4]; float gradeBuffer[4]; //creates an array size of 4
Use macro constant if we need to declare a constant: #define SIZE 4
Char gradeBuffer[SIZE]; float gradeBuffer[SIZE];
Garbage value when you first declare the array //value with no return
Assigning values to an array element?
#define SIZE 4

Char gradeBuffer[SIZE];
gradeBuffer[0] = 'c';
gradeBuffer[1] = 'd';
gradeBuffer[2] = 'a';
gradeBuffer[3] = 'a';
Array elements can be apart of an expression:
gradeBuffer[0] += 1;
What is the value of gradeBuffer[0]?
'D'
How to assign to an array element using initialization?
<array name> [<index>] = (comma separated list); //leaving the [] blank = sets size array through the values in ()
[50] = 50 array elements
(all counted) = array elements, once ran out, it'll count 0's
Char gradeBuffer[] = {'c', 'd', 'a', 'a'};
Char gradeBuffer[SIZE] = {'c'};

How to read values from an array and assign it to a variable?
Char grade1 = gradeBuffer[0];
Grade1 = 'c';

int main() {
	int i_array[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //grabs an array list

	for (size_t i = 0; i < SIZE; ++i) {
		printf("%d", i_array[i]);
	}
	int *begining = i_array;
	int *end = i_array + SIZE;
}

Example: #include <stdio.h>
#define MAX 5

int main() { //declare an array of floats to store grades

	float gradeBuffer[MAX];
	float gradeBuffer1[MAX] = { 98.2, 75.4, 60.5, 77.0, 99.5 };
	float gradeBuffer2[] = { 98.2, 75.4, 60.5, 77.0, 99.5 };
	float gradeBuffer3[MAX] = { 98.2 };

	gradeBuffer[4] = 100.0;
	gradeBuffer[3] = 100.0;
	gradeBuffer[2] = 100.0;
	gradeBuffer[1] = 100.0;
	gradeBuffer[0] = 100.0;

	printf("%f\n", gradeBuffer[4]);
	printf("%f\n", gradeBuffer[3]);
	printf("%f\n", gradeBuffer[2]);
	printf("%f\n", gradeBuffer[1]);
	printf("%f\n", gradeBuffer[0]);

	for (int index = 0; index < MAX; index++) {
		gradeBuffer[index] = 0.00;
	}
	for (int index = 0; index < MAX; index++) {
		printf("%f\n", gradeBuffer[index]);
	}
	return 0;
}

#include <stdio.h>
#define MAX 5

int Add2Numbers(int, int);

int main() { //declare an array of floats to store grades

	int operation, operation2, sum;
	printf("Enter two numbers to add: ");
	scanf("%d %d", operation, operation2); //get User Input

	Add2Numbers(operation, operation2); //implements the new function into main

	return 0;
}

int Add2Numbers(int operation, int operation2) {

	int sum = operation + operation2; //calculate Value
	return sum;
}

Void displayNumbers(int[], const int); //fully document prototypes

Void displayNumbers(int 1buffer[], const int BUFFERSIZE) {
	printf("array contents: ");
	For (int index = 0; index < BUFFERSIZE; index++)
		printf("\t1buffer[%d] = %d\n", index, 1buffer[index]);
}

Int AddThreeNumbers(int, int, int);

Int main() {
	Int numbers[] = {12, 50, 1000};
	Int sum = AddThreeNumbers(numbers[0], numbers[1], numbers[2]);
	Return 0;
}

Int AddThreeNumbers(int operand1, int operand2, int operand3) {
	Return sum = operand1 + operand2 + operand3;
}

Int multi_array[10][20]; //10 units of 20

#include <stdio.h>
#define LENGTH 10

void DisplayNumbers(int [], int); //array, size of array

int main() {
	int numbers[LENGTH] = { 10, 2, 3, 99, 44, 33, 22, 11, 10, 100 };

	DisplayNumbers(numbers, LENGTH);
	DisplayNumbers(numbers, LENGTH); //prints conversion array list

	printf("Enter a value in sub element 0: ");
	scanf("%d", &numbers[0]);

	DisplayNumbers(numbers, LENGTH); //sets array[0] to the user Input

	return 0;
}

void DisplayNumbers(int buffer[], int size) {
	for (int index = 0; index < size; index++) {
		printf("array[%d] = %d\n", index, buffer[index]);
	}
	buffer[0] = 1001; //value of array in main reflected back
}

Sorting //grabs an array and puts it into descending/ascending order
Sort - insertion sort and quicksort
Binary search assumes array is in ascending order
Insertion sort
Explanation and source code in book
Only handles int or arrays
Calling:
Int main() {
	Int 1buff[ARRAYSIZE] = {5, 4, 3, 2, 1};
DisplayArray(1buff, ARRAYSIZE);
	//finish for homework
Qsort
Several parts to it:
1. Array name, 2. Size of array, 3. How many elements, 4. Compare function names
qsort(numbers, SIZE, sizeof(numbers[0]), compareIntArray);

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void DisplayNumbers(int [], int); //array, size of array
int compareIntArray(const void *, const void *);

int main() {
	int numbers[LENGTH] = { 100, 2, 3, 99, 44, 33, 22, 11, 10, 100 };
	DisplayNumbers(numbers, LENGTH);
	qsort(numbers, LENGTH, sizeof(int), compareIntArray);
	DisplayNumbers(numbers, LENGTH);

	return 0;
}

void DisplayNumbers(int buffer[], int size) {
	for (int index = 0; index < size; index++) {
		printf("array[%d] = %d\n", index, buffer[index]);
	}
}

int compareIntArray(const void *left, const void *right) {
	if (*(int *)left < *(int *)right)
		return -1; //-1 
	return *(int *)left > *(int *)right;
}

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void DisplayNumbers(int [], int); //array, size of array
int compareIntArray(const void *, const void *);

int main() {
	int numbers[LENGTH] = { 100, 2, 3, 99, 44, 33, 22, 11, 10, 100 };
	DisplayNumbers(numbers, LENGTH);
	qsort(numbers, LENGTH, sizeof(int), compareIntArray);
	DisplayNumbers(numbers, LENGTH);

	return 0;
}

void DisplayNumbers(int buffer[], int size) {
	for (int index = 0; index < size; index++) {
		printf("array[%d] = %d\n", index, buffer[index]); //buffer[index] = element at index position
	}
}

int compareIntArray(const void *left, const void *right) {
	if (*(int *)left < *(int *)right)
		return -1; //-1 
	return *(int *)left > *(int *)right;
}
Pointer variable stores an address (location, store of memory) which always equals to 4 bytes
heap/Stack space - data structure that isn't managed, but able to retrieve data from it
All variables are stored at a memory address location
*grade *pwd = pointers (store the address of the value (15)), the location contains the memory
Int myVal = 15;
Int *grade;
Grade = &myVal;

my val = (15) = 0xF025
Pwd = (0xF025) = int *pwd == 8myVal
Sum = (0xF030) = int *sum == pwd
Grade = = int *grade;
	Grade = pwd
Pointer declaration: indirection operator = int *var == &var2
Assigning an address:
Assign null to a pointer
Each pointer has a unique address

#include <stdio.h>
#include <stdlib.h>

int main() {
	int value = 15;
	int value2 = 20;
	int value3 = 25;

	int *ptr1 = &value;
	int *ptr2 = &value2;
	int *ptr3 = NULL;

	*ptr3 = value3;
}


Int a = 13;
Int b = 17;
Int c = 19;
//declared, no value, assigned in memory
Int *ptr_1;
Int *ptr_2;
Int *ptr_3 = NULL;
//address of variable assigned to pointer variable
Ptr_1 = &a;
Ptr_2 = &b;
ptr_3 = &c;
= [A] [13] [0027F658] [4] //var name, value, address, sizeOf()
Printing an address = %p, 8myVal //prints address
"%p", 8ptr_1 //prints address contained within
Changing the value the pointer 'points to':
"%d", *pwd //reads actual value
*pwd = 20 //rewriting
Pwd = 20 //overwriting memory
(*ptr_1)++; // = 13 + 1
*ptr_2 = 23;
*ptr_3 -= 8;

*ptr_1++; //= moves 4 bytes over

Arrays and pointers are related:
Difference: array name is a pointer const
Address equates to each index
lbuff(0032F938) == &lbuff[0](0032F938)

lbuff(0032f92c) == &lbuff[0](0032f92c) == ptr(0032f92c)
					   != &ptr(0032f92c)

Int lbuff[SIZE] = {
	1, 3, 5, 7, 9, 11 //arrays
	};
Int *ptr = lbuff;

*(ptr + 0) == *(lbuff + 0); //reads lbuff[0]
*(ptr + 1) == *(lbuff + 1);
*(ptr + 2) == *(lbuff + 2);
*(ptr + 3) == *(lbuff + 3);
*ptr == *(lbuff + 4); //reads lbuff[4]; do not axceed array boundary
= [*(ptr + 0)] [0032F92C] [1] [0032F92C] ←- pointer address never changes
Pointer arithmetic: pointer modifies the addy without modifying the real value
= [1buff[0]] [0032f92c] [1] [ptr++] [0032f92c] [1] [0032f92c]


#define LENGTH 70

void displayNumbers(int[], int); //array, size of array
int compareIntArray(const void *, const void *);
void insertSort(int[], int);

int main() { //uses insert sort to print the ascending array
	
	printf("encoded list of results:\n");

	int numbers[LENGTH] = { 8,7,2,4,44,4,430, //the array is listed
	8,6,1,7,23,4,342,
	2,4,4,4,56,4,715,
	3,7,5,1,25,5,133,
	0,5,3,0,19,9,122,
	3,6,0,7,77,4,683,
	7,9,3,4,14,4,955,
	7,3,4,5,78,6,901,
	6,7,4,4,96,6,600,
	3,7,4,1,98,0,351 };

	displayNumbers(numbers, LENGTH); //prints array list

	printf("ascending decoded list of results:\n");

	insertSort(numbers, LENGTH);
	displayNumbers(numbers, LENGTH); //prints new array list, which was modified by qsort

	return 0;
}

void displayNumbers(int buffer[], int size) {
	for (int index = 0; index < size; index++) {
		printf("%d. buffer[%d] = %d\n", index + 1, index, buffer[index]);
	}
}

int compareIntArray(const void *left, const void *right) {
	if (*(int *)left < *(int *)right)
		return -1;
	return (*(int *)left > *(int *)right);
}

void insertSort(int list[], int max) {

	int i, j, temp;

	for (i = 1; i < max; i++) {

		temp = list[i];
		j = i - 1;
		while (j >= 0 && temp < list[j]) {
			list[j + 1] = list[j];
			j = j - 1;
		}
	List[j + 1] = temp;

	}
}

void displayNumbers(int buffer[], int size) {
	for (int index = 0; index < size; index++) {
		Numbers[index] = 0; //allows you to print the entire list of arrays into 1 constant integer
	}
}

	*ptr; //1
	++ptr;
	*ptr; //2

int main() {
	int numbers[5] = { 1, 2, 3, 4, 5 };
	int *ptr;
	ptr = numbers;

	for (int index = 0; index < 5; index++)
		printf("numbers[%d] = 0x%p\n", index, numbers[index], (numbers + index));
	printf("value = %p address = %d\n", *(ptr)++, ptr); //dereference address is displayed and incremented to 2
	printf("value = %p address = %d\n", ++(*ptr), ptr); //increment pointer 1, display value

	return 0;
}

int main() {
	int numbers[5] = { 1, 2, 3, 4, 5 };
	int *ptr;

	int value = 22;
	ptr = &numbers[4];
	*ptr; //5
	*(--ptr); //4
	--ptr;
	*ptr;

Strings: (array of characters)
Null terminated - '\0'
2 options when initializing
MUST set NULL terminator = { 'c', 'b', '/0' };
Control string:
printf("%s\n", messageBuffer1);

Alternate method:
Char messageBuffer2[] = "computer science"; //automattically null terminates


Char messageBuffer3[15];
messageBuffer1 = "test string";

Modifying string:
Array bracket accesses the character
How to make all characters lower case?
Using loops
For (int index = 0; index < sizeof(messageBuffer2) - 1; index++) //the -1 = doesn’t include the '/0' operator
	printf("%c", toupper(messageBuffer2[index]));
Common operations for strings:
Finding characters, finding a substring, reversing the order, count the characters, changing the casing of characters(upper/lower case), copy a string, concatenate a string(2 strings unit to make a 3rd array), compare the size of strings

int main() {

	int frequency = 0; int counter = 0;

	char messageArray[] = { 'a', 'b', 'c', 'd', '\0' };
	char messageArray2[] = "abcd";


	printf("%s\n", messageArray); //prints 1st array list
	printf("%s\n", messageArray2); //prints a 2nd array list

	for (int index = 0; index < sizeof(messageArray2) - 1; index++) { //finds and adds to how long the array is
		counter++;
	}

	printf("Character Count = %d\n", counter);

	for (int index = 0; index < sizeof(messageArray2) - 1; index++) {  //finds and adds to how many times the character is in the list
		if (messageArray2[index] == 'c')
			frequency++;
	}
	printf("Frequency of %c = %d\n", 'c', frequency);

	return 0;
}

Function list
Stdio.h
Char *gets(char *);
Int puts(char *);
String.h
Int strien(char *);
Void strcpy(char *, char *);

Int puts(char *);

int main() {
	char buffer[10];

	printf("enter a value:\n");
	gets(buffer);

	puts(buffer);
	printf("%s\n", buffer);
}

Int strlen(char *);

Char messagebuffer2[] = "computer science";
Int length = strlen(messagebuffer2);
printf("length = %d\n", length);

Void strcpy(char *, char *);

Char messagebuffer1[SIZE];
Char messagebuffer2[] = "computer science";
Int *msgPtr = messagebuffer1;
msgPtr = strcpy(messagebuffer1, messagebuffer2);
printf("%s\n, msgPtr); //same address
printf("%s\n", messagebuffer1); //same address

Void strcat(char *, char *);

#define SIZE 20

Int main() {
Char messagebuffer1[SIZE] = "computer";
Char messagebuffer2[] = "science";
Int *msgPtr = messagebuffer1;
msgPtr = strcat(messagebuffer1, messagebuffer2);
printf("%s\n, msgPtr); //same address
printf("%s\n", messagebuffer1); //same address
}

Int strcmp(char *, char *); //compare 2 strings(case sensitive)



Char messagebuffer1] = "computer";
Char messagebuffer2[] = "science";
Int result = strcmp(messageBuffer1, messagebuffer2);
If (result < 0)
printf("messagebuffer1 is less than messagebuffer2");
Else if(result > 0)
	printf("buffer2 < buffer1")
Else
	printf("buffer 1 == buffer2")

Pointer address == &array[0]

Char messagebuffer[] = "computer science";
Int length = strlen(messagebuffer);
for (char *ptr = messagebuffer; ptr < &messagebuffer[length]; ptr++)
	printf("%c", messagebuffer);

Char *messagebuffer2 = "computer science"; //pointer that can be modified

Char *buffer[3]; //uses no wasted space
Hello
World
Hi 

int main() {
	char *sec[5] = { "alabama", "auburn", "georgia", "mississippi", "LSU" };
	char bama[] = "alabama";

	printf("%s\n", sec[0]); //%s = string, [0] = location of the array
	printf("%s\n", bama);

	bama[2] = 'F';
	char *ptr = bama;
	*(ptr + 2) = 'F';
	char *gaPtr = sec[2];

	return 0;
}

Pointers chapter 12
int main() {
	int i = 7;
	int* ip = &i;

	printf("Address %p contains %d\n", ip, *ip);
	*ip = 8;

	printf("Now address %p contains %d\n", ip, *ip);

	return 0;
}

//address 0012FF88 contains 7
//Now address 0012FF88 contains 8

Void swap (int* x, int* y) {
	Int temp = *x;
	*x = *y;
	*y = temp;
}
Int main() {
	Int i = 1, j = 2;
	swap(&i, &j);
	printf(“i == %d, j == %d\n”, i, j);

	Return 0;
}
//i == 2, j == 1

int main(int argc, char* argv[]) {
	int i;
	for (i = 0; i < argc; ++i)
		puts(argv[i]);
	return 0;
}

//D:\TIC> .\echo hello there
//D:\TIC\echo.exe
//hello
//there

C heap functions:
void* malloc(size_t size);
Void free(void *ptr);
Void *calloc(size_t nelems, size_t elem_size);
void* realloc(void *ptr, size_t size);

//prints lines in reverse order from input
#define MAXWIDTH 81
#define MAXLINES 100

int main() {
	char* lines[MAXLINES];
	char line[MAXWIDTH];
	int i, n;

	for (n = 0; //store in a ragged array
		n < MAXLINES && gets(line) != NULL; ++n) {
		if ((lines[n] = malloc(strlen(line) + 1)) == NULL)
			exit(1);
		strcpy(lines[n], line);
	}

	//prints in reverse order
	for (i = 0; i < n; ++i) {
		puts(lines[n - i - 1]);
		free(lines[n - i - 1]);
	}
	return 0;
}

//passes a struct by address
struct Date {
	int year;
	int month;
	int day;
};

void printDate(struct Date* p) {
	printf("%2d/%2d/%2d", p->month, p->day, p->year);
}

int main() {
	struct Date d = { 98, 10, 2 };
	printDate(&d);

	return 0;
}
//10 / 2 / 98

#include "employ2.h"
#include <stdio.h>
#include <string.h>

#define MAXEMPS 5

int main() {
	struct Employee* emps[MAXEMPS];
	struct Employee* p;
	int i, nemps = 0;

	emps[nemps++] = createEmployee("Mantle", "Mickey", "Outfielder", 58);
	emps[nemps++] = createEmployee("Maris", "Roger", "Shortstop", 60);

	if (emps[nemps - 1]->salary != 61)
		emps[nemps - 1]->salary = 61;

	p = createEmployee("", "", "", 0);
	setLast(p, "Kaline");
	setFirst(p, "Al");
	setTitle(p, "Outfielder");
	setSalary(p, 52);
	emps[nemps++] = p;

	for (i = 0; i < nemps; ++i)
		printEmployee(emps[i]);
		putchar('\n');
		free(emps[i]);
	}
}

//{Mantle, Mickey, Outfielder, 58}
//{Maris, Roger, Shortstop, 61}
//{Kaline, Al, Outfielfer, 52}

Strings chapter 13
//Initializing an array
Char messageBuffer1[] = { ‘c’, ‘o’, ‘m’, ‘p’, ‘\0’ };
printf("%s");
//prints an input sequence backwards

#define SIZE 20

Int main() {
	Int i, n;
	Int nums[SIZE];

	For (n = 0; n < SIZE; ++n) {
		Int input;
		scanf("%d", &input);
		
		If (input == 0)
			Break;
		Nums[n] = input;
	}
	For (i = n - 1; i >= 0; --i)
		printf("%d", nums[i]);
	Return 0;
}

//2D array

Int main() {
	Int a[][2] = {{1,2}, {3,4}, {5,6}};
	Int i, j;

	For (i = 0; n < 3; ++i) {
		For (j = 0; j < 2; ++ j)
			printf("%d", a[i][j]);
		putchar('\n');
	}
	Return 0;
}
//1 2
//3 4
//5 6

//3D Array
Int main() {
	Int a[][3][2] = {{{1,2}, {3,4}, {5,6}}, 
{7,8}, {9,0}, {1,2}}};
	Int i, j, k;
	
	For (i = 0; i < 2; ++i) {
		For (j = 0; j < 3; ++j) {
			For (k = 0; k < 2; ++k)
				printf("%d", a[i][j][k]);
			putchar('\n');
	}
	putchar('\n');
}
Return 0;
}
//Initializing a string as a char
#include <stdio.h>
#include <string.h>

int main() {
	char last[] = { 'f', 'r', 'o', 's', 't', '\0' };
	char first[] = "robert";
	printf("last == %s\n", last);
	printf("first == %s\n", first);
	printf("last has %d chars\n", strlen(last));
	printf("first has %d chars\n", strlen(first));
	return 0;
}

//last == frost
//first == robert
//last has 5 chars
//first has 6 chars

//string example
int main() {
	int n = 1;
	float x = 2.0;
	char s[] = "hello";
	char string[BUFSIZ];

	sprintf(string, "%d %f j%s", n + 1, x + 2, s + 1);
	puts(string);

	sscanf(string, "%d %f %s", &n, &x, s);
	printf("n == %d, x == %f, s == %s\n", n, x, s);

	return 0;
}

//2 4.00000 jello
//n == 2, x == 4.00000, s == jello

//illustrates structures
struct Hitter {
	char last[16]; //15 + 1
	char first[11]; //10 + 1
	int home_runs;
}; //dont forget the ;

int main() {
	struct Hitter h1 = { "McGwire", "Mark", 70 };
	struct Hitter h2;

	strcpy(h2.last, "Sosa");
	strcpy(h2.first, "Sammy");
	h2.home_runs = h1.home_runs - 4;

	printf("#1 == {%s, %s, %d}\n", h1.last, h1.first, h1.home_runs);
	printf("#2 == {%s, %s, %d}\n", h2.last, h2.first, h2.home_runs);

	return 0;
}

//#1 == {McGwire, Mark, 70}
//#2 == {Sosa, Sammy, 66}

//another structure example = hall of fame showing a struct within a struct
//illustrates nested structures
struct Hitter {
	char last[16]; //15 + 1
	char first[11]; //10 + 1
	int home_runs;
	int year;
};

struct HallOfFame {
	struct Hitter players[10];
	int nPlayers;
};

int main() {
	struct HallOfFame hr;
	int i;
	hr.nPlayers = 0;

	//first player insert
	strcpy(hr.players[hr.nPlayers].last, "Ruth");
	strcpy(hr.players[hr.nPlayers].first, "Babe");
	hr.players[hr.nPlayers].home_runs = 60;
	hr.players[hr.nPlayers++].year = 1927;

	//next player insert
	strcpy(hr.players[hr.nPlayers].last, "Maris");
	strcpy(hr.players[hr.nPlayers].first, "Roger");
	hr.players[hr.nPlayers].home_runs = 61;
	hr.players[hr.nPlayers++].year = 1961;

	for (i = 0; i < hr.nPlayers; ++i)
		printf("%d: {%s, %s, %d}\n", hr.players[i].year,
			hr.players[i].last,
			hr.players[i].first,
			hr.players[i].home_runs);

	return 0;
}

//1927: {Ruth, Babe, 60}
//1961: {Maris, Roger, 61}

# include <stdio.h>
			//find /i "hi" input.txt
			//3
int main(int argc, char *argv[]) { //capture what we will put in the command line (count of user passed in parameters, an array of strings)
	
	printf("Size of array = %d\n", argc);

	for (int index = 0; index < argc; index++) {
		printf("argv[%d] = %s\n", index, argv[index]); //prints file location
	}

	return 0;
}

# include <stdio.h>
# include <string.h>

			//find /i "hi" input.txt
			//3
int main(int argc, char *argv[]) { //capture what we will put in the command line (count of user passed in parameters, an array of strings)

	//-c means to count the characters in a string (without null)
	//-h means to display the help menu

	if (!strcmp(argv[1], "-h")) {
		printf("Help\n");
		printf("options: -c = Count the characters in a string\n");
		printf("options: -h = Help menu\n");
	}

	else if (!strcmp(argv[1], "-c")) {
		int count = strlen(argv[2]);
		printf("Count of characters: %d", count);
	}

	else {
		printf("incorrect arguments\n");
	}

	return 0;
}

Enum Boolean {False, True}; //base syntax: enumeration
Keyword, enum name, values

Enum Boolean lowercase;
Char input = 'c';

Lowercase = islower(input);

If (lowercase == false) {
	toupper9input);
}

Change default value:

Resequenced in order: 2, 3, 4:

Enum schedule { jan = 1, feb, mar, apr, may, jun… };


Enum Schedule month = Jan + 1; //uses math to find location
If (month == Feb) {
	printf("month = feb\n");
}

Typedef enum Boolean {False, True,}bool;

Int main() {
	Bool answer = true;
	If answer == true
		printf("true");
	Else
		printf("false);

Enum Boolean {false, true};

Int main() {
	Enum Boolean answer = True;
	
	If (answer == true)
		printf("true");
	Else
		"False"

Structure: mixes and scalar structured data types


#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <string.h>

typedef struct {
	char name[BUFFERSIZE]; //become declared
	float gpa;
	int year;

}Student;
Student students[BUFFERSIZE];

# include <stdio.h>
# include <string.h>
#define SIZE 20

typedef struct {
	char first[SIZE]; //become declared
	char last[SIZE];
	int id;

}Student, Teacher;

int main() {
	Student _112Student1; //declared
	//writing to the structure
	strcpy(_112Student1.first, "Ada");
	strcpy(_112Student1.last, "Lovelace");
	_112Student1.id = 1;
	//reading from the structure
	printf("ID: %d\t student name = %s %s\n", _112Student1.id, _112Student1.first, _112Student1.last);
	return 0;
}

# include <stdio.h>
# include <string.h>
#define SIZE 20

typedef enum Boolean {False, True}bool;

typedef struct {
	char first[SIZE]; //become declared
	char last[SIZE];
	int id;

}Student, Teacher;

Student CreateRecord(char *, char *, int);
void displayRecord(Student);
bool lastNameMatch(Student *, char *);

int main() {
	Student _112Student1, _112Student2; //declared
	//writing to the structure
	bool isMatch;
	Student students[SIZE];
	students[0] = CreateRecord("Ada", "Lovelace", 1);
	students[1] = CreateRecord("Charles", "Babbage", 2);

	for (int index = 0; index < 2; index++) {
		displayRecord(students[index]);
	}

	//reading from the structure
	displayRecord(students[0]);
	displayRecord(students[1]);

	isMatch = lastNameMatch(&_112Student1, "Babbage");
	return 0;
}

Student CreateRecord(char *first, char *last, int id) {

	Student _112Student1; //declared
	strcpy(_112Student1.first, first);
	strcpy(_112Student1.last, last);
	_112Student1.id = id;
	return _112Student1;
}

void displayRecord(Student record) {
	//reading from the structure
	printf("ID: %d\t student name = %s %s\n", record.id, record.first, record.last);
}

bool lastNameMatch(Student *record, char *lookup) {
	if (!strcmp(record->last, lookup)) {
		return True;
	}
	else
		return False;
}

# include <stdio.h>
# include <string.h>
#define SIZE 20

typedef struct {
	int month;
	int day;
	int year;
}DateOfBirth;

typedef struct {
	char first[SIZE];
	char last[SIZE];
	int id;
	DateOfBirth dob;
}Student, Teacher;
	
int main() {
	strcpy(_112Student1.first, "fred");
	strcpy(_112Student1.last, "brooks");
	_112Student[3].id = 4;
	_112Student[3].dob.day = 19;
	_112Student[3].dob.month = 4;
	_112Student[3].dob.year = 1931;
}

# include <stdio.h>
# include <string.h>

FILE *fp;

int main() {
	char wordBuffer[100];
	int counter = 1;
	Char *name[500];
	Int index = 0;
	if (!(fp = fopen("input.txt", "r")))
	{
		printf("error opening file!\n");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%s", wordBuffer);
		printf("%d, %s\n", counter++, wordBuffer); //prints the .txt file's words with the word count
		Name[index++] = wordBuffer;
		
	}
	return 0;
}
Add words: ptr++
Skip letters: ptr +=2
Ch *ptr = Buffx[3];
Moves 1 char to the next
Ptr++ = goto → 2nd char
Ptr + 3 = goto → 4th char

scanf("%s", word);
strcpy(buffer[0], word);

int main() {
	char word; int i;
	while (!feof(fp)) {
		fscanf(fp, "%s", word);
		strcpy(buffer[i], word);
}
Stack = stores and operates data
Produces errors when its overloaded with data
Stack pointer points to the top of the stack
Heap space:
Free bucket of memory to temporarily hold
Much more slower
Stack space
Limit on size
Create a pointer:
Int ptr*
Ptr = (int *) malloc(sizeof(int));
Returns heap address or null
<Alloc.h> <stdlib.h>

Int *ptr;
Ptr = (int *) malloc(sizeof(int));
*ptr = 150;
printf(“%d\n”, *ptr);

Deallocate (free) blocks:
Int *ptr;
Ptr = (int *) malloc(sizeof(int));
*ptr = 150;
printf(“%d\n”, *ptr);
free(ptr);


//persists string on the heap
int main()
{
	int *ptr;

	ptr = (int *)malloc(sizeof(int));

	*ptr = 150;

	printf("%d\n", *ptr);

	free(ptr);

	return(0);
}

Structures:

Student *ptr_struc;
Ptr_struc = (student *) malloc (sizeof(struct Student));

Student * _student[5]; //iterates 5x
For (i = 0; i < 5; i++);
	
//create 5 structs on heap
_student = (STUDENT *) malloc (5 * sizeof(Student));

//declare an array of structs
Student **_student;
_student = (STUDENT *) malloc (5 * sizeof(Student));
For (i = 0; i < 5; i++)
	_student[i] = (STUDENT *) malloc (sizeof(Student));

int main(void)
{
	char *buf;

	buf = illegalFoo();
	puts(buf);

	buf = legalFoo();
	puts(buf);
	free(buf);

	return(0);
}

char* illegalFoo(void) {
	char buf[100];
	strcpy(buf, "a ton of words son!");

	puts(buf);
	return buf;
}

char* legalFoo(void) {
	char buf[100];
	char *ptr;

	strcpy(buf, "a ton of words son!");

	puts(buf);
	ptr = strdup(buf);
	return ptr;
}

	//pg 255 pass by reference
	//populate an array with a string
	//finding a value in an array, sorted and unsorted
	//middle element in an array
	//find frequency
	//parralel arrays
	//insertion sort (memory)
	//implement qsort
	//binary sort
	//1 or 2 dimentional array, how to declare or initialize, and what happens to the array
	//declaring a pointer, assigning, reading and derefferencing it
	//pass by reference pg 309
	//pass a particular variable, 
	//pointer arithmetic
	//implement: void foo(int *, int size);
		//foo(array, 10);
//initialize a string in 2 ways, single or double quotes
//how to copy characters to an array
//2d arrays to store strings
//chp 14
	//definition of storage classes
	//storage classes
	//initializing arrays in static storage
	//numeration without type def and with

int main(void) {
	char buff1[] = "hi"; //3 bytes; fix 3 bytes
	char buff2[100] = "hi"; //100 bytes
	char *buff3 = "hi"; //7 bytes; fix 3 bytes
	return 0;
}

int main() {

	FILE *fp;

	fp = fopen("input.txt", "r");

	char wordBuffer[100];
	char *file[100];

	if (!(fp = fopen("input.txt", "r"))) {
		exit(1);
	}
	
	while (!feof(fp)) {
		fscanf(fp, "%s", wordBuffer); //single type specifier
		strcpy(file, wordBuffer);
	}
	return 0;
}


void count();

int main() {

	FILE *fp;

	fp = fopen("input.txt", "r");

	char wordbuffer[100];
	char *file[100];

	if (!(fp = fopen("input.txt", "r"))) {
		exit(1);
	}
	int index = 0;

	while (!feof(fp)) {
		fscanf(fp, "%s", wordbuffer); //single type specifier
		strcpy(file, wordbuffer);
		file[index++] = wordbuffer;
	}

	for (int a = 0; a < 100; a++) {
		printf("%s\n", file[a]);
	}

	return 0;
}

void count() {
	static int number = 0; // static retains the last value, after number has been used, it adds another 1
	number++;
	printf("%d\n", number);
}

//populate an array with a string
#include <stdio.h>
#include <string.h>
#define SIZE 15

typedef struct {
	char fname[SIZE];
	char lname[SIZE];
}Person;

void DoStuff(Person[], int);

int main() { //pass an array of structures to a function

	Person _chris, _kylie;
	Person slaters[10];

	strcpy(_chris.fname, "Chris");
	strcpy(_chris.lname, "Slater");
	strcpy(_kylie.fname, "Kylie");
	strcpy(_kylie.lname, "Slater");

	printf("%s\n", _chris.fname);
	printf("%s\n", _chris.lname);
	printf("%s\n", _kylie.fname);
	printf("%s\n", _kylie.lname);

	slaters[0] = _chris;
	slaters[1] = _kylie;

	return 0;
}


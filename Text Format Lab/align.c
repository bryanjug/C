#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXC 100000

FILE *fp;
FILE *fpout;

int main(void) {
	fpout = fopen("csis2.txt", "w");
	fp = fopen("ALongLine.txt", "r");

	int i = 0;
	int c = 0;
	size_t n = 0;

	while (n < MAXC && (c = fgetc(fp)) != EOF && c != '\0') {
		n++;

		for (i = 0; i < 50; i++) { //prints the new lines at position 63
			if (n == 63 * i) {
				if (c != ' ') {
					printf ("\n");
					fprintf(fpout, "\n");
				}
				else if (c == ' ') {
					printf("\n");
					fprintf(fpout, "\n");
				}
			}

		}

		if (c == '\n') { //prints new lines if there is any
			printf("\b%c", c - '\n');
			fprintf(fpout, "\b%c", c - '\n');
		}

		else if (c == ' ') { //prints spaces
			printf(" ");
			fprintf(fpout, " ");
		}
		
		else { //prints the words
			printf("%c", c);
			fprintf(fpout, "%c", c);

		}
	}

	printf("\n");
	fprintf(fpout, "\n");

	if (n == MAXC) /* read and discard remaining chars in stdin */
		while ((c = fgetc(fp)) != '\n' && c != EOF);

	fclose(fp);
	fclose(fpout);
	return 0;
}
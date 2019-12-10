#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXC 1000

FILE *fp;
FILE *fpout;

int main(void) {
	fpout = fopen("csis1.txt", "w");
	fp = fopen("getty.txt", "r");

	int c = 0;
	size_t n = 0;
	printf("+");
	fprintf(fpout, "+");

	/* read up to 100 characters from stdin, print each word on a line */
	while (n < MAXC && (c = fgetc(fp)) != EOF && c != '\0') {
		if (c == '\n') {
			printf("+%c\b", c - '\n');
			fprintf(fpout, "+%c\b", c - '\n');
		}
		else if (c == ' ') {
			printf("+\n+");
			fprintf(fpout, "+\n+");
		}
		else {
			printf("%c", c);
			fprintf(fpout, "%c", c);
		}
		n++;
	}

	printf("+\n");
	fprintf(fpout, "+\n");

	while (n < MAXC && (c = fgetc(fp)) != EOF && c != '\0') {
		if (c == '\n') {
			printf("%c", c - '\n');
			fprintf(fpout, "c", c - '\n');
		}
		else if (c == ' ') {
			printf("\n");
			fprintf(fpout, "\n");
		}
		else {
			printf("%c", c);
			fprintf(fpout, "%c", c);
		}
		n++;
	}

	if (n == MAXC) /* read and discard remaining chars in stdin */
		while ((c = fgetc(fp)) != '\n' && c != EOF);

	fclose(fp);
	fclose(fpout);
	return 0;
}
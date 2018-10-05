/* Find e to the Nth Digit: Enter a number and have the program generate PI up
 * to that many decimal places. Keep a limit to how far the program will go.
 */

/* define limit
 * save e up to limit digits in a table
 * Enter number
 * record number
 * if number < 1 or number > limit
 * 	return not found
 * look up e digits table
 * return digit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 10000

int importE(char*);
void startMsg();
int getNumber();
int checkRange(int);
char findDigit(int, const char*);

int importE(char* E)
{
	FILE* f = fopen("e.dat", "r");
	char buf[LIMIT +1];
	fread(buf, sizeof('1'), LIMIT, f);
	fclose(f);
	buf[LIMIT] = '\0';
	if(!strncpy(E, buf, LIMIT+1))
		exit(2);
	return 0;
}

void startMsg()
{
	printf("Enter a decimal number which you want to check e up to that place.\nrange is from 1 up to 10,000 digits.\n"); 
	printf("Enter a number: ");
}

int getNumber()
{
	int c, result;
	for(c = getc(stdin), result = 0; (isdigit(c)); c = getc(stdin))
		result = result * 10 + c - '0';
	return result;
}

char findDigit(int i, const char* E)
{
	char c;
	c = *(E + i - 1);
	return c;
}

int main()
{
	char E[LIMIT+1];
	importE(E);

	int i;		// record position
	char c;		// record digit
	// Input loop
	startMsg();
	while(1)
	{
		i = getNumber();
		c = findDigit(i, E);
		printf("The %dth digit of e is: %c\n", i, c);
		printf("Enter a number(q for quit):");
		c = getc(stdin);
		if(c == 'q' || c == 'Q')
			{printf("Bye\n"); break;}
		ungetc(c, stdin);	
	}
	return 0;
}

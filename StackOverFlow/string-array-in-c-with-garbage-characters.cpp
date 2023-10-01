/*
StackOverFlow/string-array-in-c-with-garbage-characters.cpp
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[50];
	int i, alpha = 0, digit = 0, spec;

	printf("Enter string: ");
	fgets(str, sizeof str, stdin);

	for (i = 0; str[i] != '\0'; i++) {
		// check for alphabets
		if (isalpha(str[i]) != 0)
			alpha++;

		// check for decimal digits
		else if (isdigit(str[i]) != 0)
			digit++;

		printf("%c", str[i]);
	}
	printf("\n%d %d", alpha, digit);
	return 0;
}
/*
Dear Diary,

I wrote this assignement over three days. I had fun; working with pointers and
LinkedLists is fun !

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "poly.h"
#include "polyterm.h"

// I promise the compiler that this variable exists in a file
extern struct PolyTerm *head;

void parse(int *coef, int *pow, char *line)
{
	// I create char pointers in order to parse the fget line
	char *coef1 = malloc(sizeof(char)*20);
	char *pow1 = malloc(sizeof(char) *20);
	sscanf(line, "%s %s", coef1, pow1);
	*coef = atoi(coef1); 
	*pow = atoi(pow1);
	
}

int powi (int base, int pow) {
	// I calculate powers in an efficient manner
	int result = 1;

	while (pow != 0) {
		result *= base;
		--pow;
	}
	return result;
}

int evaluatePolynomial(int x)
{
	// I evaluate the polynomial
	int result = 0;
	struct PolyTerm *temp = head;

	while(temp != NULL) {
		result = result + temp->coeff*powi(x, temp->expo);
		temp = temp->next;
	}
	printf("For x = %d         y = %d\n", x, result);
}

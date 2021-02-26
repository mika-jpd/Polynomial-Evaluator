#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "poly.h"

int main (int argc, char *argv[]) {
    int *coef = malloc(sizeof(int));
    int *pow = malloc(sizeof(int));

    // I check if there enough arguments
    if (argc != 2) {
        fprintf(stderr, "Errror, the input is polyapp <filename>\nYou have %d inputs", argc);
        exit(30);
    }

    FILE *file = fopen(argv[1], "rt");

    // I check whether the file exists
    if (file == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		exit(10);
	}

    // Dynamic programming!!
    // I loop through the file provided line by line and send it through parse
    char *num = malloc(20*sizeof(char));
    while (fgets(num, sizeof(num), file)) {
        parse(coef, pow, num);
        addPolyTerm (*coef, *pow);
    }
    displayPolynomial ();
    evaluatePolynomial(-2);
    evaluatePolynomial(-1);
    evaluatePolynomial(-0);
    evaluatePolynomial(1);
    evaluatePolynomial(2);
}
